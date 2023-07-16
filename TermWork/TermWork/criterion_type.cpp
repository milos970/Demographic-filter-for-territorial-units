#include "criterion_type.h"
#include "../../structures/heap_monitor.h"

TerritorialUnitType CriterionType::evaluate(TerritorialUnit* objectType)
{
	return objectType->getTerritorialUnitType();
}
