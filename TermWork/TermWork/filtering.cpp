#include "filtering.h"
#include "filter_age_number.h"
#include "filter_age_fraction.h"
#include "filter_age_group_number.h"
#include "filter_age_group_fraction.h"
#include "filter_education_number.h"
#include "filter_education_fraction.h"
#include "../../structures/heap_monitor.h"

void Filtering::options()
{
	
	this->types();
	this->makeTable();
	
	unsigned int filter = 0;

	do {

	
		system("CLS");

		std::cout << "1.Vek po�et" << "\n";
		std::cout << "2.Vek podiel" << "\n";
		std::cout << "3.Vekov� skupina po�et" << "\n";
		std::cout << "4.Vekov� skupina podiel" << "\n";
		std::cout << "5.Vzdelanie po�et" << "\n";
		std::cout << "6.Vzdelanie podiel" << "\n";
		std::cout << "7.Vyfiltruj" << "\n";
		std::cout << "Vyber: ";

		
	std::cin >> filter;
	
	

	unsigned int gender = 0;
	unsigned int education = 0;
	unsigned int economicAgeGroup = 0;

	switch (filter)
	{
	case 1:
	case 2:
		
			std::cout << "\n";
			std::cout << "Vyberte pohlavie:" << "\n";
			std::cout << "1.Mu�." << "\n";
			std::cout << "2.�ena." << "\n";
			std::cout << "Vyber: ";
			std::cin >> gender;
		
			std::cout <<  "\n";
		
	

		
			
			std::cout << "Zadajte vek: ";
			std::cin >> this->age_;
		
			std::cout << "\n";
		std::cout << "Zadajte interval" << "\n";

		if (filter == 1)
		{
			std::cout << "Minimum: ";
			unsigned int min = 0;
			std::cin >> min;
			std::cout << "\n";
			std::cout << "Maximum: ";
			unsigned int max = 0;
			std::cin >> max;

			this->filterAnd_->registerFilter(new FilterAgeNumber(this->age_, intToGender(gender), min, max));
			this->criterionAgeNumber_ = new CriterionAgeNumber(this->age_, intToGender(gender));
			this->arrayList_->add(1);
			system("CLS");
		}

		if (filter == 2)
		{
			std::cout << "Minimum: ";
			double min = 0;
			std::cin >> min;
			std::cout << "\n";
			std::cout << "Maximum: ";
			double max = 0;
			std::cin >> max;

			this->filterAnd_->registerFilter(new FilterAgeFraction(this->age_, intToGender(gender), min, max));
			this->criterionAgeFraction_ = new CriterionAgeFraction(this->age_, intToGender(gender));
			this->arrayList_->add(2);
			system("CLS");
		}

		break;
	case 3:
	case 4:
		
			system("CLS");
			std::cout << "Vyberte ekonomick� vekov� skupinu:" << "\n";
			std::cout << "1.Predprodukt�vni." << "\n";
			std::cout << "2.Produkt�vni." << "\n";
			std::cout << "3.Poprodukt�vni." << "\n";
			std::cout << "Vyber: ";

			std::cin >> economicAgeGroup;
	
			std::cout << "\n";
		std::cout << "Zadajte interval" << "\n";

		if (filter == 3)
		{
			std::cout << "Minimum: ";
			unsigned int min = 0;
			std::cin >> min;
			std::cout << "\n";
			std::cout << "Maximum: ";

			unsigned int max = 0;
			std::cin >> max;
			this->filterAnd_->registerFilter(new FilterAgeGroupNumber(intToEconomicAgeGroup(economicAgeGroup), min, max));
			this->criterionAgeGroupNumber_ = new CriterionAgeGroupNumber(intToEconomicAgeGroup(economicAgeGroup));
			this->arrayList_->add(3);
			system("CLS");
		}

		if (filter == 4)
		{
			std::cout << "Minimum: ";
			double min = 0;
			std::cin >> min;
			std::cout << "\n";
			std::cout << "Maximum: ";
			double max = 0;
			std::cin >> max;

			this->filterAnd_->registerFilter(new FilterAgeGroupFraction(intToEconomicAgeGroup(economicAgeGroup), min, max));
			this->criterionAgeGroupFraction_ = new CriterionAgeGroupFraction(intToEconomicAgeGroup(economicAgeGroup));
			this->arrayList_->add(4);
			system("CLS");

		}
		break;
	case 5:
	case 6:
		
			system("CLS");
			std::cout << "Vyberte vzdelanie:" << "\n";
			std::cout << "1.Bez ukon�en�ho vzdelania." << "\n";
			std::cout << "2.Z�kladn�." << "\n";
			std::cout << "3.U��ovsk�." << "\n";
			std::cout << "4.Stredn�." << "\n";
			std::cout << "5.Vy��ie." << "\n";
			std::cout << "6.Vysoko�kolsk�." << "\n";
			std::cout << "7.Bez vzdelania." << "\n";
			std::cout << "8.Nezisten�." << "\n";
			std::cout << "Vyber: ";
			std::cin >> education;
			std::cout << "\n";
		std::cout << "Zadajte interval" << "\n";

		if (filter == 5)
		{

			std::cout << "Minimum: ";
			unsigned int min = 0;
			std::cin >> min;
			std::cout << "\n";
			std::cout << "Maximum: ";

			unsigned int max = 0;
			std::cin >> max;
			

			this->filterAnd_->registerFilter(new FilterEducationNumber(intToEducation(education), min, max));
			this->criterionEducationNumber_ = new CriterionEducationNumber(intToEducation(education));
			this->arrayList_->add(5);
			system("CLS");
		}

		if (filter == 6)
		{
			std::cout << "Minimum: ";
			double min = 0;
			std::cin >> min;
			std::cout << "\n";
			std::cout << "Maximum: ";
			double max = 0;
			std::cin >> max;

			this->filterAnd_->registerFilter(new FilterEducationFraction(intToEducation(education), min, max));
			this->criterionEducationFraction_ = new CriterionEducationFraction(intToEducation(education));
			this->arrayList_->add(6);
			system("CLS");
		}
		break;
	case 7:
		return;
	}

	} while (true);

	
}

