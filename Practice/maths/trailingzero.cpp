#include<iostream>
using namespace std;

int factorial(int n){

    if(n==0 || n==1){
        return 1;
    }
    return n * factorial(n-1);
}

int trailingzeros(int n){
    int count =0;
    while(n>0){
        if(n%10==0){
            count++;
            n=n/10;
        }
        else
            break;
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    int zeros = trailingzeros(factorial(n));
    cout << zeros;
    
}