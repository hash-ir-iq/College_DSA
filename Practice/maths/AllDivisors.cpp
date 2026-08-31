#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int divisors[10];
    int j=0;
    int i=1;
    for(;i*i<=n;i++){
        if(n%i==0){
            divisors[j++]=i;
        }
    }
    i--;

    if(i*i==n){
        i--;
    }

    for(;i>0;i--){
          if(n%i==0){
            divisors[j++]=n/i;
        }
    }

    for(int i=0;i<j;i++){
        cout<<divisors[i] << " ";
    }

}