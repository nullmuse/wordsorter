#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ws.h"

int main(int argc, char * argv[]) {
  int i, n;
  int rbit = 0;
  int argsize = argc * 4;
  char * arglist;
  char * argtok = "a";
  char * argtok_r;
  char * filename_list = NULL;
  char * wordlist = NULL;
  char * sorted = NULL;
  if (argc == 1) {
    goto STDIN;
  }
  arglist = calloc(argsize, sizeof(char));
  strncpy(arglist, argv[1], strlen(argv[1]));
  for (i = 2; i < argc; ++i) {
    strncat(arglist, argv[i], strlen(argv[i]));
  }
  if (strstr(arglist, "-h")) {
    help_message();
    goto END;
  }
  argtok = strtok_r(arglist, "-", & argtok_r);
  if(argtok[0] == '-' || argtok[0] == 'a') { 
     filename_list = NULL;
     goto STDIN;
  }
  filename_list = calloc(strlen(argtok) + 1, sizeof(char));
  strncpy(filename_list, argtok, strlen(argtok));
  argtok = strtok_r(NULL, "-", & argtok_r);
  STDIN:
  wordlist = extract_words(filename_list);
  if (wordlist == NULL)
    goto END;
  while (argtok != NULL) {
    switch (argtok[0]) {
    case 'a':
      sorted = sort_default(wordlist, 0);
      break;
    case 'c':
      argtok++;
      n = transmute_char(argtok);
      sorted = sort_trunc(wordlist, n);
      break;
    case 'r':
      rbit = !rbit;
      sorted = sort_default(wordlist, rbit);
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
      printf("%s is not a valid flag\n", argtok);
      help_message();
      goto END;
    }
    argtok = strtok_r(NULL, "-", & argtok_r);
    free(wordlist);
    wordlist = sorted;
  }

  END:
  if(wordlist) { 
    printf("%s\n", wordlist);
    free(wordlist);
  } 
  if (arglist)
    free(arglist);
  if (filename_list)
    free(filename_list);
  return 0;

}
