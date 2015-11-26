namespace std { class type_info; } // bug patch : for gcc4.4 is old
#include <iostream>
#include <array>
#include <algorithm>

int main(int argc, char *argv[])
{
  std::array<int, 5> ar = {1,2,3,4,5};
  
  int& a = std::get<0>(ar);

  std::cout << a << std::endl;

  std::for_each(ar.begin(), ar.end(),
		[](int x){ std::cout << x << std::endl; }
		);

  return 0;
}
