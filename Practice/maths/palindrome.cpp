#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int temp =n;
    int reverse=0;
    
    for(;n>0;n/=10){
        reverse = reverse * 10 + (n%10);
    }

    if(reverse==abs(temp))
        cout << "Palindrome\n";
    else
        cout << "not\n";
}