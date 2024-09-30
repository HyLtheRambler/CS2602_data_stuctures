#include <iostream>
#include "linkList.h"

int main() {
    linkList<int> list;

    // 测试插入元素
    try {
        for (int i = 1; i <= 10; ++i) {
            list.insert(i, i * 10); // 插入10个元素
        }
        list.insert(5, 55); // 插入到第5个位置
    } catch (const outOfBound& e) {
        std::cerr << "插入操作越界" << std::endl;
    }

    // 打印链表内容
    list.print(); // 期望输出: 10 20 30 40 55 50 60 70 80 90 100

    // 测试删除元素
    try {
        int e;
        list.remove(5, e); // 删除第5个位置的元素
        std::cout << "删除的元素: " << e << std::endl;
        list.remove(1, e); // 删除第1个位置的元素
        std::cout << "删除的元素: " << e << std::endl;
        list.remove(9, e); // 删除第9个位置的元素
        std::cout << "删除的元素: " << e << std::endl;
    } catch (const outOfBound& e) {
        std::cerr << "删除操作越界" << std::endl;
    }
    
    // 打印链表内容
    list.print(); // 期望输出: 20 30 40 50 60 70 80 90
    int k = 0;
    try {
        for (k = 1; k < 5; ++k) {
            int value = list.getBackwardK(k);
            std::cout << "The " << k << "rd element from the end is: " << value << std::endl;
        }
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }


    // 测试反转链表
    list.reverse();

    // 打印链表内容
    list.print(); // 期望输出: 90 80 70 60 50 40 30 20

    // 测试查找元素
    std::cout << "查找50: " << list.find(50) << std::endl; // 期望输出: 5
    std::cout << "查找100: " << list.find(100) << std::endl; // 期望输出: -1

    // 测试清空链表
    list.clear();

    // 打印链表内容
    list.print(); // 期望输出: (空)

    return 0;
}
