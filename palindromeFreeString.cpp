#include <iostream>
#include <vector>
#include <algorithm>

bool check(std::vector<char>& v, int i, int j){
    while(i < j && v[i] == v[j]){
        i++;
        j--;
    }
    if(i == j){
        return true;
    }
    return false;
}

bool hasPalindromeSubstring(std::vector<char>& v){
    for(int i = 0;i<v.size()-6;i++){
        if(check(v,i,i+5)){
            return true;
        }
    }
    return false;
}

bool isPossible(std::vector<char>& v) {
    for(int i = 0;i<v.size();i++){
        if(v[i] == '?'){
            char replacement = '0';
            if(i > 0 && v[i-1] == '0'){
                replacement = '1';
            }
            if(i > 1 && v[i-2] == replacement && v[i-1] == replacement){
                replacement = (replacement == '0') ? '1' : '0';
            }
            v[i] = replacement;
        }
    }
    return !hasPalindromeSubstring(v);
}

int main() {
    int t;
    std::cin >> t;
    int caseNum = 1;

    while (t-- > 0) {
        int n;
        std::cin >> n;
        std::vector<char> v(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> v[i];
        }
        if (isPossible(v)) {
            std::cout << "Case #" << caseNum << ": POSSIBLE\n";
        } else {
            std::cout << "Case #" << caseNum << ": IMPOSSIBLE\n";
        }
        caseNum++;
    }
    return 0;
}
