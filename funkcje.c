#include "funkcje.h"

int room_select()
{
    srand(time(NULL));
    int room_select;
    room_select = rand() % random_range;
    return room_select;
}
void room_insert(int room_select)
{
    char zt[room_txt];
    int trigger;
    FILE* zw;
    if (room_select <= cube_range1)
        trigger = 1;
    if (cube_range1 < room_select && room_select <= cube_range2)
        trigger = 2;
    if (cube_range2 < room_select && room_select <= cube_range3)
        trigger = 3;
    if (cube_range3 < room_select && room_select <= cube_range4)
        trigger = 4;
    if (cube_range4 < room_select && room_select <= cube_range5)
        trigger = 5;
    if (cube_range5 < room_select && room_select <= cube_range6)
        trigger = 6;
    switch (trigger) {
    case 1:
        zw = fopen("teksty/pokoj1.txt", "r");
        fgets(zt, room_txt, zw); //czytanie z pliku.
        printf("\n%s", zt);
        fclose(zw);
        break;
    case 2:
        zw = fopen("teksty/pokoj2.txt", "r");
        fgets(zt, room_txt, zw); //czytanie z pliku.
        printf("\n%s", zt);
        fclose(zw);
        break;
    case 3:
        zw = fopen("teksty/pokoj3.txt", "r");
        fgets(zt, room_txt, zw); //czytanie z pliku.
        printf("\n%s", zt);
        fclose(zw);
        break;
    case 4:
        zw = fopen("teksty/pokoj4.txt", "r");

        fgets(zt, room_txt, zw); //czytanie z pliku.
        printf("\n%s", zt);
        fclose(zw);
        break;
    case 5:
        zw = fopen("teksty/pokoj5.txt", "r");
        fgets(zt, room_txt, zw); //czytanie z pliku.
        printf("\n%s", zt);
        fclose(zw);
        break;
    case 6:
        zw = fopen("teksty/pokoj6.txt", "r");
        fgets(zt, room_txt, zw); //czytanie z pliku.
        printf("\n%s", zt);
        fclose(zw);
        break;
    }
}
int monster()
{
    int monster_kind;
    int monster_might;
    int trigger;
    char zt[monster_txt];
    FILE* zw;
    srand(time(NULL));
    monster_kind = rand() % random_range;
    if (monster_kind <= cube_range1)
        trigger = 1;
    if (cube_range1 < monster_kind && monster_kind <= cube_range2)
        trigger = 2;
    if (cube_range2 < monster_kind && monster_kind <= cube_range3)
        trigger = 3;
    if (cube_range3 < monster_kind && monster_kind <= cube_range4)
        trigger = 4;
    if (cube_range4 < monster_kind && monster_kind <= cube_range5)
        trigger = 5;
    if (cube_range5 < monster_kind && monster_kind <= cube_range6)
        trigger = 6;
    switch (trigger) {
    case 1: //goblin
        zw = fopen("potwory/Goblin.txt", "r");
        fgets(zt, monster_txt, zw); //czytanie z pliku.
        printf("%s\n", zt);
        fclose(zw);
        monster_might = goblin_power;
        break;
    case 2: //ork
        zw = fopen("potwory/Ork.txt", "r");
        fgets(zt, monster_txt, zw); //czytanie z pliku.
        printf("%s\n", zt);
        fclose(zw);
        monster_might = orc_power;
        break;
    case 3: //troll
        zw = fopen("potwory/Troll.txt", "r");
        fgets(zt, monster_txt, zw); //czytanie z pliku.
        printf("%s\n", zt);
        fclose(zw);
        monster_might = troll_power;
        break;
    case 4: //ogr
        zw = fopen("potwory/Ogr.txt", "r");
        fgets(zt, monster_txt, zw); //czytanie z pliku.
        printf("%s\n", zt);
        fclose(zw);
        monster_might = ogre_power;
        break;
    case 5: //gigant
        zw = fopen("potwory/Gigant.txt", "r");
        fgets(zt, monster_txt, zw); //czytanie z pliku.
        printf("%s\n", zt);
        fclose(zw);
        monster_might = giant_power;
        break;
    case 6: //smok
        zw = fopen("potwory/Smok.txt", "r");
        fgets(zt, monster_txt, zw); //czytanie z pliku.
        printf("%s\n", zt);
        fclose(zw);
        monster_might = dragon_power;
        break;
    }
    return monster_might;
}

