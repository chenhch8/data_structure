#include<iostream>

int count_ways(int num_egg, int num_baskets) {
    if (num_egg == 1 || num_baskets == 1)
        return 1;
    else if (num_egg > num_baskets)
        return count_ways(num_egg - num_baskets, num_baskets) + count_ways(num_egg, num_baskets - 1);
    else
        return 1 + count_ways(num_egg, num_egg - 1);
}

int main() {
    int T, M, N;
    std::cin >> T;
    while (T--) {
        std::cin >> M >> N;
        std::cout << count_ways(M, N) << std::endl;
    }
    return 0;
}
