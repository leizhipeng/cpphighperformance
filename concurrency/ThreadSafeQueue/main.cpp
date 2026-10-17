#include "Queue.hpp"
#include <iostream>
#include <thread>
#include <vector>

// Producer function: Pushes elements into the queue
void producer(ThreadSafeQueue<int>& queue) {
    for (int i = 0; i < 10; ++i) {
        std::cout << "Producing: " << i << std::endl;
        queue.push(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
    }
}

// Consumer function: Continuously tries to pop elements from the queue
void consumer(ThreadSafeQueue<int>& queue) {
    for (int i = 0; i < 10; ++i) {
        int value;
        queue.wait_and_pop(value);
        std::cout << "Consumed: " << value << std::endl;
    }
}

int main() {
    ThreadSafeQueue<int> queue;

    std::thread producerThread(producer, std::ref(queue));
    std::thread consumerThread(consumer, std::ref(queue));

    producerThread.join();
    consumerThread.join();

    return 0;
}

