#include <iostream>
#include "seqlist.h"

int main() {
    // 创建一个 seqList 对象
    seqList<int> list;

    // 插入一些元素
    for (int i = 1; i < 10; ++i) {
        list.insert(i, i * 10); 
    }

    // 获取并打印元素
    std::cout << "Elements in the list:" << std::endl;
    for (int i = 1; i < 10; ++i) {
        std::cout << "Element at index " << i << ": " << list.get(i) << std::endl;
    }

    // 查找元素
    int index = list.find(50);
    if (index != -1) {
        std::cout << "Element 50 found at index: " << index << std::endl;
    } else {
        std::cout << "Element 50 not found." << std::endl;
    }

    // 再次获取并打印元素
    std::cout << "Elements in the list after doubling space:" << std::endl;
    for (int i = 1; i < 10; ++i) {
        std::cout << "Element at index " << i << ": " << list.get(i) << std::endl;
    }

    return 0;
}