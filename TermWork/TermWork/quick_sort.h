#pragma once

#include "sort.h"
#include "criterion.h"
#include "../../structures/heap_monitor.h"

namespace structures
{

	/// <summary> Triedenie Quick sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T, typename R>
	class QuickSort : public Sort<K, T, R>
	{
	public:
		/// <summary> Utriedi tabulku triedenim Quick sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table) override;
		void sort(UnsortedSequenceTable<K, T>& table, CriterionTerritorialUnit<R>* criterion, unsigned int ascendingOrder) override;
	private:
		void quick(int start, int end, UnsortedSequenceTable<K, T>& table); 
		void quick(int start, int end, UnsortedSequenceTable<K, T>& table, CriterionTerritorialUnit<R>* criterion, unsigned int ascendingOrder);
	};

	template<typename K, typename T, typename R>
	inline void QuickSort<K, T, R>::sort(UnsortedSequenceTable<K, T>& table)
	{
		quick(0, table.size() - 1, table);
	}

	template<typename K, typename T, typename R>
	inline void QuickSort<K, T, R>::sort(UnsortedSequenceTable<K, T>& table, CriterionTerritorialUnit<R>* criterion, unsigned int ascendingOrder)
	{
		quick(0, table.size() - 1, table, criterion, ascendingOrder);
	}

	



	template<typename K, typename T, typename R>
	inline void QuickSort<K, T, R>::quick(int start, int end, UnsortedSequenceTable<K, T>& table)
	{
		K pivot = table.getItemAtIndex((start + end) / 2).getKey();
		int left = start;
		int right = end;

		do
		{
			while (table.getItemAtIndex(left).getKey() < pivot)
			{
				++left;
			}
			while (table.getItemAtIndex(right).getKey() > pivot)
			{
				--right;
			}

			if (left <= right)
			{
				table.swap(left, right);
				++left;
				--right;
				
			}

		} while (left <= right);

		if (start < right)
		{
			quick(start, right, table);
		}

		if (left < end)
		{
			quick(left, end, table);
		}

		


	}




	template<typename K, typename T, typename R>
	inline void QuickSort<K, T, R>::quick(int start, int end, UnsortedSequenceTable<K, T>& table, CriterionTerritorialUnit<R>* criterion, unsigned int ascendingOrder)
	{	
		T object = table.getItemAtIndex((start + end) / 2).accessData();

		R pivot = criterion->evaluate(object);
		int left = start;
		int right = end;

		do
		{
			if (ascendingOrder == 1 )
			{
				while (criterion->evaluate(table.getItemAtIndex(left).accessData()) < pivot)
				{
					++left;
				}
				while (criterion->evaluate(table.getItemAtIndex(right).accessData()) > pivot)
				{

					--right;
				}
			}
			
			if (ascendingOrder == 2)
			{
				while (criterion->evaluate(table.getItemAtIndex(left).accessData()) > pivot)
				{
					++left;
				}
				while (criterion->evaluate(table.getItemAtIndex(right).accessData()) < pivot)
				{

					--right;
				}
			}
			


			if (left <= right)
			{
				table.swap(left, right);
				++left;
				--right;
				
			}

		} while (left <= right);

		if (start < right)
		{
			quick(start, right, table, criterion, ascendingOrder);
		}

		if (left < end)
		{
			quick(left, end, table, criterion, ascendingOrder);
		}


	}


}