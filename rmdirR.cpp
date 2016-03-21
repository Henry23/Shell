#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <cstdlib>
#include <stack>
#include <cstring>
#include <cstdio>

using namespace std;

int rmdir_R(const char *);

int main(int argc, char const *argv[])
{
	string root = "./" + (string)argv[0];
	const char *path = (char *)root.c_str();
	rmdir_R(path);	// recursively
	return 0;
}

int rmdir_R(const char *path)
{
	DIR *dir = opendir(path);
	size_t path_len = strlen(path);
	int r = -1;
	if (dir)
	{
		struct dirent *ent;
		r = 0;
		while (!r && (ent=readdir(dir)))
		{
			int r2 = -1;
			char *buf;
			size_t len;
			if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
				continue;
			len = path_len + strlen(ent->d_name) + 2;
          	buf = (char *)malloc(len);
          	if (buf)
          	{
          		struct stat statbuf;
          		snprintf(buf, len, "%s/%s", path, ent->d_name);
          		if (!stat(buf, &statbuf))
          		{
          			if (S_ISDIR(statbuf.st_mode))
          				r2 = rmdir_R(buf);
          			else
          				r2 = unlink(buf);
          		}
          		free(buf);
          	}
          	r = r2;
          }
      closedir(dir);
  }
  if (!r)
  	r = rmdir(path);
  return r;
}
