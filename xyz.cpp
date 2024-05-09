#include <stdio.h>

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        switch (i % 3) {
            case 1:
                printf("*");
                break;
            case 2:
                printf(" *");
                break;
            case 0:
                printf("  *");
                break;
        }
        printf("\n");
    }

    return 0;
}
