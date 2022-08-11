#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

// Time Complexity : O(n*m)
// Space Complexity : O(n*m)
vector<vector<int>> memo;

int get_min_stesps_helper(string& A, string& B, int i, int j){
    // Base Cases ?
    if (i == A.length()){
        // Insert all the remaining charachters present in B
        return B.length() - j;
    }
    if (j == B.length()){
        // Delete the charachters present in A to match to B.
        return A.length() - i;
    }

    if (memo[i][j] != -1){
        return memo[i][j];
    }

    if (A[i] == B[j]){
        return memo[i][j] = get_min_stesps_helper(A, B, i + 1, j + 1);
    }

    // Try Insert Operation
    int result = 1 + get_min_stesps_helper(A, B, i, j + 1);

    // Try Delete Operation
    result = min(result, 1 + get_min_stesps_helper(A, B, i + 1, j));

    // Try Replacing
    result = min(result, 1 + get_min_stesps_helper(A, B, i + 1, j + 1));

    return memo[i][j] = result;

}

int get_min_steps(string A, string B){
    int n = A.length();
    int m = B.length();
    memo = vector<vector<int>>(n,vector<int>(m,-1));
    return get_min_stesps_helper(A, B, 0, 0);
}

int main(){

    cout << get_min_steps("abad", "abac") << endl;
    cout << get_min_steps("Anshuman", "Antihuman") << endl;
    system("pause");
    return 0;
}
