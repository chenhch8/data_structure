#include<iostream>
#include<ctime>
#include<cstdlib>
#include<queue>

struct E {
    int x;  // 起始时间
    int y;  // 结束时间
};

struct treeNode {
    int edage;
    int depth;
    treeNode(int _ed, int _de): edage(_ed), depth(_de) {}
};


// 按起始时间从小到大进行排序
void quicksort(struct E * temp, int Left, int Right) {
    if (Left >= Right)
        return;
    srand((unsigned)time(0));
    int Center = rand() % (Right - Left + 1) + Left;
    struct E temper = temp[Center];
    temp[Center] = temp[Left];
    int i = Left + 1, j = Right;
    while (i <= j) {
        while (temp[i].x < temper.x && i <= Right) i++;
        while (temp[j].x > temper.x && j > Left) j--;
        if (i <= j) {
            struct E tt = temp[i];
            temp[i++] = temp[j];
            temp[j--] = tt;
        }
    }
    temp[Left] = temp[j];
    temp[j] = temper;
    quicksort(temp, Left, j - 1);
    quicksort(temp, j + 1, Right);
    return;
}

// 从头到尾依次把排好序的时间区域作为根并以该根为起点向右进行广搜生成树，找到深度最深的树
int Count(struct E * Edage, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        std::queue<treeNode> que;
        que.push(treeNode(i, 1));

        while (!que.empty()) {
            treeNode tt = que.front();
            que.pop();

            if (sum < tt.depth)
                sum = tt.depth;

            for (int j = i + 1; j < n; j++) {
                if (Edage[j].x > Edage[tt.edage].y) {  // 判断是否与父节点的时间区域重叠
                    que.push(treeNode(j, tt.depth + 1));
                }
            }

        }
    }
    return sum;
}

int main() {
    int T, N, i, j, counter;
    std::cin >> T;
    while (T--) {
        counter = 0;
        std::cin >> N;
        struct E* Edage = new struct E[N];
        while (N--) {
            std::cin >> i >> j;
            Edage[counter].x = i;
            Edage[counter++].y = j;
        }
        quicksort(Edage, 0, counter - 1);

//for (int k = 0; k < counter; k++)
//    std::cout << temp[k].edage << " " << temp[k].x << std::endl;

       std::cout << Count(Edage, counter) << std::endl;
       if (counter > 0)
           delete []Edage;
    }
    return 0;
}


/*
测试样例
6
2
30 60
1 30
7
27 35
1 24
49 60
15 26
59 70
30 41
40 50
3
10 12
155 168
11 160
4
31 35
1 2
26 30
25 40
9
1 20
30 35
24 28
15 23
50 80
51 60
33 40
37 45
61 70
2
10 12
11 160
*/
