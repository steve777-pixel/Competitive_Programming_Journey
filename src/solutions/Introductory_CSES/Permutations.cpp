#include <iostream>

using namespace std;

void solve(int n){
    if(n <= 1){
        cout << "1\n";
        return;
    }

    if(n <= 3){
        cout << "NO SOLUTION\n";
        return;
    }

    int arr[n] = {0};
    int slow = 0, fast  = n/2;

    for(int i = 1; i <= n; i++){
        if((i & 1) == 0){ 
            arr[slow] = i;
            slow++;
        }else{
            arr[fast] = i; 
            fast++;
        }
    }

    for(int i : arr){
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    solve(n);
    
    return 0;
}