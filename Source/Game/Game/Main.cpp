#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include "Renderer/Moedel.h"
#include "Input/InputSystem.h"
#include "Player.h"
#include "Enemy.h"
#include "Audio/AudioSystem.h"
#include "Framework/Scene.h"

#include <iostream>
#include <vector>
#include <thread>

using namespace std;


class Star {
public:
	Star(const Loki::vec2 pos, const Loki::vec2 vel) : 
		m_pos{ pos }, 
		m_vel{ vel } 
	{}
	
	void Update(int width, int height) {
		m_pos += m_vel * Loki::g_time.GetDeltaTime();
		if (m_pos.x >= width) m_pos.x = 0;
		if (m_pos.y >= height) m_pos.y = 0;
	}

	void Draw(Loki::Renderer& renderer) {
		renderer.DrawPoint(m_pos.x, m_pos.y);
	}

public:
	Loki::vec2 m_pos;
	Loki::vec2 m_vel;

};


int main(int argc, char* argv[]) {

	Loki::seedRandom((unsigned int)time(nullptr));
	Loki::setFilePath("assets");

	Loki::g_renderer.Initialize();
	Loki::g_renderer.CreateWindow("CSC196", 800, 600);

	Loki::g_inputSystem.Initialize();


	Loki::Model model;
	model.Load("star.txt");

	//stars
	Loki::vec2 v{ 5, 5};
	v.Normalize();

	vector<Star> stars;
	for (int i = 0; i < 100; i++) {
		Loki::vec2 pos(Loki::vec2(Loki::randomf((float)Loki::g_renderer.GetWidth()), Loki::randomf((float)Loki::g_renderer.GetHeight())));
		Loki::vec2 vel((float)Loki::randomf(100., 200), 0.0f);

		stars.push_back(Star(pos, vel));
	}

	//movement
	Loki::Transform transform { { 400, 300}, 0, 4 };

	Loki::vec2 position{400, 300};
	float speed = 100.0f;
	constexpr float turnRate = Loki::DegToRad(180.0f);

	Loki::Scene scene;

	scene.Add(new Player{ 100.0f, Loki::Pi, { { 400, 300}, 0, 6}, model });
	for (int i = 0; i < 300; i++) {
		Enemy* enemy = new Enemy{Loki::randomf(200.0f), Loki::Pi, {{Loki::randomf(700.0f), Loki::randomf(600.0f)}, Loki::randomf(Loki::twoPi), 3}, model};
		scene.Add(enemy);
	}

	// main game loop
	bool quit = false;
	while (!quit) {
		Loki::g_renderer.SetColor(0, 0, 0, 0);
		Loki::g_renderer.BeginFrame();

		//update Engine
		Loki::g_time.Tick();
		Loki::g_inputSystem.Update();
		if (Loki::g_inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE)) {
			quit = true;
		}

		//Objects update
		scene.Update(Loki::g_time.GetDeltaTime());

		// draw the ~stars~
		for (auto& star : stars) {
			star.Update(Loki::g_renderer.GetWidth(), Loki::g_renderer.GetHeight());
			Loki::g_renderer.SetColor(255, 255, 255, 255);
			Loki::g_renderer.DrawPoint((float)star.m_pos.x, (float)star.m_pos.y);
		}

		//Draw game
		scene.Draw(Loki::g_renderer);

		Loki::g_renderer.EndFrame();
	}
	return 0;
}