int combat(int HeroMight, int monster_might)
{
    int Exp;
    int BonusMonsterMight;
    int BonusHeroMight;
    int i;
    if (monster_might == goblin_power)
        Exp = exp_goblin;
    else if (monster_might == orc_power)
        Exp = exp_orc;
    else if (monster_might == troll_power)
        Exp = exp_troll;
    else if (monster_might == ogre_power)
        Exp = exp_ogre;
    else if (monster_might == giant_power)
        Exp = exp_giant;
    else
        Exp = exp_dragon;
    srand(time(NULL));
    BonusHeroMight = HeroMight + rand() % HeropowerBonus_range;
    BonusMonsterMight = monster_might + rand() % MonsterpowerBonus_range;
    puts("Trwa walka");
    for(i=0;i<FightDotIterations;i++)
    {
        printf(".");
        Sleep(fight_sleep);
    }
    puts("");
    if (BonusHeroMight > BonusMonsterMight) {
        puts("Pokonujesz swojego oponenta zyskujac duza ilosc doswiadczenia w walce");
        return Exp;
    }
    else if (BonusHeroMight == BonusMonsterMight) {
        Exp = 20;
        puts("Potwor ucieka. Zyskujesz niewielka ilosc doswiadczenia");
        return Exp;
    }
    else {
        Exp = 0;
        puts("Przegrywasz potyczke. Otrzymujesz 1 punkt obrazen");
        return Exp;
    }
}

int hero(int HeroLevel)
{
    static int HeroLevelCheck = 2;

    static int HeroMight = 2;
    if (HeroLevelCheck < HeroLevel) {
        HeroLevelCheck = HeroLevel;
        HeroMight += 1;

    }

    return HeroMight;
}

int update_hero_experience(int Exp)
{
    static int HeroLevel = 0;
    static int UpdateEXP = 0;
    if (Exp > 0)
        UpdateEXP += Exp;
    if (UpdateEXP >= needed_to_level(HeroLevel)) {
        UpdateEXP = UpdateEXP - needed_to_level(HeroLevel);
        HeroLevel += 1;
        UpdateEXP = 0;
        puts("LEVEL UP");
    }

    return HeroLevel;
}

int update_hero_life(int Exp, int HeroLevel)
{
    static int UpdateLifeToLevel;
    static int Life = 8;
    if (Exp == 0)
        Life -= 1;
    if (UpdateLifeToLevel < HeroLevel) {
        UpdateLifeToLevel = HeroLevel;
        Life = Life + (8 - Life);
        printf("Odnawiam zycie\n");
    }
    printf("Zycie bohatera: %d\n ", Life);
    return Life;
}

void MapNMove()
{
    static int x = map_start;
    static int y = map_start;
    int test = 0;
    printf("\n1.Ide w lewo\n2.Ide w prawo\n3.Ide w gore\n4.Ide w dol\n");
    while (test != 1) {
        if (_kbhit())
        {
            switch (_getch()) {
            case '1':
                x = x - 1;
                if (x < 0) {
                    x = 0;
                    test = 0;
                    printf("Natrafiasz na sciane\n");
                }
                else
                    test = 1;
                break;
            case '2':
                x = x + 1;
                if (x > map_size) {
                    x = map_size;
                    test = 0;
                    printf("Natrafiasz na sciane\n");
                }
                else
                    test = 1;
                break;
            case '3':
                y += 1;
                if (y > map_size) {
                    y = map_size;
                    test = 0;
                    printf("Natrafiasz na sciane\n");
                }
                else
                    test = 1;
                break;
            case '4':
                y -= 1;
                if (y < 0) {
                    y = 0;
                    test = 0;
                    printf("Natrafiasz na sciane\n");
                }
                else
                    test = 1;
                break;
            default:
                printf("Niewlasciwy klawisz\n");
                break;
            }
        }
    }
}
