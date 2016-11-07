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

char *smallest_word(char *wordlist) { 
int len = strlen(wordlist) + 1;
int retlen;
char *word;
char *retword = NULL;
int wlen;
char *sample = calloc(len, sizeof(char));
memcpy(sample,wordlist,len-1);
word = strtok(sample," ");
retlen = strlen(word);
retword = word;
while(word[0] == 1) {
word = strtok(NULL," ");
if(word == NULL)
return NULL;
retword = word;
retlen = strlen(word);
}
while(word != NULL) {
if(word[0] != 1 || strlen(word) <= 0) {
wlen = strlen(word);
if(wlen < retlen)  {
retlen = strlen(word);
retword = word;
}
}
word = strtok(NULL," ");
}
return retword;
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

int comp_func_b(const void *comp1, const void  *comp2) {

return (*((char *)comp2) - *((char *)comp1));

}





char *sort_default(char *wordlist, int s_type) {
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
if(s_type == 0) {  
qsort(charsort, strlen(charsort), sizeof(char), comp_func_a);
}
if(s_type == 1) { 
qsort(charsort, strlen(charsort), sizeof(char), comp_func_b);
}
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
ws = sort_default(wordlist,0); 
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


char *sort_number(char *wordlist) { 

return wordlist; 

}

char *sort_scrabble(char *wordlist) { 


return wordlist; 

}




char *sort_length(char *wordlist) { 

int lsize = strlen(wordlist) + 1;
char *wordlist_copy = calloc(lsize,sizeof(char));
char *word;
char *modptr;
char *wlpt = wordlist_copy; 
word = smallest_word(wordlist); 
while(word != NULL) { 
memcpy(wlpt,word,strlen(word));
wlpt[strlen(word)] = ' ';
modptr = strstr(wordlist,wlpt);
memset(modptr,1,strlen(word)); 
wlpt += strlen(word); 
wlpt++; 
word = smallest_word(wordlist);
}

return wordlist_copy; 

}



char *sort_unique(char *wordlist) { 


char *wordlist_copy = calloc(strlen(wordlist) + 1,sizeof(char));
char *wlpt = wordlist_copy;
char *word; 
char *modword;
char *get;
word = strtok(wordlist," ");
while(word != NULL) {
modword = calloc(strlen(word) + 2,sizeof(char));
memcpy(modword,word,strlen(word));
modword[strlen(word)] = ' ';
get = strstr(wordlist_copy, modword);
if(get == NULL) {
memcpy(wlpt,modword,strlen(modword));
wlpt += strlen(modword); 
}
free(modword);
word = strtok(NULL," ");
}
return sort_default(wordlist_copy,0); 

}
