#pragma once

#include "list.h"
#include "linked_list.h"
#include "../data_item.h"
#include "../../structures/heap_monitor.h"
#include "../structure_iterator.h"

namespace structures
{
	// implementacne tipy: 
	//  - namiesto triedy List<T> mozete v triede DoubleLinkedList<T> 
	//    zdedit jednostranne zretazeny zoznam (LinkedList<T>).
	//    ak tak urobite, mozete mnoho metod odstranit a prekryt iba tie, 
	//    ktore maju z pohladu obojsmerne zretazeneho zoznamu vyznam a
	//    zvysok nechat na predka.
	//  - nezabudnite si vytvorit triedu pre prvok obojstranne zretazeneho zoznamu.
	//    opat tento prvok mozete zdedit z prvku jednostranne zretazeneho zoznamu.
	//  - ak vyuzijete dedicnost, budete moct vyuzit predkove iteratory, 
	//    takze ich nebudete musiet implementovat.

	template<typename T>
	class DoubleLinkedListItem : public DataItem<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		/// <param name = "data"> Data, ktore uchovava. </param>
		DoubleLinkedListItem(T data);

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> Prvok jednstranne zretazeneho zoznamu, z ktoreho sa prevezmu vlastnosti.. </param>
		DoubleLinkedListItem(DoubleLinkedListItem<T>& other);

		/// <summary> Destruktor. </summary>
		~DoubleLinkedListItem();

		/// <summary> Getter nasledujuceho prvku zretazeneho zoznamu. </summary>
		/// <returns> Nasledujuci prvok zretazeneho zoznamu. </returns>
		DoubleLinkedListItem<T>* getPrevious();

		/// <summary> Setter nasledujuceho prvku zretazeneho zoznamu. </summary>
		/// <param name´= "next"> Novy nasledujuci prvok zretazeneho zoznamu. </param>
		void setPrevious(DoubleLinkedListItem<T>* previous);

		/// <summary> Getter nasledujuceho prvku zretazeneho zoznamu. </summary>
		/// <returns> Nasledujuci prvok zretazeneho zoznamu. </returns>
		DoubleLinkedListItem<T>* getNext();

		/// <summary> Setter nasledujuceho prvku zretazeneho zoznamu. </summary>
		/// <param name´= "next"> Novy nasledujuci prvok zretazeneho zoznamu. </param>
		void setNext(DoubleLinkedListItem<T>* previous);

