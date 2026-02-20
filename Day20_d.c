/*#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    int sum = 0;

    int *hash = (int *)calloc(20001, sizeof(int));
    int offset = 10000;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0)
            count++;

        if(hash[sum + offset] > 0)
            count += hash[sum + offset];

        hash[sum + offset]++;
    }

    printf("%d", count);

    free(hash);
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    int sum = 0;

    int *hash = (int *)calloc(20001, sizeof(int));
    int offset = 10000;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0)
            count++;

        if(hash[sum + offset] > 0)
            count += hash[sum + offset];

        hash[sum + offset]++;
    }

    printf("%d", count);

    free(hash);
    return 0;
}