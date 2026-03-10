#include <stdio.h>

int main() {
    int hit, frames, pages, i, j, k, flag, faults = 0, index = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int frame[frames], page[pages];

    printf("Enter page reference string:\n");
    for(i = 0; i < pages; i++)
        scanf("%d", &page[i]);

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    for(i = 0; i < pages; i++) {
        flag = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == page[i]) {
            hit++;
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            frame[index] = page[i];
            index = (index + 1) % frames;
            faults++;
        }

        for(k = 0; k < frames; k++)
            printf("%d ", frame[k]);
        printf("\n");
    }

    printf("Total Page Faults = %d\n", faults);
    printf("Total page Hit = %d\n", hit);

    return 0;
}
