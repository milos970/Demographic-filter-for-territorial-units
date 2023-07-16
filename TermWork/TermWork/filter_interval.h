#pragma once
#include "criterion.h"
#include "filter_criterion.h"
#include "../../structures/heap_monitor.h"

template<typename ObjectType, typename ValueType>
class FilterInterval : public FilterCriterion<ObjectType,ValueType>
{
private:
	ValueType minValue_;
	ValueType maxValue_;

public:
	FilterInterval(Criterion<ObjectType, ValueType>* criterion, ValueType minValue, ValueType maxValue) 
		: FilterCriterion<ObjectType, ValueType>(criterion), minValue_(minValue), maxValue_(maxValue) {};

	
protected:
	bool passFilter(ValueType value) override;
};

template<typename ObjectType, typename ValueType>
inline bool FilterInterval<ObjectType, ValueType>::passFilter(ValueType value)
{
	return (this->minValue_ <= value) && (value <= this->maxValue_);
}
