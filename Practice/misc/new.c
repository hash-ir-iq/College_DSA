#include<stdio.h>

int main(){
    int n=6;
    for(int row=0;row<n;row++){
        
        for(int c=0;c<n;c++){
            if( c < n-row){
                printf(" ");
            }
            else if(c >= n-row)
                printf("*");
        }

        // for(int j=n-1;j>i;j--){
        //     printf(" ");
        // }
        // for(int k=0;k<=i;k++){
        //     printf("*");
        // }


        printf("\n");

    }
}

// if(!((str[i]>=65  AND str[i<=90]) || (str[i] >=97 and str <=122)) )
//     i++
// if(str[i]==str[j]):
//     i++
//     j--
// else"

// a  a  b    c b  d  d  e

// for(int i=0;i<str.len();i++){
//     for(int j=0;j<str.len();j++){
//         if(i==j){
//             continue;
//         }
//         else if(str[i]==str[j])
//         {
//             break;
//         }
//         else if(str[i]!=str!=[j] and j!=str.len()-1){
//         continue;
//         }
//         else: 
//             print(str[i])
//             return;
//     }  

// }