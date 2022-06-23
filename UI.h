#pragma once
#include "Service.h"


class GUI {
	service& srv;
public:
	GUI(service& srv1) : srv(srv1)
	{
		buid_UI();
		connect_signals();
	}

	void buid_UI();
	void connect_signals();
};