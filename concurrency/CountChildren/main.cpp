#include <array>
#include <iostream>
#include <string_view>
#include <thread>

constexpr int kLastNumber = 30;
constexpr std::array<std::string_view, 4> kChildren = {
    "Abdul", "Bart", "Claudia", "Divya"
};

void play_fizzbuzz(int last_number) {
    for (int number = 1; number <= last_number; ++number) {
        const auto child = kChildren[(number - 1) % kChildren.size()];
        std::cout << child << " says ";

        // Check both divisors first so 15 becomes fizzbuzz, not just fizz.
        if (number % 15 == 0) {
            std::cout << "fizzbuzz!";
        } else if (number % 3 == 0) {
            std::cout << "fizz!";
        } else if (number % 5 == 0) {
            std::cout << "buzz!";
        } else {
            std::cout << number;
        }

        std::cout << '\n';
    }
}

int main() {
    std::thread game_thread(play_fizzbuzz, kLastNumber);

    game_thread.join();
    return 0;
}
