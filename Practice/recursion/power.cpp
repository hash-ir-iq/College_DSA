#include<iostream>
using namespace std;

int power(int b, int e){
    if (e == 0){
        return 1;
    }
    int temp = power(b,e/2);
    if(e&1){
        return b * temp * temp;
    }
    else{
        return temp * temp;
    }
}

int main(){
    int base, e;

    cin >> base >> e;
    cout << power(base,e);

}