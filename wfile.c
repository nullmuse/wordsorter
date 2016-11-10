#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

char *extract_words(char *filename) { 
   struct stat file_info;
   FILE *fp;
   char *wordlist;
   int i,len;  
   
   if(stat(filename,&file_info) == -1) { 
       perror("FATAL: file does not exist");
       return NULL;
   }

   
   if(file_info.st_size <= 0) { 
      perror("FATAL: wordlist is empty file");
      return NULL;
   }
   wordlist = calloc(file_info.st_size + 1, sizeof(char)); 

   if ((fp = fopen(filename, "r")) == NULL) {
     perror("FATAL: cannot open file");
     return NULL; 
}
  fread(wordlist, sizeof(char), file_info.st_size, fp);
  
  fclose(fp);
  len = strlen(wordlist);  
  for(i=0;i<len;++i) { 
     if(wordlist[i] == '\r' || wordlist[i] == '\n')
         wordlist[i] = ' ';
  } 
  return wordlist; 

}
