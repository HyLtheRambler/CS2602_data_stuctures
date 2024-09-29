#ifndef SEQLIST_H
#define SEQLIST_H

#define INITSIZE 100
using namespace std;

class illegalSize{};
class outOfBound{};

template <class elemType>
class seqList
{
private:
    elemType *elem;
    int len;
    int maxSize;
    void doubleSpace();
public:
    seqList(int size=INITSIZE);
    bool isEmpty() const { return (len == 0); }
    bool isFull() const { return (len == maxSize); }
    int length() const { return len; }
    elemType get(int i) const;
    int find(const elemType &e) const;
    
    void insert(int i, const elemType &e);
    void remove(int i, elemType &e);
    
    void clear() { len = 0; };
    ~seqList() { delete []elem; };
};

template <class elemType>
void seqList<elemType>::doubleSpace() {
    elemType *new_elem = new elemType[maxSize * 2];    
    for (int i = 1; i < len; ++i) {
        new_elem[i] = elem[i];
    }
    delete[] elem;
    elem = new_elem;
    maxSize = 2 * maxSize - 1;
}

template <class elemType>
seqList<elemType>::seqList(int size) {
    elem = new elemType[size];
    if (!elem) throw illegalSize();
    maxSize = size - 1;
    len = 0;
}

template <class elemType>
elemType seqList<elemType>::get(int i) const {
    if ((i < 1) || (i > len)) throw outOfBound();
    return elem[i];
}

template <class elemType>
int seqList<elemType>::find(const elemType &e) const {
    elem[0] = e;
    int i = len;
    for (; i > -1; i--) {
        if (elem[i] == e) {
            break;
        }
    }
    return i;
}

template <class elemType>
void seqList<elemType>::insert(int i, const elemType &e) {
    if ((i < 1) || (i > len + 1)) return;
    for (int j = len + 1; j > i; j--) {
        elem[j]  = elem[j - 1];
    }
    elem[i] = e;
    if (len == maxSize) {
        doubleSpace();
    }
    len++;
}

template <class elemType>
void seqList<elemType>::remove(int i, elemType &e) {
    if ((i < 1) || (i > len)) return;
    e = elem[i];
    for (int j = i; i < len; ++i) {
        elem[i] = elem[i + 1];
    }
    if (len == maxSize) {
        doubleSpace();
    }
    len--;
}

#endif //SEQLIST_H