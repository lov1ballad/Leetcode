<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/decode-ways/
class Solution {
public:
	int numDecodings(string s) {
		int pre2 = 0, pre1 = 1;
		for (int i = 0; i < s.size() && pre1; ++i)
		{
			int cur = 0;
			if (s[i] != '0') cur += pre1;
			if (i != 0 && s[i - 1] != '0' && (s[i - 1] - '0') * 10 + s[i] - '0' <= 26)
				cur += pre2;
			pre2 = pre1;
			pre1 = cur;
		}
		return pre1;
	}
=======
#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/decode-ways/
class Solution {
public:
	int numDecodings(string s) {
		int pre2 = 0, pre1 = 1;
		for (int i = 0; i < s.size() && pre1; ++i)
		{
			int cur = 0;
			if (s[i] != '0') cur += pre1;
			if (i != 0 && s[i - 1] != '0' && (s[i - 1] - '0') * 10 + s[i] - '0' <= 26)
				cur += pre2;
			pre2 = pre1;
			pre1 = cur;
		}
		return pre1;
	}
>>>>>>> b3af6b28386749ab6aaaa3cc66f48cad04dfe11f
};