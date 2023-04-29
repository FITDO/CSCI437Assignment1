#include "Item.h"

Item::Item (std::string name)
: name_ (name)
{
    
}

std::string Item::getName (void)
{
    return this->name_;
}