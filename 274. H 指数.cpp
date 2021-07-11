#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int hIndex(vector<int>& citations) {
		int l = 0, r = citations.size() + 1;
		while (l < r) {
			int mid = l + ((r - l) >> 1);
			int cnt = 0;
			for (int& i : citations) {
				if (i >= mid) {
					cnt++;
				}
			}
			if (cnt < mid) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		return l - 1;
	}
};
