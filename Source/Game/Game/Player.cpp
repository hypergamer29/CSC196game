#include "Player.h"
#include "Pew.h"
#include "Framework/Scene.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"

void Player::Update(float dt) {
	//Loki::AudioSystem audioSystem;
	//audioSystem.AddAudio("shoot", "beep-07a.wav");

	//Rotation
	float rotate = 0;
	if (Loki::g_inputSystem.GetKeyDown(SDL_SCANCODE_A)) rotate = -1;
	if (Loki::g_inputSystem.GetKeyDown(SDL_SCANCODE_D)) rotate = 1;
	m_transform.rotation += rotate * m_turnRate * Loki::g_time.GetDeltaTime();

	//Moving
	float thrust = 0;
	if (Loki::g_inputSystem.GetKeyDown(SDL_SCANCODE_W)) thrust = 1;

	Loki::vec2 forward = Loki::vec2{ 0, -1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * thrust * Loki::g_time.GetDeltaTime();

	//Loop round the screen
	m_transform.position.x = Loki::Wrap(m_transform.position.x, (float)Loki::g_renderer.GetWidth());
	m_transform.position.y = Loki::Wrap(m_transform.position.y, (float)Loki::g_renderer.GetHeight());

	//Fire Pew
	if (Loki::g_inputSystem.GetKeyDown(SDL_SCANCODE_SPACE) && 
		!Loki::g_inputSystem.GetPreviousKeyDown(SDL_SCANCODE_SPACE)) {
		//create pew
		Loki::Transform transform(m_transform.position, m_transform.rotation, 1);
		Pew* pew = new Pew{400, m_transform, m_model };
		m_scene->Add(pew);
		//audioSystem.PlayOneShot("shoot");
		
	}
}
