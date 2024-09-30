#ifndef LINKLIST_H
#define LINKLIST_H

class outOfBound{};

template <class T>
class linkList;

template <class T>
class node
{
    friend class linkList<T>;
    private:
        T data;
        node *next;
    public:
        node():next(NULL) {};
        node (const T& e, node *N = NULL)
        { data = e; next = N; }
};

template <class T>
class linkList
{
    private:
        node<T> *head;
    public:
        linkList():head(new node<T>()) {};
        bool isEmpty() const;
        bool isFull() const { return false; };
        int length() const;
        T get(int i) const;
        int find(const T& e) const;
        void insert(int i, const T& e);
        void remove(int i, T& e);
        void reverse(); //元素就地逆置
        void clear();
        void print();
        T& getBackwardK(int k) const;
        ~linkList(){ clear(); };
};

template <class T>
bool linkList<T>::isEmpty() const {
    return head->next == NULL;
}

template <class T>
int linkList<T>::length() const {
    node<T> *ptr = head;
    int count = 0;
    while (ptr->next != NULL) {
        ptr = ptr->next;
        count++;
    }
    return count;
}

template <class T>
T linkList<T>::get(int i) const {
    int cur_index = 1;
    node<T> *ptr = head->next;
    while (ptr != NULL && cur_index != i) {
        ptr = ptr->next;
        cur_index++;
    }
    if (ptr == NULL) throw outOfBound();
    return ptr->data;
}

template <class T>
int linkList<T>::find(const T& e) const {
    int cur_index = 1;
    node<T> *ptr = head->next;
    while (ptr != NULL && ptr->data != e) {
        ptr = ptr->next;
        cur_index++;
    }
    return ptr == NULL ? 0 : cur_index;
}

template <class T>
void linkList<T>::insert(int i, const T& e) {
    node<T> *new_node = new node<T>(e, NULL);
    node<T> *ptr = head->next;
    node<T> *prev_ptr = head;
    int cur_index = 1;
    while (ptr != NULL && cur_index != i) {
        cur_index++;
        prev_ptr = ptr;
        ptr = ptr->next;
    }
    if (cur_index != i) throw outOfBound();
    prev_ptr->next = new_node;
    new_node->next = ptr;
}

template <class T>
void linkList<T>::remove(int i, T& e) {
    node<T> *ptr = head->next;
    node<T> *prev_ptr = head;
    int cur_index = 1;
    while (ptr != NULL && cur_index != i) {
        cur_index++;
        prev_ptr = ptr;
        ptr = ptr->next;
    }
    if (cur_index != i) throw outOfBound();
    e = ptr->data;
    prev_ptr->next = ptr->next;
    delete ptr;
}

template <class T>
void linkList<T>::reverse() { 
    //这是不插入，反转的写法。也可以从头开始遍历，初始化链表为空，将每个节点插到头部，就反转了。
    node<T> *p, *prev_p, *tmp;
    p = head->next;
    head->next = NULL;
    prev_p = NULL;
    while (p) {
        tmp = p->next;
        p->next = prev_p;
        prev_p = p;
        p = tmp;
    }
    head->next = prev_p;
}

template <class T>
void linkList<T>::clear() {
    node<T> *ptr = head->next;
    node<T> *tmp = NULL;
    while (ptr != NULL) {
        tmp = ptr->next;
        delete ptr;
        ptr = tmp;
    }
    head->next = NULL;
}

template <class T>
T& linkList<T>::getBackwardK(int k) const {
    node<T> *fast_ptr = head->next;
    node<T> *ptr = head;
    int cur_index = 1;
    while (fast_ptr && cur_index < k) {
        fast_ptr = fast_ptr->next;
        cur_index++;
    }
    if (!fast_ptr || k == 0) {
        throw outOfBound();
    }
    while (fast_ptr) {
        ptr = ptr->next;
        fast_ptr = fast_ptr->next;
    }
    return ptr->data;
}

template <class T>
void linkList<T>::print() {
    node<T> *ptr = head->next;
    while (ptr) {
        std::cout << ptr->data << ' ';
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

#endif //LINKLIST_H
