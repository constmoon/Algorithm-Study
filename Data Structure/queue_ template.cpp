#include <iostream>
using namespace std;

template <typename Type>
class Queue{
private:
    Type *d;
    int front,back;
    int size;
    
public:
    
    Queue(int _size=100){
        size = _size;
        d = new Type[size];
        front = 0;
        back = 0;
    }
    
    bool is_empty(){
        if(front == 0){
            printf("Queue is Empty\n");
            return true;
        }
        return false;
    }
    
    bool push(Type _x){
        if(back == size-1){    // push가 되지 않는 경우
            printf("Queue is Full\n");
            return false;
        }
        d[back] = _x;
        back++;
        return true;

    }
    
    bool pop(Type *_ret){
        if(is_empty()){
            return false;
        }
        *_ret = d[front];
        front++;
        return true;
    }
    
    void print(){
        for(int i=0; i<back; i++) {
            cout << d[i] << "\t";
        }
        cout << endl;
    }
};


int main(int argc, char** argv){
    
    Queue <int> q;
    
    int n=10;    // random number amount
    int *d = new int[n];
    for(int i=0; i<n; i++){
        d[i] = rand()%100;
        printf("%d\t", d[i]);
        q.push(d[i]);
    }
    printf("\n");
    q.print();
    
    for(int j=0; j<n; j++){
        int x;
        q.pop(&x);
        cout << "Popped item: " << x << endl;
        q.print();
    }
}
