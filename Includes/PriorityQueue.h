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
        T peek() const;
        size_t size() const;
        bool isEmpty() const;
        ~PriorityQueue();
};

template<typename T>
PriorityQueue<T>::PriorityQueue()
    : sizeOfArr(0), capacity(256)
{
    this->priorityArray = new T[256]; 
}

template<typename T>
void PriorityQueue<T>::enqueue(T element)
{
    ++sizeOfArr;
    if(sizeOfArr >= capacity-1)
    {
        T *tempArray = new T[capacity*2];
        for(unsigned int i = FIRST_INDEX; i < capacity; i++)
        {
            tempArray[i] = priorityArray[i];
        }
        capacity = capacity*2;
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
    if(isEmpty())
        throw "Empty Queue";
    else
    {
        unsigned int index = FIRST_INDEX;
        T element = priorityArray[sizeOfArr];
        priorityArray[index] = element;
        --sizeOfArr;
        while((2*index < sizeOfArr && priorityArray[index] > priorityArray[2*index]) || (2*index+1 < sizeOfArr && priorityArray[index] > priorityArray[2*index+1]))
        {
            if(priorityArray[2*index] < priorityArray[2*index+1])
            {
                priorityArray[index] = priorityArray[2*index];
                priorityArray[2*index] = element;
                index = 2*index;
            }
            else if(priorityArray[2*index] > priorityArray[2*index+1] )
            {
                priorityArray[index] = priorityArray[2*index+1];
                priorityArray[2*index+1] = element;
                index = 2*index+1;
            }
            else
            {
                break;
            }
            
        }
    }
}

template<typename T>
T PriorityQueue<T>::peek() const
{
    if(isEmpty())
        throw "Empty Queue";
    return this->priorityArray[FIRST_INDEX];
}

template<typename T>
size_t PriorityQueue<T>::size() const
{
    return this->sizeOfArr;
}

template<typename T>
bool PriorityQueue<T>::isEmpty() const
{
    return !sizeOfArr;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
    delete this->priorityArray;
}

#endif