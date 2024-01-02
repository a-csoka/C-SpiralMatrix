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
}

void TXTToSpiral(int** matrix, int* Size, int* ToGo, int* Direction){

}