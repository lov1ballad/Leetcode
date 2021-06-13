#define _CRT_SECURE_NO_WARNINGS 1
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n)
	{
		long long l = 0, r = n;
		while (l<r){
			long long mid = l + r + 1 >> 1;
			if (!isBadVersion(mid)) l = mid;
			else r = mid - 1;
		}
		return l + 1;
	}
};