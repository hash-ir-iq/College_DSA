#include<iostream>
using namespace std;

int main(){
    int n;
    cin>> n;

    for (int i=2;i<n;i++){
        if(n%i==0){
            cout << " not \n";
            break;
        }
        else if(i*i>n){
            cout<< "prime\n";
            break;
        }
    }
}