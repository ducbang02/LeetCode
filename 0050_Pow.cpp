#include <bits/stdc++.h>

using namespace std;


//Time: O(n), space: O(1)
double myPow(double x, int n) {
    double result = 1;
    if(n > 0 ){
        for(int i = 1; i <= n; i++){
            result *= x;
        }
    }else if(n < 0){
        for(int i = 1; i <= -n; i++){
            result /= x;
        }
    }else return 1;
    return result;
}


//Time: O(n), space: O(1)
double myPow2(double x, int n) {
    int i = n;
    if(n < 0){
        x = 1/x;
        i = -n;
    }

    double result = 1;
    while(i > 0){
        if(n % 2 == 1){
            result *= x;
        }
        x *= x;
        i/=2;
    }
    return result;
}

//Time: O(logn), space: O(1)
//Time: O(n), space: O(1)

int main(){
    cout<<myPow2(2, 7);
    
    return 0;
}