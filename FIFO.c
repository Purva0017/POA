#include <stdio.h>  

void fifo(int incomingStream[], int pages, int frames) {
    int temp[frames],s,pageFaults = 0;
    printf("Incoming\t");
    for (int i = 0; i < frames; i++)
    {
        temp[i] = -1;
        printf("Frame %d\t", i+1);
    }
    printf("\n");
    
    for (int i = 0; i < pages; i++)
    {
        s = 0;
        for (int j = 0; j < frames; j++)
        {
            if (incomingStream[i] == temp[j])
            {
                s += 1;
            }
        }
        if (s == 0) 
        {
            pageFaults++;
            if (pageFaults <= frames) 
            {
                temp[pageFaults-1] = incomingStream[i];
            }
            else
            {
                temp[(pageFaults-1)%frames] = incomingStream[i];
            }
        }
        
        printf("%d\t",incomingStream[i]);
        for (int k = 0; k < frames; k++)
        {
            if (temp[k] == -1)
                printf("-\t");
            else
                printf("%d\t",temp[k]);
        }
        printf("\n");
    }
    printf("Total number of page faults: %d", pageFaults);
    printf("Total number of Hits: %d", (pages-pageFaults));
}

void main()  
{  
    int frames,pages;
    printf("Enter number of frames");
    scanf("%d",&frames);

    printf("Enter number of pages");
    scanf("%d",&pages);
    int incomingStream[pages];

    printf("Enter pages");
    for (int i = 0; i < pages; i++)
    {
        scanf("%d",&incomingStream[i]);
    }
    

    fifo(incomingStream, pages, frames);

}  