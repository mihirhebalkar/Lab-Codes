#include <stdio.h>
#include <stdlib.h>


#define TOTAL_FRAMES 10
#define WINDOW_SIZE 4

int simulateTimeout(int frame) {
    return rand() % 10 < 3;
}

void selectiveRepeat() {
    int frame_to_send = 0;
    int window_start = 0;
    int acked[TOTAL_FRAMES] = {0};

    printf("\nSelective Repeat Protocol Simulation:\n");

    while (window_start < TOTAL_FRAMES) {
        while (frame_to_send < window_start + WINDOW_SIZE && frame_to_send < TOTAL_FRAMES) {
            printf("Sending Frame %d\n", frame_to_send);
            frame_to_send++;
        }

        for (int i = window_start; i < frame_to_send; i++) {
            if (!acked[i] && !simulateTimeout(i)) {
                printf("Received ACK for Frame %d\n", i);
                acked[i] = 1;
            }
        }

        for (int i = window_start; i < frame_to_send; i++) {
            if (!acked[i]) {
                printf("\nTimeout! Resending Frame %d\n", i);
                printf("Sending Frame %d\n", i);
                acked[i] = 1;
            }
        }

        while (window_start < TOTAL_FRAMES && acked[window_start]) {
            window_start++;
        }

        printf("\nWindow moved to frame %d\n", window_start);
    }

    printf("All frames sent and acknowledged successfully!\n");
}

int main() {
    srand(10);
    selectiveRepeat();
    return 0;
}
