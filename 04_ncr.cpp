#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> memo;
// Formula : nCr(n,r) = nCr(n-1,r-1) + nCr(n-1,r);

int p = 1e9 + 7;

int nCr_helper(int n, int r){
    // Base Cases ?

    if (n < r){
        return 0;
    }
    if (r == 0 || n == r){
        return 1;
    }

    if (memo[n][r] != -1){
        return memo[n][r];
    }

    return memo[n][r] = ((nCr_helper(n - 1, r - 1) % p) + (nCr_helper(n - 1, r) % p)) % p;
}

int nCr(int n, int r){
    memo = vector<vector<int>>(n + 1, vector<int>(r + 1, -1));
    return nCr_helper(n, r);
}
int main(){
    cout << nCr(3, 2) << endl;
    cout << nCr(4, 2) << endl;

    system("pause");
    return 0;
}