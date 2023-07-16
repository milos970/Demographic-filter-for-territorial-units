#include "vector.h"
#include "../utils.h"
#include <cstdlib>
#include <cstring>
#include "../../structures/heap_monitor.h"
namespace structures
{
	Vector::Vector(size_t size) :
		memory_(std::calloc(size, 1)),
		size_(size)
	{	
	}

	Vector::Vector(Vector& other) :
		Vector(other.size_)
	{
		std::memcpy(this->memory_,other.memory_,this->size_);
	}

	Vector::~Vector()
	{
		std::free(this->memory_); // uvolnujem pamat
		this->memory_ = nullptr; // kvoli tomu, aby mi to v buducnu padlo keby som sa chcel nahodou odkazovat
		this->size_ = 0;
	}

	size_t Vector::size()
	{
		return size_;
	}

	Structure& Vector::assign(Structure& other)
	{
		if (this != &other) {
			Vector& otherVector = dynamic_cast<Vector&>(other);//nevytvaram novy blok pamäte
			this->memory_ = std::realloc(this->memory_,otherVector.size_);
			std::memcpy(this->memory_, otherVector.memory_, otherVector.size_);
			this->size_ = otherVector.size_;
		}
		return *this;
	}

	bool Vector::equals(Structure& other)
	{
		Vector* otherVector = dynamic_cast<Vector*>(&other);//robím cez smernik lebo nechcem zachytavat vynimku, lebo pri & by mi to vyhodilo, takto to vyhodi len nullptr ak sa nepodari
		//vytvaram novy blok pamäte
		if (otherVector == nullptr) {
			return false;
		}
		return this->size_ == otherVector->size_ && memcmp(this->memory_, otherVector->memory_, this->size_) == 0;
	}

	byte& Vector::operator[](int index)
	{
		return at(index);
	}

	byte& Vector::at(int index)
	{
		return *this->getBytePointer(index);
	}

	void Vector::copy(Vector& src, int srcStartIndex, Vector& dest, int destStartIndex, int length)
	{
		if (length > 0) {
			if (srcStartIndex < 0 || srcStartIndex + length - 1 >= src.size_) {
				throw std::out_of_range("Vector<T>::copy: Invalid index in src array.");
			}
			if (destStartIndex < 0 || destStartIndex + length - 1 >= dest.size_) {
				throw std::out_of_range("Vector<T>::copy: Invalid index in dest array.");
			}

			if (&src !=  &dest || srcStartIndex > destStartIndex + length - 1 || destStartIndex > srcStartIndex + length - 1) {
				std::memcpy(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
			}
			else {
				std::memmove(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
			}
			
		}
	}

	byte* Vector::getBytePointer(int index)
	{
		if (index < 0 || index >= this->size_) {
			throw std::out_of_range("Vector::getBytePointer: invalid index!");
		}
		return reinterpret_cast<byte*>(this->memory_) + index;
	}
}