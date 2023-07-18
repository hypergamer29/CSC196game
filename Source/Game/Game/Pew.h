#pragma once
#include "Framework/Actor.h"

class Pew : public Loki::Actor {
public:
	Pew() = default;
	Pew(float speed, const Loki::Transform& transform, const Loki::Model& model) :
		Actor{ transform, model },
		m_speed{ speed }
	{};

	void Update(float dt) override;

private:
	float m_speed = 0;
	float m_turnRate = 0;

};