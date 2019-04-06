// 단어는 알파벳 소문자와 대문자로만 이루어져 있으며, 길이는 100을 넘지 않는다. 
#include<stdio.h>
#include<string.h>

int main(){
    char string[100]={0,};
    scanf("%s", &string);
    int length = strlen(string);
    for(int i=0; i<length; i++){
        printf("%c", string[i]);
        if( ((i+1)%10) ==0){
            printf("\n");
        }
    }
}