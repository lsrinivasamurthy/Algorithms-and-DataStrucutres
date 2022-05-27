#include<iostream>
#include<vector>
using namespace std;

int dx[8] = { -1, -1, -1, +0, +0, +1, +1, +1 };
int dy[8] = { -1, +0, +1, -1, +1, -1, +0, +1 };

bool is_valid(int i,int j, vector<vector<int>>&arr){
    return i >= 0 && i < arr.size() && j >= 0 && j < arr[i].size() && arr[i][j] == 1;
}

void dfs(vector<vector<int>>& arr, int i, int j){
    if (arr[i][j] == 0){
        return; // No need to traversal as it is Water. Traverse only for Land
    }
    arr[i][j] = 0; // Convert Land to Water as it is alredy visited.

    // Now we have to check for all 8 directions whether the surroundings all are lands are not ?
    for (int k = 0; k < 8; k++){
        if (is_valid(i + dx[k], j + dy[k], arr)){
            dfs(arr, i + dx[k], j + dy[k]);
        }
    }
}

int count_islands(vector<vector<int>>& arr){
    int n = arr.size();
    int m = arr[0].size();

    //No need of visited array, just make the visited node as 0(Water)

    int count = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; j++){
            if (arr[i][j] == 1){
                count++;
                cout << i << " " << j<<endl;
                dfs(arr, i, j);
            }
        }
    }
    return count;
}

int main(){
    vector<int> v1{ 1, 0, 0, 1, 0 };
    vector<int> v2{ 1, 1, 0, 0, 0 };
    vector<int> v3{ 0, 0, 1, 1, 1 };
    vector<int> v4{ 0, 0, 0, 0, 0 };
    vector<int> v5{ 0, 1, 1, 0, 0 };
    vector<vector<int>> v{ v1, v2, v3, v4, v5 };
    cout << count_islands(v)<<endl;

    system("pause");
    return 0;
}