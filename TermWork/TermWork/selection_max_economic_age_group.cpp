#include "selection_max_economic_age_group.h"
#include "selection_max_age_group.h"
#include "../../structures/heap_monitor.h"

void SelectionMaxEconomicAgeGroup::algorithm()
{
	SelectionMaxAgeGroup<std::string> selectBestAgeGroup(intToEconomicAgeGroup(this->economicAgeGroup_));
	this->territorialUnit_ = selectBestAgeGroup.selectBest(this->tableToFilter_);
}

