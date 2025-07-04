#pragma once

#include "queue.h"
#include "../../structures/array/array.h"

#include <stdexcept>

namespace structures
{
	/// <summary> Implicitny front. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych vo fronte. </typepram>
	template<typename T>
	class ImplicitQueue : public Queue<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		ImplicitQueue();

		/// <summary> Parametricky konstruktor. </summary>
		/// <param name = "capacity"> Maximalna velkost frontu. </param>
		ImplicitQueue(size_t capacity);

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> Implicitny front, z ktoreho sa prevezmu vlastnosti. </param>
		ImplicitQueue(ImplicitQueue<T>& other);

		/// <summary> Destruktor. </summary>
		~ImplicitQueue();

		/// <summary> Vrati pocet prvkov vo fronte. </summary>
		/// <returns> Pocet prvkov vo fronte. </returns>
		size_t size() override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Front, z ktoreho ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tento front nachadza po priradeni. </returns>
		Structure& assign(Structure& other) override;

		/// <summary> Porovnanie struktur. </summary>
		/// <param name="other">Struktura, s ktorou sa ma tato struktura porovnat. </param>
		/// <returns>True ak su struktury zhodne typom aj obsahom. </returns>
		bool equals(Structure& other) override;

		/// <summary> Vymaze front. </summary>
		void clear() override;

		/// <summary> Prida prvok do frontu. </summary>
		/// <param name = "data"> Pridavany prvok. </param>
		/// <exception cref="std::out_of_range"> Vyhodena, ak je front plny. </exception>
		void push(const T& data) override;

		/// <summary> Odstrani prvok z frontu. </summary>
		/// <returns> Prvok na zaciatku frontu. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak je front prazdny. </exception>
		T pop() override;

		/// <summary> Vrati prvok na zaciatku frontu. </summary>
		/// <returns> Prvok na zaciatku frontu. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak je front prazdny. </exception>
		T& peek() override;

	protected:
		/// <summary> Pole, pomocou ktoreho je implementovany front. </summary>
		Array<T>* array_;

		/// <summary> Index prveho prvku vo fronte. </summary>
		int startIndex_;

		/// <summary> Pocet prvkov vo fronte. </summary>
		size_t size_;
	};

	template<typename T>
	ImplicitQueue<T>::ImplicitQueue() :
		ImplicitQueue(10)
	{
	}

	template<typename T>
	ImplicitQueue<T>::ImplicitQueue(size_t capacity) :
		Queue<T>(),
		array_(new Array<T>(capacity)),
		startIndex_(0),
		size_(0)
	{
	}

	template<typename T>
	ImplicitQueue<T>::ImplicitQueue(ImplicitQueue<T>& other) :
		Queue<T>(other),
		array_(new Array<T>(*other.array_)),
		startIndex_(other.startIndex_),
		size_(other.size_)
	{
	}

	template<typename T>
	ImplicitQueue<T>::~ImplicitQueue()
	{
		delete this->array_;
		this->array_ = nullptr;
	}

	template<typename T>
	inline Structure& ImplicitQueue<T>::assign(Structure& other)
	{
		//TODO 05: ImplicitQueue
		throw std::runtime_error("ImplicitQueue<T>::assign: Not implemented yet.");
	}

	template<typename T>
	size_t ImplicitQueue<T>::size()
	{
		return this->array_->size();
	}

	template<typename T>
	inline bool ImplicitQueue<T>::equals(Structure& other)
	{
		//TODO 05: ImplicitQueue
		throw std::runtime_error("ImplicitQueue<T>::clear: Not implemented yet.");
	}

	template<typename T>
	inline void ImplicitQueue<T>::clear()
	{
		//TODO 05: ImplicitQueue
		throw std::runtime_error("ImplicitQueue<T>::clear: Not implemented yet.");
	}

	template<typename T>
	inline void ImplicitQueue<T>::push(const T& data)
	{
		if (this->size_ >= this->array_->size()) {
			throw std::out_of_range("ImplicitQueue<T>::push: ImplicitQueue is full.");
		}
		this->array_->at(static_cast<int>((this->startIndex_ + this->size_) % this->size_)) = data;
		this->size_++;
		
	}

	template<typename T>
	inline T ImplicitQueue<T>::pop()
	{
		if (this->size_ == 0) {
			throw std::runtime_error("ImplicitQueue<T>::peek: Front is empty!");
		}
		T item = this->array_->at(this->startIndex_);
		this->startIndex_ = (this->startIndex_ + 1) % this->array_->size();
		this->size_--;
		
		return item;
	}

	template<typename T>
	inline T& ImplicitQueue<T>::peek()
	{
		if (this->size_ == 0) {
			throw std::runtime_error("ImplicitQueue<T>::peek: Front is empty!");
		}
		return (*array_)[this->startIndex_];
	}
}