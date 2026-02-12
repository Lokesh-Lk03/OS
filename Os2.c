#include <stdio.h>

int main() {
    int frames, pages;
    int page_faults = 0;
    int i, j, k, pos, min;
    int time = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int frame[frames], page[pages], last_used[frames];

    // Initialize frames
    for (i = 0; i < frames; i++) {
        frame[i] = -1;
        last_used[i] = 0;
    }

    printf("Enter page reference string:\n");
    for (i = 0; i < pages; i++)
        scanf("%d", &page[i]);

    printf("\nPage\tFrames\n");

    for (i = 0; i < pages; i++) {
        int found = 0;
        time++;

        // Check if page is already in frame
        for (j = 0; j < frames; j++) {
            if (frame[j] == page[i]) {
                found = 1;
                last_used[j] = time;
                break;
            }
        }

        if (!found) {
            // Find empty frame
            pos = -1;
            for (j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // If no empty frame, find LRU page
            if (pos == -1) {
                min = last_used[0];
                pos = 0;
                for (j = 1; j < frames; j++) {
                    if (last_used[j] < min) {
                        min = last_used[j];
                        pos = j;
                    }
                }
            }

            frame[pos] = page[i];
            last_used[pos] = time;
            page_faults++;
        }

        // Display frames
        printf("%d\t", page[i]);
        for (j = 0; j < frames; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}
