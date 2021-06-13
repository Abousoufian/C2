// A C program that prints its source code. 
#include <stdio.h> 
   
int main(void) 
{ 
    // We can append this code to any C program 
    // such that it prints its source code. 
  
    char c;  
    FILE *fp = fopen("C:\\Users\\hamza\\Documents\\1EAI\\semester 2\\c programmeren 2\\file_handeling\\oef1.txt", "r"); 
   
    do
    { 
        c = fgetc(fp); 
        putchar(c); 
    } 
    while (c != EOF); 
   
    fclose(fp); 
   
    return 0; 
} 