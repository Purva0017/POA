#include<stdio.h>

void lru(int incomingStream[], int pages, int frames) {
    int temp[frames], recent[frames];
    int s, pageFaults = 0, lru;

    printf("Incoming\t");
    for (int i = 0; i < frames; i++)
    {
        printf("Frame %d\t",(i+1));
    }
    printf("\n");
    

    for (int i = 0; i < frames; i++)
    {
        temp[i] = -1;
        recent[i] = 0;
    }

    for (int i = 0; i < pages; i++)
    {
        s = 0;
        for (int j = 0; j < frames; j++)
        {
            if (incomingStream[i] == temp[j])
            {
                s += 1;
                recent[j] = i+1;
                break;
            }
        }
        if (s==0)
        {
            pageFaults++;
            lru = 0;
            for (int n = 1; n < frames; n++)
            {
                if (recent[n] < recent[lru])
                {
                    lru = n;
                }
            }
            temp[lru] = incomingStream[i];
            recent[lru] = i+1;
        }
        
        printf("%d\t",incomingStream[i]);
        for (int k = 0; k < frames; k++)
        {
            if(temp[k] == -1)
                printf("-\t");
            else
                printf("%d\t", temp[k]);
        }
        printf("\n");
    }
    
    printf("Total number of page faults: %d\n", pageFaults);
    printf("Total number of Hits: %d", (pages - pageFaults));
}

void main() {
    int frames,pages;

    printf("Enter number of frames: ");
    scanf("%d",&frames);

    printf("Enter number of pages: ");
    scanf("%d",&pages);

    int incomingStream[pages];
    printf("Enter pages: ");
    for (int i = 0; i < pages; i++)
    {
        scanf("%d",&incomingStream[i]);
    }
    
    lru(incomingStream, pages, frames);
}