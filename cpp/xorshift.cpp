#include <iostream>
#include <chrono>
#include <random>
#include <string>

using uint32 = unsigned int;

uint32 xorshift32()
{
	static uint32 y = 0x1234abcd;

	y = y ^ (y << 13);
	y = y ^ (y >> 17);
	y = y ^ (y << 15);

	return y;
}

template<typename F>
void bench(const F& f, std::string s = "")
{
	size_t N = 10000000;

	auto start = std::chrono::system_clock::now();

	for (size_t i = 0; i < N; i++) {
		f();
	}

	auto end = std::chrono::system_clock::now();

	auto diff = end - start;

	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
			  << " msec : " << s << std::endl;

	return;
}


int main(int argc, char *argv[])
{
	bench( []{ xorshift32(); },
		   "xorshift32"
		);

	std::random_device rnd;
	bench( [&rnd]{ rnd(); },
		   "std::random"
		);

	std::mt19937 mt(rnd());
	bench( [&mt]{ mt(); },
		   "std::mt19937"
		);
	
	return 0;
}

