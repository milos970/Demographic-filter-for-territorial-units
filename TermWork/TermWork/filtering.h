#pragma once
#include "functionality.h"
#include "criterion_education_number.h"
#include "criterion_education_fraction.h"
#include "criterion_age_number.h"
#include "criterion_age_fraction.h"
#include "criterion_age_group_number.h"
#include "criterion_age_group_fraction.h"
#include "../../structures/heap_monitor.h"

class Filtering : public Functionality
{
private:
	structures::ArrayList<unsigned int>* arrayList_; 
	CriterionEducationNumber* criterionEducationNumber_;
	CriterionEducationFraction* criterionEducationFraction_;
	CriterionAgeNumber* criterionAgeNumber_;
	CriterionAgeFraction* criterionAgeFraction_;
	CriterionAgeGroupNumber* criterionAgeGroupNumber_;
	CriterionAgeGroupFraction* criterionAgeGroupFraction_;
	
public:
	Filtering(Country* country)
		: Functionality(country) 
	{
		this->filterAnd_ = new Filter_AND<TerritorialUnit*>();
		this->tableToFilter_ = new structures::UnsortedSequenceTable<std::string, TerritorialUnit*>();
		this->filteredTable_ = new structures::UnsortedSequenceTable<std::string, TerritorialUnit*>();
		this->arrayList_ = new structures::ArrayList<unsigned int>();
	};

	~Filtering() 
	{
		delete this->arrayList_;
		delete this->filterAnd_;
		delete this->tableToFilter_;
		delete this->filteredTable_;

		this->filterAnd_ = nullptr;
		this->tableToFilter_ = nullptr;
		this->filteredTable_ = nullptr;
		this->arrayList_ = nullptr;
		this->deleteCriterions();

	}
private:
	void deleteCriterions() 
	{
		if (criterionEducationNumber_ != nullptr)
		{
			delete this->criterionEducationNumber_;
			this->criterionEducationNumber_ = nullptr;
		}

		if (criterionEducationFraction_ != nullptr)
		{
			delete this->criterionEducationFraction_;
			this->criterionEducationFraction_ = nullptr;
		}

		if (criterionAgeNumber_ != nullptr)
		{
			delete this->criterionAgeNumber_;
			this->criterionAgeNumber_ = nullptr;
		}

		if (criterionAgeFraction_ != nullptr)
		{
			delete this->criterionAgeFraction_;
			this->criterionAgeFraction_ = nullptr;
		}

		if (criterionAgeGroupNumber_ != nullptr)
		{
			delete this->criterionAgeGroupNumber_;
			this->criterionAgeGroupNumber_ = nullptr;
		}

		if (criterionAgeGroupFraction_ != nullptr)
		{
			delete this->criterionAgeGroupFraction_;
			this->criterionAgeGroupFraction_ = nullptr;
		}
	}
public:
	void options() override;
	void algorithm() override;
	void printResult() override;
	
};

