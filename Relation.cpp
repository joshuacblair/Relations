
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
				for (size_t j = 0; j < processedQuery.size(); j++) {
					if (currData.data == processedQuery.at(j).data) {
						currData.status = LOCKED;
					}	
				}
			}
			else {
				currData.status = UNLOCKED;
			}
		}
		processedQuery.push_back(currData);
	}
	return processedQuery;
}

TABLE Relation::project(std::vector<queryData> &processedQuery) {
	TABLE projectList; 
	for (size_t i = 0; i < table.size(); i++) {
		projectList.push_back(table.at(i));
	}
	
	for (size_t i = 0; i < processedQuery.size(); i++) {

		for (size_t j = 0; j < projectList.size(); j++) {

			if ((processedQuery.at(i).status == LOCKED) &&
				(processedQuery.at(i).type == CONSTANT) &&
				(projectList.at(j).at(i) != processedQuery.at(i).data)) {
				projectList.erase(projectList.begin() + j);
			}	

			if ((processedQuery.at(i).status == LOCKED) &&
				(processedQuery.at(i).type == VARIABLE)) {
				for (size_t k = 0; k < processedQuery.size(); k++) {
					if ((processedQuery.at(i).data == processedQuery.at(k).data) &&	
						(projectList.at(j).at(i) != projectList.at(j).at(k))) {
						projectList.erase(projectList.begin() + j);
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

	std::cout << toString(projectTable);
	return; 
}

std::string Relation::toString(TABLE &results) {
	std::ostringstream os;
	os << name << "(";
	for (size_t i = 0; i < headers.size() - 1; ++i) {
		os << headers.at(i) << ",";
	}
	os << headers.at(headers.size() - 1) << ")? ";
	if (results.size() > 0) {
		os << "Yes(" << results.size() << ")" << std::endl;
	}
	else {
		os << "No" << std::endl;
	}
	return os.str();
}	
