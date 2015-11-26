namespace std { class type_info; } // bug patch : for gcc4.4 is old
#include <iostream>
#include <vector>
#include <algorithm>

int
main(int argc, char *argv[])
{
  std::vector<bool> v(8,false);
  
  v[5] = true;
  v[7].flip();
  
  //bool& x = v[3];
  bool x = v[3];
  
  std::cout << "v[3] : " << x << std::endl;
  
  std::for_each(v.begin(), v.end(),
		[](bool x){ std::cout << x << std::endl; }
		);
  
  return 0;
}
