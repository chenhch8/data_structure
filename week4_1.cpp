#include<iostream>
enum ErrorCode {
    success,
    underflow,
    overflow
};

template <class StackEntry>
struct Node {
    StackEntry data;
    Node *next;
    Node(Node * n = NULL) : next(n) {}
};

template <class StackEntry>
class MyStack {
 public:
    MyStack(): tTop(NULL) {}
    /*
    判断栈是否为空，若为空则返回true，非空则返回false
    */
    bool empty() const {return tTop == NULL;}
    int size() const {
        int length = 0;
        Node<StackEntry> * pt = tTop;
        while (pt != NULL) {
            length++;
            pt = pt->next;
        }
        return length;
    }
    /*
    出栈操作，若正常出栈则返回success，若栈内无元素则返回underflow
    */
    ErrorCode pop() {
        if (tTop != NULL) {
            Node<StackEntry> * temp = tTop;
            tTop = tTop->next;
            delete temp;
            return success;
        } else {
            return underflow;
        }
    }
    /*
    获取栈顶元素，若正常获取到栈顶元素则返回success，若栈内无元素则返回underflow
    元素内容保存在引用参数item中
    */
    ErrorCode top(StackEntry &item) const {
        if (empty())
            return underflow;
        item = tTop->data;
        return success;
    }
    /*
    入栈操作，若正常入栈则返回success，若入栈失败则返回overflow
    */
    ErrorCode push(const StackEntry &item) {
        Node<StackEntry> * temp = new Node<StackEntry>(tTop);
        if (temp == NULL) return overflow;
        temp->data = item;
        tTop = temp;
        return success;
    }
    /*
    清空栈
    */
    void clear() {
        Node<StackEntry> * tp;
        while (tTop != NULL) {
            tp = tTop;
            tTop = tTop->next;
            delete tp;
        }
        return;
    }
 private:
    Node<StackEntry> *tTop;

};

int main() {
    MyStack<int> st;
    for (int i = 0; i < 100; i++)
        st.push(i);
    std::cout << st.size() << std::endl << std::endl;
    for (int i = 0; i < 10; i++)
        st.pop();
    std::cout << st.size() << std::endl << std::endl;
    for (int i = 0; i < 10; i++)
        st.push(i);
    std::cout << st.size() << std::endl << std::endl;
    while (!st.empty()) {
        int k;
        st.top(k);
        std::cout << k << std::endl;
        st.pop();
    }
    std::cout << st.size() << std::endl << std::endl;
    return 0;
}