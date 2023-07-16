#include "sort_by_age_group_number.h"
#include "criterion_age_group_number.h"
#include "filter_age_group_number.h"
#include "criterion_name.h"
#include "../../structures/heap_monitor.h"
void SortingByAgeGroupNumber::options()
{
	
		this->types();
	this->makeTable();

	
			system("CLS");
			std::cout << "Vyberte ekonomick� vekov� skupinu:" << "\n";
			std::cout << "1.Predprodukt�vni." << "\n";
			std::cout << "2.Produkt�vni." << "\n";
			std::cout << "3.Poprodukt�vni." << "\n";
			std::cout << "Vyber: ";

			std::cin >> this->economicAgeGroup_;
	
			std::cout << "\n";

	std::cout << "Zvo�te interval:" << "\n";
	std::cout << "Minimum: ";
	unsigned int min = 0;
	std::cin >> min;
	std::cout << "\n";
	std::cout << "Maximum: ";
	unsigned int max = 0;
	std::cin >> max;
	std::cout << "\n";
	this->filterAnd_->registerFilter(new FilterAgeGroupNumber(intToEconomicAgeGroup(this->economicAgeGroup_), min, max));
	this->filterTable();

	std::cout << "\n";
		std::cout << "Zoradi�:" << "\n";
		std::cout << "1.Vzostupne" << "\n";
		std::cout << "2.Zostupne" << "\n";
		std::cout << "Vyber: ";
		std::cin >> this->ascending_;
		system("CLS");
	
}

void SortingByAgeGroupNumber::algorithm()
{
	CriterionAgeGroupNumber criterionAgeGroupNumber(intToEconomicAgeGroup(this->economicAgeGroup_));

	structures::QuickSort<std::string, TerritorialUnit*, unsigned int> quickSort;
	quickSort.sort(*this->filteredTable_, &criterionAgeGroupNumber, this->ascending_);
}

void SortingByAgeGroupNumber::printResult()
{
	CriterionName criterionName;
	for (int i = 0; i < this->filteredTable_->size(); ++i)
	{
		std::cout << "*******************************************************************************" << "\n";

		CriterionAgeGroupNumber criterionAgeGroupNumber1(EconomicAgeGroup::Preproductive);
		CriterionAgeGroupNumber criterionAgeGroupNumber2(EconomicAgeGroup::Productive);
		CriterionAgeGroupNumber criterionAgeGroupNumber3(EconomicAgeGroup::Postproductive);
		TerritorialUnit* territorialUnit = this->filteredTable_->getItemAtIndex(i).accessData();
		std::cout << "N�zov: " << criterionName.evaluate(territorialUnit) << "\n";
		std::cout << "Ekonomick� vekov� skupina:" << "\n";
		std::cout << "Predprodukt�vny: " << criterionAgeGroupNumber1.evaluate(territorialUnit) << "\n";
		std::cout << "Produkt�vni: " << criterionAgeGroupNumber2.evaluate(territorialUnit) << "\n";
		std::cout << "Poprodukt�vni: " << criterionAgeGroupNumber3.evaluate(territorialUnit) << "\n";
		std::cout << "*******************************************************************************" << "\n";

		std::cout << "\n";
	}
}

