//no saving rouge-like rpg
//death is a simple restart

#include "libs\libraries.h"

int yes_or_no;
int alive = 1;

void begin()
{
    //introduction of the game
    printf("Welcome to a terminal based rpg! REMEMBER: you can't save so this is a rougelike and a death means that you have to start from the beginning\n");
    printf("Just a small project made during a summer vacation");
    printf("Now , you start your journey!\n");

    //game starts
    printf("As you head out on your way , you suddenly see...\n");
}

void first_encounter()
{
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
    scanf("%d" , yes_or_no);

    //checks the yes or no
    //if yes the game continues
    if (yes_or_no == 1)
    {
        printf("you run away");
    }

    //if no you are dead
    else if (yes_or_no == 0)
    {
        printf("you do not run away , and die");
        alive = 0;
        if (alive == 0)
        {
            exit(0);
        }
    }
}

int main(int argc, char const *argv[])
{ 
    begin();
    first_encounter();
    
    return 0;
}
