#pragma once
#include <string>

class Player
{
    private:
        std::string name;
        std::string location;

    public:
        void SetName(const std::string& newName);
        void SetLocation (const std::string& newLocation);

        const std::string& GetName() const;
        const std::string& GetLocation() const;
};