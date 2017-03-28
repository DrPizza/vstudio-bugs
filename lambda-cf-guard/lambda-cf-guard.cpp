#include "stdafx.h"

// debug build with /guard:cf
int main()
{
	using namespace std::chrono_literals;

	std::vector<std::thread> threads;
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

