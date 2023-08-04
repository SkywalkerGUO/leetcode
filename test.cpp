#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {
    int a[n+1] = {0};
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i<n+1; i++){
        a[i] = a[i-1] + a[i-2];
    }
    return a[n];
}
int main(){
    int n;
    std::cin>> n;
    int sum = fib(n);
    std::cout << sum;
    return 0;
}