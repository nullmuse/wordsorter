#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

char *extract_words(char *filename) { 
   struct stat file_info;
   FILE *fp;
   char *wordlist = NULL;
   int wordlen = 0; 
   char *filename_r = calloc(strlen(filename) + 1,sizeof(char)); 
   char *fileparse; 
   int i,len;  
   i = 0; 
   strncpy(filename_r,filename,strlen(filename)); 
   fileparse = strtok(filename,","); 
   while(fileparse != NULL) {  
   if(stat(fileparse,&file_info) == -1) { 
       perror("FATAL: file does not exist");
       goto RETURN;
   }
   if(file_info.st_size <= 0) { 
      perror("FATAL: wordlist is empty file");
      goto RETURN; 
   }
   wordlen += file_info.st_size + 1; 
   fileparse = strtok(NULL,","); 
} 

   wordlist = calloc(wordlen, sizeof(char)); 
   wordlen = 0; 
  fileparse = strtok(filename_r,",");
  while(fileparse != NULL) {
  stat(fileparse,&file_info); 
   if ((fp = fopen(fileparse, "r")) == NULL) {
     perror("FATAL: cannot open file");
     goto RETURN; 
}
  wordlen = fread((wordlist + wordlen), sizeof(char), file_info.st_size, fp);
  
  fclose(fp);
  fileparse = strtok(NULL,",");
  } 

  len = strlen(wordlist);  
  for(i=0;i<len;++i) { 
     if(wordlist[i] == '\r' || wordlist[i] == '\n')
         wordlist[i] = ' ';
  } 
  //wordlist[len] = ' ';
  //strlen(wordlist);
  goto RETURN; 

  RETURN: 
  if(filename_r)
     free(filename_r); 
  return wordlist;


}
