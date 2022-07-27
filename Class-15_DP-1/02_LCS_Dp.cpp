#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> memo; // global variable to store the results of sub-problems.

int lcs_helper(string s1, int i, string s2, int j){
    // Base Conditions
    if (i == s1.length() || j == s2.length()){
        return 0;
    }

    if (memo[i][j] != -1){
        return memo[i][j];
    }

    if (s1[i] == s2[j]){
        return memo[i][j] = 1 + lcs_helper(s1, i + 1, s2, j + 1);
    }
    
    return memo[i][j] = max(lcs_helper(s1, i, s2, j + 1), lcs_helper(s1, i + 1, s2, j));
}

int lcs(string s1, string s2){
    int n = s1.length();
    int m = s2.length();

    //just initialise the memoery with -1.
    memo = vector<vector<int>> (n, vector<int>(m, -1));
    return lcs_helper(s1, 0, s2, 0);
}

int lcs_bottom_up(string s1, string s2){
    int n = s1.length();
    int m = s2.length();

    // Base Cases are accomoddated here it self in 0th row and 0th column.
    vector<vector<int>> dp(n+1, vector<int>(m+1));

    //Fill 0th row and 0th column with zeros.
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    cout << "Welcome To Dynamic Programming" << endl;
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    cout << "Length of Longest Common Substring(LCS) :" << lcs(s1, s2) << endl;
    cout << "Length of Longest Common Substring(LCS) :" << lcs_bottom_up(s1, s2) << endl;
    system("pause");
    return 0;
}
