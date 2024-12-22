#include <stdio.h>
int main(){
    int cnt = 0;
    char starfish[200];
    scanf("%[^\n]",starfish);
    for(int i = 0;starfish[i] != '\0';i++){
        printf("%c ",starfish[i]);
    }
    return 0;
}