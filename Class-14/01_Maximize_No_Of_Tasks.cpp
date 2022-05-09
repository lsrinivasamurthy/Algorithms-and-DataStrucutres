#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int get_max_tasks(vector<int> A, int T){
    
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); ++i){
        if (A[i] <= T){
            T -= A[i];
        }
        else{            
            return i;
        }
    }
    return A.size();
}

int main(){
    cout << "Max Tasks Can be performed : " << get_max_tasks({ 4, 2, 1, 2, 5 }, 8) << endl;
    system("pause");
    return 0;
}
