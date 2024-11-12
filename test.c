#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    char ab[] = "||||||||||||||||||||||||||||||||||||";
    char ar[] = "||||   Welcome to our project   ||||";
    printf("\n\n\t\t%s\n", ab);
    printf("\t\t");
    for (int i = 0; i <= sizeof(ar); i++) {
        Sleep(10);  // 1 second delay
        printf("%c", ar[i]);
    }
    printf("\n");
    printf("\t\t%s\n", ab);
    printf("\n\n");
    return 0;
}
