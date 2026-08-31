#include<iostream>
using namespace std;

int main(){
    int n;
    int factors[5];
    cin >> n;
    int j=0;
    for(int i=2;i<=n;){
        if(n%i!=0){
            i++;
        }
        else{
            factors[j]=i;
            j++;
            n=n/i;
        }
    }
    for (int k=0;k<j ;k++){
        cout << factors[k] << " ";
    }
}