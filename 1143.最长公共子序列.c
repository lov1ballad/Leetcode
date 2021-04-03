#define _CRT_SECURE_NO_WARNINGS 1
/*int longestCommonSubsequence(char * text1, char * text2){
int length1=strlen(text1),length2=strlen(text2);

//辅助二维数组
int i,j;
int dp[length1+1][length2+1];//dp[i][j]代表text1的前i个字符和text2前j个字符两者最长公共子序列

//初始化
for(i=0;i<=length1;i++)
dp[i][0]=0;
for(j=0;j<=length2;j++)
dp[0][j]=0;

for(i=0;i<length1;i++)
for(j=0;j<length2;j++)//状态转移方程
{
if(text1[i]==text2[j])//两者相等
dp[i+1][j+1]=dp[i][j]+1;
else
dp[i+1][j+1]=dp[i+1][j]>dp[i][j+1]?dp[i+1][j]:dp[i][j+1];
}
return dp[length1][length2];
}
*/
//优化
int max(int a, int b){
	if (a>b) return a;
	return b;
}
int longestCommonSubsequence(char * text1, char * text2){
	int i, j;
	int temp;
	int pre;
	int len1;
	int len2;
	len1 = strlen(text1);
	len2 = strlen(text2);
	int cur[len2 + 1];
	memset(cur, 0, sizeof(cur));
	for (i = 1; i <= len1; i++)
	{
		pre = 0;
		for (j = 1; j <= len2; j++)
		{
			temp = cur[j];
			if (text1[i - 1] == text2[j - 1]) cur[j] = pre + 1;
			else cur[j] = max(cur[j], cur[j - 1]);
			pre = temp;
		}
	}
	return cur[len2];
}