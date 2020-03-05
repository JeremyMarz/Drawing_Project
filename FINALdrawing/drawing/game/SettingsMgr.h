//========================================================
//Jeremy Martinez
//4/2/2017
//Progamming Assignment #6
//Description: Paint
//========================================================

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Shape.h"
using namespace std;
using namespace sf;

class SettingsMgr
{
private:
	CircleShape blueBtn;
	CircleShape redBtn;
	CircleShape greenBtn;
	CircleShape yellowBtn;
	CircleShape purpleBtn;
	RectangleShape squareBtn;
	CircleShape circleBtn;
	int color;
	string shape;
	Color picked;
public:
	SettingsMgr() //default construct, creates all the default buttons
	{
		ifstream myFile;
		myFile.open("settings.txt");
		//reads data from the file to see what is previously selected
		readFromFile(myFile);

		//default button declaration
		Vector2f pos(85, 70);
		blueBtn.setPosition(pos);
		blueBtn.setRadius(20);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);
		blueBtn.setFillColor(Color::Transparent);

		Vector2f pos2(85, 120);
		redBtn.setPosition(pos2);
		redBtn.setRadius(20);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);
		redBtn.setFillColor(Color::Transparent);

		Vector2f pos3(85, 170);
		greenBtn.setPosition(pos3);
		greenBtn.setRadius(20);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);
		greenBtn.setFillColor(Color::Transparent);

		Vector2f pos4(85, 220);
		yellowBtn.setPosition(pos4);
		yellowBtn.setRadius(20);
		yellowBtn.setOutlineThickness(2);
		yellowBtn.setOutlineColor(Color::Yellow);
		yellowBtn.setFillColor(Color::Transparent);

		Vector2f pos5(85, 270);
		purpleBtn.setPosition(pos5);
		purpleBtn.setRadius(20);
		purpleBtn.setOutlineThickness(2);
		purpleBtn.setOutlineColor(Color::Magenta);
		purpleBtn.setFillColor(Color::Transparent);

		Vector2f cirPos(85, 370);
		circleBtn.setPosition(cirPos);
		circleBtn.setRadius(20);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);
		circleBtn.setFillColor(Color::Black);

		Vector2f sqPos(85, 440);
		squareBtn.setPosition(sqPos);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(40, 40));
		squareBtn.setFillColor(Color::Black);
		//makes sure previously selected items are displayed properly
		defaults(myFile);
	}

	void processClick(RenderWindow& win) //processed clicks for each button
	{
		Vector2f mouse = win.mapPixelToCoords(Mouse::getPosition(win));
		//Blue Button Click
		if (blueBtn.getGlobalBounds().contains(mouse))
		{
			color = 1;
			redBtn.setFillColor(Color::Black);
			greenBtn.setFillColor(Color::Black);
			yellowBtn.setFillColor(Color::Black);
			purpleBtn.setFillColor(Color::Black);
			blueBtn.setFillColor(Color::Blue);
			blueBtn.getFillColor();
			picked = Color::Blue;
			cout << "Color was changed to blue." << endl;
		}

		//Red Button Click
		else if (redBtn.getGlobalBounds().contains(mouse))
		{
			color = 2;
			blueBtn.setFillColor(Color::Black);
			greenBtn.setFillColor(Color::Black);
			yellowBtn.setFillColor(Color::Black);
			purpleBtn.setFillColor(Color::Black);
			redBtn.setFillColor(Color::Red);
			redBtn.getFillColor();
			picked = Color::Red;
			cout << "Color was changed to red." << endl;
		}
		//Green Button Click
		else if (greenBtn.getGlobalBounds().contains(mouse))
		{
			color = 3;
			blueBtn.setFillColor(Color::Black);
			redBtn.setFillColor(Color::Black);
			yellowBtn.setFillColor(Color::Black);
			purpleBtn.setFillColor(Color::Black);
			greenBtn.setFillColor(Color::Green);
			greenBtn.getFillColor();
			picked = Color::Green;
			cout << "Color was changed to green." << endl;
		}
		//Yellow Button Click
		else if (yellowBtn.getGlobalBounds().contains(mouse))
		{
			color = 4;
			blueBtn.setFillColor(Color::Black);
			redBtn.setFillColor(Color::Black);
			greenBtn.setFillColor(Color::Black);
			purpleBtn.setFillColor(Color::Black);
			yellowBtn.setFillColor(Color::Yellow);
			yellowBtn.getFillColor();
			picked = Color::Yellow;
			cout << "Color was changed to yellow." << endl;
		}
		else if (purpleBtn.getGlobalBounds().contains(mouse))
		{
			color = 5;
			blueBtn.setFillColor(Color::Black);
			redBtn.setFillColor(Color::Black);
			greenBtn.setFillColor(Color::Black);
			yellowBtn.setFillColor(Color::Black);
			purpleBtn.setFillColor(Color::Magenta);
			purpleBtn.getFillColor();
			picked = Color::Magenta;
			cout << "Color was changed to purple." << endl;
		}
		//Circle Shape Click
		if (circleBtn.getGlobalBounds().contains(mouse))
		{
			shape = "Circle";
			squareBtn.setFillColor(Color::Black);
			circleBtn.setFillColor(Color::White);
			circleBtn.getFillColor();
			cout << "Shape was changed to circle." << endl;
		}
		//Square Shape Click
		if (squareBtn.getGlobalBounds().contains(mouse))
		{
			shape = "Square";
			circleBtn.setFillColor(Color::Black);
			squareBtn.setFillColor(Color::White);
			squareBtn.getFillColor();
			cout << "Shape was changed to square." << endl;
		}
		ofstream myFile;
		myFile.open("settings.txt");
		writeToFile(myFile); //writes data into a file for next use
		myFile.close();
	}

	void draw(RenderWindow& win) //draws all default buttons
	{
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");
		// titles
		Text title("Drawing Color", font, 25);
		title.setPosition(30, 25);
		win.draw(title);
		Text title2("Drawing Shape", font, 25);
		title2.setPosition(30, 320);
		win.draw(title2);

		//Blue Button
		win.draw(blueBtn);
		//Red Button 
		win.draw(redBtn);
		//Blue Button
		win.draw(greenBtn);
		//Yellow Button
		win.draw(yellowBtn);
		//Purple Button
		win.draw(purpleBtn);

		//Curcle Selctor Button
		win.draw(circleBtn);
		//Square Selector Button
		win.draw(squareBtn);


	}

	void writeToFile(ofstream& file) //writes data to a file
	{
		file << shape;
		file << ',';
		file << color;
	}

	void readFromFile(ifstream& file) //reads data from a file
	{
		getline(file, shape, ',');
		file >> color;
	}

	void die(string msg) //tells when to exit
	{
		cout << msg << endl;
		exit(-1);
	}

	void drawLine(RenderWindow& win, Vector2f start, Vector2f end) //draws the default line for the program
	{
		Vertex line[] = { start, end };
		win.draw(line, 2, sf::Lines);
	}

	void defaults(ifstream& file) //makes sure correct default buttons are clicked/if any are previously clicked
	{
		if (color == 1)
		{
			blueBtn.setFillColor(Color::Blue);
			picked = Color::Blue;
		}
		else if (color == 2)
		{
			redBtn.setFillColor(Color::Red);
			picked = Color::Red;

		}
		else if (color == 3)
		{
			greenBtn.setFillColor(Color::Green);
			picked = Color::Green;
		}
		else if (color == 4)
		{
			yellowBtn.setFillColor(Color::Yellow);
			picked = Color::Yellow;
		}
		else if (color == 5)
		{
			purpleBtn.setFillColor(Color::Magenta);
			picked = Color::Magenta;
		}
		else
		{
		}
		if (shape == "Circle")
		{
			circleBtn.setFillColor(Color::White);
		}
		else if (shape == "Square")
		{
			squareBtn.setFillColor(Color::White);
		}
	}

	string getShape() //returns shape selected
	{
		return shape;
	}

	Color getColor() //returns color selected
	{
		return picked;
	}
};
