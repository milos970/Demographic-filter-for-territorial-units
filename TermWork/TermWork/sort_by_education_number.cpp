#include "sort_by_education_number.h"
#include "criterion_education_number.h"
#include "filter_education_number.h"
#include "quick_sort.h"
#include "criterion_name.h"
#include "../../structures/heap_monitor.h"
void SortingByEducationNumber::options()
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
	unsigned int min = 0;
	std::cin >> min;
	std::cout << "\n";
	std::cout << "Maximum: ";
	unsigned int max = 0;
	std::cin >> max;

	std::cout << "\n";

	this->filterAnd_->registerFilter(new FilterEducationNumber(intToEducation(this->education_), min, max));
	this->filterTable();
	
		
		std::cout << "Zoradi:" << "\n";
		std::cout << "1.Vzostupne" << "\n";
		std::cout << "2.Zostupne" << "\n";
		std::cout << "Vyber: ";
		std::cin >> this->ascending_;
		system("CLS");
	
}

void SortingByEducationNumber::algorithm()
{
	CriterionEducationNumber criterionEducationNumber(intToEducation(this->education_));

	structures::QuickSort<std::string, TerritorialUnit*, unsigned int> quickSort;
	quickSort.sort(*this->filteredTable_, &criterionEducationNumber, this->ascending_);
}

void SortingByEducationNumber::printResult()
{
	CriterionName criterionName;
	for (int i = 0; i < this->filteredTable_->size(); ++i)
	{
		std::cout << "*******************************************************************************" << "\n";
		CriterionEducationNumber criterionEducationNumber(intToEducation(this->education_));
		TerritorialUnit* territorialUnit = this->filteredTable_->getItemAtIndex(i).accessData();
		std::cout << "Názov: " << criterionName.evaluate(territorialUnit) << "\n";
		std::cout << "Vzdelanie poèet: " << criterionEducationNumber.evaluate(territorialUnit) << "\n";
		std::cout << "*******************************************************************************" << "\n";
		std::cout << "\n";
	}

}


