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

int i;
int len = strlen(qlist);
int safe_index; 
int wlen;   
char *sample = calloc(strlen(wordlist) + 1, sizeof(char));
char *sample_r = calloc(strlen(wordlist) + 1, sizeof(char));
char *word;
char *rword;
char *remove;
char *rempt = remapped;  
memcpy(sample,wordlist,strlen(wordlist) - 1);
for(i = 0; i < len; ++i) { 
memcpy(sample_r,sample,strlen(sample)); 
word = strtok(sample_r," "); 
while(word != NULL) {
wlen = strlen(word) - 1; 
safe_index = (wlen > index) ? index : 0; 
if(word[safe_index] == qlist[i]) {
memcpy(rempt,word,strlen(word));
while(*rempt != 0) {
rempt++;
}
*rempt = ' ';
rempt += 1;
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
free(sample); 
free(sample_r); 
return; 
}

int comp_func_a(const void *comp1, const void  *comp2) { 

return (*((char *)comp1) - *((char *)comp2));

} 




char *sort_default(char *wordlist) {
int size; 
int lsize = strlen(wordlist) + 1; 
char *wordlist_copy = calloc(lsize,sizeof(char));
char *charsort = calloc(lsize,sizeof(char)); 
char *sorted = calloc(lsize,sizeof(char));

strncpy(wordlist_copy,wordlist,lsize - 1); 
size = biggest_word(wordlist); 

for(;size > -1; size--) { 
memset(sorted,0,lsize); 
character_harvest(size,wordlist_copy,charsort); 
qsort(charsort, strlen(charsort), sizeof(char), comp_func_a);
remap_wordlist(size,charsort,wordlist_copy,sorted); 
memcpy(wordlist_copy,sorted,lsize + 1); 
}
return sorted;

}

char *sort_trunc(char *wordlist, int n) { 

int i; 
char *wordlist_copy = calloc(strlen(wordlist) + 1,sizeof(char));
char *ws;
char *word; 
printf("%i\n",n);
ws = sort_default(wordlist); 
word = strtok(ws," ");
strncpy(wordlist_copy,word,strlen(word));
for(i = 1; i < n; ++i) { 
word = strtok(NULL," ");
if(word == NULL) { 
break; 
}
strncat(wordlist_copy," ",2); 
strncat(wordlist_copy,word,strlen(word)); 
}
return wordlist_copy; 



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
