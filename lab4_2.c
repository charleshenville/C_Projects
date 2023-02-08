#include <stdio.h>
#include <stdbool.h>

void setGrid(int *plotValues, char *ptrToTopLeft){

    int tentValue;
    for(int cell = 0; cell<441; cell++){
        *(ptrToTopLeft + cell) = ' ';
    }
    for(int i=1; i<=21; i++){
        *(ptrToTopLeft + 20 + 21*9 + i) = '-';
    }
    for(int j=1; j<=21; j++){
        *(ptrToTopLeft + 21 * j - 11) = '|';
    }
    for(int j=0; j<=20; j++){
        tentValue = *(plotValues+j);
        if(tentValue>=(-10) && tentValue<=10){
            *(ptrToTopLeft + j + 21 * (10-tentValue)) = '*';
        }
    }
}

int main(void){

    int order;
    char grid[21][21];

    bool running = true;
    while(running){
        
        int coefs[4] = {0};
        int functionValues[21] = {0};

        bool valid = false;
        while(!valid){
            printf("Enter the order of the function: ");
            scanf(" %d", &order);

            if(order == -1){
                return 0;
            }
            else if(order > 3 || order < 0){
                printf("The order must be between [0, 3].\n");
            }
            else{
                for(int i = 0; i<=order; i++){
                    printf("Enter coefficient of x^%d: ", i);
                    scanf(" %d", &coefs[i]);
                }
                valid = true;
            }
        }

        for(int i=-10; i<=10; i++){
            functionValues[i+10] = coefs[3]*i*i*i + coefs[2]*i*i + coefs[1]*i + coefs[0];
        }

        setGrid(&functionValues[0], &grid[0][0]);
        for(int i=0; i<=20; i++){
            printf(" ");
            for(int j=0; j<=20; j++){
                printf("%c", grid[i][j]);
                if(j==20){
                    printf(" ");
                }
                else{
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
