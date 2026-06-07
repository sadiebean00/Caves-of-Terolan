#include "inventory.h"

#include <iostream>
#include <algorithm>

Inventory::Inventory()
{
    items.push_back("Map");
    items.push_back("Torch");
}

void Inventory::addItem(const std::string& item)
{
    if (!hasItem(item))
    {
        items.push_back(item);
    }
}

bool Inventory::hasItem(const std::string& item) const
{
    return std::find(
        items.begin(),
        items.end(),
        item
    ) != items.end();
}

void Inventory::showInventory() const
{
    std::cout << "\n================================\n";
    std::cout << "           INVENTORY\n";
    std::cout << "================================\n";

    if (items.empty())
    {
        std::cout << "Your bag is empty.\n";
        return;
    }

    for (const auto& item : items)
    {
        std::cout << "-" << item << "\n";
    }

    std::cout << "\nPress ENTER...";
    std::cin.get();
}