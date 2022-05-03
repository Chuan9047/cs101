#include <stdio.h>

int _sum(int x, int y) {
    return x + y; 
}

int _sub(int x, int y) {
    return x - y; 
}

int _mult(int x, int y) {
    return x * y; 
}

int _div(int x, int y) {
    return x / y; 
}

int _power(int x, int y) {
    int sum = 1;
    for(int i = 0; i < y; i++) {
        sum *= x;
    }
    return sum;
}

int main(void) {
    int x, y, choice;
    int (*operation[5])(int, int);
    operation[0] = _sum;
    operation[1] = _sub;
    operation[2] = _mult;
    operation[3] = _div;
    operation[4] = _power;

    printf("Enter two integer: ");
    scanf("%d%d", &x, &y);

    printf("Enter 0:+, 1:-, 2:*, 3:/, 4:^ ");
    scanf("%d", &choice);
    printf("%d", operation[choice](x, y));

    return 0;
}
