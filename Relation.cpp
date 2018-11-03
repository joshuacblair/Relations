
#include"Relation.h"

Relation::Relation() {}

Relation::~Relation() {}

void Relation::buildRelation(std::string sName, std::vector<std::string> first) {
	name = sName;
	headers = first;
	return;
}

void Relation::insertRow(std::vector<std::string> currVec) {
	table.push_back(currVec);
	return;
}

std::vector<int> Relation::select(std::vector<std::string> queryVec) {
	std::vector<int> lockedCol;
	std::vector<std::string> repeatCheck;
	for(size_t i = 0; i < queryVec.size(); i++) {
		if (queryVec.at(i).at(0) == "'") {
		   lockedCol.push_back(i);
		}
 		else {
			if (repeatCheck.size() > 0) {
				bool duplicate = false;
				for (size_t j = 0; j < repeatCheck.size(); j++) {
					if (queryVec.at(i) == repeatCheck.at(j)) {
						duplicate = true;
						break;
					}
				}
				if (duplicate) {
					lockedCol.push_back(i);
				}
				else {
					repeatCheck.push_back(queryVec.at(i));
				}
			}
			else {
				repeatCheck.push_back(queryVec.at(i));
			}	
		}
	}
	return;
}

void Relation::project() {

	return;
}

void Relation::rename() {

	return;
}
