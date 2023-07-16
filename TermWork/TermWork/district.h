#pragma once
#include "territorial_unit.h"
#include "../../structures/table/table.h"
#include "territorial_unit_type.h"
#include "municipality.h"
#include <iostream>
#include "../../structures/heap_monitor.h"
class District : public TerritorialUnit
{
private:
	 structures::SortedSequenceTable<std::string, Municipality*>* municipalitiesSortedTable_;
public:
	District(std::string name, std::string code, unsigned int population, structures::Array<unsigned int>* menAgeGroup, structures::Array<unsigned int>* womenAgeGroup, structures::Table<Education, unsigned int>* educationNumbers, structures::SortedSequenceTable<std::string, Municipality*>* municipalitiesSortedTable)
		: TerritorialUnit(name, code, population, menAgeGroup, womenAgeGroup, educationNumbers), municipalitiesSortedTable_(municipalitiesSortedTable) {};

	
	~District() 
	{
		delete municipalitiesSortedTable_;
		municipalitiesSortedTable_ = nullptr;

		delete educationNumbers_;
		educationNumbers_ = nullptr;
		territorialUnit_ = nullptr;
		
		delete this->menAgeGroup_;
		delete this->womenAgeGroup_;
	}

	const TerritorialUnitType getTerritorialUnitType() const
	{
		return TerritorialUnitType::District;
	}

	

	 structures::SortedSequenceTable<std::string, Municipality*>* getSortedMunicipalities() 
	{
		return this->municipalitiesSortedTable_;
	}
};
