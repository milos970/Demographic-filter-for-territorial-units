#pragma once
#include "../../structures/heap_monitor.h"

template<typename ObjectType, typename ResultType>
class Criterion
{

public:
	virtual ResultType evaluate(ObjectType objectType) = 0;
	virtual ~Criterion() = default;
};