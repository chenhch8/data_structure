
/*用一个变量实现将帅问题*/

#include<iostream>
#include<cstdio>
#define Half_Length 4
#define FullMask 255
#define Mright (FullMask >> Half_Length)
#define Mleft (FullMask << Half_Length)
#define Sright(n, s) (n = (n & Mleft) ^ s)
#define Sleft(n, s) (n = (n & Mright) ^ (s << Half_Length))
#define Gright(n) (n & Mright)
#define Gleft(n) ((n & Mleft) >> Half_Length)

void meather_1() {
    unsigned char a;
    for (Sleft(a, 1); Gleft(a) <= 9; Sleft(a, Gleft(a) + 1))
        for (Sright(a, 1); Gright(a) <= 9; Sright(a, Gright(a) + 1))
            if (Gleft(a) % 3 != Gright(a) % 3) {
                std::cout << "A = " << Gleft(a) << " " << "B = " << Gright(a) << std::endl;
            }
    return;
}

void meather_2() {
    char i = 81;
    while (i--) {
        if (i / 9 % 3 == i % 9 % 3)
            continue;
        std::cout << "A = " << i / 9 + 1 << " " << "B = " << i % 9 + 1 << std::endl;
    }
    return;
}

void meather_3() {
    struct {
        unsigned char a:4;
        unsigned char b:4;
    } i;
    for (i.a = 1; i.a <= 9; i.a++)
        for (i.b = 1; i.b <= 9; i.b++)
            if (i.a % 3 != i.b % 3)
                printf("A = %d B = %d\n", i.a, i.b);
    return;
}

int main()  {
    meather_1();
    std::cout << std::endl;
    meather_2();
    std::cout << std::endl;
    meather_3();
    return 0;
}
