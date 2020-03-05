//========================================================
//Jeremy Martinez
//4/2/2017
//Progamming Assignment #6
//Description: Paint
//========================================================

#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

//Abstract base class for Circle and Square classes

class DrawingShape
{
private:
	Color color; //color of shape
	Vector2f position; //position of shape
	int type; //holds type of shape
public:
	DrawingShape() //default constructor
	{
		color = Color::Blue;
	};

	DrawingShape(Color choosen, Vector2f pos) //constructor
	{
		color = choosen;
		position = pos;
	}

	Vector2f getPosition() //returns position of shape
	{
		return position;
	}
	Color getColor() //returns current selected color of shape
	{
		return color;
	}
	void setType(int t) //sets type of shape (0 or 1)
	{
		type = t;
	}
	int getType() //returns type of shape
	{
		return type;
	}

	virtual string toString() = 0; //private virtual function for turning data into a string
	virtual void draw(RenderWindow& win) = 0; //private virtual function from drawing a shape
};

//Circle Class

class Circle : public DrawingShape
{
private:
	CircleShape cir;
public:
	Circle(Color selected, Vector2f current) : DrawingShape(selected, current) //Circle constructor, creates circle
	{
		cir.setRadius(20);
		cir.setOutlineThickness(2);
		cir.setPosition(current);
		cir.setOutlineColor(selected);
		cir.setFillColor(selected);
		setType(0); //sets type to 0 for data output
	}

	string toString() //turns data into a string for data output
	{
		unsigned colorInt = getColor().toInteger();
		string color = to_string(colorInt);
		string x = to_string(getPosition().x);
		string y = to_string(getPosition().y);
		string type = to_string(getType());
		string input = type + " " + color + " " + x + " " + y;
		return input;
	}

	void draw(RenderWindow& win) //draws circle
	{
		win.draw(cir);
	}

};

//Square function, creates square

class Square : public DrawingShape
{
private:
	RectangleShape squ;
public:
	Square(Color selected, Vector2f current) : DrawingShape(selected, current)
	{
		squ.setSize(Vector2f(40, 40));
		squ.setOutlineThickness(2);
		squ.setPosition(current);
		squ.setOutlineColor(selected);
		squ.setFillColor(selected);
		setType(1); //sets type for data output
	}


	string toString()
	{
		unsigned colorInt = getColor().toInteger(); //turns data into a string from data output
		string color = to_string(colorInt);
		string x = to_string(getPosition().x);
		string y = to_string(getPosition().y);
		string type = to_string(getType());
		string input = type + " " + color + " " + x + " " + y;
		return input;
	}

	void draw(RenderWindow& win) //draws square
	{
		win.draw(squ);
	}
};

