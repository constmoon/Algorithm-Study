#include<stdio.h>
#include<string.h>   // strcmp() 사용을 위함

int n;    // 명령 수
int input;    // 집어넣을 숫자
int stack[10000];   // 스택 선언
int top = -1;  // 초기화
char str[10]; // 입력 명령어

void push(int x){
    stack[++top] = x;   // -1로 초기화하였으므로 prefix 증가
}
// 스택이 비어있으면 1, 아니면 0을 출력한다.
int empty(){
    if(top<0){
        return 1;
    }
    else{
        return 0;
    }
}
// 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다.
// 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void pop(){
    if(empty()==1){
        printf("-1\n");
    }
    else{
        printf("%d\n", stack[top--]);   // stack top 출력
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s", &str);
        if(strcmp(str,"push")==0){
            scanf("%d", &input);
            push(input);
        }
        else if(strcmp(str,"pop")==0){
            pop();
        }
        else if(strcmp(str,"empty")==0){
            printf("%d\n", empty());
        }
        else if(strcmp(str,"top")==0){
            if(empty() == 1){
                printf("-1\n");
            }
            else{
                printf("%d\n", stack[top]);
            }
        }
        else{ // size
            printf("%d\n", top+1);
        }
    }
    return 0;
}
