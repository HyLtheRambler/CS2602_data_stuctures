#ifndef SEQQUEUE_H_INCLUDED
#define SEQQUEUE_H_INCLUDED

#ifndef ERROR_HANDLING
#define ERROR_HANDLING

class illegalSize{};
class outOfBound{};

#endif

template <class T>
class seqQueue
{
    private:
        T *array;
        int maxSize;
        int Front, Rear;
        void doubleSpace();
    public:
        seqQueue(int size=10);
        bool isEmpty();
        bool isFull();
        T front();
        void enQueue(const T &x);
        void deQueue();
        ~seqQueue();
};

template <class T>
seqQueue<T>::seqQueue(int size) : maxSize(size)
{
    Front = 0;
    Rear = 0;
    array = new T[maxSize];
}

template <class T>
void seqQueue<T>::doubleSpace()
{
    T *new_array = new T[maxSize * 2];
    for (int i = 0; i < maxSize; ++i) {
        new_array[i] = array[(Front + i) % maxSize];
    }
    Front = 0;
    Rear = maxSize - 1;
    delete []array;
    array = new_array;
    maxSize *= 2;
}

template <class T>
bool seqQueue<T>::isEmpty()
{
    return (Front == Rear);
}

template <class T>
bool seqQueue<T>::isFull()
{
    return (((Rear + 1) % maxSize) == Front);
}


template <class T>
T seqQueue<T>::front()
{
    return array[Front + 1];
}

template <class T>
void seqQueue<T>::enQueue(const T &x)
{
    if (this->isFull()) {
        doubleSpace();
    }
    array[(Rear + 1) % maxSize] = x;
    Rear = (Rear + 1) % maxSize;
}

template <class T>
void seqQueue<T>::deQueue()
{
    Front = (Front + 1) % maxSize;
}

template <class T>
seqQueue<T>::~seqQueue()
{
    delete[] array;
}

#endif //SEQQUEUE_H_INCLUDED