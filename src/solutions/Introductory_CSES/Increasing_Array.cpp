#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    long long sum = 0;

    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1]){
            sum += (arr[i] - arr[i+1]);
            arr[i + 1] = arr[i];
        }
    }

    cout << sum << "\n";

    return 0;
}