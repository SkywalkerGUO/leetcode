#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

std::string rev(string s, int start, int end);

int main() {
    std::string s;
    int k;
    std::cin>>s>>k;
    int start = 0;
    int end = 0;
    int loop = 0;
    if (s.size() >= 2*k){

        for (int i = 0; (2*i+2)*k<=s.size(); i++){
            start = i*2*k;
            end = (2*i+1)*k - 1;
            loop ++;
            s =rev(s,start,end);
        }
        if (s.size() - (2*loop)*k < k) {
            start = (2*loop)*k;
            end = s.size()-1;
            s =rev(s,start, end);
        }

        else if (s.size() - (2*loop)*k >= k) {
            start = (2*loop)*k;
            end = start+k-1;
            s =rev(s,start,end);
        }
    }

    else if (s.size()< k) {
        start = 0;
        end = s.size()-1;
        s =rev(s,start, end);
    }

    else  {
        start = 0;
        end = k-1;
        s = rev(s,start,end);
    }

    cout<< s;
    return 0;
}

std::string rev(string s, int start, int end){
    for (int p1 = start, p2 = end; p1< (start+end)/2; p1++, p2--){
        char temp;
        temp = s[p1];
        s[p1] = s[p2];
        s[p2] = temp;
    }
    return s;
}