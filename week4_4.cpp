#include<iostream>

void count(int M, int start, int temp, int goal) {
    if (M < 1) return;
    count(M - 1, start, goal, temp);
    std::cout << "move disk " << M << " from peg " << start << " to peg " << goal << std::endl;
    count(M - 1, temp, start, goal);
    return;
}

int main() {
    int N, M;
    std::cin >> N;
    while (N--) {
        std::cin >> M;
        count(M, 1, 2, 3);
    }
    return 0;
}
