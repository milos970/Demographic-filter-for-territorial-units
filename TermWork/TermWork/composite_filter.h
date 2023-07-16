#pragma once
#include "../../structures/heap_monitor.h"
#include "../../structures/list/array_list.h"
#include "filter.h"

template<typename ObjectType>
class CompositeFilter : public Filter<ObjectType>
{
protected:
	structures::List<Filter<ObjectType>*>* filters_ = new structures::ArrayList<Filter<ObjectType>*>();
public:
	void registerFilter(Filter<ObjectType>* filter);

	~CompositeFilter() 
	{
		
		delete filters_;
	}

};


template<typename ObjectType>
inline void CompositeFilter<ObjectType>::registerFilter(Filter<ObjectType>* filter)
{
	this->filters_->add(filter);
}
