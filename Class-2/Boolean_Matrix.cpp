#include<iostream>
#include<vector>

using namespace std;
// T.C : O(nm)
// S.C : O(1)
void printMatrix(vector<vector<int>> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			cout << v[i][j];
		}
		cout << endl;
	}
}

vector<vector<int>> fill_matrix_zeros(vector<vector<int>> v)
{
	int n = v.size();
	int m = v[0].size();

	// step-1 check if 0th row and 0th column has any zeros
	bool zero_row = false;
	bool zero_col = false;
	for (int j = 0; j < m; ++j){
		if (v[0][j] == 0){
			zero_row = true;
			break;
		}
	}
	for (int i = 0; i < n; ++i){
		if (v[i][0] == 0){
			zero_col = true;
			break;
		}
	}

	// step-2 loop over inner array and construct buckets for 0th row and 0th column.
	for (int i = 1; i < n; ++i){
		for (int j = 1; j < m; ++j){
			if (v[i][j] == 0){
				v[0][j] = 0;
				v[i][0] = 0;
			}
		}
	}

	// step-3 update inner matrix as per the bucket values
	for (int i = 1; i < n; ++i){
		for (int j = 1; j < m; ++j){
			if (v[0][j] == 0 || v[i][0] == 0){
				v[i][j] = 0;
			}
		}
	}

	// step-4 update 0th row and column according to stored contents.
	if (zero_row){
		for (int j = 0; j < m; ++j){
			v[0][j] = 0;
		}
	}
	if (zero_col){
		for (int i = 0; i < n; ++i){
			v[i][0] = 0;
		}
	}

	return v;
}

int main()
{
	cout <<"Boolean Matrix"<< endl;
	vector<vector<int>> v
	{
		{ 1, 0, 1, 1 },
		{ 1, 1, 1, 1 },
		{ 1, 1, 1, 0 }
	};
	cout << "Before :" << endl; 
	printMatrix(v);
	fill_matrix_zeros(v);
	cout << "After :" << endl;
	printMatrix(v);
	system("pause");
	return 0;
}