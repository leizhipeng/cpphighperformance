#include <exception>
#include <memory>
#include <stack>
#include <mutex>

struct empty_stack: std::exception{
    const char* what () const noexcept override{
        return "Stack is empty";
    }
};

template<typename T>
class ThreadSafeStack{
private:
    std::stack<T> data;
    mutable std::mutex m;
public:
    ThreadSafeStack(){}
    ThreadSafeStack(const ThreadSafeStack& other){
        std::lock_guard<std::mutex> lock(other.m);
        data = other.data;
    }

    ThreadSafeStack& operator = (const ThreadSafeStack&) = delete;
    
    void push(T new_value){
        std::lock_guard<std::mutex> lock(m);
        data.push(std::move(new_value));
} 

    std::shared_ptr<T> pop(){
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();
        std::shared_ptr<T> const res(
            std::make_shared<T>(std::move(data.top()))
        );
        data.pop();
        return res;
    }

    void pop(T& value){
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();
        data.pop();
}

    bool empty(){
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
}



};
