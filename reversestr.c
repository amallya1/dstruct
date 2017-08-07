#include<stdio.h>
#include<string.h>

int main() {
   char a[] = "akshatha";
   int len = strlen(a);
   printf("%s\n", a);
    char rev_str[len];
   int i =0;
   for (int j = len-1; j>=0; j--) {
       rev_str[i] = a[j];
       printf("%c\n", rev_str[i]);
       i++;
    }
    rev_str[len] = '\0';
    printf("%s", rev_str);
    return 0;
}
