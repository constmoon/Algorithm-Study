#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int start, vector <int> graph[] ,bool visited[]){
    stack <int> s;
    // stack에 push되면 방문한 노드이다
    s.push(start);
    visited[start] = true;
    cout << start << " ";
    
    // stack에 노드가 있을 동안
    while(!s.empty()){
        int current = s.top();    // 스택의 맨 위 노드를 빼내서
        s.pop();    // 방문
        for(int i=0; i<graph[current].size(); i++){
            int next = graph[current][i];    // 현재 노드와 인접한 노드들을 차례로 검사
            if(visited[next] != true){
                cout << next << " ";
                visited[next] = true;
                s.push(current);
                s.push(next);
                break;
            }
        }
    }
}
void bfs(int start, vector <int> graph[], bool visited[]){
    queue <int> q;
    // 시작점부터 줄 세움
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        // queue의 맨 앞의 원소를 방문할 노드로 설정
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i=0; i<graph[node].size(); i++){
            // 노드가 방문된 적이 없다면 방문
            if(visited[graph[node][i]] != true){
                q.push(graph[node][i]);
                visited[graph[node][i]] = true;
            }
        }
    }
}

int main(){
    int n, m, start;
    cin >> n >> m >> start;
    
    vector <int> graph[n+1];    // n개의 vector로 이루어진 배열 graph 생성. 노드 번호가 1부터 시작하므로 n+1
    bool dfs_visited[n+1];    // 방문여부 확인하는 배열
    bool bfs_visited[n+1];
    for(int i=1; i<=n; i++){
        dfs_visited[i] = false;   // 초기화
        bfs_visited[i] = false;
    }
    
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        // 양방향 엣지
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // 노드 번호가 작은 것부터 먼저 방문하도록 정렬
    for(int i=1; i<=n; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    
    dfs(start, graph, dfs_visited);
    cout << "\n";
    bfs(start, graph, bfs_visited);
    
    return 0;
    
}