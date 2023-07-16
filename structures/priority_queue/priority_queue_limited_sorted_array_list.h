#pragma once

#include "priority_queue_sorted_array_list.h"
#include <stdexcept>
#include "../../structures/heap_monitor.h"

namespace structures
{
    /// <summary> Prioritny front implementovany utriednym ArrayList-om s obmedzenou kapacitou. </summary>
    /// <typeparam name = "T"> Typ dat ukladanych v prioritnom fronte. </typepram>
    template<typename T>
    class PriorityQueueLimitedSortedArrayList : public PriorityQueueSortedArrayList<T>
    {
    public:
        /// <summary> Konstruktor. </summary>
        PriorityQueueLimitedSortedArrayList();

        /// <summary> Kopirovaci konstruktor. </summary>
        /// <param name = "other"> Prioritny front implementovany utriednym ArrayList-om s obmedzenou kapacitou, z ktoreho sa prevezmu vlastnosti. </param>
        PriorityQueueLimitedSortedArrayList(PriorityQueueLimitedSortedArrayList<T>& other);

        /// <summary> Priradenie struktury. </summary>
        /// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
        /// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
        Structure& assign(Structure& other) override;

        /// <summary> Vlozi prvok s danou prioritou do prioritneho frontu implementovaneho utriednym ArrayList-om s obmedzenou kapacitou. </summary>
        /// <param name = "priority"> Priorita vkladaneho prvku. </param>
        /// <param name = "data"> Vkladany prvok. </param>
        /// <exception cref="std::logic_error"> Vyhodena, ak je prioritny front plny. </exception>
        void push(int priority, const T& data) override;

        /// <summary>
        ///  Vlozi prvok s danou prioritou do prioritneho frontu implementovaneho utriednym ArrayList-om s obmedzenou kapacitou.
        ///  V pripade, ze je prioritny front plny, odstrani polozku s najmensou prioritou z prioritneho frontu a vrati smernik na nu.
        ///  V opacnom pripade vrati nullptr.
        /// </summary>
        /// <param name = "priority"> Priorita vkladaneho prvku. </param>
        /// <param name = "data"> Vkladany prvok. </param>
        /// <returns> Smernik na odstranenu polozku alebo nullptr. </returns>
        PriorityQueueItem<T>* pushAndRemove(int priority, T data);

        /// <summary> Vrati najmensiu prioritu nachadzajucu sa v prioritnom fronte. </summary>
        /// <returns> Najmensiu priorita nachadzajuca sa v prioritnom fronte. </returns>
        int minPriority();

        int maxPriority();

        T& maxPriorityElement();

        /// <summary>
        ///  Pokusi sa zmenit kapacitu prioritneho frontu.
        ///  Kapacitu je mozne zmensit len ak nova kapacita nie je mensia ako aktualny pocet poloziek v prioritnom fronte.
        ///  V opacnom pripade nedojde k zmene kapacity.
        /// </summary>
        /// <param name = "capacity"> Nova kapacita. </param>
        /// <returns> true, ak sa kapacitu podarilo zmenit, false inak. </returns>
        bool trySetCapacity(size_t capacity);

    private:
        /// <summary> Kapacita prioritneho frontu. </summary>
        size_t capacity_;
    };

    template<typename T>
    PriorityQueueLimitedSortedArrayList<T>::PriorityQueueLimitedSortedArrayList() :
        PriorityQueueSortedArrayList<T>(),
        capacity_(5)
    {
    }

    template<typename T>
    PriorityQueueLimitedSortedArrayList<T>::PriorityQueueLimitedSortedArrayList(PriorityQueueLimitedSortedArrayList<T>& other) :
        PriorityQueueSortedArrayList<T>(other),
        capacity_(other.capacity_)
    {
    }

    template<typename T>
    inline Structure& PriorityQueueLimitedSortedArrayList<T>::assign(Structure& other)
    {
        if (this != &other)
        {
            PriorityQueueLimitedSortedArrayList<T>& otherQueue = dynamic_cast<PriorityQueueLimitedSortedArrayList<T>&>(other);
            PriorityQueueSortedArrayList<T>::assign(otherQueue);
            this->capacity_ = otherQueue.capacity_;
        }

        return *this;
    }

    template<typename T>
    void PriorityQueueLimitedSortedArrayList<T>::push(int priority, const T& data)
    {
        if (this->size() == this->capacity_) {
            throw std::logic_error("PriorityQueueLimitedSortedArrayList<T>::push: Capacity exceeded!");
        }
        PriorityQueueSortedArrayList<T>::push(priority, data);
    }

    template<typename T>
    inline PriorityQueueItem<T>* PriorityQueueLimitedSortedArrayList<T>::pushAndRemove(int priority, T data)
    {
        PriorityQueueSortedArrayList<T>::push(priority, data);
        if ( this->size() > this->capacity_ ) 
        {
            return list_->removeAt(0);
        }
        return nullptr;
    }

    template<typename T>
    inline int PriorityQueueLimitedSortedArrayList<T>::minPriority()
    {
        if ( this->size() == 0 ) {
            throw std::logic_error("PriorityQueueLimitedSortedArrayList<T>::minPriority: Queue is empty!");
        }
        
        return list_->at(0)->getPriority();
    }

    template<typename T>
    inline int PriorityQueueLimitedSortedArrayList<T>::maxPriority()
    {
        if ( this->size() == 0 ) {
            throw std::logic_error("PriorityQueueLimitedSortedArrayList<T>::maxPriority: Queue is empty!");
        }

        return list_->at(list_->size() - 1)->getPriority();
    }

    template<typename T>
    inline T& PriorityQueueLimitedSortedArrayList<T>::maxPriorityElement()
    {
        if (this->size() == 0) {
            throw std::logic_error("PriorityQueueLimitedSortedArrayList<T>::maxPriorityElement: Queue is empty!");
        }

        return list_->at(this->indexOfPeek())->accessData();
    }


    template<typename T>
    inline bool PriorityQueueLimitedSortedArrayList<T>::trySetCapacity(size_t capacity)
    {
        if ( capacity < this->size() ) {
            return false;
        }

        this->capacity_ = capacity;
        return true;
    }
}