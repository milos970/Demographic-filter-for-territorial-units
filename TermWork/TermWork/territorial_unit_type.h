#pragma once
#include <iostream>
enum class TerritorialUnitType
{
	Municipality,
	District,
	Region,
	Country
};

static std::string territorialUnitTypeToString(const TerritorialUnitType& type)
{
    switch (type)
    {
    case TerritorialUnitType::Municipality:
        return "Obec";
    case TerritorialUnitType::District:
        return "Okres";
    case TerritorialUnitType::Region:
        return "Kraj";
    case TerritorialUnitType::Country:
        return "Štát";
    default:
        std::cout << "Chybná hodnota!" << "\n";
    }

};