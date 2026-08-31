#include<iostream>
using namespace std;

void print(int n){

    for (int i=0;i<n;i++){
        for(int j=n-i;j>0;j--)
            cout << " ";
        cout<<"*";
        for(int k=0;k<2*i;k++)
            cout<<"*";
        cout<<endl;
    }
    
}

int main(){
    int  n;
    cin >> n;
    print(n);
}