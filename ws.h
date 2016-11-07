void help_message(void); 
int transmute_char(char *subject);
void character_harvest(int index, char * wordlist, char * container);
void number_harvest(int index, char * wordlist, char * container);
int biggest_word(char * wordlist);
char * smallest_word(char * wordlist);
void remap_wordlist(int index, char * qlist, char * wordlist, char * remapped);
int comp_func_a(const void * comp1,const void * comp2);
int comp_func_b(const void * comp1,const void * comp2);
int comp_func_c(const void * comp1,const void * comp2);
char *extract_words(char *filename); 
char *sort_default(char *wordlist,int s_type);
char *sort_trunc(char *wordlist, int n);
char *sort_number(char *wordlist);
char *sort_scrabble(char *wordlist);
char *sort_length(char *wordlist);
char *sort_unique(char *wordlist);


union numchar {
int  number;
char character;
};
