#include<iostream>
#include<string>
#include<vector>
#include"Relation.h"

int main(int argc, char * argv[]) {
		
	std::cout << "Test 1 - Should Yes(2)" << std::endl;
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
	
	std::cout << std::endl << "===========================" << std::endl;
	std::cout << "Test 2 - Should Yes(2)Yes(2)" << std::endl;
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
	
	std::cout << std::endl << "===========================" << std::endl;
	std::cout << "Test 3 - Should No" << std::endl;
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
	
	std::cout << std::endl << "===========================" << std::endl;
	std::cout << "Test 4 - Should No" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	
	
	Relation test4;
	std::string nameD = "RelD";
	std::vector<std::string> DA = {"a", "b", "c"};
	std::vector<std::string> DB = {"'Josh'", "'Ben'", "'Ashley'"};
	std::vector<std::string> DC = {"'Josh'", "'Ashley'", "'Ben'"};
	std::vector<std::string> DD = {"'Ben'", "'Ashley'", "'Josh'"};
	std::vector<std::string> DE = {"'Josh'", "x", "x"};
	test4.buildRelation(nameD, DA);
	test4.insertRow(DB);
	test4.insertRow(DC);
	test4.insertRow(DD);
	test4.resolveQuery(DE);
	
	std::cout << std::endl << "===========================" << std::endl;
	std::cout << "Test 5 - Should No" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	
	
	Relation test5;
	std::string nameE = "RelE";
	std::vector<std::string> EA = {"a", "b", "c"};
	std::vector<std::string> EB = {"'Josh'", "'Ben'", "'Ashley'"};
	std::vector<std::string> EC = {"'Josh'", "'Ashley'", "'Ben'"};
	std::vector<std::string> ED = {"'Ben'", "'Ashley'", "'Josh'"};
	std::vector<std::string> EE = {"x", "'Ashley'", "x"};
	test5.buildRelation(nameE, EA);
	test5.insertRow(EB);
	test5.insertRow(EC);
	test5.insertRow(ED);
	test5.resolveQuery(EE);
	
	std::cout << std::endl << "===========================" << std::endl;
	std::cout << "Test 6 - Should Yes(1)" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	
	
	Relation test6;
	std::string nameF = "RelF";
	std::vector<std::string> FA = {"a", "b", "c"};
	std::vector<std::string> FB = {"'Josh'", "'Ben'", "'Ashley'"};
	std::vector<std::string> FC = {"'Josh'", "'Ashley'", "'Ben'"};
	std::vector<std::string> FD = {"'Josh'", "'Josh'", "'Josh'"};
	std::vector<std::string> FE = {"x", "x", "x"};
	test6.buildRelation(nameF, FA);
	test6.insertRow(FB);
	test6.insertRow(FC);
	test6.insertRow(FD);
	test6.resolveQuery(FE);
	
	std::cout << std::endl << "===========================" << std::endl;
	std::cout << "Test 7 - Should Yes(1)" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	
	
	Relation test7;
	std::string nameG = "RelG";
	std::vector<std::string> GA = {"a", "b", "c"};
	std::vector<std::string> GB = {"'Josh'", "'Ben'", "'Ashley'"};
	std::vector<std::string> GC = {"'Josh'", "'Ashley'", "'Ben'"};
	std::vector<std::string> GD = {"'Josh'", "'Josh'", "'Josh'"};
	std::vector<std::string> GE = {"'Josh'", "'Josh'", "'Josh'"};
	test7.buildRelation(nameG, GA);
	test7.insertRow(GB);
	test7.insertRow(GC);
	test7.insertRow(GD);
	test7.resolveQuery(GE);
	
	std::cout << std::endl << "===========================" << std::endl;
	std::cout << "Test 8 - Should Yes(2)" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	
	
	Relation test8;
	std::string nameH = "RelH";
	std::vector<std::string> HA = {"a", "b", "c", "d"};
	std::vector<std::string> HB = {"'Josh'", "'Ben'", "'Ashley'", "'Chris'"};
	std::vector<std::string> HC = {"'Josh'", "'Ashley'", "'Ben'", "'Chris'"};
	std::vector<std::string> HD = {"'Ben'", "'Ashley'", "'Josh'", "'Chris'"};
	std::vector<std::string> HE = {"'Josh'", "opA", "opB", "'Chris'"};
	test8.buildRelation(nameH, HA);
	test8.insertRow(HB);
	test8.insertRow(HC);
	test8.insertRow(HD);
	test8.resolveQuery(HE);
	
	std::cout << std::endl << "===========================" << std::endl;
	std::cout << "Test 9 - Should Yes(2)" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	
	
	Relation test9;
	std::string nameI = "RelI";
	std::vector<std::string> IA = {"a", "b", "c"};
	std::vector<std::string> IB = {"'Josh'", "'Ben'", "'Ashley'"};
	std::vector<std::string> IC = {"'Josh'", "'Ashley'", "'Ben'"};
	std::vector<std::string> ID = {"'Ben'", "'Ashley'", "'Josh'"};
	std::vector<std::string> IE = {"y", "'Ashley'", "x"};
	test9.buildRelation(nameI, IA);
	test9.insertRow(IB);
	test9.insertRow(IC);
	test9.insertRow(ID);
	test9.resolveQuery(IE);
	
	std::cout << std::endl << "===========================" << std::endl;
	std::cout << "Test 10 - Should No" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;	

	Relation test10;
	std::string nameJ = "RelJ";
	std::vector<std::string> JA = {"a", "b", "c"};
	std::vector<std::string> JE = {"'Josh'", "x", "x"};
	test10.buildRelation(nameJ, JA);
	test10.resolveQuery(JE);
	
	return 0;
}

