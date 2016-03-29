#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h>
#include <stdlib.h>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <sys/utsname.h>
#include <fnmatch.h>

using namespace std;

const string Commands[] = {"mkdir","cd","chmod","rmdir","rm","cat","ln","ps","kill","uname","ls","q","exec"};
const int Commands_size = 13;
char path[FILENAME_MAX];
vector<string> split(string,char);
int verify_Commands(string);
void mkdir(vector<string>);
void cd(vector<string>);
void chmod(vector<string>);
void rmdir(vector<string>);
void rm(vector<string>);
void cat(vector<string>);
void ln(vector<string>);
void ps(vector<string>);
void kill(vector<string>);
void uname(vector<string>);
void ls(vector<string>);
void exec(vector<string>);
bool cmp( const dirent *, const dirent *);
void processdir( const dirent *);
int filter( const dirent *);
void pse(long);

int main(int argc, char const *argv[]){
	getcwd(path,sizeof(path));//get the path object from current path
	while(true){
		char commandLine[256];
		cout <<"Mi_shell> "<< path<<"$ ";
	    cin.getline(commandLine,256);
	    vector<string> separate = split(commandLine,'|');
	    for(int i=0;i<separate.size();i++){
	    	string indvcommand = separate.at(i);
		    vector<string> command = split(indvcommand,' ');
		    if( command.size() == 0 ){
		    	cout << "empty input at command " << i << endl;
		    	continue;
		    }
		    if( find(command.begin(), command.end(), ">" ) != command.end())
		    {
		    	cout << "hi there " << endl;
		    }else if (find(command.begin(), command.end(), "<") != command.end()){
	
		    }else if(find(command.begin(), command.end(), ">&") != command.end()){
	
		    }else if(find(command.begin(), command.end(), ">>") != command.end()){
	
		    }else {
		    	int index = verify_Commands(command[0]);
		    	//cout << "index" << index << endl;
		    	if(index != -1)
		    	{
		    		if( Commands[index] == "mkdir" )
		    			mkdir(command);
		    		else if (Commands[index] == "cd" )
		    			cd(command);
		    		else if (Commands[index] == "chmod")
		    			chmod(command);
		    		else if (Commands[index] == "rmdir")
		    			rmdir(command);
		    		else if (Commands[index] == "rm")
		    			rm(command);
		    		else if (Commands[index] == "cat")
		    			cat(command);
		    		else if (Commands[index] == "ln")
		    			ln(command);
		    		else if (Commands[index] == "ps")
		    			ps(command);
		    		else if (Commands[index] == "kill")
		    			kill(command);
		    		else if (Commands[index] == "uname")
		    			uname(command);
					else if (Commands[index] == "ls")
		    			ls(command);
		    		else if (Commands[index] == "exec")
		    			exec(command);
		    		else if (Commands[index] == "q"){
		    			cout<<"Shell terminada"<<endl;
		    			exit(0);
		    		}
		    		else
		    			cout << "something must be wrong" << endl;
		    	}else if (index == -1)
		    			cout << "Command not found" << endl;
		    }
		    getcwd(path,sizeof(path));
	    }
	}
	return 0;
}


void uname(vector<string> command)
{
	if ( command.size() == 2 )
	{
	  int z;
	  struct utsname _uname;
	  z = uname(&_uname);

		if ( z == -1 ){
	    fprintf(stderr, "%s: uname(2)\n", strerror(errno));
	    exit(1);
	  }

	  if( command[1] == "-a" ){
	    printf("\n System  = '%s';\n", _uname.sysname);
			printf(" Kernel  = '%s';\n", _uname.nodename);
			printf(" Release = '%s';\n", _uname.release);
			printf(" Version = '%s';\n", _uname.version);
			printf(" Machine = '%s';\n", _uname.machine);
	  }else if ( command[1] == "-r" ){
	    printf(" Kernel  = '%s';\n", _uname.nodename);
	  }else if ( command[1] == "-m"){
	    printf(" Machine = '%s';\n", _uname.machine);
	  }else if ( command[1] == "-s" ){
	    printf(" System  = '%s';\n", _uname.sysname);
	  }
	}else {
			cout << "you should use -a, -r, -m, -s, after the command uname" << endl;
		}
}

/*
	dividimos el comando entrante
*/
vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string tok;
	while(getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}
	return internal;
}

/*
	verificamos si el comando existe
*/
int verify_Commands(string command)
{
	for ( int i = 0; i < Commands_size; i++)
	{
		if ( command == Commands[i])
			return i;
	}
	return -1;
}

