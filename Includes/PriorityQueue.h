#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#define FIRST_INDEX 1

template<typename T>
class PriorityQueue
{
    private:
        T *priorityArray;
        size_t sizeOfArr;
        unsigned int capacity;
    public:
        PriorityQueue();
        void enqueue(T element);
        void dequeue();
        T peek();
        size_t size();
        bool isEmpty();
        ~PriorityQueue();
};

template<typename T>
PriorityQueue<T>::PriorityQueue()
    : sizeOfArr(0), capacity(16)
{
    this->priorityArray = new T[128];
}

template<typename T>
void PriorityQueue<T>::enqueue(T element)
{
    ++sizeOfArr;
    if(sizeOfArr >= capacity-1)
    {
        T *tempArray = new T[capacity*128];
        for(unsigned int i = FIRST_INDEX; i < capacity; i++)
        {
            tempArray[i] = priorityArray[i];
        }
        delete this->priorityArray;
        this->priorityArray = tempArray;
    }
    
    unsigned int index = sizeOfArr;
    while((index > FIRST_INDEX) && (priorityArray[index/2] > element))
    {
        priorityArray[index] = priorityArray[index/2];
        index = index/2;
    }
    priorityArray[index] = element;
}

template<typename T>
void PriorityQueue<T>::dequeue()
{
    --sizeOfArr;
    unsigned int index = FIRST_INDEX;
    while(true) //ska ändras
    {
        if(priorityArray[2*index] > priorityArray[2*index + 1])
        {
            priorityArray[index] = priorityArray[2*index + 1];
            index = 2*index + 1;
        }
        else
        {
            priorityArray[index] = priorityArray[2*index];
            index = 2*index;
        }
    }
}

template<typename T>
T PriorityQueue<T>::peek()
{
    return this->priorityArray[FIRST_INDEX];
}

template<typename T>
size_t PriorityQueue<T>::size()
{
    return this->sizeOfArr;
}

template<typename T>
bool PriorityQueue<T>::isEmpty()
{
    return !sizeOfArr;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
    delete this->priorityArray;
}

#endif