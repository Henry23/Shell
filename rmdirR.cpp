#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <cstdlib>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	string path = "./" + (string)argv[0];
	DIR *dir;
	struct dirent *ent;
	vector<string> list;
	if ((dir = opendir((char *)path.c_str()))) 
	{
		ent = readdir(dir);
		cout << ent->d_name << endl; 
		//while (ent = readdir(dir))
			/*if(ent->d_type == DT_DIR)
			{
				cout << ent->d_name << endl;
			} */
		
	}
	closedir(dir);
	return 0;
}