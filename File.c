#include "Header.h"y

void spiralToTXT(int** matrix, int Size, int ToGo, int Direction){
    int nameLength = (floor(log10(abs(Size))) + 1)+(1); //Size + ToGo
    int numbaLen = (floor(log10(abs(Size))) + 1);

    if (Direction == 0)
    {
        nameLength = nameLength + 1;
    }else{
        nameLength = nameLength + 2;
    }
    char *resultString = (char *)malloc(nameLength*sizeof(char));
    char* numba = (char *)malloc(numbaLen*sizeof(char));;

    sprintf(numba, "%d_", Size);

    strcat(resultString, "Spiral_");
    strcat(resultString, numba);
    switch (ToGo)
    {
    case 0:
        strcat(resultString, "L_");
        break;
    case 1:
        strcat(resultString, "F_");
        break;
    case 2:
        strcat(resultString, "B_");
        break;
    case 3:
        strcat(resultString, "J_");
        break;
    }

    switch (Direction)
    {
    case 0:
        strcat(resultString, "CW.txt");
        break;
    case 1:
        strcat(resultString, "CCW.txt");
        break;
    }
    
    FILE *file;
    file = fopen(resultString, "w");

    for (int x = 0; x < Size; x++){
        for (int y = 0; y < Size; y++){
            char* resultString = (char *)malloc((floor(log10(abs(matrix[y][x]))) + 1)*sizeof(char));
            sprintf(resultString, "%d ", matrix[y][x]);
            fprintf(file, resultString);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Fájl létrehozva a progam mappájában! (%s)\n", resultString);
}

//https://stackoverflow.com/a/47117431
char *strremove(char *str, const char *sub) {
    char *p, *q, *r;
    if (*sub && (q = r = strstr(str, sub)) != NULL) {
        size_t len = strlen(sub);
        while ((r = strstr(p = r + len, sub)) != NULL) {
            while (p < r)
                *q++ = *p++;
        }
        while ((*q++ = *p++) != '\0')
            continue;
    }
    return str;
}

int** TXTToSpiral(int** Spiral,int* Size, int* ToGo, int* Direction){
    char fileName[19];

    printf("Add meg a fájl nevét: ");
    scanf("%s", &fileName);

    FILE *file = fopen(fileName, "r");
    if (file != NULL){
        bool sSize = false;
        bool sToGo = false;
        bool sDirection = false;

        strremove(fileName,"Spiral_");
        strremove(fileName, ".txt");
        char *nameToken = strtok(fileName, "_");
        while (nameToken != NULL){
            if (!sSize){
                *Size = atoi(nameToken);
                sSize = true;
            }

            if(nameToken[0] == 'L'){
                *ToGo = 0;
                sToGo = true;
            }else if(nameToken[0] == 'F'){
                *ToGo = 1;
                sToGo = true;
            }else if(nameToken[0] == 'B'){
                *ToGo = 2;
                sToGo = true;
            }else if(nameToken[0] == 'J'){
                *ToGo = 3;
                sToGo = true;
            }

            if(nameToken[0] == 'C' && nameToken[1] == 'W'){
                *Direction = 0;
                sDirection = true;
            }else{
                *Direction = 1;
                sDirection = true;
            }

            nameToken = strtok(NULL, "_");
        }
        if (sSize && sToGo && sDirection){
            char * line = NULL;
            size_t len = 0;

            int** newSpiral = createArray(*Size, *Size);
            int x = 0;
            int y = 0;
            

            while (getline(&line, &len, file) != -1) {
                char *token = strtok(line, " ");
                while (token != NULL) {
                    newSpiral[y][x] = atoi(token);
                    ++x;
                    token = strtok(NULL, " ");
                }
                x = 0;
                ++y;
            }
            printf("A spirál sikeresen betölve!\n");
            return newSpiral;
        }else{
            printf("Nem megfelelő fájlnév!\n");
        }              
        fclose(file);
    }else{
        printf("Hiba a fájl megnyitása során!\n");
    }
    return Spiral;
}