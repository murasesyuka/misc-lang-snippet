#include <iostream>
#include <chrono>
#include <random>
#include <string>

uint32_t xorshift32()
{
	static uint32_t y = 0x1234abcd;

	y = y ^ (y << 13);
	y = y ^ (y >> 17);
	y = y ^ (y << 15);

	return y;
}

uint32_t xorshift128()
{ 
	static uint32_t x = 123456789;
	static uint32_t y = 362436069;
	static uint32_t z = 521288629;
	static uint32_t w = 88675123; 
	
	uint32_t t;
	
	t = x ^ (x << 11);
	x = y; y = z; z = w;
	w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
	
	return w;
}

template<typename F>
void bench(const F& f, std::string s = "")
{
	using std::chrono::system_clock;

	size_t N = 10000000;

	auto start = system_clock::now();

	for (size_t i = 0; i < N; i++) {
		f();
	}

	auto end = system_clock::now();

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

	bench( []{ xorshift128(); },
		   "xorshift128"
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

