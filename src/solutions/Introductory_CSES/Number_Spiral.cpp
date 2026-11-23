#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        long long y,x;
        cin >> y >> x;

        if(y <= x){
            if((x & 1) == 0){
                cout << (x - 1)*(x - 1) + y << "\n";
            }else{
                cout << x * x - y + 1 << "\n";
            }
        }else{
            if((y & 1) == 0){
                cout << y*y - x +1 << "\n";
            }else{
                cout << (y - 1)*(y - 1) + x << "\n";
            }
        }
    }

    return 0;
}