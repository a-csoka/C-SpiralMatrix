#include "Header.h"

void inputSpiralParameters(int* Size, int* ToGo, int* Direction){
    printf("Add meg a spirál méretét!(NxN)\nN=");
    while (scanf("%d", Size) == 0){
        printf("Csak számot adhatsz meg!\n");
        while (getchar() != '\n');
        printf("N=");
    }
    while (*Size < 1 || *Size > 20){
        printf("A méret 1 és 20 között legyen!\n");
        while (getchar() != '\n');
        printf("N=");
        scanf("%d", Size);
    }

    printf(
        "Add meg a spirál kezdeti irányát!\n"
        "[1] - Le\n"
        "[2] - Fel\n"
        "[3] - Balra\n"
        "[4] - Jobbra\n"
        "Kezdeti irány="
    );
    while (scanf("%d", ToGo) == 0){
        printf("Csak számot adhatsz meg!\n");
        while (getchar() != '\n');
        printf("Kezdeti irány=");
    }
    while (*ToGo < 1 || *ToGo > 4){
        printf("Az irány 1 és 4 között legyen!\n");
        while (getchar() != '\n');
        printf("Kezdeti irány=");
        scanf("%d", ToGo);
    }
    *ToGo = --*ToGo;

    printf(
        "Add meg a spirál irányát!\n"
        "[1] - Óramutató járásával megegyező\n"
        "[2] - Óramutató járásával ellentétes\n"
        "Irány="
    );
    while (scanf("%d", Direction) == 0){
        printf("Csak számot adhatsz meg!\n");
        while (getchar() != '\n');
        printf("Irány=");
    }
    while (*Direction < 1 || *Direction > 2){
        printf("Az irány 1 és 2 között legyen!\n");
        while (getchar() != '\n');
        printf("Irány=");
        scanf("%d", Direction);
    }
    *Direction = --*Direction;
}

void nextStep(int* x, int* y,int* current, char* step, char steps[4]){
    if (*current+1 == 4){
        *current = 0;
    }else{
        *current = ++*current;
    }
    *step = steps[*current];

    switch (*step)
    {
        case 'D':
            *y = ++*y;
            break;
        case 'L':
            *x = --*x;
            break;
        case 'U':
            *y = --*y;
            break;
        case 'R':
            *x = ++*x;
            break;
    }
}

//https://stackoverflow.com/questions/5201708/how-to-return-a-2d-array-from-a-function-in-c
int** createArray(int m, int n)
{
    int* values = calloc(m*n, sizeof(int));
    int** rows = malloc(m*sizeof(int*));
    for (int i=0; i<m; ++i)
    {
        rows[i] = values + i*n;
    }
    return rows;
}

