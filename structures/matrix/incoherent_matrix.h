#pragma once

#include "matrix.h"
#include <stdexcept>
#include "../array/array.h"
#include "../../structures/heap_monitor.h"

namespace structures
{
	/// <summary> Implementacia matice v nesuvislej pamati. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v matici. </typepram>
	template<typename T>
	class IncoherentMatrix
		: public Matrix<T>
	{
	public:
		/// <summary>
		///	Konstruktor. Vytvori maticu o danom pocte riadkov a stlpcov.
		/// Polozky su inicializovane na "nulovu" hodnotu typu T.
		/// </summary>
		/// <param name="rowCount"> Pocet riadkov. </param>
		/// <param name="columnCount"> Pocet stlpcov. </param>
		IncoherentMatrix(size_t rowCount, size_t columnCount);

		/// <summary> Inicializuje tuto maticu ako kopiu matice odovzdanej ako parameter. </summary>
		/// <param name = "other"> Odkaz na maticu, z ktorej sa prevezmu vlastnosti. </param>
		IncoherentMatrix(IncoherentMatrix& other);

		/// <summary> Destruktor. </summary>
		~IncoherentMatrix();

		/// <summary>
		/// Ak je to mozne (parametrom je matica, ktora ma rovnake rozmery ako ako aktualna matica),
		/// tak skopiruje vlastnosti z matice odovzdanej ako parameter.
		/// Ak to nie je mozne, vyhodi sa vynimka.
		/// </summary>
		/// <param name = "other"> Odkaz na strukturu, z ktorej maju prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
		Structure& assign(Structure& other) override;

		/// <summary>
		/// Ak je parametrom matica a obsah porovnavanych matic je rovnaky,
		/// tak vrati hodnotu true. V opacnom pripade vrati hodnotu false.
		/// </summary>
		/// <param name="other"> Odkaz na strukturu, s ktorou sa ma tato matica porovnat. </param>
		/// <returns>True ak su struktury zhodne typom aj obsahom. </returns>
		bool equals(Structure& other) override;

		/// <summary> Pocet vsetkych prvkov v matici. </summary>
		/// <returns> Pocet prvkov v matici. </returns>
		size_t size() override;

		/// <summary> Vrati pocet riadkov v matici. </summary>
		/// <returns> Pocet riadkov matice. </returns>
		size_t getRowCount() override;

		/// <summary> Vrati pocet stlpcov matice. </summary>
		/// <returns> Pocet stlpcov matice. </returns>
		size_t getColumnCount() override;

		/// <summary> Vrati odkaz na prvok v danom riadku a stlpci. </summary>
		/// <param name="rowIndex"> Index riadku. </param>
		/// <param name="columnIndex"> Index stlpca. </param>
		/// <returns> Odkaz na prvok na danych indexoch. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index riadku alebo stlpca nepatri do matice. </exception>
		T& at(int rowIndex, int columnIndex) override;
	private:
		Array<Array<T>*>* array_;
		size_t columnCount_;
		size_t rowCount_;
	};

	template<typename T>
	inline IncoherentMatrix<T>::IncoherentMatrix(size_t rowCount, size_t columnCount)
		: rowCount_(rowCount), columnCount_(columnCount)
	{
		this->array_ = new Array<Array<T>*>(rowCount);
		for (int i = 0; i < rowCount; ++i) {
			this->array_->at(i) = new Array<T>(columnCount);
		}
	}

	template<typename T>
	inline IncoherentMatrix<T>::IncoherentMatrix(IncoherentMatrix& other)
		: array_(new Array<Array<T>*>(rowCount_)) rowCount_(other.rowCount_), columnCount_(other.columnCount_)
	{
		

	}

	template<typename T>
	inline IncoherentMatrix<T>::~IncoherentMatrix()
	{
		for (int i = 0; i < this->rowCount_; ++i) {
			delete this->array_->at(i);
		}
		delete this->array_;
		
		this->rowCount_ = 0;
		this->columnCount_ = 0;
		this->array_ = nullptr;
	}

	template<typename T>
	inline Structure& IncoherentMatrix<T>::assign(Structure& other)
	{
		if (this != &other) {
			IncoherentMatrix<T>& otherMatrix = dynamic_cast<IncoherentMatrix<T>&>(other);

			if ((otherMatrix.rowCount_ != this->rowCount_) || (otherMatrix.columnCount_ != this->columnCount_)) {
				throw std::runtime_error("IncoherentMatrix<T> is not the same.");
			}

			this->rowCount_ = otherMatrix.rowCount_;
			this->columnCount_ = otherMatrix.columnCount_;
			
			for (int i = 0; i < this->rowCount_; ++i) {
				this->array_->at(i)->assign(*(otherMatrix.array_->at(i)));
			}

		}

		return *this;
	}

	template<typename T>
	inline bool IncoherentMatrix<T>::equals(Structure& other)
	{
		IncoherentMatrix<T>* otherMatrix = dynamic_cast<IncoherentMatrix<T>*>(&other);

		if (otherMatrix == nullptr) {
			return false;
		}

		if (otherMatrix->rowCount_ != this->rowCount_ || otherMatrix->columnCount_ != this->columnCount_) {
			return false;
		}

		for (int i = 0; i < this->rowCount_; ++i) {

			
				if (this->array_->at(i)->equals(*(otherMatrix->array_->at(i))) == false) {
					return false;
				}
			
			
		}

		return true;
	}

		template<typename T>
		inline size_t IncoherentMatrix<T>::size()
		{
			return this->rowCount_ * this->columnCount_;
		}

		template<typename T>
		inline size_t IncoherentMatrix<T>::getRowCount()
		{
			return this->rowCount_;
		}

		template<typename T>
		inline size_t IncoherentMatrix<T>::getColumnCount()
		{
			return this->columnCount_;
		}

		template<typename T>
		inline T& IncoherentMatrix<T>::at(int rowIndex, int columnIndex)
		{
			return this->array_->at(rowIndex)->at(columnIndex);
		}
	}
