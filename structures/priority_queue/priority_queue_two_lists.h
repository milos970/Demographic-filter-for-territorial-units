#pragma once

#include "priority_queue.h"
#include "priority_queue_limited_sorted_array_list.h"
#include "../list/linked_list.h"
#include <cmath>
#include "../../structures/priority_queue/heap.h"
#include "../../structures/heap_monitor.h"

namespace structures
{
	/// <summary> Prioritny front implementovany dvojzoznamom. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v prioritnom fronte. </typepram>
	/// <remarks> Implementacia efektivne vyuziva prioritny front implementovany utriednym ArrayList-om s obmedzenou kapacitou a LinkedList. </remarks>
	template<typename T>
	class PriorityQueueTwoLists : public PriorityQueue<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		PriorityQueueTwoLists();

		PriorityQueueTwoLists(PriorityQueueTwoLists<T>& other);
		~PriorityQueueTwoLists();

		/// <summary> Priradenie struktury. </summary>
		/// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
		Structure& assign(Structure& other) override;

		/// <summary> Vrati pocet prvkov v prioritnom fronte implementovanom dvojzoznamom. </summary>
		/// <returns> Pocet prvkov v prioritnom fronte implementovanom dvojzoznamom. </returns>
		size_t size() override;

		/// <summary> Vymaze obsah prioritneho frontu implementovaneho dvojzoznamom. </summary>
		void clear() override;

		/// <summary> Vlozi prvok s danou prioritou do prioritneho frontu. </summary>
		/// <param name = "priority"> Priorita vkladaneho prvku. </param>
		/// <param name = "data"> Vkladany prvok. </param>
		void push(int priority, const T& data) override;

		/// <summary> Odstrani prvok s najvacsou prioritou z prioritneho frontu implementovaneho dvojzoznamom. </summary>
		/// <returns> Odstraneny prvok. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je prioritny front implementovany dvojzoznamom prazdny. </exception>
		T pop() override;

		/// <summary> Vrati adresou prvok s najvacsou prioritou. </summary>
		/// <returns> Adresa, na ktorej sa nachadza prvok s najvacsou prioritou. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je prioritny front implementovany dvojzoznamom prazdny. </exception>
		T& peek() override;

		/// <summary> Vrati prioritu prvku s najvacsou prioritou. </summary>
		/// <returns> Priorita prvku s najvacsou prioritou. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je prioritny front implementovany dvojzoznamom prazdny. </exception>
		int peekPriority() override;

	private:
		/// <summary> Smernik na prioritny front ako implementovany utriednym ArrayList-om s obmedzenou kapacitou . </summary>
		/// <remarks> Z pohladu dvojzoznamu sa jedna o kratsi utriedeny zoznam. </remarks>
		PriorityQueueLimitedSortedArrayList<T>* shortList_;

		/// <summary> Smernik na dlhsi neutriedeny zoznam. </summary>
		LinkedList<PriorityQueueItem<T>*>* longList_;
	};

	template<typename T>
	PriorityQueueTwoLists<T>::PriorityQueueTwoLists() :
		shortList_(new PriorityQueueLimitedSortedArrayList<T>()),
		longList_(new LinkedList<PriorityQueueItem<T>*>())
	{
	}

	template<typename T>
	PriorityQueueTwoLists<T>::PriorityQueueTwoLists(PriorityQueueTwoLists<T>& other) :
		PriorityQueueTwoLists<T>()
	{
		assign(other);
	}

	template<typename T>
	PriorityQueueTwoLists<T>::~PriorityQueueTwoLists()
	{
		this->clear();

		delete this->shortList_;
		delete this->longList_;

		this->shortList_ = nullptr;
		this->longList_ = nullptr;
	}

	template<typename T>
	Structure& PriorityQueueTwoLists<T>::assign(Structure& other)
	{
		if (this != &other) 
		{
			PriorityQueueTwoLists<T>& otherQ = dynamic_cast<PriorityQueueTwoLists<T>&>(other);
			this->clear();
			
			
			this->shortList_->assign(*(otherQ.shortList_));
			

			for (PriorityQueueItem<T>* item : *(otherQ.longList_))
			{
				this->longList_->add(new PriorityQueueItem<T>(item->getPriority(), item->accessData()));
			}
			
		}
		
		return *this;
	}

	template<typename T>
	size_t PriorityQueueTwoLists<T>::size()
	{
		return this->shortList_->size() + this->longList_->size();
	}

	template<typename T>
	void PriorityQueueTwoLists<T>::clear()
	{
		this->shortList_->clear();
		
		for (PriorityQueueItem<T>* item : *this->longList_)
		{
			delete item;
		}
	    
		this->longList_->clear();
	
	}

	template<typename T>
	void PriorityQueueTwoLists<T>::push(int priority, const T& data)
	{
		if ( this->longList_->size() == 0  || this->shortList_->minPriority() > priority )
		{
			PriorityQueueItem<T>* item = this->shortList_->pushAndRemove(priority, data);

			if (item != nullptr) 
			{
				this->longList_->add(item);
			}
			
		}
		else 
		{
			this->longList_->add(new PriorityQueueItem<T>(priority, data));
		}
		

	}

	template<typename T>
	T PriorityQueueTwoLists<T>::pop()
	{
		if ( this->shortList_->size() == 0 )
		{
			throw std::logic_error("PriorityQueueTwoLists<T>::pop: PriorityQueueTwoLists is empty!");
		}

		T data = this->shortList_->pop();
		
		if (this->shortList_->size() == 0 && this->longList_->size() != 0) 
		{
			size_t sqrt = std::sqrt(this->longList_->size());
			while ( !(this->shortList_->trySetCapacity(sqrt)) ) 
			{
				++sqrt;
			}
			
		}
		else 
		{
			return data;
		}

		PriorityQueueItem<T>* item;

		LinkedList<PriorityQueueItem<T>*>* temporaryList = new LinkedList<PriorityQueueItem<T>*>();

		
		while (this->longList_->size() != 0) 
		{
			item = this->longList_->removeAt(0);
			T priority = item->getPriority();
			T data = item->accessData();	
			delete item;
			item = this->shortList_->pushAndRemove(priority, data);

			if (item != nullptr) {
				temporaryList->add(item);
			}

		}
			

		this->longList_->assign(*temporaryList);
		delete temporaryList;
		return data;
	}

	template<typename T>
	T& PriorityQueueTwoLists<T>::peek()
	{
		if ( this->shortList_->size() == 0 )
		{
			throw std::logic_error("PriorityQueueTwoLists<T>::peek: PriorityQueueTwoLists is empty!");
		}

		return this->shortList_->maxPriorityElement();
	}

	template<typename T>
	int PriorityQueueTwoLists<T>::peekPriority()
	{
		if ( this->shortList_->size() == 0 )
		{
			throw std::logic_error("PriorityQueueTwoLists<T>::peekPriority: PriorityQueueTwoLists is empty!");
		}

		return this->shortList_->maxPriority();
	}
}