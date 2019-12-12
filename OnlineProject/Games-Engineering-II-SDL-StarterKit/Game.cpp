#include <Game.h>
#include <iostream>
#include <thread>



using namespace std;

Game::Game() : m_running(false)
{


}

Game::~Game()
{
}

vector<int> Game::numberFromString()
{
	//bool redWin = true;
	not_digit notADigit;

	string stringpos;

	string::iterator end = std::remove_if(stringpos.begin(), stringpos.end(), notADigit);

	string all_numbers(stringpos.begin(), end);
	stringstream ss(all_numbers);
	vector<int> vec;

	int i;
	for (; ss >> i;)
	{
		vec.push_back(i);
	}

	return vec;
}

bool Game::Initialize(const char* title, int xpos, int ypos, int width, int height, int flags)
{

	if (!myClient->Connect()) //If client fails to connect...
	{
		std::cout << "Failed to connect to server..." << std::endl;
		system("pause");
		return -1;
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_p_Window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if(m_p_Window != 0)
		{
			m_p_Renderer = SDL_CreateRenderer(m_p_Window, -1, 0);
			dot.Init(m_p_Renderer);

			if(m_p_Renderer != 0)
			{
				SDL_SetRenderDrawColor(m_p_Renderer, 255, 255, 255, 255);
			}
			else
			{
				return false;
			}

		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	m_running = true;

	return true;
}

void Game::Render()
{
	SDL_RenderClear(m_p_Renderer);
	dot.render(m_p_Renderer);
	SDL_RenderPresent(m_p_Renderer);
}

void Game::Update()
{

}

void Game::HandleEvents()
{
	SDL_Event event;

	SDL_PollEvent(&event);

	dot.handleEvent(event);

		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				m_running = false;
				break;
			default:

				break;
			}
		}
		
	

	

}

bool Game::IsRunning()
{
	return m_running;
}

void Game::CleanUp()
{
	SDL_DestroyWindow(m_p_Window);
	SDL_DestroyRenderer(m_p_Renderer);
	SDL_Quit();
}


