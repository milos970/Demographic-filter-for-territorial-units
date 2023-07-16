#pragma once
#include "../../structures/table/unsorted_sequence_table.h"
#include "../../structures/heap_monitor.h"
#include "criterion_territorial_unit.h"
namespace structures
{
	/// <summary> Triedenie NonortedSequenceTable navrhnuté ako funkèný objekt. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T, typename R>
	class Sort
	{
	public:
		/// <summary> Destruktor. </summary>
		virtual ~Sort();

		/// <summary> Funkcny operator utriedi tabulku. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		/// <remarks> Využíva metódu sort. </remarks>
		void operator()(UnsortedSequenceTable<K, T>& table);

		/// <summary> Utriedi utriedi tabulku. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		virtual void sort(UnsortedSequenceTable<K, T>& table) = 0;

		virtual void sort(UnsortedSequenceTable<K, T>& table, CriterionTerritorialUnit<R>* criterion, unsigned int ascendingOrder) = 0;
	};

	template<typename K, typename T, typename R>
	inline Sort<K, T, R>::~Sort()
	{
	}

	template<typename K, typename T, typename R>
	inline void Sort<K, T, R>::operator()(UnsortedSequenceTable<K, T>& table)
	{
		this->sort(table);
	}
}