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
        "Add meg a spirál kezdeti irányát!\n",
        "[1] - Le\n",
        "[2] - Fel\n",
        "[3] - Balra\n",
        "[4] - Jobbra\n",
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
    *ToGo = --*ToGo

    printf(
        "Add meg a spirál irányát!\n",
        "[1] - Óramutató járásával megegyező\n",
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
    *Direction = --*Direction
}
