#include <iostream>
#include "data.h"
#include <io.h>
#include <Windows.h>
#include "../../structures/heap_monitor.h"
#include "searching.h"
#include "filtering.h"
#include "sorting.h"
#include "selection_max_economic_age_group.h"
#include "selection_min_economic_age_group.h"
#include "sort_by_name.h"
#include "sort_by_education_number.h"
#include "sort_by_education_fraction.h"
#include "sort_by_age_fraction.h"
#include "sort_by_age_group_number.h"
#include <conio.h>




int main() 
{
	initHeapMonitor();
	
	
	SetConsoleOutputCP(1250);
	SetConsoleCP(1250);
	setlocale(LC_ALL, "slovak");

	std::cout << "Naèítavam dáta do pamäte." << "\n";
	Data data(2928, 79, 8, "Slovensko");
	
	
	

	

	

	
		system("CLS");
		std::cout << "Vyberte funkcionalitu:" << "\n";
		std::cout << "1.Bodové vyh¾adávanie" << "\n";
		std::cout << "2.Filtrovanie" << "\n";
		std::cout << "3.Triedenie" << "\n";
		std::cout << "4.Výber najlepších" << "\n";
		std::cout << "Vyber: ";

		unsigned int input = 0;
		std::cin >> input;


		char next = ' ';
		switch (input)
		{
		case 1:
			
		{
			Searching searching(data.getCountry());
			searching.options();
			searching.algorithm();
		}
			
			
			
			

			

		
			break;

		case 2:
		
		{
			Filtering filtering(data.getCountry());
			filtering.options();
			filtering.algorithm();
			filtering.printResult();
		}
			
			

			

			
		
			break;

		case 3:
			system("CLS");
			std::cout << "Vyberte triedenie:" << "\n";
			std::cout << "1.Názov" << "\n";
			std::cout << "2.Vzdelanie poèet" << "\n";
			std::cout << "3.Vzdelanie podiel" << "\n";
			std::cout << "4.Vek podiel" << "\n";
			std::cout << "5.Veková skupina poèet" << "\n";
			std::cout << "Vyber: ";
			input = 0;

			std::cin >> input;
			system("CLS");

			
			
			
			
			

			switch (input)
			{
			case 1:
			{
				SortingByName sortingByName(data.getCountry());
				sortingByName.options();
				sortingByName.algorithm();
				sortingByName.printResult();
			}
				
				
				break;
			case 2:
			{
				SortingByEducationNumber sortingByEducationNumber(data.getCountry());
				sortingByEducationNumber.options();
				sortingByEducationNumber.algorithm();
				sortingByEducationNumber.printResult();
			}
				
				
				break;
			case 3:
			{
				SortingByEducationFraction sortingByEducationFraction(data.getCountry());
				sortingByEducationFraction.options();
				sortingByEducationFraction.algorithm();
				sortingByEducationFraction.printResult();
			}
				
				
				break;
			case 4:

			{
				SortingByAgeFration sortingByAgeFraction(data.getCountry());
				sortingByAgeFraction.options();
				sortingByAgeFraction.algorithm();
				sortingByAgeFraction.printResult();
			}
				
				
				break;
			case 5:
			{
				SortingByAgeGroupNumber sortingByAgeGroupNumber(data.getCountry());
				sortingByAgeGroupNumber.options();
				sortingByAgeGroupNumber.algorithm();
				sortingByAgeGroupNumber.printResult();
			}
				
				
				break;
			}


			

			


			break;

		case 4:
			system("CLS");
			std::cout << "1.Najväèšia veková skupina" << "\n";
			std::cout << "2.Najmenšia veková skupina" << "\n";
			std::cout << "Vyber: ";
			input = 0;

			std::cin >> input;
			

			switch (input)
			{
			case 1:
			{
				SelectionMaxEconomicAgeGroup selectionMaxEaG(data.getCountry());
				selectionMaxEaG.options();
				selectionMaxEaG.algorithm();
				selectionMaxEaG.printResult();

			}
				
				
				
				break;
			case 2:
			{
				SelectionMinEconomicAgeGroup selectionMinEaG(data.getCountry());
				selectionMinEaG.options();
				selectionMinEaG.algorithm();
				selectionMinEaG.printResult();
			}
				
				
				break;
			}





			

			



			break;
		}









	
	

	
	
	
	



	return 0;
}