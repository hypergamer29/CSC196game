#pragma once
#include "Core/Core.h"
#include "Renderer/Moedel.h"

namespace Loki {
	class Actor {
	public:
		Actor() = default;
		Actor(const Loki::Transform& transform, const Loki::Model& model) :
			m_transform{ transform },
			m_model{ model }
		{}

		virtual void Update(float dt) = 0;
		virtual void Draw(Loki::Renderer& renderer);
		class Scene* m_scene = nullptr;

	protected:
		Loki::Transform m_transform;
		Loki::Model m_model;
	};
}