#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
 * Function to reverse words
 */

void reversewords(char *s);
void reverse(char *start, char *end);

int main (int argc, char *argv[]) {
   char *input_str;
   printf("argc = %d\n", argc);
   if(argc > 1) {
      printf("%s\n", argv[1]);
    } else {
       printf("No arguments \n");
    }
    
   reversewords(argv[1]);






   return 0;
}

void reverewords(char *str) {
   char *temp = str;
   char *begin = str;

   while(*begin) {
     begin++;
     if(*begin == '\0') {
       reverse(temp, begin-1); 
     } else if (*begin == ' ') {
          reverse(temp, begin -1);
          temp = begin-1;
    }
   }
}

void reverse(char *start, char *end) {
   char temp;
   while(start < end) {
      temp = *start;
      *start++ = *end;
      *end-- = temp; 
   }


}
