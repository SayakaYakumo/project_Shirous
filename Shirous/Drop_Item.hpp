#pragma once
#include<Siv3D.hpp>

class Drop_Item
{
public:

	Drop_Item(String name, int amount) { _name = name, _amount = amount; }

	String get_item() { return _name; }
	int get_amount() { return _amount; }

private:
	String _name;

	int _amount = 0;
};

