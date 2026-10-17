# C++ High Performance Computing

Independent C++ learning projects grouped by topic. Each project under `concurrency/` has its own CMake build. Requires CMake 3.16+ and a C++17 compiler. Run the commands below from the repository root.

## Concurrency

### ThreadSafeQueue

A producer/consumer queue using a mutex and condition variable.

```sh
cmake -S concurrency/ThreadSafeQueue -B output/concurrency/ThreadSafeQueue
cmake --build output/concurrency/ThreadSafeQueue
./output/concurrency/ThreadSafeQueue/QueueExample
```

### ThreadSafeStack

A stack protected by a mutex, with a producer/consumer example.

```sh
cmake -S concurrency/ThreadSafeStack -B output/concurrency/ThreadSafeStack
cmake --build output/concurrency/ThreadSafeStack
./output/concurrency/ThreadSafeStack/StackExample
```
