#define _CRT_SECURE_NO_WARNINGS 1
#include "system.h"
//https://leetcode-cn.com/problems/power-of-two/
/*class Solution {
public:
bool isPowerOfTwo(int n)
{
return (n > 0 && !(n & (n - 1)));
}
};*/
class Solution {
public:
	bool isPowerOfTwo(int n)
	{
		if (n <= 0) {
			return false;
		}
		bool flag = true;
		while (n > 1) {
			if (n % 2 == 0) {
				n /= 2;
			}
			else {
				flag = false;
				break;
			}
		}
		return flag;
	}
};