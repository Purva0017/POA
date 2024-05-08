#include <stdio.h>

void optimal(int incomingStream[], int pages, int frames)
{
    int temp[frames], nextUse[frames], pageFault = 0, s, max_idx, k = 0, i, j;
    for (i = 0; i < frames; i++)
    {
        temp[i] = -1;
        nextUse[i] = 0;
    }
    printf("\nOPTIMAL:\n");
    for (i = 0; i < pages; i++)
    {
        s = 0;
        for (j = 0; j < frames; j++)
        {
            if (incomingStream[i] == temp[j])
            {
                s = 1;
                break;
            }
        }
        if (s==0 && k < frames)
        {
            pageFault++;
            temp[k] = incomingStream[i];
            k++;
        }
        else if (s==0 && k == frames)
        {
            pageFault++;
            for (j = 0; j < frames; j++)
            {
                for (int c = i; c < pages; c++)
                {
                    if (temp[j] != incomingStream[c])
                        nextUse[j]++;
                    else
                        break;
                }
            }
            max_idx = 0;
            for (int m = 1; m < frames; m++)
            {
                if (nextUse[m] > nextUse[max_idx])
                {
                    max_idx = m;
                }
            }
            temp[max_idx] = incomingStream[i];
            for (int c = 0; c < frames; c++)
            {
                nextUse[c] = 0;
            }
            
        }
        printf("\npage %d frame\t", incomingStream[i]);
        for (j = 0; j < frames; j++)
            printf("%d\t", temp[j]);
    }
    printf("\nNumber of Page Faults: %d\n", pageFault);
    printf("Number of Page Hits: %d\n", pages - pageFault);
    // printf("Hit Ratio: %f%%\n", (float)hit / (float)(pageFault + hit) * 100);
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
    

    optimal(incomingStream, pages, frames);

}  