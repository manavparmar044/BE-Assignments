#include<iostream>

using namespace std;

int fibonacciRecursive(int n){
    if(n <= 1){
        return n;
    }

    return fibonacciRecursive(n - 1) + fibonacciRecursive(n -2);
}

int fibonacciIterative(int n){
    if(n <= 1){}
    int a = 0;
    int b = 1;
    int c = 0;

    for(int i = 2;i<=n;i++){
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main(){
    int n;

    cout<< "Enter n:"<<endl;
    cin>>n;

    cout<<fibonacciIterative(n);

    return 0;
}