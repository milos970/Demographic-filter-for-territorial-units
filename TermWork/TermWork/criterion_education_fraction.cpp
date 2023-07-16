#include "criterion_education_fraction.h"
#include "../../structures/heap_monitor.h"

CriterionEducationFraction::~CriterionEducationFraction()
{
	delete this->criterionEducationNumber_;
}

double CriterionEducationFraction::evaluate(TerritorialUnit* tU)
{
	return 100 * (this->criterionEducationNumber_->evaluate(tU) / static_cast<double>(tU->getPopulation()));
}
