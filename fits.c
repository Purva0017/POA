#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

void bestFit(int blocks[], int processes[], int num_blocks, int num_processes){
    int i,j,a,min, min_index;
    for(i=0; i<num_processes; i++){
        min = INT_MAX;
        min_index = -1;
        for(j=0; j<num_blocks; j++){
            if(blocks[j] >= processes[i]){
                a = blocks[j] - processes[i];
                if(min > a){
                    min = a;
                    min_index = j;
                }
            }
        }

        if(min_index == -1){
            printf("%d\t %d\t Not Allocated\n", i+1, processes[i]);
        }else{
            printf("%d\t\t %d\t\t %d\n", i+1, processes[i], min_index+1);
            blocks[min_index] -= processes[i];
        }
        
    }
    printf("\nRemaining Space: ");
    for(i=0; i<num_blocks; i++){
        printf("%d ", blocks[i]);
    }
    printf("\n");
}

void worstFit(int blocks[], int processes[], int num_blocks, int num_processes){
    int i,j,a,max, max_index;
    for(i=0; i<num_processes; i++){
        max = INT_MIN;
        max_index = -1;
        for(j=0; j<num_blocks; j++){
            if(blocks[j] >= processes[i]){
                a = blocks[j] - processes[i];
                if(max < a){
                    max = a;
                    max_index = j;
                }
            }
        }

        if(max_index == -1){
            printf("%d\t\t %d\t\t Not Allocated\n", i+1, processes[i]);
        }else{
            printf("%d\t\t %d\t\t %d\n", i+1, processes[i], max_index+1);
            blocks[max_index] -= processes[i];
        }
        
    }
    printf("\nRemaining Space: ");
    for(i=0; i<num_blocks; i++){
        printf("%d ", blocks[i]);
    }
    printf("\n");
}

void firstFit(int blocks[], int processes[], int num_blocks, int num_processes){
    int i,j,f;
    for(i=0; i<num_processes; i++){
        f=0;
        for(j=0; j<num_blocks; j++){
            if(blocks[j] >= processes[i]){
                blocks[j] -= processes[i];
                printf("%d\t\t %d\t\t %d\n", i+1, processes[i], j+1);
                f=1;
                break;
            }
        }
        if(f==0){
            printf("%d\t\t %d\t\t Not Allocated\n", i+1, processes[i]);
        }
    }
    printf("\nRemaining Space: ");
    for(i=0; i<num_blocks; i++){
        printf("%d ", blocks[i]);
    }
    printf("\n");
}

void nextFit(int blocks[], int processes[], int num_blocks, int num_processes){
    int i,j,f,index, count;
    index = 0;
    for(i=0; i<num_processes; i++){
        f=0;
        count = 0;
        for(j=index; j<num_blocks; j=(j+1)%num_blocks){
            if(count == num_blocks){
                break;
            }
            if(blocks[j] >= processes[i]){
                blocks[j] -= processes[i];
                printf("%d\t\t %d\t\t %d\n", i+1, processes[i], j+1);
                index = j;
                f=1;
                break;
            }
            count++;
        }
        if(f==0){
            printf("%d\t\t %d\t\t Not Allocated\n", i+1, processes[i]);
        }
    }
    printf("\nRemaining Space: ");
    for(i=0; i<num_blocks; i++){
        printf("%d ", blocks[i]);
    }
    printf("\n");
}

void main(){
    int blocks[] = {100, 500, 200, 300, 600};
    int processes[] = {200, 400, 110, 420, 80};
    int num_blocks = sizeof(blocks)/sizeof(blocks[0]);
    int num_processes = sizeof(processes)/sizeof(processes[0]);;
    int input, i, j;
    int a[num_blocks], b[num_processes];

    printf("Enter 1 for First Fit \nEnter 2 for Next Fit \nEnter 3 for Best Fit \nEnter 4 for Worst Fit \nEnter 0 to quit\n");
    
    while(true){
        printf("\nEnter: ");
        scanf("%d", &input);
        for(i=0; i<num_blocks; i++){
            a[i] = blocks[i];
        }
        for(i=0; i<num_blocks; i++){
            b[i] = processes[i];
        }
        if(input == 0){
            break;
        }else if(input == 1){
            printf("First Fit: \n");
            printf("Process No.\t Process Size\t Block No.\n");
            firstFit(a, b, num_blocks, num_processes);
        }else if(input == 2){
            printf("Next Fit: \n");
            printf("Process No.\t Process Size\t Block No.\n");
            nextFit(a, b, num_blocks, num_processes);
        }else if(input == 3){
            printf("Best Fit: \n");
            printf("Process No.\t Process Size\t Block No.\n");
            bestFit(a, b, num_blocks, num_processes);
        }else if(input == 4){
            printf("Worst Fit: \n");
            printf("Process No.\t Process Size\t Block No.\n");
            worstFit(a, b, num_blocks, num_processes);
        }
    }
}