#pragma once
#include <iostream>
enum class Education
{
	BezUkoncenehoVzdelania,
	Zakladne,
	Ucnovske,
	Stredne,
	Vyssie,
	Vysokoskolske,
	BezVzdelania,
	Nezistene
};



static Education intToEducation(const unsigned int& option)
{
	switch (option)
	{
	case 1:
		return Education::BezUkoncenehoVzdelania;
	case 2:
		return Education::Zakladne;
	case 3:
		return Education::Ucnovske;
	case 4:
		return Education::Stredne;
	case 5:
		return Education::Vyssie;
	case 6:
		return Education::Vysokoskolske;
	case 7:
		return Education::BezVzdelania;
	case 8:
		return Education::Nezistene;
	default:
		std::cout << "Chybná hodnota!" << "\n";
	}
};

static std::string educationToString(const Education& type)
{
	switch (type)
	{
	case Education::BezUkoncenehoVzdelania:
		return "Bez ukonèeného vzdelania";
	case Education::Zakladne:
		return "Základné";
	case Education::Ucnovske:
		return "Uèòovské";
	case Education::Stredne:
		return "Stredné";
	case Education::Vyssie:
		return "Vyššie";
	case Education::Vysokoskolske:
		return "Vysokoškolské";
	case Education::BezVzdelania:
		return "Bez vzdelania";
	case Education::Nezistene:
		return "Nezistené";
	default:
		std::cout << "Chybná hodnota!" << "\n";
	}
};