void Filtering::algorithm()
{
	this->filterTable();

}

void Filtering::printResult()
{
	for (int i = 0; i < this->filteredTable_->size(); ++i) 
	{
		TerritorialUnit* territorialUnit = this->filteredTable_->getItemAtIndex(i).accessData();

		std::cout << "*******************************************************************************" << "\n";
		std::cout << "\n";
		std::cout << "N�zov: " << territorialUnit->getName() << "\n";
		std::cout << "Typ: " << territorialUnitTypeToString(territorialUnit->getTerritorialUnitType()) << "\n";

		std::cout << "\n";

		const TerritorialUnit* tU = territorialUnit->getSuperiorUnit();

		std::cout << "++++++++++++++++++++++++++" << "\n";
		std::cout << "Vy��ie celky:" << "\n";

		for (int i = 0; tU != nullptr; ++i)
		{
			std::cout << "\n";
			std::cout << "N�zov: " << tU->getName() << "\n";
			std::cout << "Typ: " << territorialUnitTypeToString(tU->getTerritorialUnitType()) << "\n";

			tU = tU->getSuperiorUnit();
			std::cout << "\n";
		}

		std::cout << "++++++++++++++++++++++++++" << "\n";
		std::cout << "\n";
		std::cout << "++++++++++++++++++++++++++" << "\n";
		std::cout << "\n";

		for (int j = 0; j < this->arrayList_->size(); ++j) 
		{
			switch (this->arrayList_->at(j)) 
			{
			case 1:
				std::cout << "Vek po�et: " << this->criterionAgeNumber_->evaluate(territorialUnit) << "\n";
				break;
			case 2:
				std::cout << "Vek podiel: " << this->criterionAgeFraction_->evaluate(territorialUnit) << "\n";
				break;
			case 3:
				std::cout << "Vekov� skupina po�et: " << this->criterionAgeGroupNumber_->evaluate(territorialUnit) << "\n";
				break;
			case 4:
				std::cout << "Vekov� skupina podiel: " << this->criterionAgeGroupFraction_->evaluate(territorialUnit) << "\n";
				break;
			case 5:
				std::cout << "Vzdelanie po�et: " << this->criterionEducationNumber_->evaluate(territorialUnit) << "\n";
				break;
			case 6:
				std::cout << "Vzdelanie podiel: " << this->criterionEducationFraction_->evaluate(territorialUnit) << "\n";
				break;
			}
		}
		std::cout << "++++++++++++++++++++++++++" << "\n";
		std::cout << "\n";
		std::cout << "*******************************************************************************" << "\n";
	}
}


