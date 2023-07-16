#pragma once
#include "sorting.h"
#include "../../structures/heap_monitor.h"
class SortingByName : public Sorting
{

public:
	SortingByName(Country* country)
		: Sorting(country) 
	{
		this->tableToFilter_ = new structures::UnsortedSequenceTable<std::string, TerritorialUnit*>();
	};

	~SortingByName()
	{
		delete this->tableToFilter_;
	}

	void options() override;
	void printResult() override;
	void algorithm() override;
	

};



 