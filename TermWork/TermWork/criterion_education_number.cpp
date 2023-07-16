#include "criterion_education_number.h"
#include "../../structures/heap_monitor.h"

unsigned int CriterionEducationNumber::evaluate(TerritorialUnit* tU)
{
	return tU->getEducationNumbers(this->education_);
}
