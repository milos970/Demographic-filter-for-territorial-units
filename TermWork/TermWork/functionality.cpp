#include "functionality.h"
#include "../../structures/heap_monitor.h"

void Functionality::types()
{
	
		system("CLS");
		std::cout << "Zvo¾te typ jednotky:" << "\n";
		std::cout << "1.Obec" << "\n";
		std::cout << "2.Okres" << "\n";
		std::cout << "3.Kraj" << "\n";
		std::cout << "4.Žiadna" << "\n";
		std::cout << "Vyber: ";
		std::cin >> this->type_;

	
	

	switch (this->type_)
	{
		
	case 1:
		
			system("CLS");
			std::cout << "Zvo¾te jej príslušnos:" << "\n";
			std::cout << "1.Okres" << "\n";
			std::cout << "2.Kraj" << "\n";
			std::cout << "3.Bez príslušnosti" << "\n";
			std::cout << "Vyber: ";
			std::cin >> this->belongTo_;
		
		break;
	case 2:
		
			system("CLS");
			std::cout << "Zvo¾te jej príslušnos:" << "\n";
			std::cout << "1.Kraj" << "\n";
			std::cout << "2.Bez príslušnosti" << "\n";
			std::cout << "Vyber: ";
			std::cin >> this->belongTo_;
		
		break;
	case 3:
	case 4:
		this->belongTo_ = 1;
		break;
	}




	if ((this->type_ == 1 && this->belongTo_ == 3) || (this->type_ == 2 && this->belongTo_ == 2) || (this->type_ == 3 && this->belongTo_ == 1) || (this->type_ == 4 && this->belongTo_ == 1))
	{
		system("CLS");
		return;
	}

	std::cout << "\n";
	std::cout << "Zadajte názov: ";
	std::cin.ignore();
	std::getline(std::cin, this->name_);

	system("CLS");
}

void Functionality::makeTable()
{



	if (this->type_ == 1 && this->belongTo_ == 1) // obce z okresu
	{
		District* district = nullptr;


		this->country_->getSortedDistricts()->tryFind(this->name_, district);

		
		


		for (structures::TableItem<std::string, Municipality*>* item : *district->getSortedMunicipalities())
		{
			this->tableToFilter_->insert(item->accessData()->getCode(), item->accessData());
		}
		
		
	}



	if (this->type_ == 1 && this->belongTo_ == 2) // obce z kraja
	{

		Region* region = nullptr;




		this->country_->getSortedRegions()->tryFind(this->name_, region);

		

		for (structures::TableItem<std::string, District*>* item : *region->getSortedDistricts())
		{
			for (structures::TableItem<std::string, Municipality*>* item1 : *item->accessData()->getSortedMunicipalities())
			{
				this->tableToFilter_->insert(item1->accessData()->getCode(), item1->accessData());
			}
		}
		

		

	}

	if (this->type_ == 1 && this->belongTo_ == 3) // obce zo statu
	{


		for (structures::TableItem<std::string, Region*>* item : *this->country_->getSortedRegions())
		{
			for (structures::TableItem<std::string, District*>* item1 : *item->accessData()->getSortedDistricts())
			{
				for (structures::TableItem<std::string, Municipality*>* item2 : *item1->accessData()->getSortedMunicipalities())
				{
					this->tableToFilter_->insert(item2->accessData()->getCode(), item2->accessData());
				}
			}
		}


	
		
	}






	if (this->type_ == 2 && this->belongTo_ == 1) //okresy z kraja
	{


		Region* region = nullptr;
		this->country_->getSortedRegions()->tryFind(this->name_, region);

		
		


		for (structures::TableItem<std::string, District*>* item : *region->getSortedDistricts())
		{
			this->tableToFilter_->insert(item->accessData()->getCode(), item->accessData());
		}
		
		
	}



	if (this->type_ == 2 && this->belongTo_ == 2) //okresy zo statu
	{

		for (structures::TableItem<std::string, Region*>* item : *this->country_->getSortedRegions())
		{

			for (structures::TableItem<std::string, District*>* item1 : *item->accessData()->getSortedDistricts())
			{
				this->tableToFilter_->insert(item1->accessData()->getCode(), item1->accessData());
			}
		}
		
	}



	if (this->type_ == 3 && this->belongTo_ == 1) //kraje zo statu
	{


		for (structures::TableItem<std::string, Region*>* item : *this->country_->getSortedRegions())
		{

			this->tableToFilter_->insert(item->accessData()->getCode(), item->accessData());
		}

		
	}



	if (this->type_ == 4 && this->belongTo_ == 1) // vsetky kraje obce okresy zo statu
	{


		for (structures::TableItem<std::string, Region*>* item : *this->country_->getSortedRegions())
		{
			this->tableToFilter_->insert(item->accessData()->getCode(), item->accessData());
		}

		for (structures::TableItem<std::string, District*>* item : *this->country_->getSortedDistricts())
		{
			this->tableToFilter_->insert(item->accessData()->getCode(), item->accessData());
		}

		for (structures::TableItem<std::string, Municipality*>* item : *this->country_->getUnsortedMunicipalities())
		{
			this->tableToFilter_->insert(item->accessData()->getCode(), item->accessData());
		}

		

	}
	
}



void Functionality::filterTable()
{
	for (int i = 0; i < this->tableToFilter_->size(); ++i) 
	{
		TerritorialUnit* unitToBeChecked = this->tableToFilter_->getItemAtIndex(i).accessData();
		
		bool passed = this->filterAnd_->pass(unitToBeChecked);

		if (passed)
		{
			this->filteredTable_->insert(unitToBeChecked->getCode(), unitToBeChecked);
		}
	}
	

}


