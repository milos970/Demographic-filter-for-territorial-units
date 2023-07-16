#include "selection_min_economic_age_group.h"
#include "selection_min_age_group.h"
#include "../../structures/heap_monitor.h"

void SelectionMinEconomicAgeGroup::algorithm()
{
	SelectionMinAgeGroup<std::string> selectWorstAgeGroup(intToEconomicAgeGroup(this->economicAgeGroup_));
	this->territorialUnit_ = selectWorstAgeGroup.selectBest(this->tableToFilter_);
}



