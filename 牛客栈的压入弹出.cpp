#define _CRT_SECURE_NO_WARNINGS 1
#include "system.h"
//https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tab=answerKey
#include <vector>
#include <stack>
class Solution
{
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		//��ջ�ͳ�ջ��Ԫ�ظ���������ͬ
		if (pushV.size() != popV.size())
			return false;
		// ��s��ģ����ջ���ջ�Ĺ���
		int outIdx = 0;
		int inIdx = 0;
		stack<int> s;
		while (outIdx < popV.size())
		{
			// ���s�ǿգ�����ջ��Ԫ�����ջ��Ԫ�ز���ȣ�����ջ
			while (s.empty() || s.top() != popV[outIdx])
			{
				if (inIdx < pushV.size())
					s.push(pushV[inIdx++]);
				else
					return false;
			}
			// ջ��Ԫ�����ջ��Ԫ����ȣ���ջ
			s.pop();
			outIdx++;
		}
		return true;
	}
};