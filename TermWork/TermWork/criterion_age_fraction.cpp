#include "criterion_age_fraction.h"
#include "../../structures/heap_monitor.h"

CriterionAgeFraction::~CriterionAgeFraction()
{
	delete this->criterionAgeNumber_;
}

double CriterionAgeFraction::evaluate(TerritorialUnit* tU)
{
	return 100 * (this->criterionAgeNumber_->evaluate(tU) / static_cast<double>(tU->getPopulation()));
}
