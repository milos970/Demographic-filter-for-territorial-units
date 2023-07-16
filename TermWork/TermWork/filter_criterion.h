#pragma once
#include "criterion.h"
#include "filter.h"
#include "../../structures/heap_monitor.h"

template<typename ObjectType, typename ValueType>
class FilterCriterion : public Filter<ObjectType>
{
private:
	Criterion<ObjectType, ValueType>* criterion_;
public:

	FilterCriterion(Criterion<ObjectType, ValueType>* criterion)
		: criterion_(criterion) {};

	~FilterCriterion();

	bool pass(const ObjectType& objectType) override;

	Criterion<ObjectType, ValueType>* getCriterion();


protected:
	virtual bool passFilter(ValueType value) = 0;


};

template<typename ObjectType, typename ValueType>
inline FilterCriterion<ObjectType, ValueType>::~FilterCriterion()
{
	delete this->criterion_;
	this->criterion_ = nullptr;
}

template<typename ObjectType, typename ValueType>
inline bool FilterCriterion<ObjectType, ValueType>::pass(const ObjectType& objectType)
{
	return passFilter(this->criterion_->evaluate(objectType));
}

template<typename ObjectType, typename ValueType>
inline Criterion<ObjectType, ValueType>* FilterCriterion<ObjectType, ValueType>::getCriterion()
{
	return this->criterion_;
}




