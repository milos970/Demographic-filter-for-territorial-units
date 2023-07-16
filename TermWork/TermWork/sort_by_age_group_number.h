#pragma once
#include "quick_sort.h"
#include "sorting.h"
#include "../../structures/heap_monitor.h"
class SortingByAgeGroupNumber : public Sorting
{
public:
	SortingByAgeGroupNumber(Country* country)
		: Sorting(country) 

	{
		this->tableToFilter_ = new structures::UnsortedSequenceTable<std::string, TerritorialUnit*>();
		this->filteredTable_ = new structures::UnsortedSequenceTable<std::string, TerritorialUnit*>();
		this->filterAnd_ = new Filter_AND<TerritorialUnit*>();
	};

	~SortingByAgeGroupNumber()
	{
		delete this->tableToFilter_;
		delete this->filterAnd_;
		delete this->filteredTable_;
	}

	void options() override;
	void algorithm() override;
	void printResult() override;
	

};