#include<iostream>
#include<stack>
#include<cstring>
#include<iomanip> 

float StringTODate(std::string st) {
    int sum = 0, i = 0;
    bool fushu = false;
    while (i < st.size()) {
        if (st[i] == '-') fushu = true;
        if (st[i] <= '9' && st[i] >= '0')
            sum = sum * 10 + st[i] - '0';
        i++;
    }
    if (fushu) sum *= -1;
    return (float)sum;
}

float count(std::string st) {
    std::stack<float> st1;
    std::stack<char> st2;
    int front = -1, rear = (st[0] == '-' ? 1 : 0);
//st[front] == '+' || st[front] == '-' || st[front] == '*' || st[front] == '/'
    for (; rear <= st.size(); rear++) {
        if (rear == st.size() || st[rear] == '+' || st[rear] == '-' || st[rear] == '*' || st[rear] == '/') {     
            st1.push(StringTODate(st.substr(front + 1, rear - front - 1)));
            if (rear == st.size()) break;
            if (st2.empty()) {
                st2.push(st[rear]);
            } else {
                if (st[rear] == '+' || st[rear] == '-') {
                    while (!st2.empty()) {
                        char ch = st2.top();
                        st2.pop();
                        float a = st1.top(), b;
                        st1.pop();
                        b = st1.top();
                        st1.pop();
                        if (ch == '+') {
                            st1.push(a + b);
                        } else if (ch == '-') {
                            st1.push(b - a);
                        } else if (ch == '*') {
                            st1.push(a * b);
                        } else if (ch == '/') {
                            st1.push(b / a);
                        }
                    }
                    st2.push(st[rear]);
                } else {
                    if (st2.top() == '+' || st2.top() == '-') {
                        st2.push(st[rear]);
                    } else {
                        while (st2.top() == '*' || st2.top() == '/') {
                            char ch = st2.top();
                            st2.pop();
                            float a = st1.top(), b;
                            st1.pop();
                            b = st1.top();
                            st1.pop();
                            if (ch == '*') {
                                st1.push(a * b);
                            } else if (ch == '/') {
                                st1.push(b / a);
                            }
                        }
                        st2.push(st[rear]);
                    }
                }
            }
            front = rear;
        }
    }
    while (!st2.empty()) {
        char ch = st2.top();
        st2.pop();
        float a = st1.top(), b;
        st1.pop();
        b = st1.top();
        st1.pop();
        if (ch == '+') {
            st1.push(a + b);
        } else if (ch == '-') {
            st1.push(b - a);
        } else if (ch == '*') {
            st1.push(a * b);
        } else if (ch == '/') {
            st1.push(b / a);
        }
    }
    return st1.top();
}

int main() {
    int N;
    std::string st;
    std::cin >> N;
    std::cin.ignore();
    while (N--) {
        getline(std::cin, st);
        std::cout <<std::setiosflags(std::ios::fixed) << std::setprecision(3) << count(st) << std::endl;
    }
}
