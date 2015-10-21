#include<cstring>
#include<cstdio>

int letters(char & s) {
    if (s <= 'Z')
        s += 'a' - 'A';
    if (s <= 'c')
        return 2 * (s - 'a' + 1);
    if (s <= 'f')
        return 3 * (s - 'd' + 1);
    if (s <= 'i')
        return 4 * (s - 'g' + 1);
    if (s <= 'l')
        return 5 * (s - 'j' + 1);
    if (s <= 'o')
        return 6 * (s - 'm' + 1);
    if (s <= 's')
        return 7 * (s - 'p' + 1);
    if (s <= 'v')
        return 8 * (s - 't' + 1);
    return 9 * (s - 'w' + 1);
}

int Count(char* str, int size) {
    int i = 0, sum = 0;
    while (i < size)
        sum += letters(str[i++]);
    return sum;
}

int main() {
    int N, sum, j;
    char str[101];
    for (j = 0; j < 101; j++)
        str[j] = '+';
    scanf("%d", &N);
    while (N--) {
        scanf("%s", str);
        for (j = 0; j < 101; j++)
            if (str[j] == '+') break;
        sum = Count(str, j - 1);
        printf("%d\n", sum);
    for (; j >= 0; j--)
        str[j] = '+';
    }
    return 0;
}
