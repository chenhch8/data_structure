#include<iostream>

int Count(int n) {
    int* pt = new int[n], *temp = new int[n], sum = 0, count = 0;
    for (int i = 0; i < n; i++)
        pt[i] = temp[i] = 0;
    pt[0] = 1;
    while (++count < n) {
        for (int i = 0; i < count; i++) {
            if (pt[i] != 0) {
                for (int j = i; j <= count; j++)
                    temp[j] += pt[i];
            }
        }
        for (int i = 0; i <= count; i++) {
            pt[i] = temp[i];
            temp[i] = 0;
        }
    }
    for (int i = 0; i < n; i++)
        sum += pt[i];
    return sum;
}

int main() {
    int T, n;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        std::cout << Count(n) << std::endl;
    }
    return 0;
}
