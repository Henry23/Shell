#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

const string Commands[] = {"mkdir","cd","chmod","rmdir","rm","cat","ln","ps","kill","uname"};
const int Commands_size = 10;
char path[FILENAME_MAX];
vector<string> split(string,char);
int verify_Commands(string);
void mkdir(vector<string>);
void rmdir(vector<string>);
void rm(vector<string>);

int main(int argc, char const *argv[]){
	getcwd(path,sizeof(path));//get the path object from current path
	while(true){
		char commandLine[256];
		cout << "mi_sh> ";
	    cin.getline(commandLine,256);
	    vector<string> command = split(commandLine,' ');
	    if( command.size() == 0 ){
	    	cout << "empty input" << endl;
	    	continue;
	    }
	    string commands = commandLine;
	    size_t found;//el tamaño de cualquier objeto en bytes
	    if( (found = commands.find(">")) != string::npos ){//compara el valor del objeto de size_t
	    	//do staff
	    }else
	    {
	    	int index = verify_Commands(command[0]);
	    	if(index != -1)
	    	{
	    		if( Commands[index] == "mkdir" )
	    		{
	    			mkdir(command);
	    		}else if (Commands[index] == "cd" )
	    		{

	    		}else if (Commands[index] == "chmod")
	    		{

	    		}else if (Commands[index] == "rmdir")
	    		{
	    			rmdir(command);
	    		}else if (Commands[index] == "rm")
	    		{
	    			
	    		}else if (Commands[index] == "cat")
	    		{
	    			
	    		}else if (Commands[index] == "ln")
	    		{
	    			
	    		}else if (Commands[index] == "ps")
	    		{
	    			
	    		}else if (Commands[index] == "kill")
	    		{
	    			
	    		}else if (Commands[index] == "uname")
	    		{
	    			
	    		}
	    	}else if (index == -1)
	    	{
	    		cout << "Command not found" << endl;
	    	}
	    }
	}
	return 0;
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
		{
			return i;
		}
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

	}else if (command.size() == 3)
	{
		if(command[2] == "-r" || command[2] == "-R")
		{
			cout << "hi there" << endl;
		}
	}
}
