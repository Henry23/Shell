#include <iostream>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
	std::cout << "hi there";

	if(rmdir(argv[0]) == 0)
	{

	}else{
		
	}
	return 0;
}