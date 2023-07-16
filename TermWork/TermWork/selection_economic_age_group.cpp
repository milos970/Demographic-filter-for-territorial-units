#include "selection_economic_age_group.h"
#include "criterion_age_group_number.h"
#include "../../structures/heap_monitor.h"
#include "criterion_name.h"
#include "criterion_type.h"

void SelectionEconomicAgeGroup::options()
{
	this->types();
	this->makeTable();
	std::cout << "Zadajte ekonomickú vekovú skupinu:" << "\n";
	std::cout << "1.Predproduktívni" << "\n";
	std::cout << "2.Produktívni" << "\n";
	std::cout << "3.Poproduktívni" << "\n";
	std::cin >> this->economicAgeGroup_;

	
	
}

void SelectionEconomicAgeGroup::printResult()
{
	CriterionAgeGroupNumber criterionAgeGroupNumber(intToEconomicAgeGroup(this->economicAgeGroup_));
	CriterionName criterionName;
	CriterionType criterionType;
	std::cout << "*******************************************************************************" << "\n";
	std::cout << "\n";
	std::cout << "Názov: " << criterionName.evaluate(this->territorialUnit_) << "\n";
	std::cout << "Typ: " << territorialUnitTypeToString(criterionType.evaluate(this->territorialUnit_)) << "\n";
	std::cout << "Ekonomická veková skupina: " << criterionAgeGroupNumber.evaluate(this->territorialUnit_) << "\n";

	std::cout << "\n";

	const TerritorialUnit* tU = this->territorialUnit_->getSuperiorUnit();

	std::cout << "++++++++++++++++++++++++++" << "\n";
	std::cout << "Vyššie celky:" << "\n";

	for (int i = 0; tU != nullptr; ++i)
	{
		std::cout << "\n";
		std::cout << "Názov: " << tU->getName() << "\n";
		std::cout << "Typ: " << territorialUnitTypeToString(tU->getTerritorialUnitType()) << "\n";

		tU = tU->getSuperiorUnit();
		std::cout << "\n";
	}

	std::cout << "++++++++++++++++++++++++++" << "\n";
	std::cout << "\n";
	std::cout << "*******************************************************************************" << "\n";
}

