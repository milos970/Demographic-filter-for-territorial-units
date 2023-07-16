#include "sort_by_education_fraction.h"
#include "criterion_education_fraction.h"
#include "filter_education_fraction.h"
#include "quick_sort.h"
#include "criterion_name.h"
#include "../../structures/heap_monitor.h"
void SortingByEducationFraction::options()
{
	
		this->types();
		this->makeTable();

	
		system("CLS");
		std::cout << "Vyberte vzdelanie:" << "\n";
		std::cout << "1.Bez ukonèeného vzdelania." << "\n";
		std::cout << "2.Základné." << "\n";
		std::cout << "3.Uèòovské." << "\n";
		std::cout << "4.Stredné." << "\n";
		std::cout << "5.Vyššie." << "\n";
		std::cout << "6.Vysokoškolské." << "\n";
		std::cout << "7.Bez vzdelania." << "\n";
		std::cout << "8.Nezistené." << "\n";
		std::cout << "Vyber: ";
		std::cin >> this->education_;

		std::cout << "\n";
	std::cout << "Zvo¾te interval:" << "\n";
	std::cout << "Minimum: ";
	double min = 0;
	std::cin >> min;
	std::cout << "\n";
	std::cout << "Maximum: ";
	double max = 0;
	std::cin >> max;

	

	this->filterAnd_->registerFilter(new FilterEducationFraction(intToEducation(this->education_), min, max));
	this->filterTable();

	
	std::cout << "\n";
		std::cout << "Zoradi:" << "\n";
		std::cout << "1.Vzostupne" << "\n";
		std::cout << "2.Zostupne" << "\n";
		std::cout << "Vyber: ";
		std::cin >> this->ascending_;
		system("CLS");
	
}

void SortingByEducationFraction::algorithm()
{
	CriterionEducationFraction criterionEducationFraction(intToEducation(this->education_));

	structures::QuickSort<std::string, TerritorialUnit*, double> quickSort;
	quickSort.sort(*this->filteredTable_, &criterionEducationFraction, this->ascending_);
}

void SortingByEducationFraction::printResult()
{
	CriterionName criterionName;
	for (int i = 0; i < this->filteredTable_->size(); ++i)
	{
		std::cout << "*******************************************************************************" << "\n";
		CriterionEducationFraction criterionEducationFraction(intToEducation(this->education_));
		TerritorialUnit* territorialUnit = this->filteredTable_->getItemAtIndex(i).accessData();
		std::cout << "Názov: " << criterionName.evaluate(territorialUnit) << "\n";
		std::cout << "Podiel obyvate¾ov: " << criterionEducationFraction.evaluate(territorialUnit) << "\n";
		std::cout << "*******************************************************************************" << "\n";
		std::cout << "\n";
	}
}

