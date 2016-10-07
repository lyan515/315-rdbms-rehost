#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stack>
#include <cctype>
#include <iostream>
#include <sstream>

#include "Container.h"

using namespace std;


class Table
{
	private:
		string name;
		// key -> entry
		unordered_map<size_t, vector<Container>> data;
		// n = VARCHAR, -1 = INTEGER
		vector<pair<string, int>> attributes;
		// stores the table's primary keys
		vector<string> primaryKeys;
		// used to easily access the table's primary keys
		vector<int> primaryKeyIndices;

		// private functions
		bool evaluate(vector<Container>& entry, vector<string> boolExpressions);
		int evaluateHelper (vector<Container>& entry, string boolExpression);
		
	public:
		// constructors
		Table() {}
		Table(string _name, vector<pair<string, int>> _attributes, vector<string> _primaryKeys);
		Table(const Table& other);
		~Table();
		// data manipulation functions
		Table* select(string _name, vector<string> boolExpressions);
		Table* project(string _name, vector<string> desiredAttributes);
		Table* rename(string _name, vector<string> newNames);
		string show();
		string getTableName();
		void setTableName (string tableName) { name = tableName; }
		vector<pair<string, int>> getAttributes();
		vector<string> getPrimaryKeys();
		const unordered_map<size_t, vector<Container>>& getData();
		void insertRecord(vector<string> entry);
		void insertRecord(Table *relationship);
		void insertRecord(vector<Container> entry);
		void deleteRecord(vector<string> boolExpressions);
		void deleteRecord(size_t key);
		void updateRecord(vector<string> desiredAttributes, vector<string> values, vector<string> boolExpressions);
		void writeToDisk();
		Table& operator=(const Table& other);
		inline bool operator==(const Table& rhs) const
		{
			if(!(this->attributes == rhs.attributes))
				return false;
			if(!(this->primaryKeys == rhs.primaryKeys))
				return false;
			if(!(this->data == rhs.data))
				return false;
			return true;
		}
		inline vector<pair<string, int>> operator=(const vector<pair<string, int>> &vec);
};
