
#include"Relation.h"

Relation::Relation() {}

Relation::~Relation() {}

void Relation::buildRelation(std::string &sName, ROW &first) {
	name = sName;
	headers = first;
	return;
}

void Relation::insertRow(ROW &currVec) {
	table.push_back(currVec);
	return;
}

std::vector<queryData> Relation::select(ROW &queryVec) {
	std::vector<queryData> processedQuery;
	numUnlocked = 0;
	for(size_t i = 0; i < queryVec.size(); i++) {
		queryData currData;
		currData.data = queryVec.at(i);
		currData.column = i;
		if (queryVec.at(i).at(0) == '\'') {
			currData.type = CONSTANT;
			currData.status = LOCKED;
		}
		else {
			currData.type = VARIABLE;
			if (processedQuery.size() > 0) {
				currData.status = UNLOCKED;
				numUnlocked++;
				for (size_t j = 0; j < processedQuery.size(); j++) {
					if (currData.data == processedQuery.at(j).data) {
						currData.status = LOCKED;
						numUnlocked--;
					}	
				}
			}
			else {
				currData.status = UNLOCKED;
				numUnlocked++;
			}
		}
		processedQuery.push_back(currData);
	}
	return processedQuery;
}

TABLE Relation::buildProject(std::vector<queryData> &processedQuery) {
	TABLE buildList;
	for (size_t i = 0; i < table.size(); i++) {
		buildList.push_back(table.at(i));
	}
	return buildList;
}

bool Relation::lockVarCheck(queryData& currData) {
	if ((currData.status == LOCKED) &&
		(currData.type == VARIABLE)) {
		return true;
	}
	return false;
}

bool Relation::constErase(TABLE &projectList, queryData &currData, size_t &i, size_t &j) {
	if ((currData.type == CONSTANT) &&
		(projectList.at(j).at(i) != currData.data)) {
		return true;
	}
	return false;
}

TABLE Relation::project(std::vector<queryData> &processedQuery) {
	TABLE projectList = buildProject(processedQuery); 

	for (size_t i = 0; i < processedQuery.size(); i++) {

		for (size_t j = 0; j < projectList.size(); j++) {

			if (/*(processedQuery.at(i).type == CONSTANT) &&
				(projectList.at(j).at(i) != processedQuery.at(i).data)*/ constErase(projectList, processedQuery.at(i), i , j)) {
				projectList.erase(projectList.begin() + j);
			}	

			if (lockVarCheck(processedQuery.at(i))) {
				for (size_t k = 0; k < processedQuery.size(); k++) {
					if ((processedQuery.at(i).data == processedQuery.at(k).data) &&	
						(projectList.at(j).at(i) != projectList.at(j).at(k))) {
						projectList.erase(projectList.begin() + j);
						--j;
						break;
					}
				}
			}
		}
	}
	return projectList;
}

void Relation::rename(ROW &currQuery) {
	for (size_t i = 0; i < currQuery.size(); i++) {
			headers.at(i) = currQuery.at(i);
	}
	return;
}

void Relation::resolveQuery(ROW &currQuery) {
	std::vector<queryData> processedQuery;
	processedQuery = select(currQuery);

	TABLE projectTable;
	projectTable = project(processedQuery);
	
	rename(currQuery);

	std::cout << toString(projectTable, processedQuery);
	return; 
}

std::string Relation::toString(TABLE &results, std::vector<queryData> &processedQuery) {
	std::ostringstream os;
	os << name << "(";
	for (size_t i = 0; i < headers.size() - 1; ++i) {
		os << headers.at(i) << ",";
	}
	os << headers.at(headers.size() - 1) << ")? ";
	if (results.size() > 0) {
		os << "Yes(" << results.size() << ")" << std::endl;
		for (size_t i = 0; i < results.size(); i++) {
			int tempNumUnlocked = numUnlocked;
			os << "  ";
			for (size_t j = 0; j < processedQuery.size(); j++) {
				if (processedQuery.at(j).status == UNLOCKED) {
					os << headers.at(j) << "=" << results.at(i).at(j);
				}
				if ((tempNumUnlocked > 1) &&
					(processedQuery.at(j).status == UNLOCKED)) {
					--tempNumUnlocked;
					os << ", ";
				}
			}
			os << std::endl;
		}
	}
	else {
		os << "No" << std::endl;
	}

	

	return os.str();
}	
