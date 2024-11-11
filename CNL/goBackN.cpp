#include <stdio.h>
#include <stdlib.h>


#define TOTAL_FRAMES 10
#define WINDOW_SIZE 4

int simulateTimeout(int frame) {
    return rand() % 10 < 3;
}

void goBackN() {
    int frame_to_send = 0;
    int ack_expected = 0;

    printf("\nGo-Back-N Protocol Simulation:\n");

    while (ack_expected < TOTAL_FRAMES) {
        while (frame_to_send < ack_expected + WINDOW_SIZE && frame_to_send < TOTAL_FRAMES) {
            printf("Sending Frame %d\n", frame_to_send);
            frame_to_send++;
        }

        if (simulateTimeout(ack_expected)) {
            printf("\nTimeout! Frame %d not received.\n", ack_expected);
            printf("Resending all frames from %d to %d\n", ack_expected, frame_to_send - 1);
            frame_to_send = ack_expected;
        } else {
            printf("Received ACK for Frame %d\n", ack_expected);
            ack_expected++;
        }

    }

    printf("All frames sent and acknowledged successfully!\n");
}

int main() {
    srand(10);
    goBackN();
    return 0;
}
