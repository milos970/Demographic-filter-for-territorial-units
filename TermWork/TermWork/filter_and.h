#pragma once
#include "../../structures/heap_monitor.h"
#include "composite_filter.h"

template<typename ObjectType>
class Filter_AND : public CompositeFilter<ObjectType>
{

public:

	bool pass(const ObjectType& object) override;

	~Filter_AND() 
	{
		for (auto item : *this->filters_)
		{
			delete item;
		}
	}

};

template<typename ObjectType>
inline bool Filter_AND<ObjectType>::pass(const ObjectType& object)
{
	for (auto item : *this->filters_)
	{
		if (item->pass(object) == false) 
		{
			return false;
		}
	}
	return true;
}
