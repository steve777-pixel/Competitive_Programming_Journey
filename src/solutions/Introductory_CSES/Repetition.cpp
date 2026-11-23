#include <iostream>
#include <string>

using namespace std;

int greaterVal(int a, int b){
    return (a > b) ? a : b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.length();
    int best = 1, curr = 1;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == s[i + 1]){
            curr++;
            best = greaterVal(curr, best);
        }else{
            curr = 1;
        }
    }

    cout << best << "\n";

    return 0;
}