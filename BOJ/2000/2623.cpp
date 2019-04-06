#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
 
int main(){
    int N, M, indegree[1000] = {0};
    vector<int> adj[1000];
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++){
        int K, prev, curr;
        scanf("%d", &K);
        if(K == 0) continue;
 
        scanf("%d", &prev);
        for(int i=1; i<K; i++){
            scanf("%d", &curr);
            indegree[curr-1]++;
            adj[prev-1].push_back(curr-1);
            prev = curr;
        }
    }
 
    int result[1000];
    queue<int> Q;
    // 위상 정렬 시작: 큐에 indegree가 0인 정점을 다 넣음
    for(int i=0; i<N; i++)
        if(indegree[i] == 0) Q.push(i);
 
    // 위상 정렬
    for(int i=0; i<N; i++){
        // 도중에 큐가 비면 불가능
        if(Q.empty()){
            puts("0");
            return 0;
        }
 
        int curr = Q.front();
        Q.pop();
        result[i] = curr+1;
        // 인접한 정점을 순회하면서 indegree 1씩 감소. 0이 되면 큐에 넣음
        for(int next: adj[curr])
            if(--indegree[next] == 0) Q.push(next);
    }
 
    // 결과 출력
    for(int i=0; i<N; i++){
        printf("%d\n", result[i]);
    }
}