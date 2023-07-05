#pragma once
#include<random>

namespace Loki {
	void seedRandom(unsigned int seed) { srand(seed); }
	unsigned int random() { return rand(); }
	unsigned int random(unsigned int max) { return rand() % max; } // 0 - (max -1)
	unsigned int random(unsigned int min, unsigned int max) { return min + random((max - min) + 1); } // min - max
}