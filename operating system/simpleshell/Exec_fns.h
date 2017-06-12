#ifndef _Exec_fns_H_
#define  _pipe_command_H_
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
//this function execute pipe commands 
	void Excut_Pipe_comm(char **arg_pre,char **arg_post)
	{
	int FIl_DIRECTS[2]; //create FIl_DIRECTS[0] as read file director
	pipe(FIl_DIRECTS);  //create FIl_DIRECTS[1] as write file director
	int childpid=fork();

	 if (childpid == -1)
    	{
        	printf("failed to create child process\n");
       
    	}
	else if(childpid==0)
	{

      	close(FIl_DIRECTS[0]);
    	dup2(FIl_DIRECTS[1],1); //close stdout and replace it by  create FIl_DIRECTS[1]
     
    	execvp(*arg_pre, arg_pre);
	}
	else
	{
	wait(&childpid);        //waits untill the child finish writting
        close(FIl_DIRECTS[1]);  
        dup2(FIl_DIRECTS[0],0); //close stdin director
        execvp(*arg_post,arg_post);
	}
	}
//_____________________________________________
//--Excution function

int Execution_Fn(char **argums )
{
    int Child_pid=fork();
     
     
     if (Child_pid < 0)
      	{     
          printf("child process is failed to create\n");
          exit(1);
     	}
     else if (Child_pid== 0)
        { 
            int state= execvp(  *argums, argums);   
            if (state < 0)
              {    
               printf("Execution is faild\n");
               exit(1);
              }
      }
     else 
       {                                  
         wait(Child_pid);
          return 0;      
      }
}
#endif
