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
        std::cout << "Chybná hodnota!" << "\n";
    }
};

static std::string economicAgeGroupToString(const EconomicAgeGroup& type)
{
    switch (type)
    {
    case EconomicAgeGroup::Preproductive:
        return "Predproduktívny";
    case EconomicAgeGroup::Productive:
        return "Produktívni";
    case EconomicAgeGroup::Postproductive:
        return "Poproduktívni";
    default:
        std::cout << "Chybná hodnota!" << "\n";
    }
};