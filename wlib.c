#include<stdio.h>
#include<stdlib.h>
#include<string.h>

  int transmute_char(char * subject) {
    int len = strlen(subject) - 1;
    int i, new = 0;
    for (i = 1; len >= 0; --len, i *= 10) {
      if (subject[len] > 0x39 || subject[len] < 0x30) {
        return -1;
        new += (subject[len] - 0x30) * i;

      }
      }
      return new;
    }

    void character_harvest(int index, char * wordlist, char * container) {
      int i = 0;
      int len = strlen(wordlist) + 1;
      int safe_index;
      int wlen;
      char * sample = calloc(len, sizeof(char));
      char * word;
      memcpy(sample, wordlist, len - 1);
      word = strtok(sample, " ");
      while (word != NULL) {
        wlen = strlen(word) - 1;
        safe_index = (wlen > index) ? index : 0;
        container[i++] = word[safe_index];
        word = strtok(NULL, " ");
      }

      free(sample);
      return;

    }

    void number_harvest(int index, char * wordlist, char * container) {
      int i = 0;
      int a = 0;
      int c = 0;
      int len = strlen(wordlist) + 1;
      int numcheck;
      char * ch = calloc(2, sizeof(char));
      int safe_index;
      int wlen;
      char * sample = calloc(len, sizeof(char));
      char * word;
      char * wordnum;
      memcpy(sample, wordlist, len - 1);
      word = strtok(sample, " ");
      while (word != NULL) {
        wlen = strlen(word) - 1;
        safe_index = (wlen > index) ? index : 0;
        ch[0] = word[safe_index];
        numcheck = transmute_char(ch);
        printf("%i %s\n", numcheck, ch);
        if (numcheck > -1) {
          wordnum = calloc(strlen(word), sizeof(char));
          for (a = safe_index; a < wlen + 1; ++a) {
            ch[0] = word[a];
            numcheck = transmute_char(ch);
            if (numcheck == -1)
              break;
            wordnum[c++] = word[a];
          }
          container[i++] = transmute_char(wordnum);
          free(wordnum);
        } else {
          if (word[safe_index] <= '9') {
            word[safe_index] += 0x30;
          }
          container[i++] = word[safe_index];
        }
        word = strtok(NULL, " ");
      }

      free(ch);
      return;

    }

    int biggest_word(char * wordlist) {

      int len = strlen(wordlist);
      int retlen = 0;
      char * word;
      int wlen;
      char * sample = calloc(len + 1, sizeof(char));
      memcpy(sample, wordlist, len);
      word = strtok(sample, " ");
      while (word != NULL) {
        wlen = strlen(word);
        if (wlen > retlen) {
          retlen = wlen;
        }
        word = strtok(NULL, " ");
      }
      free(sample);
      return retlen;
    }

    char * smallest_word(char * wordlist) {
      int len = strlen(wordlist);
      int retlen;
      char * word;
      char * smallest = NULL;
      char * retword = NULL;
      int wlen;
      char * sample = calloc(len + 1, sizeof(char));
      memcpy(sample, wordlist, len);
      word = strtok(sample, " ");
      retlen = strlen(word);
      retword = word;
      while (word[0] == 1) {
        word = strtok(NULL, " ");
        if (word == NULL) {
          retword = NULL;
          goto END;
        };
        retword = word;
        retlen = strlen(word);
      }
      while (word != NULL) {
        if (word[0] != 1 || strlen(word) <= 0) {
          wlen = strlen(word);
          if (wlen < retlen) {
            retlen = strlen(word);
            retword = word;
          }
        }
        word = strtok(NULL, " ");
      }
      END:
        if (retword != NULL) {
          smallest = calloc(wlen + 1, sizeof(char));
          strncpy(smallest, retword, wlen);
        }
      free(sample);
      return smallest;
    }

    void remap_wordlist(int index, char * qlist, char * wordlist, char * remapped) {

      int i;
      int len = strlen(qlist);
      int safe_index;
      int wlen;
      char * sample = calloc(strlen(wordlist) + 2, sizeof(char));
      char * sample_r = calloc(strlen(wordlist) + 2, sizeof(char));
      char * word;
      char * rword;
      char * remove;
      char * rempt = remapped;
      sample[0] = ' ';
      memcpy(sample + 1, wordlist, strlen(wordlist) - 1);
      for (i = 0; i < len; ++i) {
        memcpy(sample_r, sample, strlen(sample));
        word = strtok(sample_r, " ");
        while (word != NULL) {
          wlen = strlen(word) - 1;
          safe_index = (wlen > index) ? index : 0;
          if (word[safe_index] == qlist[i]) {
            memcpy(rempt, word, strlen(word));
            while ( * rempt != 0) {
              rempt++;
            } * rempt = ' ';
            rempt += 1;
            rword = calloc(strlen(word) + 3, sizeof(char));
            rword[0] = ' ';
            strncat(rword, word, strlen(word));
            rword[strlen(word) + 1] = ' ';
            remove = strstr(sample, rword);
            if (remove != NULL) {
              memset(remove + 1, 1, strlen(word));
            }
            free(rword);
            break;
          }
          word = strtok(NULL, " ");
        }
        free(sample_r);
        sample_r = calloc(strlen(wordlist) + 1, sizeof(char));
      }
      free(sample);
      free(sample_r);
      return;
    }

    int comp_func_a(const void * comp1,
      const void * comp2) {

      return ( * ((char * ) comp1) - * ((char * ) comp2));

    }

    int comp_func_b(const void * comp1,
      const void * comp2) {

      return ( * ((char * ) comp2) - * ((char * ) comp1));

    }

    int comp_func_c(const void * comp1,
      const void * comp2) {

      return (transmute_char((char * ) comp1) - transmute_char((char * ) comp2));

    }

