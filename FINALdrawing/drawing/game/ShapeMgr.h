//========================================================
//Jeremy Martinez
//4/2/2017
//Progamming Assignment #6
//Description: Paint
//========================================================

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include "Shape.h"
#include "SettingsMgr.h"
#include "split.h"
using namespace std;
using namespace sf;

// this class is responsible for maintaining all of the shapes that are drawn by the user

class ShapeMgr
{
private:
	vector<DrawingShape*> data; //vector containing all data
public:
	void processMouseMove(RenderWindow& win, SettingsMgr& settings, int mouseX, int mouseY) //processes mouse movement and clicks
	{
		Vector2f mouse = win.mapPixelToCoords(Mouse::getPosition(win));
		//offset so that the object drawn by the click is centered
		mouse.x -= 20;
		mouse.y -= 20;
		if (mouseX > 270 && settings.getShape() == "Circle") //gets circle to draw on click
		{
			Color col = settings.getColor();
			Circle *c = new Circle(col, mouse);
			data.push_back(c);
		}
		else if (mouseX > 270 && settings.getShape() == "Square")//gets square to draw on click
		{
			Color col = settings.getColor();
			Square *c = new Square(col, mouse);
			data.push_back(c);
		}
	}

	void draw(RenderWindow& win) //draws square/circle depending on what is selected
	{
		for (int count = 0; count < data.size(); count++)
		{
			data[count]->draw(win);
		}
	}
	//writes data to file
	void writeToFile(ofstream& file)
	{
		for (int count = 0; count < data.size(); count++)
		{
			file << data[count]->toString() << endl;
		}
	}

	void readFromFile(ifstream& file) //reads data from file from previous use
	{
		Vector2f tempPos;
		unsigned tempCol;
		int tempShape;
		while (file >> tempShape)
		{
			file >> tempCol;
			file >> tempPos.x;
			file >> tempPos.y;
			Color tempColor(tempCol);
			if (tempShape == 0)
			{
				Circle* tempCir = new Circle(tempColor, tempPos);
				data.push_back(tempCir);
			}
			else if (tempShape == 1)
			{
				Square* tempSquare = new Square(tempColor, tempPos);
				data.push_back(tempSquare);
			}

		}
	}


};

