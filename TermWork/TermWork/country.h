#pragma once
#include "territorial_unit.h"
#include "../../structures/table/sorted_sequence_table.h"
#include "../../structures/table/unsorted_sequence_table.h"
#include "../../structures/list/linked_list.h"
#include "territorial_unit_type.h"
#include "region.h"
#include <iostream>
#include "../../structures/heap_monitor.h"

class Country : public TerritorialUnit
{
	  structures::SortedSequenceTable<std::string, Region*>* regionsSortedTable_;

	  structures::SortedSequenceTable<std::string, District*>* districtsSortedTable_;

	  structures::UnsortedSequenceTable<std::string, Municipality*>* municipalitiesUnsortedTable_;

public:
	Country(std::string name, std::string code, unsigned int population, structures::Array<unsigned int>* menAgeGroup,
		structures::Array<unsigned int>* womenAgeGroup, structures::Table<Education, unsigned int>* educationNumbers,
		structures::SortedSequenceTable<std::string, Region*>* regionsSortedTable, 
		
		structures::SortedSequenceTable<std::string, District*>* districtsSortedTable, 
		
		structures::UnsortedSequenceTable<std::string, Municipality*>* municipalitiesUnsortedTable)
	: TerritorialUnit(name, code, population, menAgeGroup, womenAgeGroup, educationNumbers), 
		regionsSortedTable_(regionsSortedTable), 
		
		districtsSortedTable_(districtsSortedTable), 
		
		municipalitiesUnsortedTable_(municipalitiesUnsortedTable) {};

	~Country() 
	{
		delete educationNumbers_;
		educationNumbers_ = nullptr;
		territorialUnit_ = nullptr;
		delete this->menAgeGroup_;
		delete this->womenAgeGroup_;
		
		for (auto item : *municipalitiesUnsortedTable_)
		{
			delete item->accessData();
		}
		delete municipalitiesUnsortedTable_;

		


		for (const auto item : *districtsSortedTable_)
		{
			delete item->accessData();
		}

		delete districtsSortedTable_;

		for (auto item : *regionsSortedTable_)
		{
			delete item->accessData();
		}

		delete regionsSortedTable_;
		


		this->regionsSortedTable_ = nullptr;
		this->districtsSortedTable_ = nullptr;
		this->municipalitiesUnsortedTable_ = nullptr;
		

	}

	const TerritorialUnitType getTerritorialUnitType() const
	{
		return TerritorialUnitType::Country;
	}


	 District* getDistrict(const std::string& name) 
	{
		District* founded = nullptr;
		this->districtsSortedTable_->tryFind(name, founded);
		return founded;
	}

	 Region* getRegion(const std::string& name) 
	{
		Region* founded = nullptr;
		this->regionsSortedTable_->tryFind(name, founded);
		return founded;
	}


	

	 structures::SortedSequenceTable<std::string, District*>* getSortedDistricts() 
	{
		return this->districtsSortedTable_;
	}

	 structures::SortedSequenceTable<std::string, Region*>* getSortedRegions() 
	{
		return this->regionsSortedTable_;
	}

	

	 structures::UnsortedSequenceTable<std::string, Municipality*>* getUnsortedMunicipalities() 
	{
		return this->municipalitiesUnsortedTable_;
	}
	
};

