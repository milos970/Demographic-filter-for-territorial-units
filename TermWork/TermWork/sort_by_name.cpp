#include "sort_by_name.h"
#include "criterion_name.h"
#include "gender.h"
#include "quick_sort.h"
#include "../../structures/heap_monitor.h"
void SortingByName::options()
{
	
		this->types();
	this->makeTable();

	
		system("CLS");
		std::cout << "Zoradi:" << "\n";
		std::cout << "1.Vzostupne" << "\n";
		std::cout << "2.Zostupne" << "\n";
		std::cout << "Vyber: ";
		std::cin >> this->ascending_;
		system("CLS");

}


void SortingByName::algorithm()
{

	CriterionName criterionName;
	structures::QuickSort<std::string, TerritorialUnit*, std::string> quickSort;
	quickSort.sort(*this->tableToFilter_, &criterionName, this->ascending_);
	
}



void SortingByName::printResult()
{
	CriterionName criterionName;
	for (int i = 0; i < this->tableToFilter_->size(); ++i) 
	{
		std::cout << "*******************************************************************************" << "\n";

		TerritorialUnit* territorialUnit = this->tableToFilter_->getItemAtIndex(i).accessData();
		std::cout << "Názov: " << criterionName.evaluate(territorialUnit) << "\n";
		std::cout << "*******************************************************************************" << "\n";
		std::cout << "\n";
	}
}
