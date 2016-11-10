#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ws.h"

int transmute_char(char *subject) {
   int len = strlen(subject) - 1;
   int i,new = 0;

   for(i = 1;len >= 0;--len,i *= 10) {
      
      if(subject[len] > 0x39 || subject[len] < 0x30) {
         return 0;
                                                     }
      new += (subject[len] - 0x30) * i;
                                     }
   return new;
}





int main(int argc, char *argv[]) { 
   int i,n;
   int argsize = argc * 4;    
   char *arglist;
   char *argtok;
   char *argtok_r; 
   char *filename_list = NULL;
   char *wordlist = NULL;
   char *sorted = NULL; 
   if(argc == 1) {
      help_message();
      return 0;
   }
   arglist = calloc(argsize, sizeof(char)); 
   strncpy(arglist,argv[1],strlen(argv[1])); 
   for(i = 2; i < argc; ++i) {
      strncat(arglist,argv[i],strlen(argv[i])); 
  } 
  if(strstr(arglist,"-h")) { 
     help_message(); 
     goto END; 
  }
  argtok = strtok_r(arglist,"-",&argtok_r); 
  filename_list = calloc(strlen(argtok) + 1,sizeof(char)); 
  strncpy(filename_list,argtok,strlen(argtok)); 
  wordlist = extract_words(filename_list);
  if(wordlist == NULL) 
     goto END; 
  printf("%s\n",wordlist); 
  argtok = strtok_r(NULL,"-",&argtok_r);
  printf("%s\n",argtok);
  while(argtok != NULL) { 
     switch(argtok[0]) { 
         
        case 'a':
            sorted = sort_default(wordlist); 
            break; 
        case 'c':
            argtok++;
            n = transmute_char(argtok); 
            sorted = sort_trunc(wordlist,n); 
            break; 
        case 'r':
            sorted = sort_reverse(wordlist); 
            break; 
        case 'n':
            sorted = sort_number(wordlist); 
            break;
        case 's':
            sorted = sort_scrabble(wordlist); 
            break;
        case 'l':
            sorted = sort_length(wordlist); 
            break; 
        case 'u':
            sorted = sort_unique(wordlist); 
            break; 
        default:
            printf("%s is not a valid flag\n",argtok); 
            help_message(); 
            goto END; 
    } 
            
     argtok = strtok_r(NULL, "-",&argtok_r); 
  } 


   END:
   printf("%s\n",sorted); 
   if(arglist)
   free(arglist); 
   if(filename_list)
   free(filename_list); 
   if(wordlist)
   free(wordlist); 
   return 0; 

}
