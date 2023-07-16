#pragma once
#include "../../structures/heap_monitor.h"

template<typename KeyType, typename ObjectType, typename ValueType>
class SelectionCriterion
{
private:
	Criterion<ObjectType, ValueType>* criterion_;
public:
	SelectionCriterion(Criterion<ObjectType, ValueType>* criterion) : criterion_(criterion) {};

	virtual ~SelectionCriterion();

	ObjectType selectBest(structures::UnsortedSequenceTable<KeyType, ObjectType>* table);

protected:
	virtual bool isTestedValueBetter(ValueType bestNow, ValueType bestTested) = 0;
};

template<typename KeyType, typename ObjectType, typename ValueType>
inline SelectionCriterion<KeyType, ObjectType, ValueType>::~SelectionCriterion()
{
	delete this->criterion_;
}

template<typename KeyType, typename ObjectType, typename ValueType>
inline ObjectType SelectionCriterion<KeyType, ObjectType, ValueType>::selectBest(structures::UnsortedSequenceTable<KeyType, ObjectType>* table)
{
	ObjectType bestObject{};
	ObjectType testedObject = table->getItemAtIndex(0).accessData();
	ValueType testedValue = this->criterion_->evaluate(testedObject);
	ValueType bestValue = testedValue;

	for (int i = 1; i < table->size(); ++i) 
	{
		 testedObject = table->getItemAtIndex(i).accessData();
		 testedValue = this->criterion_->evaluate(testedObject);

		if (isTestedValueBetter(bestValue, testedValue))
		{
			bestValue = testedValue;
			bestObject = testedObject;
		}
	}


	return bestObject;
}
