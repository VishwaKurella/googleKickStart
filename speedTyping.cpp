#include<iostream>
#include <string>

int CheckTyping(std::string &I, std::string &P){
    if(I.length() > P.length()){
        return -1;
    }
    int extra = 0;
    int i = 0;
    for(const auto& c : P){
        if(i < I.length() && c == I[i]){
            i++;
        }else{
            extra++;
        }
    }
    if(i <I.length()){
        return -1;
    }
    return extra;
}

int main(){
    int t;
    std::cin>>t;
    int c = 1;
    while(t-- > 0){
        std::string I;
        std::cin>>I;
        std::string P;
        std::cin>>P;
        int check = CheckTyping(I, P);
        if(check < 0){
            std::cout<<"case #"<<c<<": "<<"IMPOSSIBLE"<<"\n";
        }else{
            std::cout<<"case #"<<c<<": "<<check<<"\n";
        }
        c++;
    }
}
