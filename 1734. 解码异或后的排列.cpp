#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/decode-xored-permutation/
#include "system.h"
#include <vector>
class Solution {
public:
	vector<int> decode(vector<int>& encoded)
	{
		int old_size = encoded.size();
		vector<int> ans(old_size + 1);
		int ABCDE = 0;
		for (int i = 0; i <= old_size + 1; ++i)
		{
			ABCDE ^= i;
		}
		int BCDE = 0;
		for (int i = 1; i<old_size; i += 2)
		{
			BCDE ^= encoded[i];
		}
		ans[0] = ABCDE ^ BCDE;
		for (int i = 1; i<ans.size(); ++i)
		{
			ans[i] = ans[i - 1] ^ encoded[i - 1];
		}
		return ans;
	}
};