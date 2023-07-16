#pragma once
#include "selection_economic_age_group.h"
#include "../../structures/heap_monitor.h"

class SelectionMinEconomicAgeGroup : public SelectionEconomicAgeGroup
{
public:
	SelectionMinEconomicAgeGroup(Country* country)
		: SelectionEconomicAgeGroup(country) 
	{
		this->tableToFilter_ = new structures::UnsortedSequenceTable<std::string, TerritorialUnit*>();
	};

	~SelectionMinEconomicAgeGroup()
	{
		delete this->tableToFilter_;
	}

	void algorithm() override;
	
};

