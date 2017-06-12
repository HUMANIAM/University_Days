//Name: Ibrahim elsaid saad    section: 1
// simple shell

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include"Help_fns.h"
#include"Exec_fns.h"


	int main()
	{


	    char Command_Line[300];

	    char *ARGUMS[20];
// pipe_comm refers to that input command is pipe command
	   int pipe_comm=5;

	while(1)
	{
	
	printf("SIM_SHELL$ ");	
	   scanf ("%[^\n]%*c", Command_Line);
	 
	   parsing(Command_Line,ARGUMS);

 	if (strcmp(*ARGUMS,"exit")==0)  exit(1);

	 pipe_comm=check_pipe(ARGUMS); 

	if(pipe_comm==1)
	{

	//divide pipe command into two processes one process before | and anthor after |
	char *args_pre[5],*args_post[5];
	divide_pipe(args_pre,args_post,ARGUMS);
	Excut_Pipe_comm(args_pre,args_post);
	}

	else
	{      
	     int s= Execution_Fn(ARGUMS);  
	}

	}
	    return 0;
	
	}
