#include <stdio.h>
int Fibonacci(int n) {
    if (n <= 1)
        return n;
    return Fibonacci(n-1) + Fibonacci(n-2);
}

int main() {
    int n = 10, i;
    printf("enter the no of fibonacci series wanted to be print ");
    scanf("%d",&n);
    for (i = 0; i < n; i += 2) {
        printf("%d ", Fibonacci(i));
    }
    printf("\n");
    printf("The sum of even indexed terms of Fibonacci series for %d terms is: ", n);
    int sum = 0;
    for (i = 0; i < n; i += 2) {
        sum += Fibonacci(i);
    }
    printf("%d\n", sum);

    return 0;
}
