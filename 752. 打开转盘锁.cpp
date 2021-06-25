#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/open-the-lock/
class Solution {
public:
	string s, t;
	unordered_set<string> st;
	int openLock(vector<string>& deadends, string target) {
		s = "0000";
		t = target;
		if (s == t) return 0;
		for (const auto& d : deadends) st.insert(d);
		if (st.count(s)) return -1;
		int ans = bfs();
		return ans;
	}
	int bfs(){
		queue<string> d1, d2;
		unordered_map<string, int> m1, m2;
		d1.push(s); m1[s] = 0;
		d2.push(t); m2[t] = 0;
		while (d1.size() and d2.size()){
			int t = -1;
			if (d1.size() <= d2.size()){
				t = update(d1, m1, m2);
			}
			else{
				t = update(d2, m2, m1);
			}
			if (t != -1) return t;
		}
		return -1;
	}
	int update(queue<string>& q, unordered_map<string, int>& cur, unordered_map<string, int>& other){
		string t = q.front(); q.pop();
		int step = cur[t];
		for (int i = 0; i < 4; i++){
			for (int j = -1; j <= 1; j++){
				if (j == 0) continue;
				int origin = t[i] - '0';
				int next = (origin + j) % 10;
				if (next == -1) next = 9;
				string copy = t;
				copy[i] = '0' + next;
				if (st.count(copy) or cur.count(copy)) continue;
				if (other.count(copy)) return step + 1 + other[copy];
				else{
					q.push(copy);
					cur[copy] = step + 1;
				}
			}
		}
		return -1;
	}
};
