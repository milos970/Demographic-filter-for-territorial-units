#pragma once
#include "../../structures/heap_monitor.h"
#include "../../structures/list/array_list.h"
#include "../../structures/table/unsorted_sequence_table.h"
#include "territorial_unit.h"
#include "country.h"
#include "filter_and.h"

class Functionality
{
protected:
	structures::UnsortedSequenceTable<std::string, TerritorialUnit*>* tableToFilter_;
	structures::UnsortedSequenceTable<std::string, TerritorialUnit*>* filteredTable_;
	Filter_AND<TerritorialUnit*>* filterAnd_;

	unsigned int age_;
	unsigned int type_;
	unsigned int belongTo_;
	unsigned int education_;
	unsigned int economicAgeGroup_;
	unsigned int gender_;
	Country* country_;
	
	TerritorialUnit* territorialUnit_;
	std::string name_;
public:
	Functionality(Country* country) 
		: country_(country) {};

	virtual ~Functionality() 
	{
		this->tableToFilter_ = nullptr;
		this->filteredTable_ = nullptr;
		this->filterAnd_ = nullptr;
		this->territorialUnit_ = nullptr;
		this->country_ = nullptr;
	}
	
	void types();
	void makeTable();
	void filterTable();

	
	virtual void options() = 0;
	virtual void algorithm() = 0; 
	virtual void printResult() = 0;

	
	
};


