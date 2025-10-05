#include <bits/stdc++.h>
using namespace std;

int val[1005];
int dp[1005][1005];

bool subsetSum(int i, int sum) {
    if (sum == 0) return true;
    if (i < 0) return false;

    if(dp[i][sum] != -1)
        return dp[i][sum];

    if(val[i] <= sum){
        dp[i][sum] = subsetSum(i - 1, sum - val[i]) + subsetSum(i - 1, sum);
    } 
    else{
        dp[i][sum] = subsetSum(i - 1, sum);
    }

    return dp[i][sum];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> val[i];
        sum += val[i];
    }

    if(sum % 2 == 1) cout << "NO" << '\n';
    else{
        // Initialize DP table
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= sum; j++)
                dp[i][j] = -1;

        if(subsetSum(n - 1, sum/2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

// Input
// 4
// 1 2 4 7

// Output
// YES