int** generateMatrix(int Size, int ToGo, int Direction){
    char steps[4];
    int x;
    int y;
    if(Direction == 0){
        switch (ToGo)
        {
        case 0: // Le
            if (Size % 2 == 0){
                steps[0] = 'D';
                steps[1] = 'R';
                steps[2] = 'U';
                steps[3] = 'L';
                x = 0;
                y = 0;
            }else{
                steps[0] = 'U';
                steps[1] = 'L';
                steps[2] = 'D';
                steps[3] = 'R';
                x = Size-1;
                y = Size-1;
            }
            break;
        case 1: // Fel
            if (Size % 2 == 0){
                steps[0] = 'U';
                steps[1] = 'L';
                steps[2] = 'D';
                steps[3] = 'R';
                x = Size-1;
                y = Size-1;
            }else{
                steps[0] = 'D';
                steps[1] = 'R';
                steps[2] = 'U';
                steps[3] = 'L';
                x = 0;
                y = 0;
            }
            break;
        case 2: // Balra
            if (Size % 2 == 0){
                steps[0] = 'L';
                steps[1] = 'D';
                steps[2] = 'R';
                steps[3] = 'U';
                x = Size-1;
                y = 0;
            }else{
                steps[0] = 'R';
                steps[1] = 'U';
                steps[2] = 'L';
                steps[3] = 'D';
                x = 0;
                y = Size-1;
            }
            break;
        case 3: // Jobbra
            if (Size % 2 == 0){
                steps[0] = 'R';
                steps[1] = 'U';
                steps[2] = 'L';
                steps[3] = 'D';
                x = 0;
                y = Size-1;
            }else{
                steps[0] = 'L';
                steps[1] = 'D';
                steps[2] = 'R';
                steps[3] = 'U';
                x = Size-1;
                y = 0;
            }
            break;
        }
    }else{
        switch (ToGo)
        {
        case 0: // Le
            if (Size % 2 == 0){
                steps[0] = 'D';
                steps[1] = 'L';
                steps[2] = 'U';
                steps[3] = 'R';
                x = Size-1;
                y = 0;
            }else{
                steps[0] = 'U';
                steps[1] = 'R';
                steps[2] = 'D';
                steps[3] = 'L';
                x = 0;
                y = Size-1;
            }
            break;
        case 1: // Fel
            if (Size % 2 == 0){
                steps[0] = 'U';
                steps[1] = 'R';
                steps[2] = 'D';
                steps[3] = 'L';
                x = 0;
                y = Size-1;
            }else{
                steps[0] = 'D';
                steps[1] = 'L';
                steps[2] = 'U';
                steps[3] = 'R';
                x = Size-1;
                y = 0;
            }
            break;
        case 2: // Balra
            if (Size % 2 == 0){
                steps[0] = 'L';
                steps[1] = 'U';
                steps[2] = 'R';
                steps[3] = 'D';
                x = Size-1;
                y = Size-1;
            }else{
                steps[0] = 'R';
                steps[1] = 'D';
                steps[2] = 'L';
                steps[3] = 'U';
                x = 0;
                y = 0;
            }
            break;
        case 3: // Jobbra
            if (Size % 2 == 0){
                steps[0] = 'R';
                steps[1] = 'D';
                steps[2] = 'L';
                steps[3] = 'U';
                x = 0;
                y = 0;
            }else{
                steps[0] = 'L';
                steps[1] = 'U';
                steps[2] = 'R';
                steps[3] = 'D';
                x = Size-1;
                y = Size-1;
            }
            break;
        }
    }
    char step = steps[0];

    int** matrix = createArray(Size, Size); 
    int count = Size * Size;
    int current = 0;

    while (count != 0)
    {
        switch (step)
        {
            case 'D':
                if (y < Size && matrix[x][y] == 0)
                {
                    matrix[x][y] = count;
                    ++y;
                    --count;
                }else{
                    --y;
                    nextStep(&x, &y, &current, &step, steps);
                }                    
                break;
            case 'L':
                if (x > -1 && matrix[x][y] == 0)
                {
                    matrix[x][y] = count;
                    --x;
                    --count;
                }else{
                    ++x;
                    nextStep(&x, &y, &current, &step, steps);
                }
                break;
            case 'U':
                if (y > -1 && matrix[x][y] == 0)
                {
                    matrix[x][y] = count;
                    --y;
                    --count;
                }else{
                    ++y;
                    nextStep(&x, &y, &current, &step, steps);
                }
                break;
            case 'R':
                if (x < Size && matrix[x][y] == 0)
                {
                    matrix[x][y] = count;
                    ++x;
                    --count;
                }else{
                    --x;
                    nextStep(&x, &y, &current, &step, steps);
                }
                break;
        }
    }

    return matrix;
}

void displaySpiral(int** matrix, int Size){
    for (int x = 0; x < Size; x++){
        int Length = 1;
        for (int y = 0; y < Size; y++){
            int currLen = floor(log10(abs(matrix[y][x]))) + 1; // https://stackoverflow.com/questions/3068397/finding-the-length-of-an-integer-in-c
            if (Length < currLen)
            {
                Length = currLen;
            }
        }

        for (int y = 0; y < Size; y++){
            int currLen = floor(log10(abs(matrix[y][x]))) + 1; // https://stackoverflow.com/questions/3068397/finding-the-length-of-an-integer-in-c
            char *resultString = (char *)malloc(Length*sizeof(char));
            char *numba = (char *)malloc(currLen*sizeof(char));
            for (int i = 0; i < Length-currLen; ++i) {
                strcat(resultString, " ");
            }
            sprintf(numba, "%d", matrix[y][x]);
            strcat(resultString, numba);
            printf("%s ", resultString);
        }
        printf("\n");
    }
}