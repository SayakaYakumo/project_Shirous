#pragma once
#include<Siv3D.hpp>
class Item
{
public:

	Item(int x,int y,String name) {
		 ini(x,y);
		 _name = name;
	}

	void ini(int,int);
	void update();
	void draw();

	Rect get_rect() { return _rect; }

	String get_kind() { return _name; }

private:

	Rect _rect;
	String _name;

};

