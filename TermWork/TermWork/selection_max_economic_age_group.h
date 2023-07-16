#pragma once
#include "selection_economic_age_group.h"
#include "../../structures/heap_monitor.h"

class SelectionMaxEconomicAgeGroup : public SelectionEconomicAgeGroup
{
public:
	SelectionMaxEconomicAgeGroup(Country* country) 
		: SelectionEconomicAgeGroup( country) 
	{
		this->tableToFilter_ = new structures::UnsortedSequenceTable<std::string, TerritorialUnit*>();
	};

	~SelectionMaxEconomicAgeGroup() 
	{
		delete this->tableToFilter_;
	}

	void algorithm() override;
	
	
};

