#pragma once

#include "stack.h"
#include "../list/array_list.h"

namespace structures
{
	/// <summary> Implicitny zasobn�k. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v zasobniku. </typepram>
	template<typename T>
	class ImplicitStack : public Stack<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		ImplicitStack();

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> Implicitny zasobn�k, z ktoreho sa prevezmu vlastnosti. </param>
		ImplicitStack(ImplicitStack<T>& other);

		/// <summary> Destruktor. </summary>
		~ImplicitStack();

		/// <summary> Vrati pocet prvkov v zasobniku. </summary>
		/// <returns> Pocet prvkov v zasobniku. </returns>
		size_t size() override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Zasobnik, z ktoreho ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tento zasobnik nachadza po priradeni. </returns>
		Structure& assign(Structure& other) override;

		/// <summary> Porovnanie struktur. </summary>
		/// <param name="other">Struktura, s ktorou sa ma tato struktura porovnat. </param>
		/// <returns>True ak su struktury zhodne typom aj obsahom. </returns>
		bool equals(Structure& other) override;

		/// <summary> Vymaze zasobnik. </summary>
		void clear() override;

		/// <summary> Prida prvok do zasobnika. </summary>
		/// <param name = "data"> Pridavany prvok. </param>
		void push(const T& data) override;

		/// <summary> Odstrani prvok na vrchole zasobnika. </summary>
		/// <returns> Prvok na vrchole zasobnika. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak je zasobnik prazdny. </exception>
		T pop() override;

		/// <summary> Vrati prvok na vrchole zasobnika. </summary>
		/// <returns> Prvok na vrchole zasobnika. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak je zasobnik prazdny. </exception>
		T& peek() override;

	protected:
		/// <summary> Zoznam, pomocou ktoreho je implementovany zasobnik. </summary>
		ArrayList<T>* list_;
	};

	template<typename T>
	ImplicitStack<T>::ImplicitStack() :
		Stack<T>(),
		list_(new ArrayList<T>())
	{
	}

	template<typename T>
	ImplicitStack<T>::ImplicitStack(ImplicitStack<T>& other) :
		ImplicitStack()
	{
		assign(other);
	}

	template<typename T>
	ImplicitStack<T>::~ImplicitStack()
	{
		delete this->list_;
		this->list_ = nullptr;
	}

	template<typename T>
	inline Structure& ImplicitStack<T>::assign(Structure& other)
	{
		ImplicitStack<T>* otherStack = dynamic_cast<ImplicitStack<T>*>(&other);
		this->list_->assign(*otherStack->list_);
		return *this;
	}

	template<typename T>
	inline bool ImplicitStack<T>::equals(Structure& other)
	{
		//TODO 10: BinarySearchTree
		throw std::runtime_error("BinarySearchTree<K, T>::size: Not implemented yet.");
	}

	template<typename T>
	size_t ImplicitStack<T>::size()
	{
		return this->list_->size();
	}

	template<typename T>
	inline void ImplicitStack<T>::clear()
	{
		this->list_->clear();
	}

	template<typename T>
	inline void ImplicitStack<T>::push(const T& data)
	{
		this->list_->add(data);
	}

	template<typename T>
	inline T ImplicitStack<T>::pop()
	{
		return this->list_->removeAt(this->list_->size() - 1);
	}

	template<typename T>
	inline T& ImplicitStack<T>::peek()
	{
		return   (*list_)[list_->size() - 1];
	}
}