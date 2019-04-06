#include <stdio.h>

int n;
int map[100][100];     // 입력 배열
int result[100][100];  // 출력 배열
int visited[100];

////////// QUEUE start //////////
typedef struct _queue{
    int data;
    struct _queue* link;
}Queue;

Queue* front = NULL;
Queue* rear = NULL;

void enqueue(int item) {
    if(front == NULL && rear == NULL) {
        Queue* queue = (Queue*)malloc(sizeof(Queue));
        queue->data = item;
        queue->link = NULL;
        front = queue;
        rear = queue;
    }
    else {
        Queue* tmp = (Queue*)malloc(sizeof(Queue));
        tmp -> data = item;
        rear->link = tmp;
        rear = rear->link;
    }
}

void dequeue() {

    if(front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->link;
    }
}
////////// QUEUE end //////////


void BFS(int value){
    enqueue(value);
    while(!(front == NULL)){
        int data = front->data;
        for(int i=0; i<n; i++){
            if(map[data][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                enqueue(i);
            }
        }
        dequeue();
    }
}

void check(int value){
    for(int i=0; i<n; i++){
        if(visited[i] == 1){
            result[value][i] = 1;
            visited[i] = 0;
        }
    }
}

int main(){
    
    // input
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        BFS(i);
        check(i);
    }
    
    
    // output
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    
}
