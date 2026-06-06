#pragma once

#include <vector>
#include <string>

class Inventory
{
    private:
        std::vector<std::string> items;

    public:
        Inventory();

        void addItem(const std::string& item);

        bool hasItem(const std::string& item) const;

        void showInventory() const;
};