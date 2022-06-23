#pragma once
#include "Repo.h"

class service {
	repo& repo1;
public:
	service(repo& rep) : repo1(rep){}

	vector<task>& get_list()
	{
		return repo1.get_list();
	}

	void update()
	{
		repo1.Soerteaza();
	}

	string add(int id, string descriere, string programatori, string stare)
	{
		vector<task> v = repo1.get_list();
		for (auto& x : v)
			if (x.id == id)
				return "ID-ul exista deja";

		if (descriere == "")
			return "Descrierea nu poate fi vida";

		if (stare != "closed" && stare != "open" && stare != "inprogress")
			return "Stare incorecta!!!!";

		return repo1.add(id, descriere, programatori, stare);
	}
};