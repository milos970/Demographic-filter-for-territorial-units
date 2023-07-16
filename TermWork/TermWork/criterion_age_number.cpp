#include "criterion_age_number.h"
#include "../../structures/heap_monitor.h"

unsigned int CriterionAgeNumber::evaluate(TerritorialUnit* tU)
{
	return this->gender_ == Gender::Female ? tU->getWomenAgeGroup(this->age_) : tU->getMenAgeGroup(this->age_);
}
