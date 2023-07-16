#include "data.h"
#include <fstream>
#include <sstream> 
#include "../../structures/table/sorted_sequence_table.h"
#include "../../structures/table/unsorted_sequence_table.h"
#include <iostream>
#include "criterion_age_group_number.h"
#include "criterion_education_number.h"
#include "../../structures/heap_monitor.h"



Data::Data(const unsigned int numberOfMunicipalities, const unsigned int numberOfDistricts, const unsigned int numberOfRegions, const std::string& countryName)
{

	std::ifstream  file1;
	std::ifstream  file2;
	std::ifstream  file3;
	std::ifstream  file4;
	std::ifstream  file5;

	file1.imbue(std::locale("zh_CN.UTF-8"));
	file2.imbue(std::locale("zh_CN.UTF-8"));
	file3.imbue(std::locale("zh_CN.UTF-8"));
	file4.imbue(std::locale("zh_CN.UTF-8"));
	file5.imbue(std::locale("zh_CN.UTF-8"));

	file1.open("files/obce.csv", std::ifstream::in);
	file2.open("files/vek.csv", std::ifstream::in);
	file3.open("files/vzdelanie.csv", std::ifstream::in);
	file4.open("files/okresy.csv", std::ifstream::in);
	file5.open("files/kraje.csv", std::ifstream::in);





	std::string line = "";
	std::string word = "";

	std::string name = "";
	std::string code = "";



	//hlavicky preskocim
	std::getline(file1, line);
	std::getline(file2, line);
	std::getline(file3, line);
	std::getline(file4, line);
	std::getline(file5, line);

	structures::UnsortedSequenceTable <std::string, std::string>* municipalitiesData = new structures::UnsortedSequenceTable <std::string, std::string>();
	structures::SortedSequenceTable <std::string, std::string>* educationsData = new structures::SortedSequenceTable <std::string, std::string>();
	structures::SortedSequenceTable <std::string, std::string>* agesData = new structures::SortedSequenceTable <std::string, std::string>();



	unsigned int which = 0;
	for (int i = 0; i < numberOfMunicipalities; ++i)
	{
		std::getline(file2, line);
		std::stringstream ss1(line);

		which = 0;
		while (std::getline(ss1, word, ';'))
		{


			code = word;
			agesData->insert(code, line);
			break;

		}



	}

	which = 0;
	for (int i = 0; i < numberOfMunicipalities; ++i)
	{
		std::getline(file3, line);
		std::stringstream ss2(line);

		which = 0;
		while (std::getline(ss2, word, ';'))
		{


			code = word;
			educationsData->insert(code, line);

			break;

		}



	}

	which = 0;
	for (int i = 0; i < numberOfMunicipalities; ++i)
	{
		std::getline(file1, line);
		std::stringstream ss3(line);

		which = 0;
		while (std::getline(ss3, word, ';') && which != 4)
		{

			if (which == 1)
			{
				code = word;
			}

			if (which == 3)
			{
				name = word;
			}

			++which;

		}

		municipalitiesData->insert(code, name);

	}

	structures::UnsortedSequenceTable <std::string, Municipality*>* municipalitiesUnsortedTable = new structures::UnsortedSequenceTable <std::string, Municipality*>();



	//vytvaranie obce
	unsigned int municipalityPopulation = 0;
	for (int i = 0; i < municipalitiesData->size(); ++i) 
	{
		structures::Array<unsigned int>* menAgeGroup = new structures::Array<unsigned int>(101);
		structures::Array<unsigned int>* womenAgeGroup = new structures::Array<unsigned int>(101);
		municipalityPopulation = 0;

		agesData->tryFind(municipalitiesData->getItemAtIndex(i).getKey(), line); 

		std::stringstream ss4(line);
		//nacitavam veky
		which = 0;
		while (std::getline(ss4, word, ';')) 
		{

			if (which > 1 && which < 103)
			{
				unsigned int toInt = std::stoi(word);
				menAgeGroup->at(which - 2) = toInt;
				municipalityPopulation += toInt;

			}

			if (which >= 103)
			{
				unsigned int toInt = std::stoi(word);
				womenAgeGroup->at(which - 103) = toInt;
				municipalityPopulation += toInt;
			}
			++which;

		}


		//nacitavam vzdelania
		structures::SortedSequenceTable <Education, unsigned int>* educationNumbers = new structures::SortedSequenceTable <Education, unsigned int>();

		educationsData->tryFind(municipalitiesData->getItemAtIndex(i).getKey(), line);

		std::stringstream ss5(line);


		which = 0;
		while (std::getline(ss5, word, ';'))
		{
			switch (which)
			{
			case 2:
				educationNumbers->insert(Education::BezUkoncenehoVzdelania, std::stoi(word));
				break;
			case 3:
				educationNumbers->insert(Education::Zakladne, std::stoi(word));
				break;
			case 4:
				educationNumbers->insert(Education::Ucnovske, std::stoi(word));
				break;
			case 5:
				educationNumbers->insert(Education::Stredne, std::stoi(word));
				break;
			case 6:
				educationNumbers->insert(Education::Vyssie, std::stoi(word));
				break;
			case 7:
				educationNumbers->insert(Education::Vysokoskolske, std::stoi(word));
				break;
			case 8:
				educationNumbers->insert(Education::BezVzdelania, std::stoi(word));
				break;
			case 9:
				educationNumbers->insert(Education::Nezistene, std::stoi(word));
				break;
			}
			++which;

		}

		code = municipalitiesData->getItemAtIndex(i).getKey(); // 0(1)
		name = municipalitiesData->getItemAtIndex(i).accessData(); // 0(1)
		Municipality* municipality = new Municipality(name, code, municipalityPopulation, menAgeGroup, womenAgeGroup, educationNumbers);
		municipalitiesUnsortedTable->insert(municipality->getCode(), municipality); // 0(1)

	}


	








	








	delete municipalitiesData;
	delete educationsData;
	delete agesData;










	//***********************************Okres*************************
	structures::SortedSequenceTable<std::string, District*>* districtsSortedTable = new structures::SortedSequenceTable<std::string, District*>();
	structures::UnsortedSequenceTable<std::string, District*>* districtsUnsortedTable = new structures::UnsortedSequenceTable<std::string, District*>();



	unsigned int districtPopulation = 0;
	int municipalitiesOrder = 0; 

	for (int i = 0; i < numberOfDistricts; ++i) 
	{
		std::getline(file4, line);

		std::stringstream ss(line);

		districtPopulation = 0;

		int which = 0;
		while (std::getline(ss, word, ';')) 
		{
			if (which == 1)
			{
				code = word;

			}

			if (which == 3)
			{
				name = word;

			}
			++which;

		}



		structures::Array<unsigned int>* menAgeGroup = new structures::Array<unsigned int>(101);
		structures::Array<unsigned int>* womenAgeGroup = new structures::Array<unsigned int>(101);

		this->initializeEduTable();

		structures::SortedSequenceTable<std::string, Municipality*>* municipalitiesSortedTable1 = new  structures::SortedSequenceTable<std::string, Municipality*>();




		int c = 0;
		while (municipalitiesOrder != numberOfMunicipalities && (municipalitiesUnsortedTable->getItemAtIndex(municipalitiesOrder).accessData()->getCode().find(code) != std::wstring::npos))
		{


			for (int k = 0; k < 101; ++k)
			{
				unsigned int number = municipalitiesUnsortedTable->getItemAtIndex(municipalitiesOrder).accessData()->getMenAgeGroup(k);
				menAgeGroup->at(k) += number;
				districtPopulation += number;
			}

			for (int k = 0; k < 101; ++k)
			{
				unsigned int number = municipalitiesUnsortedTable->getItemAtIndex(municipalitiesOrder).accessData()->getWomenAgeGroup(k);
				womenAgeGroup->at(k) += number;
				districtPopulation += number;

			}

			unsigned int numberOfEducated = 0;



			numberOfEducated = municipalitiesUnsortedTable->getItemAtIndex(municipalitiesOrder).accessData()->getEducationNumbers(Education::BezUkoncenehoVzdelania);
			this->educationNumbers_->find(Education::BezUkoncenehoVzdelania) += numberOfEducated;


			numberOfEducated = municipalitiesUnsortedTable->getItemAtIndex(municipalitiesOrder).accessData()->getEducationNumbers(Education::Zakladne);
			this->educationNumbers_->find(Education::Zakladne) += numberOfEducated;


			numberOfEducated = municipalitiesUnsortedTable->getItemAtIndex(municipalitiesOrder).accessData()->getEducationNumbers(Education::Ucnovske);
			this->educationNumbers_->find(Education::Ucnovske) += numberOfEducated;



			numberOfEducated = municipalitiesUnsortedTable->getItemAtIndex(municipalitiesOrder).accessData()->getEducationNumbers(Education::Stredne);
			this->educationNumbers_->find(Education::Stredne) += numberOfEducated;


			numberOfEducated = municipalitiesUnsortedTable->getItemAtIndex(municipalitiesOrder).accessData()->getEducationNumbers(Education::Vyssie);
			this->educationNumbers_->find(Education::Vyssie) += numberOfEducated;


			numberOfEducated = municipalitiesUnsortedTable->getItemAtIndex(municipalitiesOrder).accessData()->getEducationNumbers(Education::Vysokoskolske);
			this->educationNumbers_->find(Education::Vysokoskolske) += numberOfEducated;


			numberOfEducated = municipalitiesUnsortedTable->getItemAtIndex(municipalitiesOrder).accessData()->getEducationNumbers(Education::BezVzdelania);
			this->educationNumbers_->find(Education::BezVzdelania) += numberOfEducated;


			numberOfEducated = municipalitiesUnsortedTable->getItemAtIndex(municipalitiesOrder).accessData()->getEducationNumbers(Education::Nezistene);
			this->educationNumbers_->find(Education::Nezistene) += numberOfEducated;

			municipalitiesSortedTable1->insert(municipalitiesUnsortedTable->getItemAtIndex(municipalitiesOrder).accessData()->getName(), municipalitiesUnsortedTable->getItemAtIndex(municipalitiesOrder).accessData());

			++municipalitiesOrder;
			++c;

		}




		District* district = new District(name, code, districtPopulation, menAgeGroup, womenAgeGroup, this->educationNumbers_, municipalitiesSortedTable1);



		for (int u = (municipalitiesOrder - c); u < municipalitiesOrder; ++u)
		{

			municipalitiesUnsortedTable->getItemAtIndex(u).accessData()->setSuperiorUnit(district);
		}


		districtsSortedTable->insert(name, district);
		districtsUnsortedTable->insert(name, district);



	}










	//***************************Region*********************************

	structures::SortedSequenceTable<std::string, Region*>* regionsSortedTable = new structures::SortedSequenceTable<std::string, Region*>();
	structures::UnsortedSequenceTable<std::string, Region*>* regionsUnsortedTable = new structures::UnsortedSequenceTable<std::string, Region*>();


	unsigned int regionPopulation = 0;
	unsigned int districtsOrder = 0; // poradie okresov


	for (int j = 0; j < numberOfRegions; ++j)
	{
		std::getline(file5, line);

		std::stringstream ss(line);

		regionPopulation = 0;

		int which = 0;
		while (std::getline(ss, word, ';'))
		{
			if (which == 5)
			{
				code = word;

			}

			if (which == 4)
			{
				name = word;

			}
			++which;

		}


		structures::Array<unsigned int>* menAgeGroup = new structures::Array<unsigned int>(101);
		structures::Array<unsigned int>* womenAgeGroup = new structures::Array<unsigned int>(101);

		this->initializeEduTable();

		structures::SortedSequenceTable<std::string, District*>* districtsSortedTable1 = new structures::SortedSequenceTable<std::string, District*>();
		//structures::UnsortedSequenceTable<std::string, District*>* districtsUnsortedTable1 = new structures::UnsortedSequenceTable<std::string, District*>();

		structures::UnsortedSequenceTable<std::string, District*>* table = dynamic_cast<structures::UnsortedSequenceTable<std::string, District*>*>(districtsUnsortedTable);



		int c = 0;
		while (districtsOrder != numberOfDistricts && table->getItemAtIndex(districtsOrder).accessData()->getCode().find(code) != std::string::npos) // pokial okres patri podla kodu do daneho kraja
		{


			for (int k = 0; k < 101; ++k)
			{
				unsigned int number = table->getItemAtIndex(districtsOrder).accessData()->getMenAgeGroup(k);
				menAgeGroup->at(k) += number;
				regionPopulation += number;
			}

			for (int k = 0; k < 101; ++k)
			{
				unsigned int number = table->getItemAtIndex(districtsOrder).accessData()->getWomenAgeGroup(k);
				womenAgeGroup->at(k) += number;
				regionPopulation += number;

			}

			unsigned int numberOfEducated = 0;



			numberOfEducated = table->getItemAtIndex(districtsOrder).accessData()->getEducationNumbers(Education::BezUkoncenehoVzdelania);
			this->educationNumbers_->find(Education::BezUkoncenehoVzdelania) += numberOfEducated;



			numberOfEducated = table->getItemAtIndex(districtsOrder).accessData()->getEducationNumbers(Education::Zakladne);
			this->educationNumbers_->find(Education::Zakladne) += numberOfEducated;


			numberOfEducated = table->getItemAtIndex(districtsOrder).accessData()->getEducationNumbers(Education::Ucnovske);
			this->educationNumbers_->find(Education::Ucnovske) += numberOfEducated;



			numberOfEducated = table->getItemAtIndex(districtsOrder).accessData()->getEducationNumbers(Education::Stredne);
			this->educationNumbers_->find(Education::Stredne) += numberOfEducated;


			numberOfEducated = table->getItemAtIndex(districtsOrder).accessData()->getEducationNumbers(Education::Vyssie);
			this->educationNumbers_->find(Education::Vyssie) += numberOfEducated;


			numberOfEducated = table->getItemAtIndex(districtsOrder).accessData()->getEducationNumbers(Education::Vysokoskolske);
			this->educationNumbers_->find(Education::Vysokoskolske) += numberOfEducated;


			numberOfEducated = table->getItemAtIndex(districtsOrder).accessData()->getEducationNumbers(Education::BezVzdelania);
			this->educationNumbers_->find(Education::BezVzdelania) += numberOfEducated;


			numberOfEducated = table->getItemAtIndex(districtsOrder).accessData()->getEducationNumbers(Education::Nezistene);
			this->educationNumbers_->find(Education::Nezistene) += numberOfEducated;


			districtsSortedTable1->insert(table->getItemAtIndex(districtsOrder).accessData()->getName(), table->getItemAtIndex(districtsOrder).accessData());

			++districtsOrder;
			++c;
		}




		Region* region = new Region(name, code, regionPopulation, menAgeGroup, womenAgeGroup, this->educationNumbers_, districtsSortedTable1);

		for (int u = (districtsOrder - c); u < districtsOrder; ++u)
		{
			table->getItemAtIndex(u).accessData()->setSuperiorUnit(region);
		}



		regionsSortedTable->insert(name, region);
		regionsUnsortedTable->insert(name, region);



	}





	//***************************Country*********************************




	structures::Array<unsigned int>* menAgeGroup = new structures::Array<unsigned int>(101);
	structures::Array<unsigned int>* womenAgeGroup = new structures::Array<unsigned int>(101);

	this->initializeEduTable();



	unsigned int countryPopulation = 0;



	int c = 0;

	for (int i = 0; i < regionsUnsortedTable->size(); ++i) // 8x
	{
		// 204
		for (int k = 0; k < 101; ++k)
		{
			unsigned int number = regionsUnsortedTable->getItemAtIndex(i).accessData()->getMenAgeGroup(k);
			menAgeGroup->at(k) += number;
			countryPopulation += number;
		}

		for (int k = 0; k < 101; ++k)
		{
			unsigned int number = regionsUnsortedTable->getItemAtIndex(i).accessData()->getWomenAgeGroup(k);
			womenAgeGroup->at(k) += number;
			countryPopulation += number;

		}

		unsigned int numberOfEducated = 0;


		//8*logn
		numberOfEducated = regionsUnsortedTable->getItemAtIndex(i).accessData()->getEducationNumbers(Education::BezUkoncenehoVzdelania);
		this->educationNumbers_->find(Education::BezUkoncenehoVzdelania) += numberOfEducated;



		numberOfEducated = regionsUnsortedTable->getItemAtIndex(i).accessData()->getEducationNumbers(Education::Zakladne);
		this->educationNumbers_->find(Education::Zakladne) += numberOfEducated;


		numberOfEducated = regionsUnsortedTable->getItemAtIndex(i).accessData()->getEducationNumbers(Education::Ucnovske);
		this->educationNumbers_->find(Education::Ucnovske) += numberOfEducated;


		numberOfEducated = regionsUnsortedTable->getItemAtIndex(i).accessData()->getEducationNumbers(Education::Stredne);
		this->educationNumbers_->find(Education::Stredne) += numberOfEducated;


		numberOfEducated = regionsUnsortedTable->getItemAtIndex(i).accessData()->getEducationNumbers(Education::Vyssie);
		this->educationNumbers_->find(Education::Vyssie) += numberOfEducated;


		numberOfEducated = regionsUnsortedTable->getItemAtIndex(i).accessData()->getEducationNumbers(Education::Vysokoskolske);
		this->educationNumbers_->find(Education::Vysokoskolske) += numberOfEducated;


		numberOfEducated = regionsUnsortedTable->getItemAtIndex(i).accessData()->getEducationNumbers(Education::BezVzdelania);
		this->educationNumbers_->find(Education::BezVzdelania) += numberOfEducated;


		numberOfEducated = regionsUnsortedTable->getItemAtIndex(i).accessData()->getEducationNumbers(Education::Nezistene);
		this->educationNumbers_->find(Education::Nezistene) += numberOfEducated;

	}


	this->country_ = new Country(countryName, "421", countryPopulation, menAgeGroup, womenAgeGroup, this->educationNumbers_, regionsSortedTable, districtsSortedTable, municipalitiesUnsortedTable);

	for (int i = 0; i < regionsUnsortedTable->size(); ++i)
	{
		regionsUnsortedTable->getItemAtIndex(i).accessData()->setSuperiorUnit(this->country_);
	}



	this->country_->setSuperiorUnit(nullptr);









	file1.close();
	file2.close();
	file3.close();
	file4.close();
	file5.close();



	delete districtsUnsortedTable;

	delete regionsUnsortedTable;
}

void Data::initializeEduTable()
{
	this->educationNumbers_ = new structures::SortedSequenceTable <Education, unsigned int>();
	this->educationNumbers_->insert(Education::BezUkoncenehoVzdelania, 0);
	this->educationNumbers_->insert(Education::Zakladne, 0);
	this->educationNumbers_->insert(Education::Ucnovske, 0);
	this->educationNumbers_->insert(Education::Stredne, 0);
	this->educationNumbers_->insert(Education::Vyssie, 0);
	this->educationNumbers_->insert(Education::Vysokoskolske, 0);
	this->educationNumbers_->insert(Education::BezVzdelania, 0);
	this->educationNumbers_->insert(Education::Nezistene, 0);
}
