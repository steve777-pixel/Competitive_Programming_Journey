#include <iostream>

using namespace std;

int main(){
    long long n;
    cin >> n;
    long long expected_sum = (n*(n + 1)) / 2;
    long long sum = 0;
    for(int i = 0; i < n - 1; i++){
        long long a;
        cin >> a;
        sum += a;
    }
    cout << expected_sum - sum << "\n";

    return 0;
}