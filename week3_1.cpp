#include<iostream>

int main() {
    int a[40], N, M;
    a[0] = 1; a[1] = 2;
    for (int i = 2; i < 40; i++)
        a[i] = a[i - 1] + a[i - 2];
    std::cin >> N;
    while (N--) {
        std::cin >> M;
        std::cout << a[M - 1] << std::endl;
    }
}
