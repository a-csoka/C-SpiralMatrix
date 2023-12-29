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
        
    }
    printf("A program futása befejeződött! >:(\n");
}