# C++ High Performance Computing

Independent C++ learning projects grouped by topic. Each project under `concurrency/` has its own CMake build. Requires CMake 3.16+ and a C++17 compiler. Start each command block from the repository root.

## Concurrency

### CountChildren

A round-robin FizzBuzz game running in a separate thread.

```sh
cd concurrency/CountChildren
cmake -B build
cmake --build build && ./build/CountChildren
```

### ThreadSafeQueue

A producer/consumer queue using a mutex and condition variable.

```sh
cd concurrency/ThreadSafeQueue
cmake -B build
cmake --build build && ./build/QueueExample
```

### ThreadSafeStack

A stack protected by a mutex, with a producer/consumer example.

```sh
cd concurrency/ThreadSafeStack
cmake -B build
cmake --build build && ./build/StackExample
```
