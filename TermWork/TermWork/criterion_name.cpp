#include "criterion_name.h"
#include "../../structures/heap_monitor.h"

std::string CriterionName::evaluate(TerritorialUnit* tU)
{
    return tU->getName();
}
