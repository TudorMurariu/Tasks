#pragma once
#include "Task.h"
#include <fstream>

class repo {
	string nume_fisier;
	vector<task> taskuri;
public:
	repo(string name)
	{
		nume_fisier = name;
		ifstream f(nume_fisier);


	}


};