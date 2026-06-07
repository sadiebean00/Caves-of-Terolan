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
                CrateRoom();
                break;

            case gamestate::MermaidLagoon:
                MermaidLagoon();
                break;

            case gamestate::MerpeopleConversation:
                MerpeopleConversation();
                break;

            case gamestate::CanteenRoom:
                CanteenRoom();
                break;

            case gamestate::RuneRoom:
                RuneRoom();
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
                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\nHow to Play\n";
                std::cout << "\nWhen prompted, enter your name. Make sure to add it properly as you cannot change it later!";
                std::cout << "\nChoose options using numbers.";
                std::cout << "\nAnd read all the choices carefully!";
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
             << "\nYou receive a mysterious letter detailing treasures untold in a cave in the town of Terolan"
             << "\nCuriosity got the best of you and you decide to head over to the caves to investigate.";

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
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        std::cout << "\n\n1. Go through the gap by the minecart.";
        std::cout << "\n2. Go through the rusty door.";
        std::cout << "\n3. Turn around and go home.";

        int choice = getChoice();

        switch (choice)
        {
            case 1:
                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\nYou see a small gap between the gap and the minecart and decide to squeeze through.";
                std::cout <<"\nYou get through with a couple of scrapes.";
                pause(3);

                changeState(gamestate::EndlessPit);
                return;

            case 2:
                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\nYou try the rusty door and get it open."
                          << "\nYou walk through the door as someone left it unlocked.";
                pause(3);

                changeState(gamestate::CrateRoom);
                return;

            case 3:
                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\nYou chicken shit. You turned back to go home.";
                
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
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        std::cout << "\n\n1. Use the torch";
        std::cout << "\n2. Feel for the wall";
        std::cout << "\n3. Go back";

        int choice = getChoice();

        switch (choice)
        {
            case 1:
                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\nYou fumble around in your bag for a torch and grab it out." 
                          << "\nThe torch reveals a giant black pit."
                          << "\nYou carefully and safely walk to the exit avoiding the pit.";

                pause(3);

                changeState(gamestate::MermaidLagoon);
                return;

            case 2:
                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\nAgainst your and the narrator's better judgement, you decide to feel along the wall for grip. Or perhaps a lightswitch?"
                          << "\nUnfortunately, you do not see where you are going and miss the massive hole in the floor."
                          << "\nYou continue falling forever and ever and ever and ever...";
                
                pause(3);

                changeState(gamestate::GameOver);
                return;

            case 3:
                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\nYou decide it is too risky to explore this room and decide to head back through the gap."
                          << "\nAfter much swearing, you re-emerge in the daylight back outside the caves."
                          << "\nYou forget why you were here in the first place.        |   ";

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
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
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
        << "\nLight returns to normal and the spirits are no more."
        << "\nnYou look at where the book is and see a group of halflings standing extremely confused."
        << "\nThey thank you for rescuing them as they had been trapped by the spirits for over 20 years, but are now free."
        << "\nBefore you exit out of the cave - they offer you a new contract by the ports of Meraid, to investigate the mystery further.";

        while (true)
        {
            std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
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
        << "\nLight returns to the room and the spirits are no more."
        << "\nThere is nothing located in the room, apart from a piece of parchment which is where the spirits once were."
        << "\nThe parchment describes a new contract by the ports of Meraid, which is ours for the taking if we want to get to the bottom of the mystery.";
        
        while (true)
        {
            std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
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

void Game::CrateRoom()
{
    clearScreen();

    std::cout << "\n###############################################################";
    std::cout << "\n#                     THE CRATE ROOM                          #";
    std::cout << "\n###############################################################";

    std::cout << "\nYou enter a room filled to the brim with various crates."
              << "\nOne of the crates has some documents on the crate lid."
              << "\nThere is also a door at the back of the room.";

    while (true)
    {
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        std::cout << "\n\n1. Read some of the documents on top of the crate";
        std::cout << "\n2. Try the door at the back of the room";
        std::cout << "\n3. Exit via the rusty door";
        std::cout << "\n4. View bag";

        int choice = getChoice();

        switch (choice)
        {
            case 1:
            {
                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\nYou discover a bunch of documents describing the cave's abandonment from 20 years ago.";
                std::cout << "\nThe caves were rumoured to be haunted by an unspecified spirit.";
                std::cout << "\nThere is also a book of runes among the documents.";

                std::cout << "\n1. Pickup the book";
                std::cout << "\n2. Ignore the book";

                int book_choice = getChoice();

                if (book_choice == 1)
                {
                    inventory.addItem("Book of Runes");

                    std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                    std::cout << "\nYou added the Book of Runes to your bag.";

                    pause(2);
                }
                else if (book_choice == 2)
                {
                    std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                    std::cout << "\nYou ignore the book that is lying on the crate. You swear it makes a weird groaning noise and swore at you as you walked away.";

                    pause(2);
                }
                else
                {
                    std::cout << "PLEASE PUT IN THE RIGHT NUMBER";
                }

                break;
            }    
            
            case 2:
            {
                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\nYou try the door, but it will not budge.";
                std::cout << "\nYou loook around and discover that you need to find a key.";
                std::cout << "\nAs you look - you see a small hole in the wall that you might be able to fit through.";

                std::cout << "\n1. Try go through the gap.";
                std::cout << "\n2. Continue searching the room.";
                std::cout << "\n3. Unlock the door.";

                int doorChoice = getChoice();

                switch (doorChoice)
                {
                    case 1:
                        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                        std::cout << "\nYou slide through the gap and emerge in another unfamiliar room.";

                        pause(3);
                        changeState(gamestate::CanteenRoom);
                        return;

                    case 2:
                        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                        std::cout << "\nYou decide against going through the gap and continue to explore the room.";

                        pause(2);
                        break;
                    
                    case 3:
                        if (inventory.hasItem("Key"))
                        {
                            std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                            std::cout << "\nYou get the shiny key out of your bag and place it into the door to unlock the door.";

                            pause(3);
                            changeState(gamestate::RuneRoom);
                            return;
                        }

                        else
                        {
                            std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                            std::cout << "\nWhat part of trying the door earlier did you forget? I don't suppose you forgot it was locked right?";

                            pause(2);
                            break;
                        }

                        break;
                }
                
                break;
            }

            case 3:
                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\nYou decide to go back to the outside, back to ponder on why you are here in the first place.";
                
                pause(2);
                changeState(gamestate::CaveEntrance);

            case 4:
                inventory.showInventory();
                break;

            default:
                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\nReally. Just pick a number that's offered...";
        }
    }
}

void Game::CanteenRoom()
{
    clearScreen();

    std::cout << "\n###############################################################";
    std::cout << "\n#                       THE CANTEEN                           #";
    std::cout << "\n###############################################################";

    std::cout << "\nYou emerge from the gap in a room that is filled with pots and pans, as well as food everywhere and a table.";
    std::cout << "\nYou swear that you see something shiny on the other end of the table.";

    while (true)
    {
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        std::cout << "\n1. Eat the food on the table.";
        std::cout << "\n2. Investigate the shiny object at the end of the table.";

        int choice = getChoice();

        switch (choice)
        {
            case 1:
                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\n You go over to the food that is lying on the table untouched, and start to eat it. After all, this adventure is making you hungry.";
                std::cout << "\n However, the food on the table has been untouched for 20+ years and is seriously deadly.";
                std::cout << "\nWell. Now you know";

                pause(3);
                changeState(gamestate::GameOver);
                return;

            case 2:
                inventory.addItem("Key");

                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\nHeading over to the table you notice a shiny key on the table underneath some documents and reports.";
                std::cout << "\nWhile moving the documents to grab the key, you notice that the supposed hauntings started around 20 years ago when the caves were going to be sold to some unfriendly halflings, known for dodgy dealings.";
                std::cout << "\nYou add the key to your bag and head back to the room with the crates through the small gap in the wall.";
                
                pause(3);
                changeState(gamestate::CrateRoom);
                return;

            default:
                std::cout << "\nJust pick a number. 1 or 2.";
        }
    }
}

void Game::MermaidLagoon()
{
    clearScreen();

    std::cout << "\n###############################################################";
    std::cout << "\n#                  THE MERPEOPLE LAGOON                       #";
    std::cout << "\n###############################################################";

    std::cout << "\nA glittering blue pool greets you as you enter this room. You notice two merpeople in the pool at the end and a corridor leading off somewhere.";
    std::cout << "\nThe merpeople give you a friendly wave as you enter the room.";

    while (true)
    {
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        std::cout << "\n\n1. Approach the merpeople";
        std::cout << "\n2. Go through the hallway";

        int choice = getChoice();

        switch (choice)
        {
            case 1:
                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\nYou approach the merpeople apprehensive if they can understand you and strike up a conversation.";
                std::cout << "\nLuckily for you, they speak perfect basic.";

                pause (3);

                changeState(gamestate::MerpeopleConversation);
                return;

            case 2:
                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\nAsyou walk straight past the merpeople towards the hallway - you're hit with something on the back of your head";
                std::cout << "\nYou're knocked unconcious as the merpeople are laughing and are saying - next don't ignore us, have some manners!";

                pause(3);

                changeState(gamestate::GameOver);
                return;

            default:
                std::cout << "\nAre you scared of what's going to happen? Just pick 1 or 2.";
        }
    }
}

void Game::MerpeopleConversation()
{
    clearScreen();
    std::cout << "\nAh so you speak basic too young adventurer and welcome to our lagoon. I am Pilew, a merperson here in the Caves of Lerolan";
    std::cout << "\nYou must be " << player.GetName() << " it is a pleasure to meet you.";
    std::cout << "\nYou don't look like you're from around here.";

    std::cout << "\nWhere are you from?";

    std::string location;
    std::getline(std::cin, location);

    player.SetLocation(location);

    std::cout << player.GetLocation() <<" you're a bit far from there!";
    std::cout << "\n Well, what do you want to know?";

    while (true)
    {
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        std::cout << "\n\n1. Ask about the caves";
        std::cout << "\n2. Ask about the hallway";
        std::cout << "\n3. End the conversation";

        int choice = getChoice();

        switch (choice)
        {
            case 1:
                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\nAh so you want to know more about the caves?";
                std::cout << "\nThey were brought by some halflings about 20 years ago, to try expell some spirits that were hiding in the walls.";
                std::cout << "\nThey found a way of expelling the spirits and wrote the counter curse in a Book of Runes that was hidden when they disappeared.";
                std::cout << "\nIf the book is reunited with the room, the spirits will dispell and the curse will be lifted.";

                pause(3);
                break;

            case 2:
                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\nAh so you want to know about the hallway.";
                std::cout << "\nThe hallway leads to the infamous Rune Room where the spirits lie and the halflings disappeared.";
                std::cout << "\nDo walk there if you dare, but not all those who go in come out alive.";

                pause(3);
                break;

            case 3:
                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\nSo you've chosen to go through to the Rune Room. Good luck adventurer and I hope we meet again.";

                pause(3);

                changeState(gamestate::RuneRoom);
                return;
            
            default:
                std::cout << "You're testing my patience today. Please pick a valid number.";
        }
    }
}

void Game::RuneRoom()
{
    clearScreen();

    std::cout << "\n###############################################################";
    std::cout << "\n#                     THE RUNE ROOM                           #";
    std::cout << "\n###############################################################";

    std::cout << "\nYou enter the most mesmorising room of the caves, covered in weird symbols around on the walls.";
    std::cout << "\nThere is a magnificient book stand in the middle of the room, surrounded by lots of lights in the floor.";

    while (true)
    {
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        std::cout << "\n\n1. Approach the book stand";
        std::cout << "\n2. Go back";

        int choice = getChoice();

        switch (choice)
        {
            case 1:
            {
                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\nYou approach the book stand and the room starts to spin. The lights flicker and some weird shapes, which resemble spirits appear.";
                std::cout << "\nYou have a couple of choices left what do you do?";

                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\n1. Place the Book of Runes on the stand.";
                std::cout << "\n2. Fight the spirits off with the torch.";
                std::cout << "\n3. Stand there and do nothing.";

                int final_choice = getChoice();

                switch (final_choice)
                {
                    case 1:
                        if (inventory.hasItem("Book of Runes"))
                        {
                            std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                            std::cout << "\nYou place the book down on the book stand and stand back as it flickers between the pages until it stays open on one in particular.";
                            std::cout << "\nThe spirits all go towards the book and a bright light emits through the room.";

                            pause(3);

                            changeState(gamestate::EndingBook);
                            return;
                        }

                        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                        std::cout << "\nYou never found the Book of Runes and the spirits are coming at you. They attack you from all angles and you feel your spirit departing your body.";
                        
                        pause(3);
                        changeState(gamestate::GameOver);
                        return;

                    case 2:
                        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                        std::cout << "\nYou panic and grab the torch from your bag and switch it on. You shine the light wildly at the spirits.";
                        std::cout << "\nThe room goes black for a minute, obscuring your view.";

                        pause(3);
                        changeState(gamestate::EndingTorch);
                        return;
                    
                    case 3:
                        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                        std::cout << "\nWhat are you standing around for. You need to move before the spirits-";
                        std::cout << "\nUh oh, too late.";

                        pause(3);
                        changeState(gamestate::GameOver);
                    
                    default:
                        std::cout << "Pick one last choice!";
                        
                    break;
                }
            }

            case 2:
                std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                std::cout << "\nYou go to turn back, but see that there is no exits or entrances. Not even the way you came in.";

                pause(3);
                break;
            
            default:
                std::cout << "Just pick a number shown.";
        }
    }
}