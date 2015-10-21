#include<iostream>
#include<stack>
#include<cstring>
#include<iomanip> 
#include<cmath>

float StringToDate(std::string st) {
    float sum_z = 0, sum_x = 0;
    int i = 0 , k = -1;
    bool xiaoshu = false, fushu = false;
    while (st[i] == ' ') i++;
    if (st[i] == '-') {
        fushu = true;
        i += 1;
    }
    while (i < st.size()) {
        if (st[i] == '.') {
            xiaoshu = true;
        }
        if (!xiaoshu && st[i] <= '9' && st[i] >= '0')
            sum_z = sum_z * 10 + st[i] - '0';
        if (xiaoshu && st[i] <= '9' && st[i] >= '0')
            sum_x += (st[i] - '0') * pow(10, k--);
        i++;
    }
    return (fushu == false ? 1 : -1) * (sum_z + sum_x);
}

void subcount(std::stack<float> & st1, std::stack<char> & st2, char st) {
    while (!st2.empty() && st2.top() != st) {
        float b = st1.top(); st1.pop();
        float a = st1.top(); st1.pop();
        switch(st2.top()) {
            case '+' : st1.push(a + b); break;
            case '-' : st1.push(a - b); break;
            case '*' : st1.push(a * b); break;
            case '/' : st1.push(a / b); break;
        }
        st2.pop();
    }
    return;
}

void st1_push(int & front, int & rear, std::string & st, std::stack<float> & st1) {
    bool if_push = false;
    for (int i = front + 1; i < rear; i++)
        if (st[i] <= '9' && st[i] >= '0') {
            if_push = true;
            break;
        }
    if (if_push) {
        st1.push(StringToDate(st.substr(front + 1, rear - front - 1)));
    }
    front = rear;
}

float count(std::string st) {
    std::stack<float> st1;
    std::stack<char> st2;
    int front = -1, rear = 0;
    for (; rear <= st.size(); rear++) {
        if (rear < st.size()) {
            if (st[rear] == '(') {
                st2.push(st[rear]);
                st1_push(front, rear, st, st1);
            } else if (st[rear] == ')') {
                st1_push(front, rear, st, st1);
                if (st1.size() >= 2)
                    subcount(st1, st2, '(');
                st2.pop();
            } else if (st[rear] == '+' || st[rear] == '-') {
                bool fs = false;
                if (st[rear] == '-') { // 判断是否负数
                    int p = rear - 1;
                    while (st[p] == ' ') p--;
                    if (p >= 0 && st[p] == '(' || p == -1) {
                        rear++;
                        while (st[rear] <= '9' && st[rear] >= '0' || st[rear] == ' ' || st[rear] == '.') rear++;
                        st1.push(StringToDate(st.substr(p + 1, rear - p - 1)));
                        front = --rear;
                        fs = true;
                    }
                }
                if (!fs) {  // 不是负数
                    st1_push(front, rear, st, st1);
                    subcount(st1, st2, '(');
                    st2.push(st[rear]);
                }
            } else if (st[rear] == '*' || st[rear] == '/') {
                st1_push(front, rear, st, st1);
                while (!st2.empty() && st2.top() != '(') {
                    if (st2.top() == '*' || st2.top() == '/') {
                        float b = st1.top(); st1.pop();
                        float a = st1.top(); st1.pop();
                        switch(st2.top()) {
                            case '*' : st1.push(a * b); break;
                            case '/' : st1.push(a / b); break;
                        }
                        st2.pop();
                    } else {
                        break;
                    }
                }
                st2.push(st[rear]);
            }
        } else {
            st1_push(front, rear, st, st1);
            /*if (rear > front + 1) {
                st1.push(StringToDate(st.substr(front + 1, rear - front - 1)));
            }
            front = rear;*/
        }
    }
    subcount(st1, st2, '(');
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
    return 0;
}
