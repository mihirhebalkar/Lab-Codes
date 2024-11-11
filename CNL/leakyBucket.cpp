#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10
#define OUTGOING_RATE 3

void leaky_bucket(int arr[], int n) {
    int bucket = 0, i;

    printf("+-------+----------+-------------+----------+\n");
    printf("| Time  | Incoming | Bucket Size | Outgoing |\n");
    printf("+-------+----------+-------------+----------+\n");

    for (i = 0; i < n; i++) {
        if (arr[i] + bucket <= BUCKET_SIZE) {
            bucket += arr[i];
        } else {
            printf("Overflow! Dropping packet of size %d at time %d\n", arr[i], i);
            bucket = BUCKET_SIZE;
        }

        int outgoing = (bucket > OUTGOING_RATE) ? OUTGOING_RATE : bucket;
        bucket -= outgoing;

        printf("| %5d | %8d | %11d | %8d |\n", i, arr[i], bucket, outgoing);
    }

    while (bucket > 0) {
        int outgoing = (bucket > OUTGOING_RATE) ? OUTGOING_RATE : bucket;
        bucket -= outgoing;

        printf("| %5d |    0     | %11d | %8d |\n", i++, bucket, outgoing);
    }

    printf("+-------+----------+-------------+----------+\n");
    printf("Final bucket size: %d\n", bucket);
}

int main() {
    int packets[] = {4, 7, 2, 10, 1};
    int n = sizeof(packets) / sizeof(packets[0]);

    leaky_bucket(packets, n);

    return 0;
}
