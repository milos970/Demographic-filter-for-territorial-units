#pragma once

#include "priority_queue_list.h"
#include "../list/array_list.h"
#include "../utils.h"
#include <stdexcept>
#include "../../structures/heap_monitor.h"

namespace structures
{
	/// <summary> Prioritny front implementovany haldou. Implementujucim typom haldy je struktura ArrayList. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v prioritnom fronte. </typepram>
	template<typename T>
	class Heap : public PriorityQueueList<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		Heap();

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> Halda, z ktorej sa prevezmu vlastnosti. </param>
		Heap(Heap<T>& other);

		/// <summary> Priradenie struktury. </summary>
		/// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
		Structure& assign(Structure& other) override;

		/// <summary> Vlozi prvok s danou prioritou do haldy. </summary>
		/// <param name = "priority"> Priorita vkladaneho prvku. </param>
		/// <param name = "data"> Vkladany prvok. </param>
		void push(int priority, const T& data) override;

		/// <summary> Odstrani prvok s najvacsou prioritou z haldy. </summary>
		/// <returns> Odstraneny prvok. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je halda prazdna. </exception>
		T pop() override;

	public:
		/// <summary> Vrati index v ArrayList-e, na ktorom sa nachadza prvok s najvacsou prioritou. </summary>
		/// <returns> Index prvku s najvacsou prioritou. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je ArrayList prazdny. </exception>
		int indexOfPeek() override;

	private:
		/// <summary> Vrati index v ArrayList-e, na ktorom by sa mal nachadzat otec daneho prvku. </summary>
		/// <param name = "index"> Index prvku, ktoreho otca chceme vratit. </param>
		/// <returns> Index, na ktorom ba sa mal nachadzat otec prvku. </returns>
		int getParentIndex(int index);

		/// <summary> Vrati index v ArrayList-e, na ktorom by mal mat dany prvok syna s najvacsou prioritou. </summary>
		/// <param name = "index"> Index prvku, ktoreho syna chceme vratit. </param>
		/// <returns> Index, na ktorom by sa mal nachadzat syn prvku. </returns>
		int getGreaterSonIndex(int index);
	};

	template<typename T>
	Heap<T>::Heap() :
		PriorityQueueList<T>(new ArrayList<PriorityQueueItem<T>*>())
	{
	}

	template<typename T>
	Heap<T>::Heap(Heap<T>& other) :
		Heap<T>()
	{
		assign(other);
	}

	template<typename T>
	inline Structure& Heap<T>::assign(Structure& other)
	{
		if (this != &other) 
		{
			Heap<T>& otherHeap = dynamic_cast<Heap<T>&>(other);
			PriorityQueueList<T>::assign(otherHeap);
		}

		return *this;
	}

	template<typename T>
	void Heap<T>::push(int priority, const T& data)
	{
		
		this->list_->add(new PriorityQueueItem<T>(priority, data));

		if (this->list_->size() != 1)  // if heap already contains at least 2 elements
		{
			int index = this->list_->size() - 1; // index of inserted element

			PriorityQueueItem<T>* father = this->list_->at(this->getParentIndex(index)); // father of insertedElement
			PriorityQueueItem<T>* child = this->list_->at(index); // inserted element

			
			while (father->getPriority() > child->getPriority())
			{
				Utils::swap(this->list_->at(this->getParentIndex(index)), this->list_->at(index));
				child = this->list_->at(this->getParentIndex(index));
				index = this->list_->getIndexOf(child);
				father = this->list_->at(this->getParentIndex(index));
			}
		}
		
	}

	template<typename T>
	T Heap<T>::pop()
	{
		
		if ( this->list_->size() == 0 ) 
		{
			throw std::logic_error("Heap<T>::pop: Heap is empty!");
		}

		PriorityQueueItem<T>* root;
		T data;

		if ( this->list_->size() == 1 ) 
		{
			root = this->list_->removeAt(0);

			data = root->accessData();
			delete root;
			return data;
		}

		
		
		
		int rootNodeIndex = 0;
		int lastNodeIndex = this->list_->size() - 1;
		
		Utils::swap(this->list_->at(rootNodeIndex), this->list_->at(lastNodeIndex) );

		
		

		root = this->list_->removeAt(lastNodeIndex);
		
		

		int greaterSon;

		while (true) 
		{
			greaterSon = this->getGreaterSonIndex(rootNodeIndex);

			if (greaterSon >= this->list_->size()) {
				break;
			}

			if (this->list_->at(rootNodeIndex)->getPriority() > this->list_->at(greaterSon)->getPriority())
			{
				
				Utils::swap(this->list_->at(rootNodeIndex), this->list_->at(greaterSon)); 
				rootNodeIndex = greaterSon;
				continue;
			}
			break;
			
		}
		
		
		
		data = root->accessData();
		delete root;
		return data;
		
	}


	template<typename T>
	inline int Heap<T>::getParentIndex(int index)
	{
		return (index - 1) / 2;
	}

	template<typename T>
	inline int Heap<T>::getGreaterSonIndex(int index)
	{
		if (this->list_->size() > ( (index * 2) + 2)) // if there is right son so there is left son too
		{
			PriorityQueueItem<T>* leftSon = this->list_->at( (index * 2) + 1);
			PriorityQueueItem<T>* rightSon = this->list_->at( (index * 2) + 2);

			if (leftSon->getPriority() < rightSon->getPriority())
			{
				return (index * 2) + 1;
			}

			return (index * 2) + 2;
		}

		return (index * 2) + 1;
		
	}

	template<typename T>
	inline int Heap<T>::indexOfPeek()
	{
		if ( this->size() == 0 ) 
		{
			throw std::logic_error( "Heap<T>::indexOfPeek: Heap is empty!" );
		}
		
		return 0;
	}
}