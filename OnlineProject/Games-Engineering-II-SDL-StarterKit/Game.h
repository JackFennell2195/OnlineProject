#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <Dot.h>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <Client.h>
#include "Dot.h"
#include <SDL.h>



struct not_digit {
	bool operator()(const char c)
	{
		return c != ' ' && !isdigit(c);
	}
};

class Game
{
public:
	Game();
	~Game();






	Client* myClient = new Client("149.153.106.156", 1111);//Create client to connect to server 127.0.0.1 [localhost] on port 1111

	std::string userinput; //holds the user's chat message


	bool Initialize(const char*, int, int, int, int, int);
	void Render();
	void Update();
	void HandleEvents();
	bool IsRunning();
	void CleanUp();

	Dot dot;
	std::vector<int> numberFromString();

private:
	bool m_running;
	SDL_Window* m_p_Window;
	SDL_Renderer* m_p_Renderer;
};
#endif

