#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#include "ws.h"

    char * sort_default(char * wordlist, int s_type) {
      int size;
      int lsize = strlen(wordlist) + 1;
      char * wordlist_copy = calloc(lsize, sizeof(char));
      char * charsort = calloc(lsize, sizeof(char));
      char * sorted = calloc(lsize, sizeof(char));
      strncpy(wordlist_copy, wordlist, lsize - 1);
      size = biggest_word(wordlist_copy);

      for (; size > -1; size--) {
        memset(sorted, 0, lsize);
        if (s_type == 0) {
          character_harvest(size, wordlist_copy, charsort);
          qsort(charsort, strlen(charsort), sizeof(char), comp_func_a);
        }
        if (s_type == 1) {
          character_harvest(size, wordlist_copy, charsort);
          qsort(charsort, strlen(charsort), sizeof(char), comp_func_b);
        }
        remap_wordlist(size, charsort, wordlist_copy, sorted);
        memcpy(wordlist_copy, sorted, lsize);
      }
      free(charsort);
      free(sorted);
      return wordlist_copy;

    }

    char * sort_trunc(char * wordlist, int n) {

      int i;
      char * wordlist_copy = calloc(strlen(wordlist) + 1, sizeof(char));
      char * ws;
      char * word;
      ws = sort_default(wordlist, 0);
      word = strtok(ws, " ");
      strncpy(wordlist_copy, word, strlen(word));
      for (i = 1; i < n; ++i) {
        word = strtok(NULL, " ");
        if (word == NULL) {
          break;
        }
        strncat(wordlist_copy, " ", 2);
        strncat(wordlist_copy, word, strlen(word));
      }
      return wordlist_copy;

      return wordlist;

    }

    char * sort_number(char * wordlist) {
      int size,i;
      int lsize = strlen(wordlist) + 1;
      char * wordlist_copy = calloc(lsize, sizeof(char));
      char * charsort = calloc(lsize, sizeof(char));
      char * sorted = calloc(lsize, sizeof(char));
      struct numchar *numchars;
      strncpy(wordlist_copy, wordlist, lsize - 1);
      character_harvest(0, wordlist_copy, charsort);
      size = strlen(charsort);
      numchars = calloc(size,sizeof(struct numchar));
      memset(sorted, 0, lsize);
      number_harvest(wordlist_copy, numchars);
      qsort(numchars, size, sizeof(struct numchar), comp_func_c);
      remap_wordlist_numsort(size, numchars, sorted);
      for(i = 0;i < size; ++i)strncpy(wordlist_copy, wordlist, lsize - 1);
      character_harvest(0, wordlist_copy, charsort);
      size = strlen(charsort);
      numchars = calloc(size,sizeof(struct numchar));

         free(numchars[i].word);
      free(wordlist_copy);
      free(numchars);
      free(charsort);
      return sorted;
    }

    char * sort_scrabble(char * wordlist) {
      printf("not implemented\n"); 
      printf("%s\n",wordlist); 

      return NULL;

    }

    char * sort_length(char * wordlist) {

      int lsize = strlen(wordlist);
      char * wordlist_copy = calloc(lsize + 2, sizeof(char));
      char * wordlist_copy2 = calloc(lsize + 1, sizeof(char));
      char * word;
      int size;
      char * modptr;
      char * wlpt = wordlist_copy;
      strncpy(wordlist_copy2, wordlist, strlen(wordlist));
      word = smallest_word(wordlist_copy2);
      wordlist_copy[0] = ' ';
      wlpt++;
      while (word != NULL) {
        size = strlen(word);
        memcpy(wlpt, word, size);
        wlpt[size] = ' ';
        modptr = strstr(wordlist_copy2, (wlpt - 1));
        if (modptr == NULL) {
          modptr = strstr(wordlist_copy2, wlpt);
          modptr--;
        };
        memset(modptr + 1, 1, size);

        wlpt += size;
        wlpt++;
        free(word);
        word = smallest_word(wordlist_copy2);
      }
      return wordlist_copy;

    }

    char * sort_unique(char * wordlist) {

      char * wordlist_copy = calloc(strlen(wordlist) + 1, sizeof(char));
      char * wlpt = wordlist_copy;
      char * word;
      int size;
      char * modword;
      char * get;
      word = strtok(wordlist, " ");
      while (word != NULL) {
        size = strlen(word);
        modword = calloc(size + 2, sizeof(char));
        memcpy(modword, word, size);
        modword[size] = ' ';
        get = strstr(wordlist_copy, modword);
        if (get == NULL) {
          memcpy(wlpt, modword, strlen(modword));
          wlpt += strlen(modword);
        }
        free(modword);
        word = strtok(NULL, " ");
      }
      return sort_default(wordlist_copy, 0);

    }
