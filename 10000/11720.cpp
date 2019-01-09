#include<stdio.h>

int main(){
    int n;
    char num[100]={0,};
    int ret=0;
    
    scanf("%d", &n);   // 입력받을 숫자
    scanf("%s", &num);
    for(int i=0; i<n; i++){
        ret += num[i]-'0';
    }
    printf("%d\n",ret);
        
}