void menuHandler() {
    printf(
    "✨Spirál Mátrix Program✨\n"
    "[1] - Felhasználói kézikönyv\n"
    "[2] - Mátrix generálása\n"
    "[3] - Jelenlegi mátrix mentése\n"
    "[4] - Meglévő mátrix betöltése\n"
    "[5] - Mátrix megjelenítése\n"
    "[6] - Kilépés\n"
    );

    // Spirál értékek
    int Size = -1;
    int ToGo = -1; // 0-Le, 1-Fel, 2-Balra, 3-Jobbra
    int Direction = -1; // 0-CW, 1-CCW
    int** Spiral;
    //-----------------

    int input = 0;
    while (input != 6){
        printf("Utasítás: ");
        while (scanf("%d", &input) == 0){
            printf("Csak számot adhatsz meg!\n");
            while (getchar() != '\n');
            printf("Utasítás: ");
        }
        while (input < 1 || input > 6){
            printf("Az utasítás 1 és 6 között legyen!\n");
            while (getchar() != '\n');
            printf("Utasítás: ");
            scanf("%d", &input);
        }

        switch (input)
        {
        case 1:
            printf("kezikönyv\n");
            break;
        case 3:
            
        case 2:
            inputSpiralParameters(&Size, &ToGo, &Direction);
            Spiral = generateMatrix(Size, ToGo, Direction);
            break;
        case 5:
            if(Size == -1 || ToGo == -1 || Direction == -1){
                inputSpiralParameters(&Size, &ToGo, &Direction);
                Spiral = generateMatrix(Size, ToGo, Direction);
            }
            displaySpiral(Spiral, Size);
            break;
        }
        
    }
    printf("A program futása befejeződött! >:(\n");
}