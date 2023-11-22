#include<stdio.h>
int isPerfect(int num) {
    int sum = 1;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            if (i * i != num) { 
                sum = sum + i + num / i;
            } else { 
                sum = sum + i;
            }
        }
    }
      if (sum == num && num != 1) {
        return 1;
    } else {
        return 0;
    }
}
int main() {
    int n, count = 0, num = 2; 

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("First %d perfect numbers are:\n", n);

    while (count < n) {
        if (isPerfect(num)) {
            printf("%d\n", num);
            count++;
        }
        num++;
    }

    return 0;
}

