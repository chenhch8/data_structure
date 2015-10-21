#include<iostream>

void Do(int n) {
    int* pt = new int[n], count = 0, tag = 1;
    for (int i = 0; i < n; i++)
        pt[i] = i + 1;
    int i;
    for (i = 0;;i++) {
        if (i >= n)
            i = 0;
        if (pt[i] != 0) {
            if (tag == 1) {
                std::cout << pt[i] << " ";
                pt[i] = tag = 0;
                ++count;
                if (count >= n)
                    break;
            } else {
                tag++;
            }
        }
    }
    std::cout << std::endl;
    delete []pt;
    return;
}

int main() {
    int T, n;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        Do(n);
    }
    return 0;
}
