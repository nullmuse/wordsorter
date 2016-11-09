#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ws.h"

int main(int argc, char *argv[]) { 
   int i;
   int argsize = argc * 4; 
   if(argc == 1) { 
      help_message();
      return 0;   
   }
   char *arglist = malloc(argsize); 
   char *argtok; 
   memset(arglist,0,argsize); 
   strncpy(arglist,argv[1],strlen(argv[1])); 
   for(i = 2; i < argc; ++i) {
      strncat(arglist,argv[i],strlen(argv[i])); 
  } 
  if(strstr(arglist,"-h")) { 
     help_message(); 
     return 0;
  }
  argtok = strtok(arglist,"-"); 
  while(argtok != NULL) { 
     printf("%s\n",argtok);
     argtok = strtok(NULL, "-"); 
  } 




   return 0; 

}
