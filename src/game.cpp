#include "game.h"

#include <iostream>
#include <thread>
#include <chrono>

#ifdef _WIN32
#include <cstdlib>
#endif

Game::Game()
{
    currentState = gamestate::Title;
}

Player& Game::getplayer()
{
    return player;
}

Inventory& Game::getInventory()
{
    return inventory;
}

void Game::changeState(gamestate newState)
{
    currentState = newState;
}

void Game::clearScreen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Game::pause(int seconds)
{
    std::this_thread::sleep_for(
        std::chrono::seconds(seconds)
    );
}

int Game::getChoice()
{
    int choice;

    while (true)
    {
        std::cout << "\nWhat do you want to do?: ";

        if (std::cin >> choice)
        {
            std::cin.ignore(10000, '\n');
            return choice;
        }

        std::cin.clear();
        std::cin.ignore(10000, '\n');

        std::cout << "\n Please enter a valid number.\n";
    }
}

void Game::run()
{
    while(currentState != gamestate::Exit)
    {
        switch (currentState)
        {
            case gamestate::Title:
                TitleScreen();
                break;

            case gamestate::CaveEntrance:
                CaveEntrance();
                break;

            case gamestate::EndlessPit:
                EndlessPit();
                break;

            case gamestate::CrateRoom:
                break;

            case gamestate::MermaidLagoon:
                break;

            case gamestate::MerpeopleConversation:
                break;

            case gamestate::CanteenRoom:
                break;

            case gamestate::RuneRoom:
                break;

            case gamestate::EndingBook:
                BookEnding();
                break;

            case gamestate::EndingTorch:
                TorchEnding();
                break;

            case gamestate::GameOver:
                GameOver();
                break;

            default:
                break;
        }
    }
}

void Game::TitleScreen()
{
    clearScreen();

    std::cout << "\n###############################################################";
    std::cout << "\n# Welcome to the Mystical Isles of Lerolan: Caves of Teralon! #";
    std::cout << "\n###############################################################\n";

    while (true)
    {
        std::cout << "\n1. Play Game";
        std::cout << "\n2. Options";
        std::cout << "\n3. Quit\n";

        int choice = getChoice();

        switch (choice)
        {
            case 1:
                StartAdventure();
                return;

            case 2:
                std::cout << "\nHow to Play\n";
                std::cout << "\nChoose options using numbers.";
                std::cout << "\nExplore the caves and uncover the mystery.\n";

                pause(3);
                break;

            case 3:
            changeState(gamestate::Exit);
            return;

            default:
            std::cout << "\nInvalid choice.\n";
        }
    }
}

void Game::StartAdventure()
{
    clearScreen();

    std::string name;

    std::cout << "\nWhat is your name adventurer? ";

    std::getline(std::cin, name);

    player.SetName(name);

    std::cout << "\nAh yes now I remember, welcome "
    << player.GetName();

    std::cout<< "\nLet us start your journey!\n"
             << "\nYou recieve a mysterious letter detailing treasures untold in a cave in the town of Terolan"
             << "\nCuriosity got the best of you and you decide to head over to the caves.";

    pause(3);

    changeState(gamestate::CaveEntrance);
}

void Game::CaveEntrance()
{
    clearScreen();

    std::cout << "\n###############################################################";
    std::cout << "\n#                     CAVE ENTRANCE                           #";
    std::cout << "\n###############################################################";

    std::cout <<"\nYou're standing outside the derelict caves."
              << "\nThere is a minecart blocking the entrance of the cave."
              << "\nThere is also a rusty looking door to the right.";

    while (true)
    {
        std::cout << "\n\n1. Go through the gap by the minecart.";
        std::cout << "\n2. Go through the rusty door.";
        std::cout << "\n3. Turn around and go home.";

        int choice = getChoice();

        switch (choice)
        {
            case 1:
                std::cout << "\nYou see a small gap between the gap and the minecart and decide to squeeze through.";
                pause(3);

                changeState(gamestate::EndlessPit);
                return;

            case 2:
                std::cout << "\nYou try the rusty door and get it open."
                          << "\nYou walk through the door";
                pause(3);

                changeState(gamestate::CrateRoom);
                return;

            case 3:
                std::cout << "\nYou chicken shit.";
                
                changeState(gamestate::GameOver);
                return;

            default:
                std::cout << "\nCan you not read? Pick a number between 1-3.";
        }
    }
}

