#include<iostream>




int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        for(int j=n-i;j>0;j--)
            std::cout<<" ";
        std::cout<<"*";
        for(int j=0;j<2*i-1;j++)
            std::cout<<" ";
        if(i)
            std::cout<<"*";
        std::cout << std::endl;
    }

    for(int i=n;i>=0;i--){
        for(int j=n-i;j>0;j--)
            std::cout<<" ";
        std::cout << "*";
        for(int j=0;j<2*i-1;j++){
            std::cout << " ";
        }
        if(i)
            std::cout<<"*";
        std::cout <<std::endl;
    }
}