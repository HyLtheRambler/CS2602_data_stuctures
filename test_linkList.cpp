#include <iostream>
#include "linkList.h"

int main() {
    linkList<int> list;

    // 测试插入元素
    try {
        list.insert(1, 10); // 插入到第1个位置
        list.insert(2, 20); // 插入到第2个位置
        list.insert(3, 30); // 插入到第3个位置
        list.insert(2, 15); // 插入到第2个位置
    } catch (const outOfBound& e) {
        std::cerr << "插入操作越界" << std::endl;
    }

    // 打印链表内容
    list.print(); // 期望输出: 10 15 20 30

    // 测试删除元素
    try {
        int e;
        list.remove(2, e); // 删除第2个位置的元素
        std::cout << "删除的元素: " << e << std::endl;
    } catch (const outOfBound& e) {
        std::cerr << "删除操作越界" << std::endl;
    }

    // 打印链表内容
    list.print(); // 期望输出: 10 20 30

    // 测试反转链表
    list.reverse();

    // 打印链表内容
    list.print(); // 期望输出: 30 20 10

    // 测试清空链表
    list.clear();

    // 打印链表内容
    list.print(); // 期望输出: (空)

    return 0;
}