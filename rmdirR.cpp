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
		if (ent->d_type == DT_DIR)
		{
			if( ((string)ent->d_name).compare(".") != 0 && ((string)ent->d_name).compare("..") != 0 )
				list.push_back("/" +(string)ent->d_name);		
		}else {}

		//while (ent = readdir(dir))
			/*if(ent->d_type == DT_DIR)
			{
				cout << ent->d_name << endl;
			} */
		
	}
	closedir(dir); 
	while( !list.empty() )
	{
		cout << "borrando" << endl;
		rmdir((char *)list.back().c_str());
		list.pop_back();
	}
	return 0;
}
