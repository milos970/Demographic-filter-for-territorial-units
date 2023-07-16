#pragma once
#include <iostream>
enum class EconomicAgeGroup
{
    Preproductive,
	Productive,
	Postproductive
};

static EconomicAgeGroup intToEconomicAgeGroup(const unsigned int& option)
{
    switch (option)
    {
    case 1:
        return EconomicAgeGroup::Preproductive;
    case 2:
        return EconomicAgeGroup::Productive;
    case 3:
        return EconomicAgeGroup::Postproductive;
    default:
        std::cout << "Chybn� hodnota!" << "\n";
    }
};

static std::string economicAgeGroupToString(const EconomicAgeGroup& type)
{
    switch (type)
    {
    case EconomicAgeGroup::Preproductive:
        return "Predprodukt�vny";
    case EconomicAgeGroup::Productive:
        return "Produkt�vni";
    case EconomicAgeGroup::Postproductive:
        return "Poprodukt�vni";
    default:
        std::cout << "Chybn� hodnota!" << "\n";
    }
};