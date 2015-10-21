#include<iostream>

enum ErrorCode {
    success,
    underflow,
    overflow
};

template <class QueueEntry>
struct Node {
    QueueEntry data;
    Node<QueueEntry> *next;
    Node(): next(NULL) {}
};

template <class QueueEntry>
class MyQueue {
 public:
    MyQueue(): front(NULL), rear(NULL) {}
    // 判断队列是否为空
    bool empty() const {return front == NULL;}
    // 入队操作
    ErrorCode append(const QueueEntry &item) {
        Node<QueueEntry> * temp = new Node<QueueEntry>;
        if (temp == NULL) return overflow;
        if (empty()) {
            front = rear = temp;
            front->data = item;
        } else {
            rear->next = temp;
            rear = temp;
            rear->data = item;
        }
        return success;
        
    }
    // 出队操作
    ErrorCode serve() {
        if (front == NULL)
            return underflow;
        Node<QueueEntry> * temp = front;
        front = front->next;
        delete temp;
        if (front == NULL) rear = NULL;
        return success;
    }
    // 获取队头元素
    ErrorCode retrieve(QueueEntry &item) const {
        if (front == NULL)
            return underflow;
        item = front->data;
        return success;
    }
    // 获取队列已有元素个数
    int size() const {
        Node<QueueEntry> * temp = front;
        int length = 0;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        return length;
    }
    // 清除队列所有元素
    void clear() {
        Node<QueueEntry> * tp;
        while (front != NULL) {
            tp = front;
            front = front->next;
            delete tp;
        }
        rear = NULL;
        return;
    }
    // 获取队头元素并出队
    ErrorCode retrieve_and_serve(QueueEntry &item) {
        ErrorCode ss = retrieve(item);
        if (ss == underflow) return ss;
        return serve();
    }
 private:
    Node<QueueEntry> *front;                           // 队头指针
    Node<QueueEntry> *rear;                             // 队尾指针
};

int main() {
    MyQueue<int> st;
    int k;
    for (int i = 0; i < 100; i++)
        st.append(i);
    std::cout << st.size() << std::endl << std::endl;
    for (int i = 0; i < 10; i++)
        st.serve();
    st.retrieve(k);
    std::cout << k << std::endl << std::endl;
    std::cout << st.size() << std::endl << std::endl;
    for (int i = 0; i < 10; i++)
        st.append(i);
    std::cout << st.size() << std::endl << std::endl;
    while (!st.empty()) {
        st.retrieve_and_serve(k);
        std::cout << k << std::endl;
    }
    std::cout << st.size() << std::endl << std::endl;
    return 0;
}