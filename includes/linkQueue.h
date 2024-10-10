#ifndef LINKQUEUE_H_INCLUDED
#define LINKQUEUE_H_INCLUDED

class illegalSize{};
class outOfBound{};

template <class T>
class linkQueue;

template <class T>
class Node
{
    friend class linkQueue<T>;
    private:
        T value;
        Node *next;
    public:
        Node() {next = NULL; }
        Node(const T &x, Node *p = NULL)
        { value=x; next=p;}
};

template <class T>
class linkQueue
{
    private:
        Node<T> *Front, *Rear;
    public:
        linkQueue() {Front = Rear = NULL; };
        bool isEmpty() { return !Front; };
        bool isFull() {return false; };
        T front();
        void enQueue(const T &x);
        void deQueue();
        ~linkQueue();
};

template <class T>
T linkQueue<T>::front()
{
    return Front->value;
}

template <class T>
void linkQueue<T>::enQueue(const T &x)
{
    Node<T> *new_node = new Node<T>(x);
    if (!Rear) {
        Rear = new_node;
        Front = new_node;
        return;
    }
    Rear->next = new_node;
    Rear = Rear->next;
}

template <class T>
void linkQueue<T>::deQueue()
{
    if (!Front) throw outOfBound();
    Node<T> *tmp = Front;
    Front = tmp->next;
    delete tmp;
}

template <class T>
linkQueue<T>::~linkQueue()
{
    Node<T> *tmp;
    while (Front != NULL) {
        tmp = Front->next;
        delete Front;
        Front = tmp;
    }
}


#endif //LINKQUEUE_H_INCLUDED