void Game::EndlessPit()
{
    clearScreen();

    std::cout << "\n###############################################################";
    std::cout << "\n#                     THE DARK ROOM                           #";
    std::cout << "\n###############################################################";

    std::cout << "\nYou walk into a pitch black room. You can't see anything.";

    while (true)
    {
        std::cout << "\n\n1. Use the torch";
        std::cout << "\n2. Feel for the wall";
        std::cout << "\n3. Go back";

        int choice = getChoice();

        switch (choice)
        {
            case 1:
                std::cout << "\nThe torch reveals a giant black pit."
                          << "\nYou carefully and safely walk to the exit avoiding the pit.";

                pause(3);

                changeState(gamestate::MermaidLagoon);
                return;

            case 2:
                std::cout << "\nYou fall into the pit."
                          << "\nYou continue falling forever and ever and ever and ever...";
                
                pause(3);

                changeState(gamestate::GameOver);
                return;

            case 3:
                std::cout << "\nYou fumble for the door handle and head back out.";

                pause(3);

                changeState(gamestate::CaveEntrance);
                return;

            default:
                std::cout << "\nAgain can you not read?? Pick a number between 1-3.";
        }
    }
}

void Game::GameOver()
{
    clearScreen();

    std::cout << "\n###############################################################";
    std::cout << "\n#                         GAME OVER                           #";
    std::cout << "\n###############################################################";

    std::cout << "\nYour adventure is over.";

    while (true)
    {
        std::cout << "\n\n1. Play Again?";
        std::cout << "\n2. Quit";

        int choice = getChoice();

        switch (choice)
        {
            case 1:
                inventory = Inventory();

                changeState(gamestate::Title);
                return;

            case 2:
                changeState(gamestate::Exit);
                return;

            default:
                std::cout << "\nReally? Pick a number 1 or 2.";
        }
    }
}

void Game::BookEnding()
{
    clearScreen();

    std::cout << "\n###############################################################";
    std::cout << "\n#                        BOOK ENDING                          #";
    std::cout << "\n###############################################################";

    std::cout
        << "\nThe spirits vanish."
        << "\nThe trapped halflings are freed."
        << "\nA letter drops in front of your character. You open it."
        << "\nDear " << player.GetName() << " a new adventure awaits for you in the Ports of Meraid.";

        while (true)
        {
            std::cout << "\n\n1. Play Again";
            std::cout << "\n2. Quit";

            int choice = getChoice();

            switch (choice)
            {
                case 1:
                    inventory = Inventory();

                    changeState(gamestate::Title);
                    return;

                case 2:
                    changeState(gamestate::Exit);
                    return;

                default:
                    std::cout << "\nDon't fail me now. Just pick a number between 1 and 2. AND IT HAS TO BE WHOLE";
            }
        }
}

void Game::TorchEnding()
{
    clearScreen();

    std::cout << "\n###############################################################";
    std::cout << "\n#                       TORCH ENDING                          #";
    std::cout << "\n###############################################################";

    std::cout
        << "\nThe spirits disappear."
        << "\nOnly a mysterious parchment remains."
        << "\nYou pickup the parchment and read;"
        << "\nDear " << player.GetName() << " your expertise is needed in the ports of Meraid.";
        
        while (true)
        {
            std::cout << "\n\n1. Play Again";
            std::cout << "\n2. Quit";

            int choice = getChoice();

            switch (choice)
            {
                case 1:
                    inventory = Inventory();

                    changeState(gamestate::Title);
                    return;

                case 2:
                    changeState(gamestate::Exit);
                    return;

                default:
                    std::cout << "\nOnce more please enter a number of 1 or 2.";
            }
        }
}