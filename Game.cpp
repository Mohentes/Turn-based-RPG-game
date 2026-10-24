#include <iostream>
#include <random>

int main()
{
    // random number gen
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 10);

    // Declaring Values
    int playerHP, enemyHP, Pdamage, Edamage, choice;
    bool isDead, inFight, running;
    isDead = false;
    inFight = false;
    running = true;
    char Playing;

    playerHP = 100;
    enemyHP = 100;

    // Core game loop
    while (running == true)
    {

        // if player died (meaning this is not his first loop show u died)
        if (isDead == true)
        {
            std::cout << "You died! Restart? (Y/N)\n";
        }
        else
        {
            std::cout << "Welcome to the game! Are you ready? (Y/N)\n";
        }

        std::cin >> Playing;

        while (Playing != 'y' && Playing != 'Y' && Playing != 'n' && Playing != 'N')
        {
            std::cout << "Please enter a valid choice\n";
            std::cin >> Playing;
        }

        switch (Playing)
        {
        case 'Y':
        case 'y':
            // Game starts here
            inFight = true;
            // reseting values
            isDead = false;
            enemyHP = 100;
            playerHP = 100;

            std::cout << "While walking to the castle, an enemy appeared!\n";
            std::cout << "What will you do? (Press 1 to hit, 2 to flee(Restarts game))\n";

            while (inFight == true)
            {
                // player enters they choice
                std::cin >> choice;
                while (choice != 1 && choice != 2)
                {
                    std::cout << "Please enter a valid choice\n";
                    std::cin >> choice;
                }

                switch (choice)
                {
                case 1:
                    // Deal Damage to the enemy
                    Pdamage = distrib(gen);
                    enemyHP = enemyHP - Pdamage;
                    std::cout << "You dealt " << Pdamage << " to the enemy. Enemy Hp now: " << enemyHP << std::endl;
                    // enemy deals damage if he's still alive
                    if (enemyHP > 0)
                    {
                        Edamage = distrib(gen);
                        playerHP = playerHP - Edamage;
                        std::cout << "The enemy dealt " << Edamage << " damage. Your HP now is: " << playerHP << std::endl;
                    }
                    else
                    {
                        std::cout << "The enemy is dead! You won\n";
                    }
                    // prompts the player for another choice
                    if (playerHP > 0 && enemyHP > 0)
                    {
                        std::cout << "What will you do? Hit-1 Flee-2\n";
                    }
                    else if(playerHP <= 0 )
                    {
                        std::cout << "You died\n";
                    }
                    break;

                case 2:
                    inFight = false;
                    break;
                }

                if (playerHP <= 0)
                {
                    inFight = false;
                    isDead = true;
                }
                if (enemyHP <= 0)
                {
                    isDead = false;
                    inFight = false;
                }
            }
            break;

        case 'N':
        case 'n':
            std::cout << "Bye!\n";
            running = false;
            break;

        default:
            std::cout << "Bye!\n";
            running = false;
            break;
        }
    }
}