/*
	mkdir
*/
void mkdir(vector<string> command ){

	if(command.size() == 2 )
	{
		char *argv[] = {(char *)command[1].c_str(), (char *)0};
		if( !fork() )
		{
			string TO_EXEC_COMMAND = path;
			TO_EXEC_COMMAND += "/mkdir";
			execv(TO_EXEC_COMMAND.c_str(), argv);
		}
	}
}


void rmdir(vector<string> command)
{
	if(command.size() == 2)
	{
		char *argv[] = {(char *)command[1].c_str(), (char *)0};
		if( !fork() )
		{
			string TO_EXEC_COMMAND = path;
			TO_EXEC_COMMAND += "/rmdir";
			execv(TO_EXEC_COMMAND.c_str(), argv);
		}
	}else if (command.size() == 3)
	{
		if(command[1] == "-r" || command[1] == "-R")
		{
			char *argv[] = {(char *)command[2].c_str(), (char *)0};
			if( !fork() )
			{
				string TO_EXEC_COMMAND = path;
				TO_EXEC_COMMAND += "/rmdirR";
				execv(TO_EXEC_COMMAND.c_str(), argv);
			}
		}
	}
}

void cd (vector<string> command){
	if(command.size() == 2 ){
		char *argv[] = {(char *)command[1].c_str(), (char *)0};
		if (chdir((char *)command[1].c_str()) != 0){
			printf("Error in chdir\n");
			exit(1);
		}
	}
}

void ls (vector<string> command){
	bool l = false;
	bool m = false;
	bool t = false;

	for(int i = 0; i<command.size(); i++){
		if(command[i] == "-l")
			l = true;
		if(command[i] == "-m")
			m = true;
		if(command[i] == "-t")
			t = true;
	}
	//if(command.size() == 1){
		DIR *mydir;
	    struct dirent *myfile;
	    struct stat mystat;

	    mydir = opendir(path);
	    vector<dirent*> entries;

	    while((myfile = readdir(mydir)) != NULL)
	    {
	    	entries.push_back(myfile);
	    }
	    vector<dirent*> temp = entries;
	    if(t){
	    	sort( entries.begin(), entries.end(), cmp );
	    }
	    for(int i = 0; i<entries.size(); i++){
	    	myfile = entries[i];
	    	if(myfile->d_name[0] == '.')
	    		continue;
	    	if(l){
	    		stat(myfile->d_name, &mystat);
	    		//permissions

			    printf( (S_ISDIR(mystat.st_mode)) ? "d" : "-");
			    printf( (mystat.st_mode & S_IRUSR) ? "r" : "-");
			    printf( (mystat.st_mode & S_IWUSR) ? "w" : "-");
			    printf( (mystat.st_mode & S_IXUSR) ? "x" : "-");
			    printf( (mystat.st_mode & S_IRGRP) ? "r" : "-");
			    printf( (mystat.st_mode & S_IWGRP) ? "w" : "-");
			    printf( (mystat.st_mode & S_IXGRP) ? "x" : "-");
			    printf( (mystat.st_mode & S_IROTH) ? "r" : "-");
			    printf( (mystat.st_mode & S_IWOTH) ? "w" : "-");
			    printf( (mystat.st_mode & S_IXOTH) ? "x" : "-");
			    //owner
			    struct passwd *tf;
    			struct group *gf;
		        tf = getpwuid(mystat.st_uid);
		        printf("\t%s ", tf->pw_name);

		        //group
		        gf = getgrgid(mystat.st_gid);
		        printf("\t%s ", gf->gr_name);
		        //time
	    		struct tm * timeinfo;
	    		timeinfo = localtime (&(mystat.st_atime));
	    		char buff[20];
	    		strftime(buff, 20, "%b %d %H:%M", timeinfo);
	        	printf("\t%d \t%s",mystat.st_size,buff);
	        	//name
	        	printf("%s\n", myfile->d_name);
	    	}else if(m){
	    		printf("%s,", myfile->d_name);
	    	}else{
	    		printf("%-15s", myfile->d_name);
	    		if(i != 0 && i%5 == 0)
	    			printf("\n");
	    	}
	    }
	    printf("\n");
	    closedir(mydir);
	//	}
}

