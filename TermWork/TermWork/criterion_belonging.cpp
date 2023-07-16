#include "criterion_belonging.h"
#include "../../structures/heap_monitor.h"

CriterionBelonging::~CriterionBelonging()
{
	this->tU_ = nullptr;
}

bool CriterionBelonging::evaluate(TerritorialUnit* tU)
{
	return tU->getSuperiorUnit() == this->tU_;
}
