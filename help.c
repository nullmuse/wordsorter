#include <stdio.h>


void help_message(void) { 

   puts("\
argv[0]: word-sorting command-line utility\n\
argv[0] filename [-c] <n> [-r] [-n] [-l] [-s] [-a] [-u] [-h]\n\n\
-c <n>: Print the first n results of the sorted list of words\n\
-r: Print word list in reverse order\n\
-n: Sort words as if they were numbers\n\
-l: Sort words by length\n\
-s: Sort words by Scrabble© score\n\
-a: Sort lexicographically (default)\n\
-u: Print unique words (de-dupe list)\n\
-h: Prints this message"); 

return; 

}


 

