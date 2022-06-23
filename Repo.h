#pragma once
#include <fstream>
#include "Task.h"

class repo {
	string nume_fisier;
	vector<task> taskuri;
public:
	repo(string name)
	{
		nume_fisier = name;
		ifstream f(nume_fisier);

		string id, descriere, programatori, stare;
		while (f >> id >> descriere >> programatori >> stare)
		{
			task t(stoi(id), descriere, stare);
			
			int poz = 0;
			for (int i = 0; i < programatori.length(); i++)
			{
				if (programatori[i] == ',')
				{
					string p = programatori.substr(poz, i-poz+1);
					t.add(p);
					poz = i+1;
				}
			}
			string p = programatori.substr(poz,programatori.length() - poz);
			t.add(p);

			taskuri.push_back(t);
		}


		Soerteaza();
	}

	void Soerteaza()
	{
		bool ok = true;
		while (ok)
		{
			ok = false;
			for(int i=0;i<taskuri.size()-1;i++)
				if (taskuri[i].stare > taskuri[i + 1].stare)
				{
					ok = true;
					swap(taskuri[i], taskuri[i + 1]);
				}
		}
	}

	vector<task>& get_list()
	{
		return taskuri;
	}

	string add(int id, string descriere, string programatori, string stare)
	{
		task t(id, descriere, stare);

		int poz = 0,nr = 1;
		for (int i = 0; i < programatori.length(); i++)
		{
			if (programatori[i] == ',')
			{
				string p = programatori.substr(poz, i - poz + 1);
				t.add(p);
				poz = i + 1;
				nr++;
			}
		}
		string p = programatori.substr(poz, programatori.length() - poz);
		t.add(p);

		if (nr > 4)
			return "Prea multi programatori!!!";

		taskuri.push_back(t);
		return "";
	}
};