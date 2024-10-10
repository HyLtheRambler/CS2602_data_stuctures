#include <iostream>
#include "../includes/seqQueue.h"

void testSeqQueue() {
    seqQueue<int> queue(5);

    // 测试 isEmpty 方法
    std::cout << "Queue is empty: " << (queue.isEmpty() ? "true" : "false") << std::endl;

    // 测试 enQueue 方法
    for (int i = 1; i <= 5; ++i) {
        queue.enQueue(i);
        std::cout << "Enqueued " << i << " to the queue." << std::endl;
    }

    // 测试 isFull 方法
    std::cout << "Queue is full: " << (queue.isFull() ? "true" : "false") << std::endl;

    // 测试 front 方法
    std::cout << "Front element is: " << queue.front() << std::endl;

    // 测试 deQueue 方法
    for (int i = 1; i <= 5; ++i) {
        std::cout << "Dequeued " << queue.front() << " from the queue." << std::endl;
        queue.deQueue();
    }

    // 再次测试 isEmpty 方法
    std::cout << "Queue is empty: " << (queue.isEmpty() ? "true" : "false") << std::endl;

    // 测试 doubleSpace 方法
    for (int i = 1; i <= 10; ++i) {
        queue.enQueue(i);
        std::cout << "Enqueued " << i << " to the queue." << std::endl;
    }
    std::cout << "Queue is full: " << (queue.isFull() ? "true" : "false") << std::endl;
    std::cout << "Front element is: " << queue.front() << std::endl;
}

int main() {
    try {
        testSeqQueue();
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}