#pragma once

#include "player.h"
#include "inventory.h"
#include "gamestate.h"

class Game
{ 
    private:
        Player player;
        Inventory inventory;
        gamestate currentState;

    public:
        Game();
        void run();
        void changeState(gamestate newState);
        Player& getplayer();
        Inventory& getInventory();

        static void clearScreen();
        
        static void pause(int seconds);

        static int getChoice();

        void TitleScreen();

        void StartAdventure();

        void CaveEntrance();

        void EndlessPit();

        void GameOver();

        void BookEnding();

        void TorchEnding();

        void CrateRoom();

        void MermaidLagoon();

        void MerpeopleConversation();

        void CanteenRoom();

        void RuneRoom();
};