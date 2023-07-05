#include "Memory.h"
#include <iostream>

using namespace std;
Loki::MemoryTracker Loki::g_memoryTracker;

void* operator new (size_t size) {
	void* p = malloc(size);

	Loki::g_memoryTracker.Add(p, size);

	return p;
}

void operator delete (void* address, size_t size) {
	Loki::g_memoryTracker.Remove(address, size);
	free(address);

}

namespace Loki {
	void MemoryTracker::Add(void* address, size_t size) {
		m_bytesAllocated += size;
		m_numAllocations += 1;

	}
	void MemoryTracker::Remove(void* address, size_t size) {
		m_bytesAllocated -= size;
		m_numAllocations -= 1;
	}

	void MemoryTracker::DisplayInfo() {
		cout << "Current Bytes Allocated: " << m_bytesAllocated << endl;
		cout << "Current Number Allocations: " << m_numAllocations << endl;

	}

}