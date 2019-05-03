#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool Check(string str){
    int len = (int)str.length();   // length() returns size_t
    stack<char> s;   // char 타입을 받는 stack

    for(int i=0; i<len; i++){
        char c = str[i];   // 문자 하나씩 받음
        // 1. '(' 여는 괄호면 스택에 push
        if(c == '('){
            s.push(str[i]);
        }
        // 2. ')' 닫힌 괄호일 경우
        else{
            if(!s.empty()){    // 스택이 비어있지 않으면 pop
                s.pop();
            }
            else{    // 스택이 비어있으면 false(NO)
                return false;
            }
        }
    }
    return s.empty();    // 입력받은 문자열 길이만큼의 반복문이 끝나고도 스택에 괄호가 남아있으면 false
}

int main(){
    int n;   // test 횟수
    cin >> n;

    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        if(Check(str)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}