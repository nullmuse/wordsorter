#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void character_harvest(char *wordlist, char *container) {

int i = 0;
int len = strlen(wordlist) + 1;

char *sample = calloc(len, sizeof(char));
char *word;
memcpy(sample,wordlist,len-1);

word = strtok(sample," ");
while(word != NULL) {
container[i++] = word[0];
word = strtok(NULL," ");
}


return;

}

void remap_wordlist(char *qlist, char *wordlist, char *remapped) { 

int i,wl;
int n = 0; 
int len = strlen(qlist);
printf("qlist len %i, wordlist len %i\n",len,strlen(wordlist));  
char *sample = calloc(strlen(wordlist) + 1, sizeof(char));
char *sample_r = calloc(strlen(wordlist) + 1, sizeof(char));
char *word;
char *remove;
char *rempt = remapped;  
memcpy(sample,wordlist,strlen(wordlist) - 1);
for(i = 0; i < len; ++i) { 
memcpy(sample_r,sample,strlen(sample) - 1);
word = strtok(sample_r," "); 
while(word != NULL) { 
if(word[0] == qlist[i]) {
wl = strlen(word);  
memcpy(rempt,word,wl);
printf("word %s\n",word);
printf("locaton %s\n",rempt);  
rempt += wl;
*rempt = ' ';
rempt += sizeof(char);
remove = strstr(sample,word);
memset(remove,'^',wl);
}
word = strtok(NULL," ");
}
free(sample_r); 
sample_r = calloc(strlen(wordlist) + 1, sizeof(char));
}
return; 
}

int comp_func_a(const void *comp1, const void  *comp2) { 

return (*((char *)comp1) - *((char *)comp2));

} 




char *sort_default(char *wordlist) { 

char *charsort = calloc(strlen(wordlist) + 1,sizeof(char)); 
char *sorted = calloc(strlen(wordlist) + 1,sizeof(char));

character_harvest(wordlist,charsort); 

printf("char sort presort %s length %i\n",charsort, strlen(charsort)); 
qsort(charsort, strlen(charsort), sizeof(char), comp_func_a);
printf("char sort post-sort %s\n",charsort); 
printf("wordlist %s\n",wordlist); 
remap_wordlist(charsort,wordlist,sorted); 



return sorted;

}

char *sort_trunc(char *wordlist, int n) { 

return wordlist;

}

char *sort_reverse(char *wordlist) { 

return wordlist; 

}

char *sort_number(char *wordlist) { 

return wordlist; 

}

char *sort_scrabble(char *wordlist) { 


return wordlist; 

}




char *sort_length(char *wordlist) { 

return wordlist; 

}



char *sort_unique(char *wordlist) { 

return wordlist; 

}
