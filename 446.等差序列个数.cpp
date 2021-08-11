#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& nums) {
		int res = 0;
		int n = nums.size();
		// dp[3][2] = 5 -> nums[3]��β ����Ϊ2 �� �Ȳ����У����ȴ���2���ĸ���Ϊ 5
		vector<unordered_map<long long, int>> dp(n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				long long d = (long long)nums[i] - nums[j];
				dp[i][d] += dp[j][d] + 1;
				// dp[j][d] ������ dp[i] ��ʾ�˳�������Ϊ3�ĵȲ�����
				res += dp[j][d];
			}
		}

		return res;
	}
};
