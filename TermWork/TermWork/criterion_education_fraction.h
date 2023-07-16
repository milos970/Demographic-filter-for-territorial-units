#pragma once
#include "criterion_territorial_unit.h"
#include "criterion_education_number.h"
#include "../../structures/heap_monitor.h"
class CriterionEducationFraction : public CriterionTerritorialUnit<double>
{
private:
	CriterionEducationNumber* criterionEducationNumber_;
	
public:
	CriterionEducationFraction(Education education)
		: criterionEducationNumber_(new CriterionEducationNumber(education)){};

	~CriterionEducationFraction();

	double evaluate(TerritorialUnit* tU) override;


};
