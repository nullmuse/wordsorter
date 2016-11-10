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
   char *arglist = calloc(argsize, sizeof(char)); 
   char *argtok;
   char *filename_list = NULL;
   char *wordlist = NULL; 
   strncpy(arglist,argv[1],strlen(argv[1])); 
   for(i = 2; i < argc; ++i) {
      strncat(arglist,argv[i],strlen(argv[i])); 
  } 
  if(strstr(arglist,"-h")) { 
     help_message(); 
     goto END; 
  }
  argtok = strtok(arglist,"-"); 
  filename_list = calloc(strlen(argtok) + 1,sizeof(char)); 
  strncpy(filename_list,argtok,strlen(argtok)); 
  wordlist = extract_words(filename_list);
  if(wordlist == NULL) 
     goto END; 
  printf("%s\n",wordlist); 
  argtok = strtok(arglist,"-");
  while(argtok != NULL) { 
     printf("%s\n",argtok);
     argtok = strtok(NULL, "-"); 
  } 


   END:
   if(arglist)
   free(arglist); 
   if(filename_list)
   free(filename_list); 
   if(wordlist)
   free(wordlist); 
   return 0; 

}
