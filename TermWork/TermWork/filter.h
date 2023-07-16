#pragma once
#include "../../structures/heap_monitor.h"

template<typename ObjectType>
class Filter
{
public:

	virtual bool pass(const ObjectType& objectType) = 0;
	virtual ~Filter() = default;

};