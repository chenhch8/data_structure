enum ErrorCode {success, underflow, overflow};

const int maxQueue = 100;

template <class QueueEntry>
class MyQueue {
 public:
    MyQueue():front(0), rear(0) {}
// �ж϶����Ƿ�Ϊ��
    bool empty() const {
        return front == rear;
    }
// ��Ӳ���
    ErrorCode append(const QueueEntry &item) {
        if (rear != front - 1) {
            rear = (++rear) % maxQueue;
            entry[rear] = item;
            return success;
        } else {
            return overflow;
        }
    }
// ���Ӳ���
    ErrorCode serve() {
        if (rear != front) {
            front = (++front) % maxQueue;
            return success;
        } else {
            return underflow;
        }
    }
// ��ȡ��ͷԪ��
    ErrorCode retrieve(QueueEntry &item) const {
        if (rear == front) {
            return underflow;
        } else {
            item = entry[front + 1];
            return success;
        }
    }
// �ж϶����Ƿ�����
    bool full() const {
        return rear == front - 1;
    }
// ��ȡ��������Ԫ�ظ���
    int size() const {
        if (front <= rear)
            return rear - front;
        else
            return maxQueue - front + rear;
    }
// �����������Ԫ��
    void clear() {
        front = 0;
        rear = 0;
    }
// ��ȡ��ͷԪ�ز�����
    ErrorCode retrieve_and_serve(QueueEntry &item) {
        if (front == rear) {
            return underflow;
        } else {
            item = entry[front + 1];
            serve();
            return success;
        }
    }
 private:
    int front;                             // ��ͷ�±�
    int rear;                              // ��β�±�
    QueueEntry entry[100];       // ��������
};

#include<iostream>

int main() {
    MyQueue<int> que;

    /*for (int i = 0; i < 99; i++)
        std::cout << i + 1 << "��" << que.append(i)<< std::endl;
    std::cout << std::endl;

    if (que.full())
        std::cout << "full\n\n";

    int k;
    while (!que.empty()) {
        que.retrieve_and_serve(k);
        std::cout << k << std::endl;
    }*/

    for (int i = 0; i < 120; i++) {
        que.append(i);
    }
    
for (int i = 0; i < 10; i++)
        que.serve();

    for (int i = 0; i < 100; i++)
        que.append(i);
for (int i = 0; i < 10; i++)
        que.serve();

    for (int i = 0; i < 100; i++)
        que.append(i);
for (int i = 0; i < 10; i++)
        que.serve();

    for (int i = 0; i < 100; i++)
        que.append(i);
    
    int k;
    while (!que.empty()) {
        que.retrieve(k);
        std::cout << k << std::endl;
        que.serve();
    }

    /*std::cout << que.size() << std::endl;*/

    return 0;
}



// 0 1 2 3 4 5