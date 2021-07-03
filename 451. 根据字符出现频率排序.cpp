#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/sort-characters-by-frequency/
class Solution {
public:
	string frequencySort(string s)
	{
		int a[127]{}; char x;
		for (char k : s) ++a[k];
		for (int i = -1, i1, j = 0; i != 0;){
			i1 = i = x = 0;
			for (char n = 32; n<127; ++n) if (a[n]>i) { i = a[n]; x = n; }
			for (i1 = i, a[x] = 0; 0 != i1--; s[j++] = x);
		}
		return s;
	}
};