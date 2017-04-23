#ifndef funkcje_h
#define funkcje_h
//Need_to_RUN
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
//variables
#define room_txt 170
#define monster_txt 30
//monster_power n exp
#define MonsterpowerBonus_range (HeropowerBonus_range-2)
#define goblin_power 2
#define orc_power (goblin_power+1)
#define troll_power (goblin_power+2)
#define ogre_power (goblin_power+3)
#define giant_power (goblin_power+4)
#define dragon_power (goblin_power+5)
#define exp_goblin 50
#define exp_orc (exp_goblin+exp_goblin)
#define exp_troll (exp_orc+exp_goblin)
#define exp_ogre (exp_troll+exp_goblin)
#define exp_giant (exp_ogre+exp_goblin)
#define exp_dragon (exp_giant+exp_goblin)
//shit u need
#define fight_sleep 100
#define HeropowerBonus_range 6
#define FightDotIterations 10
#define needed_to_level(exp) ((exp)*50 + 50)
//cube throws range n shit
#define random_range 601
#define cube_range1 ((random_range-1)/6)
#define cube_range2 (cube_range1*2)
#define cube_range3 (cube_range1*3)
#define cube_range4 (cube_range1*4)
#define cube_range5 (cube_range1*5)
#define cube_range6 (cube_range1*6)
//map
#define map_size 4
#define map_start (map_size/2)
//functions
int room_select();
void room_insert(int);
int monster();
int hero(int);
int combat(int,int);
int update_hero_experience(int);
int update_hero_life(int,int);
void MapNMove();
#endif // funkcje_h
