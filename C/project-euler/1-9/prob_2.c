#include <stdio.h>

int main(void)
{
    /* code */
    int a1 = 1, a2 = 1, a3 = 2, sum = a3;

    while(a3 < 4000000) {
        a1 = a2;
        a2 = a3;
        a3 = a1 + a2;
        sum += (a3 * !(a3%2));
    }

    printf("%u\n", sum);
    
    return 0;
}
