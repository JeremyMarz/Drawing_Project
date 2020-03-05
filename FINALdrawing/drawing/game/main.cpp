//========================================================
//Jeremy Martinez
//4/2/2017
//Progamming Assignment #6
//Description: Paint
//========================================================

#include <iostream>
#include <fstream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "SettingsMgr.h"
#include "ShapeMgr.h"
using namespace sf;

int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Drawing");
	window.setFramerateLimit(60);

	SettingsMgr settingsMgr;
	ShapeMgr shapeMgr;
	Vector2f(window.getSize());

	ifstream myFile; //reads default data
	myFile.open("shapes.txt");
	shapeMgr.readFromFile(myFile);

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{

			// "close requested" event: we close the window
			if (event.type == Event::Closed)
			{
				ofstream myFile; //saves current state
				myFile.open("shapes.txt");
				shapeMgr.writeToFile(myFile);
				myFile.close();
				window.close();
			}
			else if (event.type == Event::MouseButtonReleased)
			{
				settingsMgr.processClick(window);
			}
			else if (event.type == Event::MouseMoved && Mouse::isButtonPressed(Mouse::Button::Left))
			{
				shapeMgr.processMouseMove(window, settingsMgr, event.mouseMove.x, event.mouseMove.y);
			}
		}

		window.clear();
		settingsMgr.draw(window);
		shapeMgr.draw(window);
		settingsMgr.drawLine(window, Vector2f(250, 0), Vector2f(250, 600));
		window.display();


	} // end body of animation loop


	return 0;
}