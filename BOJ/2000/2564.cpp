#include <stdio.h>
#include <math.h>

int blockX, blockY;    // block X, Y
int num;    // 상점 개수
int curDirect, curLocation, curDistance;    // 동근이 위치
int tmp, result=0;    // 결과값 저장 변수

typedef struct shop{
    int direct;    // 상점 방향
    int location;    // 상점 위치
    int distance;
}Shop;

int getDistance(int direct, int location){
    int distance;
    switch(direct){
        case 1:
            distance = location;
            break;
        case 2:
            distance = blockX + blockY + (blockX - location);
            break;
        case 3:
            distance = 2*blockX + blockY + (blockY - location);
            break;
        case 4:
            distance = blockX + location;
            break;
        default:
            break;
    }
    return distance;
}

int main(){

    scanf("%d %d", &blockX, &blockY);
    scanf("%d", &num);
    
    Shop shop[num];
    for(int i=0; i<num; i++){
        scanf("%d %d", &shop[i].direct, &shop[i].location);
        shop[i].distance = getDistance(shop[i].direct, shop[i].location);
        //printf("shop %d distance to (0,0): %d\n", i, shop[i].distance);
    }
    scanf("%d %d", &curDirect, &curLocation);
    curDistance = getDistance(curDirect, curLocation);
    for(int i=0; i<num; i++){
        tmp = abs(curDistance - shop[i].distance);
        if(tmp > blockX+blockY){
            tmp = 2*(blockX+blockY)-tmp;
        }
        result += tmp;
    }
    
    printf("%d\n", result);
    
    return 0;
}