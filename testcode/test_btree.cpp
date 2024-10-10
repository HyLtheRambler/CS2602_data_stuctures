#include <iostream>
#include "../includes/btree.h"

void testBTree() {
    btree<int> tree;

    // 创建一个简单的二叉树
    tree.createTree(-1);

    // 测试前序遍历（递归）
    std::cout << "PreOrder (Recursive): ";
    tree.PreOrder();
    std::cout << std::endl;

    // 测试中序遍历
    std::cout << "InOrder: ";
    tree.InOrder();
    std::cout << std::endl;

    // 测试后序遍历
    std::cout << "PostOrder: ";
    tree.PostOrder();
    std::cout << std::endl;

}

int main() {
    try {
        testBTree();
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
