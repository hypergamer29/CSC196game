#include "Enemy.h"
#include "Renderer/Renderer.h"

void Enemy::Update(float dt) {

	Loki::vec2 forward = Loki::vec2{ 0, -1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * Loki::g_time.GetDeltaTime();
	//Loop round the screen
	m_transform.position.x = Loki::Wrap(m_transform.position.x, (float)Loki::g_renderer.GetWidth());
	m_transform.position.y = Loki::Wrap(m_transform.position.y, (float)Loki::g_renderer.GetHeight());
}
