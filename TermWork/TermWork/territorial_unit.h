#pragma once
#include <string>
#include "territorial_unit_type.h"
#include "../../structures/array/array.h"
#include "../../structures/table/table.h"
#include "education.h"
#include "../../structures/heap_monitor.h"

class TerritorialUnit
{
protected:
	 std::string name_;
	 std::string code_;
	 unsigned int population_;
	structures::Array<unsigned int>* menAgeGroup_;
	structures::Array<unsigned int>* womenAgeGroup_;
	structures::Table<Education, unsigned int>* educationNumbers_;
	TerritorialUnit* territorialUnit_;

public:
	TerritorialUnit(std::string name, std::string code, unsigned int population,
		structures::Array<unsigned int>* menAgeGroup, structures::Array<unsigned int>* womenAgeGroup, structures::Table<Education, unsigned int>* educationNumbers)
		: name_(name), code_(code), population_(population), menAgeGroup_(menAgeGroup), womenAgeGroup_(womenAgeGroup), educationNumbers_(educationNumbers) {};

	
	virtual ~TerritorialUnit() = default;

	

	void setSuperiorUnit(TerritorialUnit* territorialUnit)
	{
		this->territorialUnit_ = territorialUnit;
	}

	const TerritorialUnit* getSuperiorUnit() const
	{
		return this->territorialUnit_;
	}

	 const std::string getName() const
	{
		return this->name_;
	}

	 const std::string getCode() const
	{
		return this->code_;
	}

	 const unsigned int getPopulation() const
	{
		return this->population_;
	}


	 unsigned int getMenAgeGroup(const unsigned int& age) 
	{
		return this->menAgeGroup_->at(age);
	}

	 unsigned int getWomenAgeGroup(const unsigned int& age) 
	{
		return this->womenAgeGroup_->at(age);
	}

	 unsigned int getEducationNumbers(const Education& education) 
	{
		return this->educationNumbers_->find(education);
	}

	virtual const TerritorialUnitType getTerritorialUnitType() const = 0;
	


};

