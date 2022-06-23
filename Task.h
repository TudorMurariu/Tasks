#pragma once
#include <string>
#include <vector>
using namespace std;

class task {

public:
	int id;
	string descriere;
	vector<string> programatori;
	string stare;

	task(int id1,string descriere1,string stare1)
	{
		id = id1;
		descriere = descriere1;
		stare = stare1;
	}

	void add(string programator)
	{
		programatori.push_back(programator);
	}
};