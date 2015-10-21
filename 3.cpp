#include<iostream>

void Count(int n) {
    int i = 0, k = 1, a[n];
    for (int j = 0; j < n; j++)
        a[j] = 0;
    while (k <= n) {
        int count = 0;
        for (;; i++) {
            if (i == n)
                i = 0;
            if (a[i] == 0) {
                count++;
                if (count == k) {
                    a[i] = k++;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    return;
}

int main() {
    int T, n;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        Count(n);
    }
    return 0;
}
