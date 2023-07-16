#pragma once
#include "criterion_territorial_unit.h"
#include "territorial_unit.h"
#include "gender.h"
#include <iostream>
#include "../../structures/heap_monitor.h"

	class CriterionAgeNumber : public CriterionTerritorialUnit<unsigned int>
	{
	private:
		unsigned int age_;
		Gender gender_;

	public:
		CriterionAgeNumber(unsigned int age, Gender gender) : age_(age), gender_(gender) {}

		unsigned int evaluate(TerritorialUnit* tU) override;
		
	};


