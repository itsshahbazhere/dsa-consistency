// - Reverse an Array: https://bit.ly/3EOyAFz 

#include <bits/stdc++.h> 
void reverseArray(vector<int> &arr , int m)
{
	int start = m+1;
	int end = arr.size()-1;

	while(start<=end){
		swap(arr[start++], arr[end--]);
		// start++;
		// end--;
	}
}

