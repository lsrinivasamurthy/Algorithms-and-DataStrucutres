#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

// Time Complexity : O(n*m)
// Space Complexity : O(n*m)

int count_paths(vector<vector<bool>> mat){
    int n = mat.size();
    int m = mat[0].size();

    //If starting or ending node is 0 then directly return 0.
    if (mat[0][0] == 1 || mat[n - 1][m - 1] == 1){
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = 1;

    // Fill the 0th row.
    int j = 1;
    while (j < m && mat[0][j] == 0){
        dp[0][j] = 1;
        j++;
    }
    while (j < m){
        dp[0][j] = 0;
        j++;
    }

    // Fill the 0th column
    int i = 1;
    while (i < n && mat[i][0] == 0){
        dp[i][0] = 1;
        i++;
    }
    while (i < n){
        dp[i][0] = 0;
        i++;
    }

    // Fill the remaining values
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            if (mat[i][j] == 1){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[n - 1][m - 1];
}






int main(){
    cout << count_paths({   { 0, 0, 0 },
                            { 0, 1, 0 },
                            { 0, 0, 0 } }) << endl;

    cout << count_paths({   {0, 1, 0, 1},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 1, 1, 0} }) << endl;

    system("pause");
    return 0;
}
