#define CATCH_CONFIG_MAIN
#include "Catch/include/catch.hpp"
#include "DataBase.h"
#include <iostream>
#include <vector>
#include <typeinfo>
/*
SCENARIO("A database table is created", "createTable") {
	pair<string, int> xcoord = {"x", 5};
        pair<string, int> ycoord = {"y", 10};
        pair<string, int> zcoord = {"z", 2};
        string name = "points";
        vector<pair<string, int>> attributespoints = {xcoord, ycoord, zcoord};
        vector<string> primarykeyspoints = {"x", "y"};
        
	DataBase cp; //coordinate plane. not actually important because these are just tests
        cp.createTable(name, attributespoints, primarykeyspoints);
	//REQUIRE(dataBaseHashTable.find(name) == dataBaseHashTable.end());
	//cp.createTable(name, attributespoints, primarykeyspoints);
	//GIVEN("A table name, a vector of attributes, and a vector of primary keys"){

	//}
}
*/
//int main()
//{

template <typename T, typename V>
bool typechecker(T t, V v){
	return (typeid(t).name()) == (typeid(v).name());
}

SCENARIO("rdbms online", "main"){
	GIVEN("some data to work with"){	
		pair<string, int> p1 {"name", 20};
        	pair<string, int> p2 {"kind", 8};
        	pair<string, int> p3 {"years", -1};
        	vector<pair<string, int>> attributes1 = {p1, p2, p3};
        	vector<string> primaryKeys1 = {"name", "kind"};
		
        	DataBase db;
        	db.createTable("animals", attributes1, primaryKeys1);
		WHEN("creating a database"){
			DataBase dc;
			//REQUIRE(!attributes1.empty());  //these two things can be commented out if needed,
			//REQUIRE(!primaryKeys1.empty()); //but ultimately a table doensn't necessarily require elements to exist
			dc.createTable("animalia", attributes1, primaryKeys1);
		}
		//}
       		// TEST_CASE("Values are inserted into animals"){
        	//Table animals("animals", attributes1, primaryKeys1);
        	vector<string> v1 = {"Joe", "cat", "4"};
        	vector<string> v2 = {"Spot", "dog", "10"};
        	vector<string> v3 = {"Snoopy", "dog", "3"};
        	vector<string> v4 = {"Tweety", "bird", "1"};
        	vector<string> v5 = {"Joe", "bird", "2"};
        	// animals.insertRecord(v1);
        	// animals.insertRecord(v2);
        	// animals.insertRecord(v3);
        	// animals.insertRecord(v4);
        	// animals.insertRecord(v5);
		
		WHEN("inserting into the database"){
			vector<string> testvec;
			REQUIRE(typechecker(v1,testvec));
			REQUIRE(typechecker(v2,testvec));
			REQUIRE(typechecker(v3,testvec));
			REQUIRE(typechecker(v4,testvec));
			REQUIRE(typechecker(v5,testvec));
			//dc.insertIntoTable("animalia", v1);
			db.insertIntoTable("animals", v1);
			db.insertIntoTable("animals", v2);	
			db.insertIntoTable("animals", v3);
			db.insertIntoTable("animals", v4);
			db.insertIntoTable("animals", v5);
		}
	        //db.insertIntoTable("animals", v1);
	        //db.insertIntoTable("animals", v2);
	        //db.insertIntoTable("animals", v3);
       		//db.insertIntoTable("animals", v4);
        	//db.insertIntoTable("animals", v5);
        	// }
        	cout << db.showTable("animals") << endl;
        	//cout << animals.show() << endl;

        	//Table animals = db.getTable("animals");
        	//Table dogs = animals.select("dogs", {"kind == dog"});
        	//cout << dogs.show() << endl
        	Table dogs = db.selectTable("animals", "dogs", {"kind == dog"});
		WHEN("selecting elements from a table"){
			Table cats = db.selectTable("animals","cats", {"type == cat"});
			Table birds = db.selectTable("animals", "birds", {"type == bird"});
		}
        	//Table dogs = db.getTable("animals").select("dogs", {"kind == dog"});
        	db.createTable(dogs);
        	cout << db.showTable("dogs") << endl;
        	// Table old_dogs = dogs.select("old_dogs", {"years>10"});
        	// cout << old_dogs.show() << endl;
	
        	// Table cats = animals.select("cats", {"kind==cat"});
        	// cout << cats.show() << endl;

       		// Table projection = animals.project("projection", {"name", "kind"});
        	// cout << projection.show() << endl;

        	// pair<string, int> p4 {"kind", 10};           
        	// Table species("species", {p4}, {"kind"});
        	// species.insertRecord(animals.project("temp", {"kind"}));
        	// cout << species.show() << endl;
	
        	// this isn't working right
        	// Table a = (animals.project("temp", {"name", "kind"})).rename("a", {"aname", "akind"});
        	// cout << a.show() << endl;
	} 
}

