#include <bits/stdc++.h>
using namespace std;
int val[10005];

bool subsetSum(int i, int sum){
    if(sum == 0) return true;    
    if(i < 0 || sum < 0) return false;
    
    return subsetSum(i - 1, sum - val[i]) || subsetSum(i - 1, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> val[i];

    int sum;
    cin >> sum;
    if(subsetSum(n - 1, sum))
        cout << "YES\n";
    else
        cout << "NO\n";
}

// Input
// 4
// 1 2 4 6
// 7

// Output
// YES