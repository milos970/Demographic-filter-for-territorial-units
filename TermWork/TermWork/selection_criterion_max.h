#include "selection_criterion.h"
#include "../../structures/heap_monitor.h"

template<typename KeyType, typename ObjectType, typename ValueType>

class SelectionCriterionMax : public SelectionCriterion<KeyType, ObjectType, ValueType>
{
public:
	SelectionCriterionMax(Criterion<ObjectType, ValueType>* criterion)
		: SelectionCriterion<KeyType, ObjectType, ValueType>(criterion) {};

protected:
	bool isTestedValueBetter(ValueType bestNow, ValueType bestTested) override;
};

template<typename KeyType, typename ObjectType, typename ValueType>
inline bool SelectionCriterionMax<KeyType, ObjectType, ValueType>::isTestedValueBetter(ValueType bestNow, ValueType bestTested)
{
	
		return bestTested > bestNow;
}
