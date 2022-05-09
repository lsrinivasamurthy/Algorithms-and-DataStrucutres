#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(pair<int,int>& a, pair<int,int>& b){
    return (a.first / (float)a.second) > (b.first / (float)b.second);
}

float fractional_knapsack(vector<int> values, vector<int> weights, int W){
    int n = values.size();
    
    // construct a vector which will have a relation between weights and its corresponding values
    vector<pair<int, int>> items(n);
    for (int i = 0; i < weights.size(); ++i){
        items[i] = { values[i], weights[i] };
    }

    // Now sort this in a way that value per weight will be more.
    sort(items.begin(), items.end(), comp);

    float max_value = 0;

    for (int i = 0; i < n; ++i){
        if (items[i].second <= W){
            max_value += items[i].first;
            W -= items[i].second;
        }
        else{
            max_value += W / (float)items[i].second * items[i].first;
            W = 0;
            break;
        }
    }
    return max_value;
}

int main(){
    cout << fractional_knapsack({ 100, 60, 120 }, { 20, 10, 30 }, 50) << endl;
    cout << fractional_knapsack({ 5, 7, 100 }, { 10, 40, 45 }, 50) << endl;
    system("pause");
    return 0;
}
