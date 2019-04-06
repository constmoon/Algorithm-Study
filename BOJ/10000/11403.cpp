#include <stdio.h>

int map[100][100];
int visited[100][100];
int n;

// start: 몇번째 정점에서 시작하는지
// 1->2->3으로 갈수 있을때 1->3으로도 갈 수 있으므로 map[1][3]도 갈 수 있다고 1로 체크
void travel(int start, int destination){
    map[start][destination] = 1;
    visited[start][destination] = 1;
    for(int i=0; i<n; i++){
        if(visited[start][i]==0 && map[destination][i]==1){
            travel(start,i);
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
        for(int j=0; j<n; j++){
            if(visited[i][i]==0 && map[i][j]==1){
                travel(i,j);
            }
        }
    }
    
    // output
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}