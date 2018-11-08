#include<iostream>
#include<string>
#include<vector>
#include"Relation.h"

int main(int argc, char * argv[]) {
		
	std::cout << "Test 1" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	
	
	Relation test1;
	std::string name = "RelA";
	std::vector<std::string> AA = {"a", "b"};
	std::vector<std::string> AB = {"'Josh'", "'Ben'"};
	std::vector<std::string> AC = {"'Josh'", "'Ashley'"};
	std::vector<std::string> AD = {"'Ben'", "'Ashley'"};
	std::vector<std::string> AE = {"'Josh'", "x"};
	test1.buildRelation(name, AA);
	test1.insertRow(AB);
	test1.insertRow(AC);
	test1.insertRow(AD);
	test1.resolveQuery(AE);
	
	std::cout << "Test 2" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	

	std::cout << "Test 3" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	
	
	std::cout << "Test 4" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	
	
	std::cout << "Test 5" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	
	
	std::cout << "Test 6" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	
	
	std::cout << "Test 7" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	
	
	std::cout << "Test 8" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	
	
	std::cout << "Test 9" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	
	
	std::cout << "Test 10" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	

	return 0;
}

