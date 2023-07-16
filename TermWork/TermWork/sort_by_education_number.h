#pragma once
#include "sorting.h"
#include "../../structures/heap_monitor.h"
class SortingByEducationNumber : public Sorting
{
public:
	SortingByEducationNumber(Country* country)
		: Sorting(country) 

	{
		this->tableToFilter_ = new structures::UnsortedSequenceTable<std::string, TerritorialUnit*>();
		this->filteredTable_ = new structures::UnsortedSequenceTable<std::string, TerritorialUnit*>();
		this->filterAnd_ = new Filter_AND<TerritorialUnit*>();
	};

	~SortingByEducationNumber()
	{
		delete this->tableToFilter_;
		delete this->filterAnd_;
		delete this->filteredTable_;
	}

	void options() override;
	void algorithm() override;
	void printResult() override;
	
};




