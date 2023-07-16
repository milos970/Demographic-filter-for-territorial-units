#include "searching.h"
#include "criterion_age_group_number.h"
#include "criterion_education_number.h"
#include "criterion_name.h"
#include "criterion_type.h"
#include "../../structures/heap_monitor.h"

void Searching::options()
{
	system("CLS");
	std::cout << "Zadajte n�zov: ";
	std::cin.ignore();
	std::getline(std::cin, this->name_);
	system("CLS");
}

void Searching::algorithm()
{
	this->territorialUnit_ = nullptr;



	for (structures::TableItem<std::string, District*>* item : *this->country_->getSortedDistricts())
	{
		District* district = item->accessData();

		Municipality* mun = nullptr;
		district->getSortedMunicipalities()->tryFind(this->name_, mun);

		this->territorialUnit_ = mun;
		if (this->territorialUnit_ != nullptr)
		{
			this->printResult();
			
		}
	}

	District* district = nullptr;
	this->country_->getSortedDistricts()->tryFind(this->name_, district);


	if (district != nullptr)
	{
		this->territorialUnit_ = district;
		this->printResult();
		
	}

	Region* region = nullptr;
	this->country_->getSortedRegions()->tryFind(this->name_, region);


	if (region != nullptr)
	{
		this->territorialUnit_ = region;
		this->printResult();
		
	}


	if (this->name_ == this->country_->getName())
	{
		this->territorialUnit_ = this->country_;
		this->printResult();
	}

	

	
}

void Searching::printResult()
{
	CriterionName criterionName;
	CriterionType criterionType;

	std::cout << "*******************************************************************************" << "\n";
	std::cout << "\n";
	std::cout << "N�zov: " << criterionName.evaluate(this->territorialUnit_) << "\n";
	std::cout << "Typ: " << territorialUnitTypeToString(criterionType.evaluate(this->territorialUnit_)) << "\n";

	std::cout << "\n";

	CriterionAgeGroupNumber ageGroupNumber1(EconomicAgeGroup::Preproductive);
	CriterionAgeGroupNumber ageGroupNumber2(EconomicAgeGroup::Productive);
	CriterionAgeGroupNumber ageGroupNumber3(EconomicAgeGroup::Postproductive);

	CriterionEducationNumber educationNumber1(Education::BezUkoncenehoVzdelania);
	CriterionEducationNumber educationNumber2(Education::Zakladne);
	CriterionEducationNumber educationNumber3(Education::Ucnovske);
	CriterionEducationNumber educationNumber4(Education::Stredne);
	CriterionEducationNumber educationNumber5(Education::Vyssie);
	CriterionEducationNumber educationNumber6(Education::Vysokoskolske);
	CriterionEducationNumber educationNumber7(Education::BezVzdelania);
	CriterionEducationNumber educationNumber8(Education::Nezistene);

	std::cout << "++++++++++++++++++++++++++" << "\n";
	std::cout << "Vzdelanie:" << "\n";
	std::cout << "Bez ukon�en�ho vzdelania: " << educationNumber1.evaluate(this->territorialUnit_) << "\n";
	std::cout << "Z�kladn�: " << educationNumber2.evaluate(this->territorialUnit_) << "\n";
	std::cout << "U��ovsk�: " << educationNumber3.evaluate(this->territorialUnit_) << "\n";
	std::cout << "Stredn�: " << educationNumber4.evaluate(this->territorialUnit_) << "\n";
	std::cout << "Vy��ie: " << educationNumber5.evaluate(this->territorialUnit_) << "\n";
	std::cout << "Vysoko�kolsk�: " << educationNumber6.evaluate(this->territorialUnit_) << "\n";
	std::cout << "Bez vzdelania: " << educationNumber7.evaluate(this->territorialUnit_) << "\n";
	std::cout << "Nezisten�: " << educationNumber8.evaluate(this->territorialUnit_) << "\n";
	std::cout << "++++++++++++++++++++++++++" << "\n";
	std::cout << "\n";
	std::cout << "++++++++++++++++++++++++++" << "\n";
	std::cout << "Ekonomick� vekov� skupina:" << "\n";
	std::cout << "Predprodukt�vny: " << ageGroupNumber1.evaluate(this->territorialUnit_) << "\n";
	std::cout << "Produkt�vni: " << ageGroupNumber2.evaluate(this->territorialUnit_) << "\n";
	std::cout << "Poprodukt�vni: " << ageGroupNumber3.evaluate(this->territorialUnit_) << "\n";
	std::cout << "++++++++++++++++++++++++++" << "\n";

	const TerritorialUnit* tU = this->territorialUnit_->getSuperiorUnit();

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
	std::cout << "*******************************************************************************" << "\n";
}

