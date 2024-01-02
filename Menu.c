void userManual(){
    printf(
        "✨[1] - Felhasználói kézikönyv✨\n"
        "Ezt olvasod...\n"
        "✨[2] - Mátrix generálása✨\n"
        "Itt a program megkérdezi, hogy mekkora mátrixot szeretnél, merről induljon és milyen irányba menjen. A mátrix maximum 20-as nagyságú lehet.\n"
        "✨[3] - Jelenlegi mátrix mentése\n"
        "Itt a jelenleg betöltött mátrixot fogja egy mappába menteni. A fájl mindig a program mappájába fog kerülni. A fájl neve a következő sablon szerint jön létre Spiral_*MÉRET*_*KEZDŐ IRÁNY*_*IRÁNY*.txt.\n"
        "✨[4] - Meglévő mátrix betöltése✨\n"
        "Váratlan fordulat, itt pedig a mentett mátrixokat fogja betölteni. A fájl nevét pontosan írd be a fájlformátummal együtt. A fájlnak muszáj követnie a név sablont, különben nem fogja betölteni a mátrixot.\n"
        "✨[5] - Mátrix megjelenítése✨\n"
        "Megmutatja hogy néz ki a mátrix a terminálban.\n"
        "✨[6]- Kilépés✨\n"
        "Kilép a programból és csókok.\n"
    );
}

void menuHandler() {
    // Spirál értékek
    int Size = -1;
    int ToGo = -1; // 0-Le, 1-Fel, 2-Balra, 3-Jobbra
    int Direction = -1; // 0-CW, 1-CCW
    int** Spiral;
    //-----------------

    int input = 0;
    while (input != 6){
        printf(
        "✨Spirál Mátrix Program✨\n"
        "[1] - Felhasználói kézikönyv\n"
        "[2] - Mátrix generálása\n"
        "[3] - Jelenlegi mátrix mentése\n"
        "[4] - Meglévő mátrix betöltése\n"
        "[5] - Mátrix megjelenítése\n"
        "[6] - Kilépés\n"
        );
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
            userManual();
            break;
        case 2:
            inputSpiralParameters(&Size, &ToGo, &Direction);
            Spiral = generateMatrix(Size, ToGo, Direction);
            break;
        case 3:
            if(Size == -1 || ToGo == -1 || Direction == -1){
                inputSpiralParameters(&Size, &ToGo, &Direction);
                Spiral = generateMatrix(Size, ToGo, Direction);
            }
            spiralToTXT(Spiral, Size, ToGo, Direction);
            break;
        case 4:
            Spiral = TXTToSpiral(Spiral, &Size, &ToGo, &Direction);
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