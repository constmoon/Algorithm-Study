#include <iostream>
using namespace std;

typedef long long ll;
int cnt[10];   // 0~9 출현 빈도 저장

// 특정 숫자의 각 자릿수를 뽑는다
void calc(ll n, ll digit){
    while(n>0){
        cnt[n%10] += digit;   // n%10 = 일의 자리
        n = n/10;    // n/10 = 일의 자리를 제외한 나머지 수
    }
}

int main(){
    ll start = 1;
    ll end;
    ll digit = 1;   // 자릿수
    scanf("%lld", &end);  // 페이지 입력(끝점)
    
    // 시작점 증가~끝점 감소를 반복하여 시작점과 끝점이 같아질 동안
    while(start <= end){
        // 시작점의 일의 자리가 0이 될 때까지 증가
        while(start%10 != 0 && start <= end){
            calc(start, digit);
            start++;
        }
        if(start > end){
            break;
        }
        // 끝점의 일의 자리가 9가 될 때까지 감소
        while(end%10 != 9 && start <= end){
            calc(end, digit);
            end--;
        }
        
        // 두 숫자의 일의 자리를 0과 9로 맞춘 후
        // 0~9 횟수의 규칙 적용
        /* 횟수의 규칙:
         * 두 수 A와 B가 있을 때,
         * 각 수의 횟수는 B/10 - A/10 + 1 로 구할 수 있다.
         * e.g. 10과 39
         *      A = 10, B = 39
         *      일의 자리에서 0~9는 각 (3 - 1 + 1) * 1 = 3회씩 등장
         *      ----->  자릿수 UP
         *      A = 1, B = 3 -> cnt[1] += 10
         *      B = 2, B = 3 -> cnt[2] += 10
         *      A = 3, B = 3 -> cnt[3] += 10
         *      A = 4, B = 3 -> break
         *      3 13 13 13 3 3 3 3 3 3
         */
        ll fill = (end/10 - start/10 + 1);
        for(int i=0; i<10; i++){
            cnt[i] += fill * digit;
        }
        
        // 다음 자릿수로 넘어감
        start = start / 10;
        end = end / 10;
        digit *= 10;
    }
    
    for(int i=0; i<10; i++){
        printf("%d ", cnt[i]);
    }
    printf("\n");
    return 0;
}


