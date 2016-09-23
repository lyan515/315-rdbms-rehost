#include <iostream>

#include "Table.h"

using namespace std;

varchar::varchar(int _limit)
	: limit (_limit) {}

void varchar::setString(string s) {
	if (s.length() > limit)
		throw "Varchar exceeded maximum size";
	else
		data = s;
}

bool Table::evaluate(tuple<> entry, vector<string> boolExpressions)
{

}

void Table::insertRecord(tuple<> entry)
{
	string hashString = "";
	for (int i = 0; i < primaryKeyIndices.size(); ++i)
	{
		hashString += attributes[primaryKeyIndices[i]].first;
	}
	hash<string> str_hash;
	size_t hash = str_hash(hashString);

	unordered_map<size_t, tuple<> >::const_iterator checkEntryUniq = data.find(hash);	
	if(checkEntryUniq != data.end())
	{
		data[hash] = entry;
	}
	else
		throw "Entry already exists.";
}

Table::Table(string _name, vector<pair<string, int>> _attributes, vector<string> _primaryKeys)
{
	name = _name;
	attributes = _attributes;
	primaryKeys = _primaryKeys;
	for (int i = 0; i < primaryKeys.size(); ++i)
	{
		for (int j = 0; j < attributes.size(); ++j)
		{
			if (primaryKeys[i] == attributes[i].first)
			{
				primaryKeyIndices.push_back(j);
			}
		}
	}
}

Table Table::select(string _name, vector<string> boolExpressions)
{
	Table view(_name, attributes, primaryKeys);
	for (auto it = data.begin(); it != data.end(); ++it)
	{
		if (evaluate(it->second, boolExpressions))
		{
			view.insertRecord(it->second);
		}
	}
	return view;
}

Table Table::project(string _name, vector<string> desiredAttributes)
{
	// how should this handle projections that don't include the primary key(s)?
}

// written assuming attributes and newNames have same size
Table Table::rename(string _name, vector<string> newNames)
{
	vector<pair<string, int>> newAttributes = attributes;
	vector<string> newPrimaryKeys = primaryKeys;
	for (int i = 0; i < newAttributes.size(); ++i)
	{
		for (int j = 0; j < newPrimaryKeys.size(); ++j)
		{
			if (newAttributes[i].first == newPrimaryKeys[j])
			{
				newPrimaryKeys[j] == newNames[i];
			}
		}
		newAttributes[i].first = newNames[i];
	}
	Table view(_name, newAttributes, newPrimaryKeys);
	return view;
}

template<int i>
string get_elem_string(tuple<> t)
{
    return get<i>(t);
}

template<int i>
string get_elem_int(tuple<> t)
{
    return get<i>(t);
}

string Table::show()
{
	// string s = "";
	// for (int i = 0; i < attributes.size(); ++i)
	// {
	// 	s += attributes[i].first + "\t";
	// }
	// s += "\n";
	// for (auto it = data.begin(); it != data.end(); ++it)
	// {
	// 	for (int i = 0; i < tuple_size<decltype(it->second)>::value; ++i)
	// 	{
	// 		if (attributes[i].second == 0)
	// 		{
	// 			s += get_elem_string<i>(it->second) + "\t";
	// 		}
	// 		else
	// 		{
	// 			s += get_elem_int<i>(it->second) + "\t";
	// 		}
			
	// 	}
	// 	s += "\n";
	// }
	// return s;
}

void Table::insertRecord(vector<string> entry)
{

}

void Table::insertRecord(Table relationship)
{

}

void Table::deleteRecord(vector<string> boolExpressions)
{

}

void Table::updateRecord(vector<string> attributes, vector<string> values, vector<string> boolExpressions)
{

}

void Table::writeToDisk()
{

}