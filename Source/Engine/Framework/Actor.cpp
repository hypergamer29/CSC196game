#include "Framework/Actor.h"

namespace Loki {
	void Actor::Draw(Loki::Renderer& renderer) {
		m_model.Draw(renderer, m_transform);
	}
}