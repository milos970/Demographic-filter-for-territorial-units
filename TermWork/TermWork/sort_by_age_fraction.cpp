#include "sort_by_age_fraction.h"
#include "criterion_age_fraction.h"
#include "filter_age_fraction.h"
#include "criterion_name.h"
#include "../../structures/heap_monitor.h"
void SortingByAgeFration::options()
{
	
		this->types();
	this->makeTable();

	
		system("CLS");
		std::cout << "Zadajte vek: ";
		std::cin >> this->age_;
	

	
		std::cout << "\n";
		std::cout << "Vyberte pohlavie:" << "\n";
		std::cout << "1.Muž." << "\n";
		std::cout << "2.Žena." << "\n";
		std::cout << "Vyber: ";
		std::cin >> this->gender_;
		std::cout << "\n";

	std::cout << "Zvo¾te interval:" << "\n";
	std::cout << "Minimum: ";
	double min = 0;
	std::cin >> min;
	std::cout << "\n";
	std::cout << "Maximum: ";
	double max = 0;
	std::cin >> max;

	this->filterAnd_->registerFilter(new FilterAgeFraction(this->age_, intToGender(this->gender_), min, max));
	this->filterTable();

	
	std::cout << "\n";
		std::cout << "Zoradi:" << "\n";
		std::cout << "1.Vzostupne" << "\n";
		std::cout << "2.Zostupne" << "\n";
		std::cout << "Vyber: ";
		std::cin >> this->ascending_;
		system("CLS");
	
	

}

void SortingByAgeFration::algorithm()
{
	CriterionAgeFraction criterionAgeFraction(this->age_, intToGender(this->gender_));
	structures::QuickSort<std::string, TerritorialUnit*, double> quickSort;
	quickSort.sort(*this->filteredTable_, &criterionAgeFraction, this->ascending_);
}

void SortingByAgeFration::printResult()
{
	CriterionName criterionName;
	for (int i = 0; i < this->filteredTable_->size(); ++i)
	{
		std::cout << "*******************************************************************************" << "\n";
		CriterionAgeNumber criterionAgeNumberMale(this->age_, Gender::Male);
		CriterionAgeNumber criterionAgeNumberFemale(this->age_, Gender::Female);
		TerritorialUnit* territorialUnit = this->filteredTable_->getItemAtIndex(i).accessData();
		std::cout << "Názov: " << criterionName.evaluate(territorialUnit) << "\n";
		std::cout << "Vek: " << this->age_ << "\n";
		std::cout << "Pohlavie: " << "\n";
		std::cout << "Muži: " << criterionAgeNumberMale.evaluate(territorialUnit) << "\n";
		std::cout << "Ženy: " << criterionAgeNumberFemale.evaluate(territorialUnit) << "\n";
		std::cout << "*******************************************************************************" << "\n";
		std::cout << "\n";
	}
}

