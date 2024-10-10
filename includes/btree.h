#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#include <iostream>
#include "seqStack.h"
#include "seqQueue.h"

using namespace std;

template <class T>
class btree;

template <class T>
class Node
{
    friend class btree<T>;
    private:
        T value;
        Node *left, *right;
        int leftFlag;
        int rightFlag;
    public:
        Node() {left=NULL; right=NULL; leftFlag = 0; rightFlag = 0; };
        Node(const T &e, Node *L = NULL, Node *R = NULL)
        {
            value = e;
            left = L; right = R; leftFlag = 0; rightFlag = 0;
        }
};

template <class T>
class btree
{
    private:
        Node<T> *root;
        T stopFlag;

        int Size(Node<T> *t);
        int Height(Node<T> *t);
        void DelTree(Node<T> *t);
        void PreOrder_recursive(Node<T> *t);
        void InOrder_recursive(Node<T> *t);
        void PostOrder_recursive(Node<T> *t);
        void PreOrder_iterative(Node<T> *t);
        void InOrder_iterative(Node<T> *t);
        void PostOrder_iterative(Node<T> *t);


    public:
        btree() {root=NULL;}
        void createTree(const T& flag);
        int isEmpty() {return (root==NULL); };
        Node<T> *GetRoot(){ return root; }

        int Size();
        int Height();
        void DelTree();
        void PreOrder();
        void InOrder();
        void PostOrder();
        void LevelOrder(); //层次遍历
};

template <class T>
void btree<T>::createTree(const T &flag)
{
    seqQueue<Node<T>*> que;
    T e, el, er;
    Node<T> *p, *pl, *pr;
    cin >> e;

    if (e==flag) { root = NULL; return; }

    p = new Node<T>(e);
    root = p;

    que.enQueue(p);
    while (!que.isEmpty())
    {
        p = que.front();
        que.deQueue();

        cin >> el >> er;
        if (el != flag)
        {
            pl = new Node<T>(el);
            p->left = pl;
            que.enQueue(pl);
        }

        if (er != flag)
        {
            pr = new Node<T>(er);
            p->right = pr;
            que.enQueue(pr);
        }
    }
}

template <class T>
int btree<T>::Size()
{ return Size(root); }

template <class T>
int btree<T>::Size(Node<T> *node)
{
    if (!node) return 0;
    return 1 + Size(node->left) + Size(node->right);
}

template <class T>
int btree<T>::Height()
{ Height(root); }

template <class T>
int btree<T>::Height(Node<T> *node)
{
    if (!node) return 0;
    int hl, hr;
    hl = Height(node->left);
    hr = Height(node->right);

    return hl > hr ? hl + 1 : hr + 1;
}

template <class T>
void btree<T>::DelTree()
{
    DelTree(root);
    root=NULL;
}

template <class T>
void btree<T>::DelTree(Node<T> *t)
{
    if (!t) return;
    DelTree(t->left);
    DelTree(t->right);
    delete t;
}

template <class T>
void btree<T>::PreOrder() 
{
    cout << "PreOrder_recursive: " << endl;
    PreOrder_recursive(root); 
    cout << endl;
    cout << "PreOrder_iterative: " << endl;
    PreOrder_iterative(root);
    cout << endl;
}

template <class T>
void btree<T>::PreOrder_recursive(Node<T> *t)
{
    if (t == NULL) return;
    cout << t->value << ' ';
    PreOrder_recursive(t->left);
    PreOrder_recursive(t->right);
}

template <class T>
void btree<T>::InOrder()
{
    cout << "InOrder_recursive" << endl;
    InOrder_recursive(root); 
    cout << endl;
    cout << "InOrder_iterative" << endl;
    InOrder_iterative(root);
    cout << endl;
}

template <class T>
void btree<T>::InOrder_recursive(Node<T> *t)
{
    if (t == NULL) return;
    InOrder_recursive(t->left);
    cout << t->value << ' ';
    InOrder_recursive(t->right);
}

template <class T>
void btree<T>::PostOrder()
{
    cout << "PostOrder_recursive" << endl;
    PostOrder_recursive(root);
    cout << endl;
    cout << "PostOrder_iterative" << endl;
    PostOrder_iterative(root);
    cout << endl;
}

template <class T>
void btree<T>::PostOrder_recursive(Node<T> *t)
{
    if (t == NULL) return;
    PostOrder_recursive(t->left);
    PostOrder_recursive(t->right);
    cout << t->value << ' ';
}

template <class T>
void btree<T>::PreOrder_iterative(Node<T> *t)
{
    seqStack<Node<T> *> helper_stack;
    Node<T> *cur_node;
    helper_stack.push(t);
    while (!helper_stack.isEmpty()) {
        cur_node = helper_stack.top();
        helper_stack.pop();
        if (cur_node == NULL) continue;
        cout << cur_node->value << ' ';
        helper_stack.push(cur_node->right);
        helper_stack.push(cur_node->left);
    }
}

template <class T>
void btree<T>::InOrder_iterative(Node<T> *t)
{
    seqStack<Node<T> *> node_stack;
    seqStack<int> flag_stack; 
    //与node_stack中一一对应，表示当前节点的左节点是否已经遍历过
    int flag = 0;
    Node<T> *cur_node;
    node_stack.push(t);
    flag_stack.push(0);
    while (!node_stack.isEmpty()) {
        flag = flag_stack.top(); flag_stack.pop(); 
        if (flag) {
            cur_node = node_stack.top(); node_stack.pop();
            cout << cur_node->value << ' ';
            if (!cur_node->right) continue;
            node_stack.push(cur_node->right);
            flag_stack.push(0);
        } else {
            flag_stack.push(1);
            if (node_stack.top()->left) {
                flag_stack.push(0);
                node_stack.push(node_stack.top()->left);
            }
        }
    }
}

template <class T>
void btree<T>::PostOrder_iterative(Node<T> *t)
{
    seqStack<Node<T> *> node_stack;
    seqStack<int> flag_stack;
    int cur_flag = 0;
    Node<T> *cur_node = NULL;
    //与中序类似，但用0表示左右均未处理，1表示处理过左节点，2表示处理过右节点。
    node_stack.push(t);
    flag_stack.push(0);
    while (!node_stack.isEmpty())
    {
        cur_flag = flag_stack.top(); flag_stack.pop();
        switch (cur_flag)
        {
            case 2:
                cur_node = node_stack.top(); node_stack.pop();
                cout << cur_node->value << ' ';
                break;
            case 1:
                flag_stack.push(2);
                if (node_stack.top()->right) {
                    node_stack.push(node_stack.top()->right);
                    flag_stack.push(0);
                }
                break;
            case 0:
                flag_stack.push(1);
                if (node_stack.top()->left) {
                    node_stack.push(node_stack.top()->left);
                    flag_stack.push(0);
                }
                break;
            default:
                return;
        }
    }
}

#endif //BTREE_H_INCLUDED