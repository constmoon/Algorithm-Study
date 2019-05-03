#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    string str;
    stack<char> s;
    int result = 0;

    cin >> str;
    int len = (int)str.length();

    for(int i=0; i<len; i++){
        // 여는 괄호면 stack에 push
        if(str[i] == '('){
            s.push(str[i]);
        }
        // 닫는 괄호면 레이저 / 파이프인지 확인한다
        else{
            s.pop();
            // 직전 괄호가 여는 괄호면 레이저
            if(str[i-1] == '('){
                result += s.size();   // 잘린 갯수 추가
            }
            else{
                result++;    // 잘린 쇠막대기의 마지막 부분
            }
        }
    }

    cout << result;
    return 0;
}