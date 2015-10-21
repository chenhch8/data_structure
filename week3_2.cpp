#include<iostream>
#include<stack>

class Queue { 
 public:
     bool IsEmpty() const {
         return firstStack.empty() && secondStack.empty();
     }
     int & front() {
         if (secondStack.empty())
             while (!firstStack.empty()) {
                 secondStack.push(firstStack.top());
                 firstStack.pop();
             }
         if (!secondStack.empty())
             return secondStack.top();
     }
     void push(int a) {
         firstStack.push(a);
         return;
     }
     void pop() {
         if (secondStack.empty())
             while (!firstStack.empty()) {
                 secondStack.push(firstStack.top());
                 firstStack.pop();
             }
         if (!secondStack.empty())
             secondStack.pop();
     } 
 private: 
     std::stack<int> firstStack; 
     std::stack<int> secondStack; 
};

int main() {
    Queue que;
    for (int i = 1; i <= 100; i++)
        que.push(i);
    std::cout << que.front() << std::endl;
    for (int i = 0; i < 10; i++)
        que.pop();
    for (int i = 1; i <= 10; i++)
        que.push(i);
    while (!que.IsEmpty()) {
        std::cout << que.front() << std::endl;
        que.pop();
    }
    return 0;
}