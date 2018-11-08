#include<iostream>
#include<string>
#include<vector>
#include"Relation.h"

int main(int argc, char * argv[]) {
		
	std::cout << "Test 1" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	
	
	Relation test1;
	std::string nameA = "RelA";
	std::vector<std::string> AA = {"a", "b"};
	std::vector<std::string> AB = {"'Josh'", "'Ben'"};
	std::vector<std::string> AC = {"'Josh'", "'Ashley'"};
	std::vector<std::string> AD = {"'Ben'", "'Ashley'"};
	std::vector<std::string> AE = {"'Josh'", "x"};
	test1.buildRelation(nameA, AA);
	test1.insertRow(AB);
	test1.insertRow(AC);
	test1.insertRow(AD);
	test1.resolveQuery(AE);
	
	std::cout << "Test 2" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	

	Relation test2;
	std::string nameB = "RelB";
	std::vector<std::string> BA = {"a", "b", "c"};
	std::vector<std::string> BB = {"'Josh'", "'Ben'", "'Ashley'"};
	std::vector<std::string> BC = {"'Josh'", "'Ashley'", "'Ben'"};
	std::vector<std::string> BD = {"'Ben'", "'Ashley'", "'Josh'"};
	std::vector<std::string> BE = {"'Josh'", "x", "y"};
	std::vector<std::string> BF = {"opA", "'Ashley'", "opB"};
	test2.buildRelation(nameB, BA);
	test2.insertRow(BB);
	test2.insertRow(BC);
	test2.insertRow(BD);
	test2.resolveQuery(BE);
	test2.resolveQuery(BF);
	
	std::cout << "Test 3" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	
	
	Relation test3;
	std::string nameC = "RelC";
	std::vector<std::string> CA = {"a", "b", "c"};
	std::vector<std::string> CB = {"'Josh'", "'Ben'", "'Ashley'"};
	std::vector<std::string> CC = {"'Josh'", "'Ashley'", "'Ben'"};
	std::vector<std::string> CD = {"'Ben'", "'Ashley'", "'Josh'"};
	std::vector<std::string> CE = {"x", "x", "x"};
	test3.buildRelation(nameC, CA);
	test3.insertRow(CB);
	test3.insertRow(CC);
	test3.insertRow(CD);
	test3.resolveQuery(CE);
	
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

