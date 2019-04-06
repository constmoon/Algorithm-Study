#include <iostream>
using namespace std;

template <typename Type>
class myStack{
private:
    Type *d;
    int top;
    int size;
    
public:
    // size 개수 받을 수도 안 받을 수도 있음. 안 받으면 default가 100으로 설정됨
    myStack(int your_size=100){
        size = your_size;
        d = new Type[size];
        top = -1;
    }
    
    bool is_empty(){
        if(top == -1){
            return true;
        }
        return false;
    }
    
    bool push(Type x){
        if(top == size-1){
            return false;
        }
        top++;
        d[top] = x;
        return true;
    }
    
    bool pop(Type *ret){
        if(is_empty()){
            return false;
        }
        
        *ret = d[top];
        top--;
        return true;
    }
    
    void print(){
        for(int i=0; i<=top; i++) {
            cout << d[i] << "\t";
        }
        cout << endl;
    }
};


int main(int argc, char** argv){
    
    myStack <int> st;
    int n = 10;
    int *d = new int[n];
    
    // push
    for(int i=0; i<n; i++){
        d[i] = rand()%100;
        printf("%d ", d[i]);
        st.push(d[i]);
    }
    printf("\n");
    st.print();
    
    // pop
    for(int j=0; j<n; j++){
        int x;
        st.pop(&x);
        cout << "Popped item: " << x << endl;
        st.print();
    }
}
