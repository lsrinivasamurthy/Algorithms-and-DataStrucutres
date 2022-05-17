#include<iostream>
#include<vector>

using namespace std;

void dfs_helper(vector<vector<int>>& adj, int current, vector<bool>& visited){
    if (visited[current]){
        return;
    }
    visited[current] = true;
    cout << current << " ";
    for (int neighbour : adj[current]){
        dfs_helper(adj, neighbour, visited);
    }
}

void dfs(vector<vector<int>>& adj){
    int v = adj.size();
    vector<bool> visited(v, false);

    int count = 0;
    for (int i = 0; i < v; ++i){
        if (!visited[i]){
            ++count;
            dfs_helper(adj, i, visited);
        }
    }
    cout << endl;
    cout << "connected components:" << count << endl;
}

int main(){
    cout << "DFS Traversal In Graphs :" << endl;
    
    cout << "Example-1:" << endl;
    vector<int> row1{ 1, 4 };
    vector<int> row2{ 0, 2, 3 };
    vector<int> row3{ 1, 3 };
    vector<int> row4{ 1, 2 };
    vector<int> row5{ 0 };

    vector<vector<int>> v1{ row1, row2, row3, row4, row5 };
    dfs(v1);
    cout << endl;

    cout << "Example-2:" << endl;
    vector<int> row6{ 1, 4 };
    vector<int> row7{ 0};
    vector<int> row8{ 3 };
    vector<int> row9{ 2 };
    vector<int> row10{ 0 };

    vector<vector<int>> v2{ row6, row7, row8, row9, row10 };
    dfs(v2);
    cout << endl;

    system("pause");
    return 0;
}