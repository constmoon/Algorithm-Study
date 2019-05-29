#include <iostream>
using namespace std;

typedef long long ll;

int N;    // N명의 아이들
int M;    // M종류의 놀이기구
int rides[10000];    // 각 놀이기구의 운행 시간

// 마지막 아이가 타게될 시간을 계산한다.
// mid분에 몇 명이 탔는지 알아보고, N과 비교해서 binary search를 실행
ll BinarySearch(){
    
    // N명의 인원(최대 2000000000명)이 M개의 기구(최대 30분)를 모두 타는 데에 소요되는 시간
    ll low = 0;
    ll high = 2000000000ll * 30ll;
    ll result = 0;
    
    while(low <= high){
        ll mid = (low+high) / 2;
        ll sum = M;
        for(int i=0; i<M; i++){
            sum += mid / rides[i];
        }
        if(sum >= N){
            result = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return result;
}

int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> rides[i];
    }
    // 놀이기구 수보다 아이들 수가 적으면 아이들 수 출력한다
    if(N <= M){
        cout << N << endl;
        return 0;
    }
    
    // 마지막 아이가 탑승한 시간 time
    ll time = BinarySearch();
    
    // (time - 1(분))까지 몇 명의 아이들이 탑승했는지 확인한다.
    ll children = M;
    for(int i=0; i<M; i++){
        children += (time - 1)/rides[i];
    }
    
    // time에 탑승한 아이를 확인한다
    for(int i=0; i<M; i++){
        // 운행시간에 각 놀이기구의 운행시간을 나눈 나머지가 0이라면 탑승완료
        if (!(time % rides[i])){
            children++;
        }
        // 마지막 아이
        if(children == N){
            cout << i+1 << endl;
            break;
        }
    }
    return 0;
}
