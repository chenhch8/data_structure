#include<iostream>

bool Judge(int * a) {
    bool if_true;
    int k;
    for (int i = 10; i > 1; i--) {
        for (k = 0; k < i; k++)
             if (a[k] == i) break;
        if_true = false;
        for (int j = 0; j <= k + 1; j++) {
            if (j != k)
                if (a[j] == a[k] - 1) {
                    if_true = true;
                    break;
                }
        }
        if (if_true == false)
            return false;
        for (int j = k; j <= i - 2; j++)
            a[j] = a[j + 1];
    }
    return true;
}

int main() {
    int a[10];
    int N;
    std::cin >> N;
    while (N--) {
        for (int i = 0; i < 10; i++)
            std::cin >> a[i];
        if (Judge(a))
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    }
}

/*
6
2 1 4 3 7 6 10 9 8 5
1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1
3 1 2 4 5 6 7 8 9 10
3 2 1 5 8 7 6 4 10 9
3 5 4 7 6 2 1 9 10 8

*/