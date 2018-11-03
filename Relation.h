#ifndef RELATION_H
#define RELATION_H

#include<tuple>
#include<map>
#include<string>
#include<vector>

class Relation {
	private:
		std::string name;
		std::vector<std::string> headers;
	   	typedef	std::vector<std::string> ROW;	
		std::vector<ROW> table;
	public:
		Relation();
		~Relation();

		void buildRelation(std::string, std::vector<std::string>);
		void insertRow(std::vector<std::string>);

		std::vector<int> select(std::vector<std::string>);
		void project();
		void rename();
};

#endif //RELATION_H
