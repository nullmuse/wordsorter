#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void character_harvest(int index, char *wordlist, char *container) {
int i = 0;
int len = strlen(wordlist) + 1;
int safe_index;
int wlen;  
char *sample = calloc(len, sizeof(char));
char *word;
memcpy(sample,wordlist,len-1);
word = strtok(sample," ");
while(word != NULL) {
wlen = strlen(word) - 1; 
safe_index = (wlen > index) ? index : 0;
container[i++] = word[safe_index];
word = strtok(NULL," ");
}


return;

}


int biggest_word(char *wordlist) { 

int len = strlen(wordlist) + 1;
int retlen = 0; 
char *word; 
int wlen; 
char *sample = calloc(len, sizeof(char));
memcpy(sample,wordlist,len-1);
word = strtok(sample," ");
while(word != NULL) {
wlen = strlen(word); 
if(wlen > retlen)  {
retlen = strlen(word); 
}
word = strtok(NULL," ");
}
return retlen; 
}


void remap_wordlist(int index, char *qlist, char *wordlist, char *remapped) { 

int i,wl;
int n = 0; 
int len = strlen(qlist);
int safe_index; 
int wlen; 
//printf("wordlist len %i\n",strlen(wordlist));  
char *sample = calloc(strlen(wordlist) + 1, sizeof(char));
char *sample_r = calloc(strlen(wordlist) + 1, sizeof(char));
char *word;
char *rword;
char *remove;
char *rempt = remapped;  
memcpy(sample,wordlist,strlen(wordlist) - 1);
for(i = 0; i < len; ++i) { 
memcpy(sample_r,sample,strlen(sample));
printf("sample: %s\n",sample_r); 
word = strtok(sample_r," "); 
while(word != NULL) {
printf("%s\n",word);
wlen = strlen(word) - 1; 
safe_index = (wlen > index) ? index : 0; 
if(word[safe_index] == qlist[i]) {
memcpy(rempt,word,strlen(word));
while(*rempt != 0) {
rempt++;
}
*rempt = ' ';
rempt += 1;
//printf("%s\n",remapped); 
//*rempt = ' ';
rword = calloc(strlen(word) + 2,sizeof(char));
strncpy(rword,word,strlen(word)); 
rword[strlen(word)] = ' ';
remove = strstr(sample,rword);
if(remove != NULL) {
memset(remove,'^',strlen(word));
}
free(rword); 
break;
}
word = strtok(NULL," ");
}
free(sample_r); 
sample_r = calloc(strlen(wordlist) + 1, sizeof(char));
}
//*rempt = 0; 
//printf("ret wordlist len %i\n",strlen(remapped));
free(sample); 
free(sample_r); 
return; 
}

int comp_func_a(const void *comp1, const void  *comp2) { 

return (*((char *)comp1) - *((char *)comp2));

} 




char *sort_default(char *wordlist) { 
int lsize = strlen(wordlist) + 1; 
char *wordlist_copy = calloc(lsize,sizeof(char));
char *charsort = calloc(lsize,sizeof(char)); 
char *sorted = calloc(lsize,sizeof(char));

strncpy(wordlist_copy,wordlist,lsize - 1); 
int size = biggest_word(wordlist); 

for(;size > -1; size--) { 
printf("SIZE IS %i\n",size); 
memset(sorted,0,lsize); 
character_harvest(size,wordlist_copy,charsort); 
printf("harvest: %s\n",charsort); 
qsort(charsort, strlen(charsort), sizeof(char), comp_func_a);
printf("pre:(%s)\n",wordlist_copy);
remap_wordlist(size,charsort,wordlist_copy,sorted); 
memcpy(wordlist_copy,sorted,lsize + 1); 
printf("post:(%s)\n",wordlist_copy); 
}
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
