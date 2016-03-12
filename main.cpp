#include <iostream>#include <vector>#include <string>#include <string.h>#include <sstream>#include <fstream>#include <unistd.h>#include <stdio.h>#include <unistd.h>#include <sys/wait.h>#include <errno.h>  #include <dirent.h>#include <stdlib.h> #include <algorithm>#include <sys/types.h>#include <sys/stat.h>#include <dirent.h>#include <time.h>#include <pwd.h>#include <grp.h>using namespace std;const string Commands[] = {"mkdir","cd","chmod","rmdir","rm","cat","ln","ps","kill","uname","ls"};const int Commands_size = 11;char path[FILENAME_MAX];vector<string> split(string,char);int verify_Commands(string);void mkdir(vector<string>);void cd(vector<string>);void chmod(vector<string>);void rmdir(vector<string>);void rm(vector<string>);void cat(vector<string>);void ln(vector<string>);void ps(vector<string>);void kill(vector<string>);void uname(vector<string>);void ls(vector<string>);bool cmp( const dirent *, const dirent *); int main(int argc, char const *argv[]){	getcwd(path,sizeof(path));//get the path object from current path	while(true){		char commandLine[256];		cout <<"Mi_shell> "<< path<<"$ ";	    cin.getline(commandLine,256);	    vector<string> command = split(commandLine,' ');	    if( command.size() == 0 ){	    	cout << "empty input" << endl;	    	continue;	    }	    if( find(command.begin(), command.end(), ">" ) != command.end())	    {	    	cout << "hi there " << endl;	    }else if (find(command.begin(), command.end(), "<") != command.end()){	    }else if(find(command.begin(), command.end(), ">&") != command.end()){ 	    }else if(find(command.begin(), command.end(), ">>") != command.end()){	    }else {	    	int index = verify_Commands(command[0]);	    	//cout << "index" << index << endl;	    	if(index != -1)	    	{	    		if( Commands[index] == "mkdir" )	    			mkdir(command);	    		else if (Commands[index] == "cd" )	    			cd(command);	    		else if (Commands[index] == "chmod")	    			chmod(command);	    		else if (Commands[index] == "rmdir")	    			rmdir(command);	    		else if (Commands[index] == "rm")	    			rm(command);	    		else if (Commands[index] == "cat")	    			cat(command);	    		else if (Commands[index] == "ln")	    			ln(command);	    		else if (Commands[index] == "ps")	    			ps(command);	    		else if (Commands[index] == "kill")	    			kill(command);	    		else if (Commands[index] == "uname")	    			uname(command);	    		else if (Commands[index] == "ls")	    			ls(command);	    		else 	    			cout << "something must be wrong" << endl;	    	}else if (index == -1)	    			cout << "Command not found" << endl;	    }	    getcwd(path,sizeof(path));	}	return 0;}void chmod(vector<string>){cout << "chmod" << endl; }void cat(vector<string>){cout << "cat" << endl; }void ln(vector<string>){cout << "ln" << endl; }void ps(vector<string>){cout << "ps" << endl; }void kill(vector<string>){cout << "kill" << endl; }void uname(vector<string>){cout << "uname" << endl; }/*	dividimos el comando entrante */vector<string> split(string str, char delimiter) {	vector<string> internal;	stringstream ss(str); 	string tok;	while(getline(ss, tok, delimiter)) {		internal.push_back(tok);	}	return internal;}/*	verificamos si el comando existe*/int verify_Commands(string command){	for ( int i = 0; i < Commands_size; i++)	{		if ( command == Commands[i])			return i;	}	return -1;}/*	mkdir*/void mkdir(vector<string> command ){		if(command.size() == 2 )	{		char *argv[] = {(char *)command[1].c_str(), (char *)0};		if( !fork() )		{			string TO_EXEC_COMMAND = path;			TO_EXEC_COMMAND += "/mkdir";			execv(TO_EXEC_COMMAND.c_str(), argv);		}	}}void rmdir(vector<string> command){	if(command.size() == 2)	{		char *argv[] = {(char *)command[1].c_str(), (char *)0};		if( !fork() )		{ 			string TO_EXEC_COMMAND = path;			TO_EXEC_COMMAND += "/rmdir";			execv(TO_EXEC_COMMAND.c_str(), argv);		}	}else if (command.size() == 3)	{		if(command[1] == "-r" || command[1] == "-R")		{			char *argv[] = {(char *)command[2].c_str(), (char *)0};			if( !fork() )			{				string TO_EXEC_COMMAND = path;				TO_EXEC_COMMAND += "/rmdirR";				execv(TO_EXEC_COMMAND.c_str(), argv);			}		}	}}void cd (vector<string> command){	if(command.size() == 2 ){		char *argv[] = {(char *)command[1].c_str(), (char *)0};		if (chdir((char *)command[1].c_str()) != 0){			printf("Error in chdir\n");			exit(1);		}	}}void ls (vector<string> command){	bool l = false;	bool m = false;	bool t = false;	for(int i = 0; i<command.size(); i++){		if(command[i] == "-l")			l = true;		if(command[i] == "-m")			m = true;		if(command[i] == "-t")			t = true;	}	//if(command.size() == 1){		DIR *mydir;	    struct dirent *myfile;	    struct stat mystat;	    mydir = opendir(path);	    vector<dirent*> entries;	    while((myfile = readdir(mydir)) != NULL)	    {	    	entries.push_back(myfile);	    }	    vector<dirent*> temp = entries;	    if(t){ 	    	sort( entries.begin(), entries.end(), cmp );	    }	    for(int i = 0; i<entries.size(); i++){	    	myfile = entries[i];	    		    	if(l){	    		stat(myfile->d_name, &mystat); 	    		//permissions	    					    printf( (S_ISDIR(mystat.st_mode)) ? "d" : "-");			    printf( (mystat.st_mode & S_IRUSR) ? "r" : "-");			    printf( (mystat.st_mode & S_IWUSR) ? "w" : "-");			    printf( (mystat.st_mode & S_IXUSR) ? "x" : "-");			    printf( (mystat.st_mode & S_IRGRP) ? "r" : "-");			    printf( (mystat.st_mode & S_IWGRP) ? "w" : "-");			    printf( (mystat.st_mode & S_IXGRP) ? "x" : "-");			    printf( (mystat.st_mode & S_IROTH) ? "r" : "-");			    printf( (mystat.st_mode & S_IWOTH) ? "w" : "-");			    printf( (mystat.st_mode & S_IXOTH) ? "x" : "-");			    //owner 			    struct passwd *tf;     			struct group *gf;		        tf = getpwuid(mystat.st_uid);		        printf("\t%s ", tf->pw_name);		        //group		        gf = getgrgid(mystat.st_gid);		        printf("\t%s ", gf->gr_name);		        //time	    		struct tm * timeinfo;  	    		timeinfo = localtime (&(mystat.st_atime));	    		char buff[20];	    		strftime(buff, 20, "%b %d %H:%M", timeinfo); 	        	printf(" \t%d \t%s",mystat.st_size,buff);	        	//name	        	printf(" %s\n", myfile->d_name);	    	}else if(m){	    		printf(" %s,", myfile->d_name);	    	}else{	    		printf(" %s\t", myfile->d_name);	    	}	    }	    printf("\n");	    closedir(mydir);	//	}}bool cmp(const dirent * a, const dirent * b ) {	struct stat mystat1;	struct stat mystat2;	stat(a->d_name, &mystat1); 	stat(b->d_name, &mystat2);     return mystat1.st_atime < mystat2.st_atime;}void rm (vector<string> command){	if(command.size() == 2){		char *argv[] = {(char *)command[1].c_str(),(char *)0};		if (remove((char *)command[1].c_str()) != 0)		{			printf("Error in remove\n");			exit(1);		}	}}