#pragma once

#include <unordered_map>
#include <string>
#include <vector>

#include "Container.h"

using namespace std;

class Table
{
	string name;
	unordered_map<size_t, vector<Container>> data;
	// 0 = VARCHAR, 1 = INTEGER
	vector<pair<string, int> > attributes;
	vector<string> primaryKeys;
	vector<int> primaryKeyIndices;

	// private functions
	bool evaluate(vector<Container> entry, vector<string> boolExpressions);
	void insertRecord(vector<Container> entry);
	
public:
	// constructors
	Table() {}
	Table(string _name, vector<pair<string, int>> _attributes, vector<string> _primaryKeys);
	// data manipulation functions
	Table select(string _name, vector<string> boolExpressions);
	Table project(string _name, vector<string> desiredAttributes);
	Table rename(string _name, vector<string> newNames);
	string show();
	void insertRecord(vector<string> entry);
	void insertRecord(Table relationship);
	void deleteRecord(vector<string> boolExpressions);
	void updateRecord(vector<string> attributes, vector<string> values, vector<string> boolExpressions);
	void writeToDisk();
};