#pragma once
#include "territorial_unit.h"
#include "../../structures/table/table.h"
#include "../../structures/array/array.h"
#include "territorial_unit_type.h"
#include "../../structures/heap_monitor.h"

class Municipality : public TerritorialUnit
{	
public:
	Municipality(std::string name, std::string code, unsigned int population, structures::Array<unsigned int>* menAgeGroup, structures::Array<unsigned int>* womenAgeGroup, structures::Table<Education, unsigned int>* educationNumbers)
		: TerritorialUnit(name, code, population, menAgeGroup, womenAgeGroup, educationNumbers) {};

	
	~Municipality() 
	{
		delete educationNumbers_;
		educationNumbers_ = nullptr;
		territorialUnit_ = nullptr;
		
	
		delete this->menAgeGroup_;
		delete this->womenAgeGroup_;
	}
	const TerritorialUnitType getTerritorialUnitType() const
	{
		return TerritorialUnitType::Municipality;
	}


};

