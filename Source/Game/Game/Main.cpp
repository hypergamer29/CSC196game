#include "Core/Random.h"
#include "Core/FileIO.h"
#include "Core/Memory.h"
#include "Core/Time.h"
#include "Renderer/Renderer.h"
#include <iostream>

using namespace std;

int main() {
	Loki::g_memoryTracker.DisplayInfo();
	int* p = new int;
	Loki::g_memoryTracker.DisplayInfo();
	delete p;
	Loki::g_memoryTracker.DisplayInfo();
	
	Loki::Time timer;
	for(int i= 0; i < 100000000; i++) {}
	cout << timer.GetElapsedSeconds() << endl;

	/*auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++) {}
	auto end = std::chrono::high_resolution_clock::now();

	cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;*/
	

	//// File get locations
	//cout << Loki::getFilePath() << endl;
	//Loki::setFilePath("Assets");
	//cout << Loki::getFilePath() << endl;
	//size_t size;
	//Loki::getFileSize("game.txt", size);
	//cout << size << endl;

	//// Get file info
	//std::string s;
	//Loki::readFile("game.txt", s);
	//cout << s << endl;

	//Loki::seedRandom((unsigned int)time(nullptr));
	//for (int i = 0; i < 4; i++) {
	//	cout << Loki::random(7, 32) << endl;
	//}

}