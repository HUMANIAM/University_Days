#ifndef _Help_fns_H_
#define  _Help_command_H_

//this function divide the pipe command into two processes
	void divide_pipe(char **arg_pre,char **arg_post,char **ARGUMS)
	{
	
	
	while((strcmp(*ARGUMS,"|")!=0)){*arg_pre++=*ARGUMS++; }
	*arg_pre='\0';
	ARGUMS++; 
	
	while(*ARGUMS!='\0'){*arg_post++=*ARGUMS++; }
	*arg_post=NULL;
	}
//this function check if command is pipe command or no
	int check_pipe(char **argums)
	{
	char **ptr=argums;
	while(*ptr != '\0' && (strcmp(*ptr,"|")!=0) ){ptr++; }

	if(*ptr == '\0') return 0;

	else  return 1;

	}
	


	//-- parsing function

	void parsing(char Command_Line[],char **ARGUMS)
	{

	// every argument will be seperated from anthor by one or more \0
	  while (*Command_Line!='\0')
	   {
	  
	      while (*Command_Line==' ') {*Command_Line++='\0'; }
	     *ARGUMS++=Command_Line;
	      while (*Command_Line !=' ' && *Command_Line!='\0'){ *Command_Line++; }
	   }
	    *ARGUMS=NULL;
	  }
#endif
