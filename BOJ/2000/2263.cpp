#include <iostream>
#include <vector>
using namespace std;

vector<int> inorder;
vector<int> postorder;

void preorder(int inorder_start, int inorder_end, int postorder_start, int postorder_end){
    // 더이상 분할할 수 없을시 종료
    if(inorder_end - inorder_start == 0){
        return;
    }
    // postorder의 가장 끝에 있는 노드가 root
    int root = postorder[postorder_end - 1];
    int len;
    for(int i=inorder_start; i<inorder_end; i++){
        if(inorder[i] == root){
            // inorder의 root를 기준으로 왼쪽 자식이 몇 개 있는지 저장
            len = i - inorder_start;
            break;
        }
    }
    cout << root << " ";
    // root를 기준으로 왼쪽으로 이동
    preorder(inorder_start, inorder_start+len, postorder_start, postorder_start+len);
    // root를 기준으로 오른쪽으로 이동
    preorder(inorder_start+len+1, inorder_end, postorder_start+len, postorder_end-1);
}

int main(){
    int N;
    cin >> N;
    
    // inorder, postorder 생성
    for(int i=0; i<N; i++){
        int val;
        cin >> val;
        inorder.push_back(val);
    }
    for(int i=0; i<N; i++){
        int val;
        cin >> val;
        postorder.push_back(val);
    }
    
    // preorder 찾고 출력
    preorder(0, N, 0, N);
    
}