bool cmp(const dirent * a, const dirent * b ) {
	struct stat mystat1;
	struct stat mystat2;
	stat(a->d_name, &mystat1);
	stat(b->d_name, &mystat2);
    return mystat1.st_atime < mystat2.st_atime;
}
void rm (vector<string> command){
	if(command.size() == 2){
		char *argv[] = {(char *)command[1].c_str(),(char *)0};
		if (remove((char *)command[1].c_str()) != 0)
		{
			printf("Error in remove\n");
			exit(1);
		}
	}
}

void ln(vector<string> command){
	if(command.size()==4 && command[1] == "-s"){
		if(symlink(command[2].c_str(),command[3].c_str())==-1){
			cout<<"Error en ln -s"<<endl;
		}
	}else if(command.size() == 3){
		if(link(command[1].c_str(),command[2].c_str())==-1){
			cout<<"Error en ln"<<endl;
		}
	}else{
		cout<<"Error en ln"<<endl;
	}
}

void exec(vector<string> command){
	vector<char *> commandVector;
	for(int i = 1;i<command.size();i++){
		if(command[i] != "&"){
			char *cstr = new char[command[i].length() + 1];
			strcpy(cstr, command[i].c_str());
			commandVector.push_back(cstr);
		}
		//cout<<cstr<<endl;
	}
	commandVector.push_back(NULL);
	char **command2 = &commandVector[0];
	int status;
	if(fork() == 0){
		if(execvp(command2[0], command2) == -1){
			cout<<"Error"<<endl;
		}
	}
	if(command[command.size()-1] != "&"){
		wait(&status);
	}
	for(int i = 0; i<commandVector.size(); i++){
		delete commandVector[i];
	}
}

void kill(vector<string> command){
	if(command[1] == "-9"){
		if (kill( atoi(command[2].c_str()), SIGKILL ) != 0)
			cout<<"Error en kill"<<endl;
	}
}
void chmod(vector<string> command){
	if (command.size() == 3)
	{
		char *argv[] = {(char *)command[1].c_str(),(char *)0};
		if (chmod((char *)command[1].c_str(),strtol(command[2].c_str(),NULL,8))==-1)
		{
			printf("Error in change permissions");
			exit(1);
		}
	}
}

void cat(vector<string> command){
	if (command.size()==2)
	{
		char *argv[] = {(char *)command[1].c_str(),(char *)0};
		string line;
		ifstream myfile (command[1].c_str());
	  	if (myfile.is_open())
	  	{
	    	while ( getline (myfile,line) )
	    {
	      printf((char *)line.c_str());
	    }
	      myfile.close();
	  }

	  else 
	  	printf("Error in cat");
	}	
}


void processdir(const struct dirent *dir)
{
     puts(dir->d_name);

}

int filter(const struct dirent *dir)
{
     /*uid_t user;
     struct stat dirinfo;
     int len = strlen(dir->d_name) + 7; 
     char path[len];

     strcpy(path, "/proc/");
     strcat(path, dir->d_name);
     user = getuid();
     if (stat(path, &dirinfo) < 0) {
	  perror("processdir() ==> stat()");
	  exit(EXIT_FAILURE);
     }*/
     return !fnmatch("[1-9]*", dir->d_name, 0) /*&& user == dirinfo.st_uid*/;
}


void ps(vector<string> command)
{
	bool a = false;
	bool u = false;
	bool x = false;
	bool e = false;

	for(int i = 0; i<command.size(); i++){
		if(command[i] == "-a")
			a = true;
		if(command[i] == "-u")
			u = true;
		if(command[i] == "-x")
			x = true;
		if(command[i] == "-e")
			e = true;
	}
		DIR* proc = opendir("/proc");
		struct dirent* ent;
		long tgid;

		if(proc == NULL) {
		    perror("opendir(/proc)");
		    
		}

		while(ent = readdir(proc)) {
		    if(!isdigit(*ent->d_name))
		        continue;

		    tgid = strtol(ent->d_name, NULL, 10);

		    if(e)
		    	pse(tgid);
		}

		closedir(proc);
	
}

void pse(long tgid) {
    char path[100], line[100], *p;
    FILE* statusf;

    snprintf(path, 100, "/proc/%ld/status", tgid);

    statusf = fopen(path, "r");
    if(!statusf)
        return;

    while(fgets(line, 100, statusf)) {
        if(strncmp(line, "State:", 6) != 0)
            //continue;
        // Ignore "State:" and whitespace
        p = line + 6;
        while(isspace(*p)) ++p;

        printf("%6ld %s", tgid, p);
        break;
    }

    fclose(statusf);
}
