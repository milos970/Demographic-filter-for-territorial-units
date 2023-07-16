#include "criterion_age_group_fraction.h"
#include "../../structures/heap_monitor.h"

CriterionAgeGroupFraction::~CriterionAgeGroupFraction()
{
	delete this->criterionAgeGroupNumber_;
}

double CriterionAgeGroupFraction::evaluate(TerritorialUnit* tU)
{   
	return 100 * (this->criterionAgeGroupNumber_->evaluate(tU) / static_cast<double>(tU->getPopulation()));
}
