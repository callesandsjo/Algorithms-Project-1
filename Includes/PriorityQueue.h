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


//public functions

template<typename T>
PriorityQueue<T>::PriorityQueue()
    : sizeOfArr(0), capacity(256)
{
    this->priorityArray = new T[256]; 
}

template<typename T>
void PriorityQueue<T>::enqueue(T element)
{
    ++this->sizeOfArr;
    if(this->capacity < this->sizeOfArr)
    {
        T *tempArray = new T[this->capacity*2];
        for(unsigned int i = FIRST_INDEX; i < this->sizeOfArr+1; i++)
        {
            tempArray[i] = this->priorityArray[i];
        }
        this->capacity = this->capacity*2;
        delete this->priorityArray;
        this->priorityArray = tempArray;
    }
    
    unsigned int index = sizeOfArr;
    while((FIRST_INDEX < index) && (element < this->priorityArray[index/2]))
    {
        
        this->priorityArray[index] = this->priorityArray[index/2];
        index = index/2;
    }
    this->priorityArray[index] = element;

}


template<typename T>
void PriorityQueue<T>::dequeue()
{
    if(isEmpty())
        throw "Empty Queue";
    else
    {
        unsigned int index = FIRST_INDEX;
        this->priorityArray[index] = this->priorityArray[this->sizeOfArr];
        T element = this->priorityArray[index];
        --this->sizeOfArr;
        while((2*index+1 < this->sizeOfArr && this->priorityArray[2*index+1] < this->priorityArray[index]) ||
            (2*index < this->sizeOfArr && this->priorityArray[2*index] < this->priorityArray[index])) //starts evaluating 2*index+1 because of lazy evaluation
        {
            if(this->priorityArray[2*index] < this->priorityArray[2*index+1])
            {
                this->priorityArray[index] = this->priorityArray[2*index];
                this->priorityArray[2*index] = element;
                index = 2*index;
            }
            else
            {
                this->priorityArray[index] = this->priorityArray[2*index+1];
                this->priorityArray[2*index+1] = element;
                index = 2*index+1;
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
    delete[] this->priorityArray;
}

#endif