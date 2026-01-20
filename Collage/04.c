#include <stdio.h>

int main() {
    int n, i, j, count;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nFrequency of elements:\n");

    for (i = 0; i < n; i++) {
        if (arr[i] == -1) {
            continue;
        }

        count = 1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                arr[j] = -1;
            }
        }
        printf("%d occurs %d times\n", arr[i], count);
    }

    return 0;
}
