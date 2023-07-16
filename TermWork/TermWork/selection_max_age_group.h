#pragma once
#include "territorial_unit.h"
#include "criterion_age_group_number.h"
#include "selection_criterion_max.h"
#include "../../structures/heap_monitor.h"

template <typename K>
class SelectionMaxAgeGroup : public SelectionCriterionMax<K, TerritorialUnit*, unsigned int> 
{
public:
	SelectionMaxAgeGroup(EconomicAgeGroup evs) : SelectionCriterionMax<K, TerritorialUnit*, unsigned int>(new CriterionAgeGroupNumber(evs)) {};

};