#include<algorithm>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

/* Using Hash Map Technique
 * Time Complexity  : O(N)
 * Space Complexity : O(N)
 */
int getMinNumber_hashing(const vector<int>& v)
{
	map<int, bool> myMap;
	for (int i = 0; i < v.size(); ++i){
		myMap[v[i]] = true;
	}

	// Map filling is done with vector contents.
	// Now traverse from the smallest positive number and if number not found return that no.
	int index = 1;
	while (true){
		if (myMap.find(index) == myMap.end()){
			return index;
		}
		index++;
	}
}

/* Using Sorting Technique
* Time Complexity  : O(N)
* Space Complexity : O(1)
*/
int getMinNumber_Bucketing(vector<int> v)
{
	int n = v.size(); // so ans lies in the range of [1,n+1].

	// step-1: Replace all negative numbers with greater than range.
	// so replace all negative numbers with (n+1)+1 as this no won't be any possible outcome
	int x = n + 2;
	for (int i = 0; i < n; ++i){
		if (v[i] <= 0){
			v[i] = x;
		}
	}

	// step-2: for any valid element present in the array, make it corresponding bucket negative.
	for (int i = 0; i < n; ++i){
		int element = abs(v[i]);
		if (element >= 1 && element <= n && v[element - 1] >0)
			v[element - 1] *= -1;
	}

	// step-3 : Iterate over the array and return the smallest positive number
	for (int i = 0; i < n; ++i){
		if (v[i] > 0) return i + 1;
	}

	// special condition if all buckets are negative then return the next available positive number
	return n + 1;
}

/* Using Bucketing Technique
* Time Complexity  : O(NlogN)
* Space Complexity : O(1)
*/
int getMinNumber_Sorting(vector<int> v)
{
	sort(v.begin(), v.end());
	int index = 1;
	for (int i = 0; i < v.size(); ++i){
		if (v[i] > 0){
			if (index != v[i])
				return index;
			else
				index++;
		}
	}
}

int main()
{
	cout << "Smallest Positive Number" << endl;
	vector<int> v = { 0, -10, 1, 3, -20 };
	cout << "From Hashing :"<<getMinNumber_hashing(v) << endl;
	cout << "From Sorting :"<<getMinNumber_Sorting(v) << endl;
	cout << "From Sorting :" << getMinNumber_Bucketing(v) << endl;
	system("pause");
}

