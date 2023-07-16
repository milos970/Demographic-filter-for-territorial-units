#pragma once
#include "criterion_territorial_unit.h"
#include <iostream>
#include "../../structures/heap_monitor.h"

class CriterionEducationNumber : public CriterionTerritorialUnit< unsigned int>
{
private:
	Education education_;
public:
	CriterionEducationNumber(Education education) : education_(education) {};


	unsigned int evaluate(TerritorialUnit* tU) override;
	

};
