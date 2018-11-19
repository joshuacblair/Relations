#ifndef RELATION_H
#define RELATION_H

#include<utility>
#include<map>
#include<string>
#include<vector>
#include<iostream>
#include<sstream>

enum varType {CONSTANT, VARIABLE};
enum varStatus {LOCKED, UNLOCKED};

typedef	std::vector<std::string> ROW;	
typedef std::vector<ROW> TABLE;

struct queryData {
	std::string data;
	int column;
	varType type;
	varStatus status;
};

class Relation {
	private:
		std::string name;
		ROW headers;
		TABLE table;
		int numUnlocked;
	public:
		Relation();
		~Relation();

		void buildRelation(std::string&, ROW&);
		void insertRow(ROW&);

		std::vector<queryData> select(ROW&);
		TABLE buildProject(std::vector<queryData>&);
		bool lockVarCheck(queryData&);
		bool constErase(TABLE&, queryData&, size_t&, size_t&);
		TABLE project(std::vector<queryData>&);
		void rename(ROW&);
		void resolveQuery(ROW&);
		std::string toString(TABLE&, std::vector<queryData>&);
};

#endif //RELATION_H
