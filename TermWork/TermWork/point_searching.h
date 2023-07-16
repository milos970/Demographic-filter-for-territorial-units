#pragma once
#include "country.h"

class PointSearching
{
private:
	Country country_;
	TerritorialUnit* territorialUnit_;

	void printToConsole();

public:
	PointSearching(const Country& country) : country_(country) {};

	void search(const std::string& name);

	
};

