#pragma once
#include "../../structures/table/sorted_sequence_table.h"
#include "country.h"
#include "../../structures/heap_monitor.h"

class Data
{
private:
	Country* country_;

	structures::SortedSequenceTable <Education, unsigned int>* educationNumbers_;

	


public:
	Data(const unsigned int numberOfMunicipalities, const unsigned int numberOfDistricts, const unsigned int numberOfRegions, const std::string& countryName);

	~Data() 
	{
		delete country_;
		country_ = nullptr;
		

		educationNumbers_ = nullptr;
	}

	Country* getCountry() 
	{
		return this->country_;
	}

private:
	void initializeEduTable();


};

