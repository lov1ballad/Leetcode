#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/chuan-di-xin-xi/
class Solution {
	/*public:
	int numWays(int n, vector<vector<int>>& relation, int k) {
	/*vector<int> a[n];
	for(auto v : relation) a[v[0]].push_back(v[1]);
	queue<int> q;
	q.push(0);
	int step = 0;
	int ans = 0;
	while(q.size()&&step < k){//模拟层序遍历 当走到第k层时 也即第k轮 统计第k层编号为n-1的节点有几个即可
	int len = q.size();
	while(len--){//当前step层有len个节点,基于此，拓展第step+1层
	int t = q.front();
	q.pop();
	for(auto v : a[t]){//拓展第step+1层
	if(step+1==k&&v==n-1) ans++;//统计到第k层时的节点编号为n-1的数量 即为答案
	q.push(v);
	}
	}
	step++;
	}
	return ans;*/
public:
	int numWays(int n, vector<vector<int>>& relation, int k) {
		vector<vector<int>> grid(n, vector<int>(n, 0));
		for (int i = 0; i<relation.size(); i++) {
			grid[relation[i][0]][relation[i][1]] = 1;
		}
		if (k == 1)
			return grid[0][n - 1];
		else {
			vector<vector<int>> res = grid;
			//A乘n-1次自己得到A^n
			for (int i = 1; i<k; i++) {
				res = mul_matrix(res, grid, n);
			}
			return res[0][n - 1];
		}
	}
	vector<vector<int>> mul_matrix(vector<vector<int>> grid1, vector<vector<int>> grid2, int n) {
		vector<vector<int>> grid(n, vector<int>(n, 0));
		for (int i = 0; i<grid.size(); i++) {
			for (int j = 0; j<grid.size(); j++) {
				int temp = 0;
				for (int k = 0; k<n; k++) {
					temp += grid1[i][k] * grid2[k][j];
				}
				grid[i][j] = temp;
			}
		}
		return grid;
	}
};