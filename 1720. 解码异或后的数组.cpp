#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/decode-xored-array/
class Solution {
public:
	vector<int> decode(vector<int>& encoded, int first)
	{
		vector<int> ans(encoded.size() + 1);
		ans[0] = first;
		for (int i = 1; i<ans.size(); ++i)
		{
			ans[i] = ans[i - 1] ^ encoded[i - 1];
		}
		return ans;
	}
};