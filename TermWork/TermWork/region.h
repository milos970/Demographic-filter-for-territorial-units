#pragma once
#include "territorial_unit.h"
#include "../../structures/table/table.h"
#include "territorial_unit_type.h"
#include "municipality.h"
#include "district.h"
#include "../../structures/heap_monitor.h"

class Region : public TerritorialUnit
{	
private:
	 structures::SortedSequenceTable<std::string, District*>* districtsSortedTable_;
public:
	Region(std::string name, std::string code, unsigned int population, structures::Array<unsigned int>* menAgeGroup, structures::Array<unsigned int>* womenAgeGroup, structures::Table<Education, unsigned int>* educationNumbers, structures::SortedSequenceTable<std::string, District*>* districtsSortedTable)
		: TerritorialUnit(name, code, population, menAgeGroup, womenAgeGroup, educationNumbers), districtsSortedTable_(districtsSortedTable) {};

	~Region() 
	{
		
		delete districtsSortedTable_;
		districtsSortedTable_ = nullptr;
		delete educationNumbers_;
		educationNumbers_ = nullptr;
		territorialUnit_ = nullptr;
		delete this->menAgeGroup_;
		delete this->womenAgeGroup_;

	}

	

	const TerritorialUnitType getTerritorialUnitType() const
	{
		return TerritorialUnitType::Region;
	}

	 structures::SortedSequenceTable<std::string, District*>* getSortedDistricts() 
	{
		return this->districtsSortedTable_;
	}

	


};