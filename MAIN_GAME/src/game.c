//no saving rouge-like rpg
//death is a simple restart

#include "header_files\libraries.h"

int health = 100;
int armor = 0;
int have_pistol = 0;
int massacre = 1;
int loot = 0;
int pistol_ammo = 6;
int trade = 0;
int trade_choice;

void intro() {
    //introduction of the game
    printf("Welcome to a terminal based rpg! REMEMBER: you can't save so this is a rougelike and a death means that you have to start from the beginning\n");
    printf("Now , you start your journey!\n");
}

void first_encounter() {
    int yes_or_no;
    //game starts
    printf("As you head out on your way , you suddenly see...\n");

    //1st enemy encounter
    //NOTE:all enemy encounters after the first 5 will be random
    printf("A goblin!\n");
    printf("what do you do?!\n");
    printf("You don't even have a single weapon! Maybe you can run away...\n");

    /*NOTE:need to fix
    REASON:1 or 0 isn't a good choice to make choices in a game about making choices
    ---------------------*/
    printf("Will you run away? (1(standing for yes)/0(standing for no))\n");
    /*---------------------*/

    //first yes or no question , the main mechanic of the game
    scanf_s("%d" , &yes_or_no);

    //checks the yes or no
    //if yes the game continues
    if (yes_or_no == 1)
    {
        printf("you run away\n");
    }

    //if no you are dead
    else if (yes_or_no == 0)
    {
        printf("you do not run away , and die\n");
        exit(0);
    }
}

void second_encounter() {
    //bunch of integers I don't think making these global would be a good idea
    int fight_or_run;
    int fight_or_run2;
    int chainsaw_pickup;
    int weapon_choice;

    //run away because of the fact that if you don't run you die and have to restart
    printf("as you run away you see , it a pistol\n");
    //you take the pistol
    printf("you take the pistol\n");
    have_pistol = 1;
    //you have the pistol
    printf("you see a path and you decide to follow it\n");
    printf("and, as you are walking you see a group of goblins with a box full of loot!\n");

    printf("do you fight them or run away? (1 to fight , 0 to run away)\n");

    scanf_s("%d" , &fight_or_run);

    if (fight_or_run == 1)
    {
        printf("you approach the goblins and challenge them to a fight\n");
        printf("the challenge: if you win they give you all their loot , if you lose...\n");
        printf("your dead.\n");

        printf("what do you fight them with?\n");
        printf("Health: 100\nArmor:0\n");
        printf("1:Fists\n2: Pistol , Ammo = 6\n");
        printf("press 1 for the fists and 2 for the pistol\n");

        scanf_s("%d" , &weapon_choice);

        if (weapon_choice == 1)
        {
            printf("you try to go closer to hurt them but when you are only a few steps away ,\n");
            printf("one of them pulls out a chainsaw\n");
            printf("you got absolutely destroyed by the chainsaw\n");

            _Exit(0);
        }
        else if (weapon_choice == 2)
        {
            printf("you take out the pistol and shoot a goblin\n");
            printf("you panicked and instead of hitting your shot in the goblin's head\n");
            pistol_ammo--;
            printf("you instead hit it the goblin in the chest\n");
            printf("still the goblin dies and the others rush you\n");
            printf("a goblin takes out a chainsaw\n");
            printf("you can't counter that! (1 to fight , 0 to run)\n");

            scanf_s("%d" , &fight_or_run2);

            if(fight_or_run2 == 0)
            {
                printf("you run away as fast as you can and keep running\n");
                massacre = 0;
            }
            else if (fight_or_run2 == 1)
            {
                printf("you shoot your pistol and..\n");
                printf("it's a headshot!\n");
                printf("somehow you could counter that\n");

                printf("the goblin dropped it's chainsaw\n");
                massacre = 1;

                printf("you pick it up and absolutely slaughter the other goblins\n");
                chainsaw_pickup = 1;
                printf("during all of this a trader sees you and is terrified because he thinks that he's next\n");
            }
        }
    }

    else if (fight_or_run == 0)
    {
        printf("you run away\n");
        massacre = 0;
        printf("and as you run away you see a trader\n");
    }
}

