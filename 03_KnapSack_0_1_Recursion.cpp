#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int max_value_helper(vector<int>& values, vector<int>& weights, int i, int W){
    // Base cases ?
    if (i == values.size()) return 0;
    if (W == 0) return 0;

    if (weights[i] > W){
        return max_value_helper(values, weights, i + 1, W);
    }

    int result = max(max_value_helper(values,weights,i+1,W-weights[i])+ values[i],
                     max_value_helper(values,weights,i+1,W));
    return result;
}

int max_value(vector<int> values, vector<int> weights, int W){
    return max_value_helper(values, weights, 0, W);
}

int main(){
    cout << max_value({60,100,120}, {10,20,30},50) << endl;
    system("pause");
    return 0;
}