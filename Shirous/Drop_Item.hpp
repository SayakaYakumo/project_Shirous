#pragma once
#include<Siv3D.hpp>
#include "Item.hpp"

class Drop_Item
{
public:

	Drop_Item(ItemType type, int amount) { _type = type, _amount = amount; }

	ItemType get_item() { return _type; }
	int get_amount() { return _amount; }

private:
	ItemType _type;

	int _amount = 0;
};

