#include "criterion_superior.h"
#include "../../structures/heap_monitor.h"

const TerritorialUnit* CriterionSuperior::evaluate(TerritorialUnit* tU)
{
	return tU->getSuperiorUnit();
}
