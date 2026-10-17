#include "Stack.hpp"
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void producer(ThreadSafeStack<int>& stack) {
    for (int i = 0; i < 10; ++i) {
        std::cout << "Producing: " << i << std::endl;
        stack.push(i);
    }
}

void consumer(ThreadSafeStack<int>& stack) {
    for (int i = 0; i < 10; ++i) {
        try {
            auto value = stack.pop();
            std::cout << "Consuming: " << *value << std::endl;
        } catch (std::runtime_error& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
}

int main() {
    ThreadSafeStack<int> stack;

    std::thread producerThread(producer, std::ref(stack));
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::thread consumerThread(consumer, std::ref(stack));

    producerThread.join();
    consumerThread.join();

    return 0;
}
