#include<iostream>
using namespace std;

void print(int n,int m){
    for(int i=0;i<n;i++){
        cout << "*";
        for(int j=0;j<m;j++)
        {
            if (i==0 || i==n-1)
                cout << "*";
            else
                cout << " ";
        }
        cout << "*";
        cout << endl;
    }
}

int main(){
    int n,m;
    cin >>n;
    cin >> m;
    print(n,m);
}