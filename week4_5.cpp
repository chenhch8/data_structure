#include<iostream>
#include<queue>

char map[30][30];

struct Node {
    int x, y;
    int depth;
    Node(int _x, int _y, int _d): x(_x), y(_y), depth(_d) {}
};

int count(int N) {
    std::queue<Node> st;
    st.push(Node(0, 0, 1));
    map[0][0] = '1';
    while (!st.empty()) {
        Node no = st.front();
        if (no.x == N - 1 && no.y == N - 1)
            return no.depth;
        st.pop();
        if (no.x < N - 1 && map[no.x + 1][no.y] == '0') {
            st.push(Node(no.x + 1, no.y, no.depth + 1));
            map[no.x + 1][no.y] = '1';
        }
        if (no.x > 0 && map[no.x - 1][no.y] == '0') {
            st.push(Node(no.x - 1, no.y, no.depth + 1));
            map[no.x - 1][no.y] = '1';
        }
        if (no.y < N - 1 && map[no.x][no.y + 1] == '0') {
            st.push(Node(no.x, no.y + 1, no.depth + 1));
            map[no.x][no.y + 1] = '1';
        }
        if (no.y > 0 && map[no.x][no.y - 1] == '0') {
            st.push(Node(no.x, no.y - 1, no.depth + 1));
            map[no.x][no.y - 1] = '1';
        }
    }
    return 0;
}

int main() {
    int N = 1;
    while (N != 0) {
        std::cin >> N;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                std::cin >> map[i][j];
        if (N > 0)
            std::cout << count(N) << std::endl;
    }
}