void first_trade() {
    int count = 100;

    printf("The trader says:\n");
    if (massacre == 1)
    {
        trade = 1;

        printf("please don't hurt me\n");
        printf("I have a family, if you want anything i will give it to you for free\n");
        printf("you explain to him that you are just an adventurer and need supplies and have loads of loot with you\n");
        printf("he continues:\n");
        printf("well in that case , hello there lone traveller how may i help you?\n");
        printf("do you want any weapons? Some mana (health) or armor?\n");
        printf("No worry's you can take anything you want from here.\n");
        printf("list of items:\n");
        printf("1.Mana potion(restores 50 health) 50 loot\n2.Wooden armor(gives 20 armor)50 loot\n3.Pistol ammo(gives 1 clip/6 bullets) 60 loot\n");
        printf("4.Pistol(if you lose your pistol or for duel wielding, included with 3 clips) 90 loot\n5.Shotgun(a pump aciton shotgun)150 loot\n6.Shotgun shells(for a shotgun or a super shotgun) 80 loot\n");
        printf("input 7 to leave the shop\n");
        printf("Loot:100\n");
    }
    else if (massacre == 0)
    {
        trade = 0;
        printf("hello there lone traveller\n");
        printf("how are you doing do you want to buy anything from me?\n");
        printf("type 'exit' to leave the shop\n");
        printf("Loot:100\n");
    }
}

void ActualTrade() {
  scanf_s("%d" , &trade_choice);

  //a trading system using the list in the above function
  if (trade == 1)
  {
      if (trade_choice == 1)
      {
          printf("you bought a mana potion\n");
          loot -= 50;
          printf("Loot:%d\n" , loot);
      }
      else if (trade_choice == 2)
      {
          printf("you bought a wooden armor\n");
          loot -= 20;
          printf("Loot:%d\n" , loot);
      }
      else if (trade_choice == 3)
      {
          printf("you bought a pistol ammo\n");
          loot -= 60;
          printf("Loot:%d\n" , loot);
      }
      else if (trade_choice == 4)
      {
          printf("you bought a pistol\n");
          loot -= 90;
          printf("Loot:%d\n" , loot);
      }
      else if (trade_choice == 5)
      {
          if (loot <= 150)
          {
              printf("you don't have enough loot\n");
          }
          else
          {
              printf("you bought a shotgun\n");
              loot -= 150;
              printf("Loot:%d\n" , loot);
          }
      }
      else if (trade_choice == 6)
      {
          printf("you bought a shotgun shells\n");
          loot -= 80;
          printf("Loot:%d\n" , loot);
      }
      else if (trade_choice == 7)
      {
          printf("you left the shop\n");
      }
      else
      {
          printf("you entered an invalid command\n");
      }

    }

    if (trade == 0)
    {
      scanf_s("%d" , &trade_choice);

      //copy and pasted the above mentioned list
          if (trade_choice == 1)
          {
              printf("you bought a mana potion\n");
              loot -= 50;
              printf("Loot:%d\n" , loot);
          }
          else if (trade_choice == 2)
          {
              printf("you bought a wooden armor\n");
              loot -= 20;
              printf("Loot:%d\n" , loot);
          }
          else if (trade_choice == 3)
          {
              printf("you bought a pistol ammo\n");
              loot -= 60;
              printf("Loot:%d\n" , loot);
          }
          else if (trade_choice == 4)
          {
              printf("you bought a pistol\n");
              loot -= 90;
              printf("Loot:%d\n" , loot);
          }
          else if (trade_choice == 5)
          {
              printf("you bought a shotgun\n");
              loot -= 150;
              printf("Loot:%d\n" , loot);
          }
          else if (trade_choice == 6)
          {
              printf("you bought a shotgun shells\n");
              loot -= 80;
              printf("Loot:%d\n" , loot);
          }
          else if (trade_choice == 7)
          {
              printf("you left the shop\n");
          }
          else
          {
              printf("you entered an invalid command\n");
          }
    }
}

void third_encounter() {
  printf("do you follow the path? \n");
  printf("you know the one that you decided to go on?\n just asking if you want to continnue \n");
}

void GameLoop() {
  intro();
  first_encounter();
  second_encounter();
  first_trade();
  ActualTrade();
  third_encounter();
}

int main(int argc, char const *argv[]) {

    GameLoop();

    return 0;
}
