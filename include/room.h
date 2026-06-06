#pragma once

class game;

class room
{
    public:
        virtual ~room() = default;

        virtual void enter(game& game) = 0;
};