#include "funkcje.h"
int main()
{
    int GenerateRoom, Exp, MonsterMight, HeroMight, Life,Hero_Level=0;
    puts("########  ##     ## ##    ##  ######   ########  #######  ##    ##");
    puts("##     ## ##     ## ###   ## ##    ##  ##       ##     ## ###   ##");
    puts("##     ## ##     ## ####  ## ##        ##       ##     ## ####  ##");
    puts("##     ## ##     ## ## ## ## ##   #### ######   ##     ## ## ## ##");
    puts("##     ## ##     ## ##  #### ##    ##  ##       ##     ## ##  ####");
    puts("##     ## ##     ## ##   ### ##    ##  ##       ##     ## ##   ###");
    puts("########   #######  ##    ##  ######   ########  #######  ##    ##");
    puts("");
    puts(" ######  ########     ###    ##      ## ##       ######## ########");
    puts("##    ## ##     ##   ## ##   ##  ##  ## ##       ##       ##     ##");
    puts("##       ##     ##  ##   ##  ##  ##  ## ##       ##       ##     ##");
    puts("##       ########  ##     ## ##  ##  ## ##       ######   ########");
    puts("##       ##   ##   ######### ##  ##  ## ##       ##       ##   ##");
    puts("##    ## ##    ##  ##     ## ##  ##  ## ##       ##       ##    ##");
    puts(" ######  ##     ## ##     ##  ###  ###  ######## ######## ##     ##");
    puts("\n");
    system("pause");

    puts("Budzisz sie w ciemnym pokoju nie majac pojecia co sie stalo.\nPo ciezkiej nocy picia z kompanami w tawernie urwal ci sie film.\nPrzy sobie masz tylko miecz. Postanawiasz ruszyc w glab labiryntu z nadzieja na ucieczke.\n");
    while(1) {
        MapNMove();
        GenerateRoom = room_select();
        room_insert(GenerateRoom);
        MonsterMight = monster();
        HeroMight = hero(Hero_Level);
        Exp = combat(HeroMight, MonsterMight);
        Hero_Level = update_hero_experience(Exp);
        Life = update_hero_life(Exp, Hero_Level);
        printf("Poziom postaci %d",Hero_Level+1);
        printf("\n");
        if (Hero_Level == 13) {
            puts("Sciana rozpada sie ukazujac wyjscie z labiryntu jestes wolny i ruszasz ku kolejnej przygodzie");
            break;
        }
        if (Life == 0) {
            puts("Umierasz. Twoj poziom zycia spadl do 0");
            break;
        }
    }
    system("pause");
    return 0;
}