	private:
		/// <summary> Nasledujuci prvok zretazeneho zoznamu. </summary>
		DoubleLinkedListItem<T>* next_;
		/// <summary> Predchadzajuci prvok zretazeneho zoznamu. </summary>
		DoubleLinkedListItem<T>* previous_;
	};





	/// <summary> Obojstranne zretazeny zoznam. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v zozname. </typepram>
	template<typename T>
	class DoubleLinkedList : public List<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		DoubleLinkedList();

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> DoubleLinkedList, z ktoreho sa prevezmu vlastnosti. </param>
		DoubleLinkedList(DoubleLinkedList<T>& other);

		/// <summary> Destruktor. </summary>
		~DoubleLinkedList();

		/// <summary> Vrati pocet prvkov v zozname. </summary>
		/// <returns> Pocet prvkov v zozname. </returns>
		size_t size() override;

		/// <summary> Priradenie struktury. </summary>
		/// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
		Structure& assign(Structure& other) override;

		/// <summary> Porovnanie struktur. </summary>
		/// <param name="other">Struktura, s ktorou sa ma tato struktura porovnat. </param>
		/// <returns>True ak su struktury zhodne typom aj obsahom. </returns>
		bool equals(Structure& other) override;

		/// <summary> Vrati adresou prvok na indexe. </summary>
		/// <param name = "index"> Index prvku. </param>
		/// <returns> Adresa prvku na danom indexe. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
		T& at(int index) override;

		/// <summary> Prida prvok do zoznamu. </summary>
		/// <param name = "data"> Pridavany prvok. </param>
		void add(const T& data) override;

		/// <summary> Vlozi prvok do zoznamu na dany index. </summary>
		/// <param name = "data"> Pridavany prvok. </param>
		/// <param name = "index"> Index prvku. </param>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
		/// <remarks> Ak je ako index zadana hodnota poctu prvkov (teda prvy neplatny index), metoda insert sa sprava ako metoda add. </remarks>
		void insert(const T& data, int index) override;

		/// <summary> Odstrani prvy vyskyt prvku zo zoznamu. </summary>
		/// <param name = "data"> Odstranovany prvok. </param>
		/// <returns> true, ak sa podarilo prvok zo zoznamu odobrat, false inak. </returns>
		bool tryRemove(const T& data) override;

		/// <summary> Odstrani zo zoznamu prvok na danom indexe. </summary>
		/// <param name = "index"> Index prvku. </param>
		/// <returns> Odstraneny prvok. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
		T removeAt(int index) override;

		/// <summary> Vrati index prveho vyskytu prvku v zozname. </summary>
		/// <param name = "data"> Prvok, ktoreho index sa hlada. </param>
		/// <returns> Index prveho vyskytu prvku v zozname, ak sa prvok v zozname nenachadza, vrati -1. </returns>
		int getIndexOf(const T& data) override;

		/// <summary> Vymaze zoznam. </summary>
		void clear() override;

		/// <summary> Vrati skutocny iterator na zaciatok struktury </summary>
		/// <returns> Iterator na zaciatok struktury. </returns>
		/// <remarks> Zabezpecuje polymorfizmus. </remarks>
		Iterator<T>* getBeginIterator() override;

		/// <summary> Vrati skutocny iterator na koniec struktury </summary>
		/// <returns> Iterator na koniec struktury. </returns>
		/// <remarks> Zabezpecuje polymorfizmus. </remarks>
		Iterator<T>* getEndIterator() override;
	private:
		/// <summary> Pocet prvkov v zozname. </summary>
		size_t size_;
		/// <summary> Prvy prvok zoznamu. </summary>
		DoubleLinkedListItem<T>* first_;
		/// <summary> Posledny prvok zoznamu. </summary>
		DoubleLinkedListItem<T>* last_;
		/// <summary> Vrati prvok zoznamu na danom indexe. </summary>
		/// <param name = "index"> Pozadovany index. </summary>
		/// <returns> Prvok zoznamu na danom indexe. </param>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
		DoubleLinkedListItem<T>* getItemAtIndex(int index);

		/// <summary> Iterator pre LinkedList. </summary>
		class DoubleLinkedListIterator : public Iterator<T>
		{
		public:
			/// <summary> Konstruktor. </summary>
			/// <param name = "position"> Pozicia v zretazenom zozname, na ktorej zacina. </param>
			DoubleLinkedListIterator(DoubleLinkedListItem<T>* position);

			/// <summary> Destruktor. </summary>
			~DoubleLinkedListIterator();

			/// <summary> Operator priradenia. Priradi do seba hodnotu druheho iteratora. </summary>
			/// <param name = "other"> Druhy iterator. </param>
			/// <returns> Vrati seba po priradeni. </returns>
			Iterator<T>& operator= (Iterator<T>& other) override;

			/// <summary> Porovna sa s druhym iteratorom na nerovnost. </summary>
			/// <param name = "other"> Druhy iterator. </param>
			/// <returns> True, ak sa iteratory nerovnaju, false inak. </returns>
			bool operator!=(Iterator<T>& other) override;

			/// <summary> Vrati data, na ktore aktualne ukazuje iterator. </summary>
			/// <returns> Data, na ktore aktualne ukazuje iterator. </returns>
			T operator*() override;

			/// <summary> Posunie iterator na dalsi prvok v strukture. </summary>
			/// <returns> Iterator na dalsi prvok v strukture. </returns>
			/// <remarks> Zvycajne vrati seba. Ak vrati iny iterator, povodny bude automaticky zruseny. </remarks>
			Iterator<T>& operator++() override;

		private:
			/// <summary> Aktualna pozicia v zozname. </summary>
			DoubleLinkedListItem<T>* position_;
		};
	};

	template<typename T>
	inline DoubleLinkedList<T>::DoubleLinkedList()
		: size_(0), first_(nullptr), last_(nullptr)
	{

	}

	template<typename T>
	inline DoubleLinkedList<T>::DoubleLinkedList(DoubleLinkedList<T>& other) : DoubleLinkedList<T>()
	{
		this->assign(other);
	}

	template<typename T>
	inline DoubleLinkedList<T>::~DoubleLinkedList()
	{
		this->clear();

	}

	template<typename T>
	inline size_t DoubleLinkedList<T>::size()
	{
		return this->size_;
	}

	template<typename T>
	inline Structure& DoubleLinkedList<T>::assign(Structure& other)
	{
		if (this != &other) {
			DoubleLinkedList<T>& otherList = dynamic_cast<DoubleLinkedList<T>&>(other);
			this->clear();

			for (T data : otherList) {
				DoubleLinkedList<T>::add(data);
			}
		}
		return *this;
	}

	template<typename T>
	inline bool DoubleLinkedList<T>::equals(Structure& other)
	{
		if (this == &other) {
			return true;
		}

		DoubleLinkedList<T>* otherList = dynamic_cast<DoubleLinkedList<T>*>(&other);

		if (otherList == nullptr)
		{
			return false;
		}

		if (size_ != other.size())
		{
			return false;
		}

		auto thisIterator = this->begin();
		auto otherIterator = otherList->begin();

		for (int i = 0; i < size_; ++i)
		{
			if (*thisIterator != *otherIterator)
			{
				return false;
			}
			++thisIterator;
			++otherIterator;
		}
		return true;
	}

	template<typename T>
	inline T& DoubleLinkedList<T>::at(int index)
	{
		Utils::rangeCheckExcept(index, size_, "Invalid index!");
		return this->getItemAtIndex(index)->accessData();
	}

	template<typename T>
	inline void DoubleLinkedList<T>::add(const T& data)
	{
		DoubleLinkedListItem<T>* newItem = new DoubleLinkedListItem<T>(data);

		if (size_ == 0)
		{
			first_ = newItem;
			last_ = newItem;
		}
		else
		{
			newItem->setPrevious(last_);
			last_->setNext(newItem);
			last_ = newItem;
		}
		++size_;

	}

	template<typename T>
	inline void DoubleLinkedList<T>::insert(const T& data, int index)
	{
		if (index == size_)
		{
			add(data);
		}
		else
		{
			Utils::rangeCheckExcept(index, size_, "Invalid index!");

			DoubleLinkedListItem<T>* newItem = new DoubleLinkedListItem<T>(data);
			if (index == 0)
			{
				newItem->setNext(first_);

				first_->setPrevious(newItem);

				first_ = newItem;
			}
			else
			{

				DoubleLinkedListItem<T>* prevItem = this->getItemAtIndex(index - 1);

				newItem->setNext(prevItem->getNext());
				newItem->setPrevious(prevItem);
				newItem->getNext()->setPrevious(newItem);
				prevItem->setNext(newItem);

			}
			++size_;
		}

	}

	template<typename T>
	inline bool DoubleLinkedList<T>::tryRemove(const T& data)
	{
		int index = this->getIndexOf(data);
		if (index != -1) {
			this->removeAt(index);
			return true;
		}

		return false;
	}

	template<typename T>
	inline T DoubleLinkedList<T>::removeAt(int index)
	{
		Utils::rangeCheckExcept(index, size_, "Invalid index!");

		DoubleLinkedListItem<T>* deletedItem;

		if (size_ == 1)
		{
			deletedItem = first_;
			first_ = nullptr;
			last_ = nullptr;
		}
		else {

			if (index == 0)
			{
				deletedItem = first_;
				first_ = first_->getNext();
				first_->setPrevious(nullptr);

			}
			else {

				deletedItem = this->getItemAtIndex(index);

				if (deletedItem == last_) {
					last_ = deletedItem->getPrevious();
					last_->setNext(nullptr);
				}
				else {
					deletedItem->getPrevious()->setNext(deletedItem->getNext());
					deletedItem->getNext()->setPrevious(deletedItem->getPrevious());
				}

				/*DoubleLinkedListItem<T>* prevItem = this->getItemAtIndex(index - 1);
				deletedItem = prevItem->getNext();
				if (deletedItem == last_) {
					last_ = prevItem;
					last_->setNext(nullptr);
				}
				else {
					prevItem->setNext(deletedItem->getNext());
					deletedItem->getNext()->setPrevious(prevItem);
				}*/

			}
		}

		--size_;
		T data = deletedItem->accessData();
		delete deletedItem;
		return data;
	}

	template<typename T>
	inline int DoubleLinkedList<T>::getIndexOf(const T& data)
	{
		int index = 0;
		for (T element : *this)
		{
			if (element == data)
			{
				return index;
			}
			++index;
		}
		return -1;
	}

	template<typename T>
	inline void DoubleLinkedList<T>::clear()
	{
		DoubleLinkedListItem<T>* item = first_;

		while (item != nullptr)
		{
			DoubleLinkedListItem<T>* next = item->getNext();
			delete item;
			item = next;
		}
		size_ = 0;
		first_ = nullptr;
		last_ = nullptr;
	}

	template<typename T>
	inline Iterator<T>* DoubleLinkedList<T>::getBeginIterator()
	{
		return new DoubleLinkedListIterator(first_);
	}

	template<typename T>
	inline Iterator<T>* DoubleLinkedList<T>::getEndIterator()
	{
		return new DoubleLinkedListIterator(nullptr);
	}

	template<typename T>
	inline DoubleLinkedListItem<T>* DoubleLinkedList<T>::getItemAtIndex(int index)
	{
		DoubleLinkedListItem<T>* item = first_;
		for (int i = 0; i < index; ++i) {

			item = item->getNext();
		}

		return item;
	}








	template<typename T>
	inline DoubleLinkedListItem<T>::DoubleLinkedListItem(T data)
		: DataItem<T>(data), next_(nullptr), previous_(nullptr)
	{

	}

	template<typename T>
	inline DoubleLinkedListItem<T>::DoubleLinkedListItem(DoubleLinkedListItem<T>& other)
		: LinkedListItem<T>(other), next_(other.next_), previous_(other.previous_)
	{

	}

	template<typename T>
	inline DoubleLinkedListItem<T>::~DoubleLinkedListItem()
	{
		next_ = nullptr;
		previous_ = nullptr;
	}

	template<typename T>
	inline DoubleLinkedListItem<T>* DoubleLinkedListItem<T>::getPrevious()
	{
		return previous_;
	}

	template<typename T>
	inline void DoubleLinkedListItem<T>::setPrevious(DoubleLinkedListItem<T>* previous)
	{
		this->previous_ = previous;
	}

	template<typename T>
	inline DoubleLinkedListItem<T>* DoubleLinkedListItem<T>::getNext()
	{

		return next_;
	}

	template<typename T>
	inline void DoubleLinkedListItem<T>::setNext(DoubleLinkedListItem<T>* next)
	{
		this->next_ = next;
	}

	template<typename T>
	inline DoubleLinkedList<T>::DoubleLinkedListIterator::DoubleLinkedListIterator(DoubleLinkedListItem<T>* position)
		: position_(position)
	{
	}

	template<typename T>
	inline DoubleLinkedList<T>::DoubleLinkedListIterator::~DoubleLinkedListIterator()
	{
		this->position_ = nullptr;
	}

	template<typename T>
	inline Iterator<T>& DoubleLinkedList<T>::DoubleLinkedListIterator::operator=(Iterator<T>& other)
	{
		position_ = dynamic_cast<DoubleLinkedListIterator&>(other).position_;
		return *this;
	}

	template<typename T>
	inline bool DoubleLinkedList<T>::DoubleLinkedListIterator::operator!=(Iterator<T>& other)
	{
		return position_ != dynamic_cast<DoubleLinkedListIterator&>(other).position_;
	}

	template<typename T>
	inline T DoubleLinkedList<T>::DoubleLinkedListIterator::operator*()
	{
		return position_->accessData();
	}

	template<typename T>
	inline Iterator<T>& DoubleLinkedList<T>::DoubleLinkedListIterator::operator++()
	{
		position_ = position_->getNext();
		return *this;
	}


}