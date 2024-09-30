#include <iostream>
#include "seqStack.h"

int main() {
    // 创建一个 seqStack 对象
    seqStack<int> stack;

    // 测试 isEmpty 方法
    std::cout << "Stack is empty: " << (stack.isEmpty() ? "true" : "false") << std::endl;

    // 测试 push 方法
    for (int i = 1; i <= 10; ++i) {
        stack.push(i);
        std::cout << "Pushed " << i << " onto the stack." << std::endl;
    }

    // 测试 isFull 方法
    std::cout << "Stack is full: " << (stack.isFull() ? "true" : "false") << std::endl;

    // 测试 top 方法
    std::cout << "Top element is: " << stack.top() << std::endl;

    // 测试 pop 方法
    for (int i = 1; i <= 10; ++i) {
        std::cout << "Popped " << stack.top() << " from the stack." << std::endl;
        stack.pop();
    }

    // 再次测试 isEmpty 方法
    std::cout << "Stack is empty: " << (stack.isEmpty() ? "true" : "false") << std::endl;

    return 0;
}