#include "criterion_age_group_number.h"
#include "../../structures/heap_monitor.h"

unsigned int CriterionAgeGroupNumber::evaluate(TerritorialUnit* tU)
{
	unsigned int numberOfPeople = 0;

	switch (economicAgeGroup_)
	{
	case EconomicAgeGroup::Preproductive:
		for (int i = 0; i <= 14; ++i) 
		{
			numberOfPeople += (tU->getWomenAgeGroup(i) + tU->getMenAgeGroup(i));
		}
		break;
	case EconomicAgeGroup::Productive:
		for (int i = 15; i <= 64; ++i)
		{
			numberOfPeople += (tU->getWomenAgeGroup(i) + tU->getMenAgeGroup(i));
		}
		break;
	case EconomicAgeGroup::Postproductive:
		for (int i = 65; i <= 100; ++i)
		{
			numberOfPeople += (tU->getWomenAgeGroup(i) + tU->getMenAgeGroup(i));
		}
		break;
	}
	
	return numberOfPeople;
}
