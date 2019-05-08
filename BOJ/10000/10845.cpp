#include <iostream>
#include <queue>    // STL Queue 사용
#include <string>
using namespace std;

int main(){
    int n;
    queue<int> q;

    cin >> n;
    for(int i=0; i<n; i++){
        string command;
        cin >> command;

        if(command == "push"){
            int data;
            cin >> data;
            q.push(data);
        }
        else if(command == "pop"){
            if(!q.empty()){
                // 가장 앞에 있는 정수를 출력하고 pop
                cout << q.front() << endl;
                q.pop();
            }
            else{
                cout << -1 << endl;
            }
        }
        else if(command == "size"){
            cout << q.size() << endl;
        }
        else if(command == "empty"){
            if(!q.empty()){
                cout << 0 << endl;
            }
            else{
                cout << 1 << endl;
            }
        }
        else if(command == "front"){
            if(!q.empty()){
                cout << q.front() << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
        else if(command == "back"){
            if(!q.empty()){
                cout << q.back() << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}