#pragma once
#include "territorial_unit.h"
#include "criterion_age_group_number.h"
#include "selection_criterion_min.h"
#include "../../structures/heap_monitor.h"

template <typename K>
class SelectionMinAgeGroup : public SelectionCriterionMin<K, TerritorialUnit*, unsigned int>
{
public:
	SelectionMinAgeGroup(EconomicAgeGroup evs) : SelectionCriterionMin<K, TerritorialUnit*, unsigned int>(new CriterionAgeGroupNumber(evs)) {};

};