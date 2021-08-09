#define _CRT_SECURE_NO_WARNINGS 1
//
class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> v;
		for (long long a = 1; a <= INT_MAX; a = a * 2)
		for (long long b = a; b <= INT_MAX; b = b * 3)
		for (long long c = b; c <= INT_MAX; c = c * 5)
			v.push_back(c);
		sort(v.begin(), v.end());
		return v.at(n - 1);
	}
};

���ȶ��� (С����)
���ȶ��� / С���� / �󶥶�
�������ȶ������Զ�����Ĺ���
ÿ��ȡ����ͷԪ�أ������ͷԪ�� * 2����ͷԪ�� * 3����ͷԪ�� * 5
��ע�⣬�� 12 ���Ԫ�أ����� 4 �� 3 �õ���Ҳ���� 6 �� 2 �õ�������Ҫע��ȥ��


class Solution {
public:
	int nthUglyNumber(int n) {
		priority_queue <double, vector<double>, greater<double> > q;
		double answer = 1;
		for (int i = 1; i<n; ++i)
		{
			q.push(answer * 2);
			q.push(answer * 3);
			q.push(answer * 5);
			answer = q.top();
			q.pop();
			while (!q.empty() && answer == q.top())
				q.pop();
		}
		return answer;
	}
};

class Solution {
public:
	int nthUglyNumber(int n) {
		priority_queue <double, vector<double>, greater<double> > q;
		set<int> s;
		s.insert(1);
		vector<int> mask({ 2, 3, 5 });
		double answer = 1;
		for (int i = 1; i<n; ++i)
		{
			for (int &j : mask)
			if (s.count(answer*j) == 0)
			{
				q.push(answer*j);
				s.insert(answer*j);
			}
			answer = q.top();
			q.pop();
		}
		return answer;
	}
};


������ģ����д�����Ĺ���
1 ��ͷ��1 �� 2 1 �� 3 1 �� 5��������{ 1, 2, 3, 5 }
�ֵ� 2��2 �� 2 2 �� 3 2 �� 5��������{ 1, 2, 3, 4, 5, 6, 10 }
��д�Ĺ��̺Ͳ���С���ѵķ������񣬵�����ô������ǰ������

С���ѵķ������ȴ����ţ�dp �ķ������������ٴ�
������ 3 ��ָ�� p_2, p_3, p_5
������ǵڼ�������2�����ڼ����� 3 �����ڼ����� 5 ��
��̬���� dp[i] = min(dp[p_2] * 2, dp[p_3] * 3, dp[p_5] * 5)
С������һ��Ԫ�س���Ȼ��� 3 ��Ԫ��
��̬�滮���Ǳ�ʶ 3 ��Ԫ�أ�ͨ���Ƚ����ǵ� 2 ����3 ����5 ���Ĵ�С����һ��һ����



class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> dp(n);
		dp.at(0) = 1;
		int p_2, p_3, p_5;
		p_2 = p_3 = p_5 = 0;
		for (int i = 1; i<n; ++i)
		{
			dp.at(i) = min(min(2 * dp.at(p_2), 3 * dp.at(p_3)), 5 * dp.at(p_5));
			if (dp.at(i) == 2 * dp.at(p_2))
				++p_2;
			if (dp.at(i) == 3 * dp.at(p_3))
				++p_3;
			if (dp.at(i) == 5 * dp.at(p_5))
				++p_5;
		}
		return dp.at(n - 1);
	}
};


