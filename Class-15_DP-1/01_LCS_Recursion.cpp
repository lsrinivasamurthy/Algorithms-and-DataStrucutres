#include<iostream>
#include<algorithm>
using namespace std;

int lcs_helper(string s1, int i, string s2, int j){
    // Base Conditions
    if (i == s1.length() || j == s2.length()){
        return 0;
    }

    if (s1[i] == s2[j]){
        return 1 + lcs_helper(s1, i + 1, s2, j + 1);
    }
    else{
        return max(lcs_helper(s1, i, s2, j + 1), lcs_helper(s1, i + 1, s2, j));
    }
}

int lcs(string s1, string s2){
    return lcs_helper(s1, 0, s2, 0);
}

int main(){
    cout << "Welcome To Dynamic Programming" << endl;
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    cout<<"Length of Longest Common Substring(LCS) :"<<lcs(s1, s2)<<endl;
    system("pause");
    return 0;
}
