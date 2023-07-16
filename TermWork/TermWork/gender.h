#pragma once
#include <iostream>
enum class Gender
{
	Male,
	Female
}; 

static Gender intToGender(const unsigned int& option)
{
    switch (option)
    {
    case 1:
        return Gender::Male;
    case 2:
        return Gender::Female;
    default:
        std::cout << "Chybn� hodnota!" << "\n";
    }
};

static std::string genderToString(const Gender& type)
{
    switch (type)
    {
    case Gender::Male:
        return "Mu�i";
    case Gender::Female:
        return "�eny";
    default:
        std::cout << "Chybn� hodnota!" << "\n";
    }
};