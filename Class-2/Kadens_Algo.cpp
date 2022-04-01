#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/* Brute Force Approach
 * T.C : O(n^2)
 * S.C : O(1)
 */
int max_sum_subArray(vector<int> v)
{
	int max = v[0];
	int n = v.size();
	for (int i = 0; i < n; ++i){
		int cur_sum = 0;
		for (int j = i; j < n; ++j){
			cur_sum += v[j];
			if (cur_sum > max)
				max = cur_sum;
		}
	}
	return max;
}

/* Kadens Algo
 * meh : max ending here
 * Input : -5,1,3,-7,5,2
 * MEH   : -5,1,4,-3,5,7 ( Consider only max ending here at index - 0,1,2,3,4,5)
 * Formula : meh[i] = meh[i-1] + arr[i] if meh[i-1] > 0 means positive
 *           meh[i] = arr[i]          if meh[i-1] < 0 means negative
 * we have to store the max sum of contigious sub array so store only the max sum ending at exact index.
 *
 * T.C : O(n)
 * S.C : O(n)
 */
int max_sum_subArray_kadens(vector<int> v){
	int n = v.size();
	vector<int> meh(n);
	meh[0] = v[0];

	// step-1: prepare the meh.
	for (int i = 1; i < n; ++i){
		if (meh[i - 1] > 0){
			meh[i] = meh[i-1]+v[i];
		}
		else{
			meh[i] = v[i];
		}
	}
	
	// stpe-2 : loop over meh and return the max element
	int max = meh[0];
	for (int i = 1; i < meh.size(); ++i){
		if (meh[i] > max) max = meh[i];
	}
	return max;
}

/* Kadens Algo Alternate
*  Improved Space Complexity.
*  The logic is seperate meh is not required , store it in the original array itself and then take a decision to add or to drop.
*  T.C : O(n)
*  S.C : O(1)
*/
int max_sum_subArray_kadens_alt(vector<int> v){
	int n = v.size();
	int prev_max = v[0];
	int result = v[0];
	
	for (int i = 1; i < n; ++i){
		int cur_max;
		if (prev_max > 0){
			cur_max = prev_max + v[i];
		}
		else{
			cur_max = v[i];
		}
		result = max(result, cur_max);
		prev_max = cur_max;
	}
	return result;
}

int main()
{
	cout << "Kadens Algo" << endl;

	vector<int> v = { -5, 1, 3, -7, 5, 2 };
	cout << "Max Sum of Sub Array Brute Force:"<<max_sum_subArray(v)<< endl;
	cout << "Max Sum of Sub Array Kadens Algo:" << max_sum_subArray_kadens(v) << endl;
	cout << "Max Sum of Sub Array Kadens Algo Alt:" << max_sum_subArray_kadens_alt(v) << endl;
	
	system("pause");
	return 0;
}