#include "stdafx.h"

// debug build with /guard:cf
int main()
{
	using namespace std::chrono_literals;

	std::vector<std::thread> threads;
	// do a clean build, then comment out this for loop, and do an incremental build/link
	for(size_t i = 0; i < 2; ++i) {
		threads.push_back(std::thread([]() {
			std::this_thread::sleep_for(1s);
		}));
	}

	for(size_t i = 0; i < 2; ++i) {
		threads.push_back(std::thread([](size_t num) {
			std::this_thread::sleep_for(num * 1s);
		}, i));
	}
	for(auto& t : threads) {
		t.join();
	}
	std::cout << "not reached" << std::endl;
	return 0;
}
