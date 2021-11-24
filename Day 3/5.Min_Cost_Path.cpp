/*
  Name            :   Himanshu Agrawal
  Codeforces      :   https://codeforces.com/profile/harry_6003
  Codechef        :   https://www.codechef.com/users/harrry_60
  Leetcode        :   https://leetcode.com/harry_6003/
  Github          :   https://github.com/harry6003
  Motto           :   Make my Parents Proud..!!
*/

#include <bits/stdc++.h>
using namespace std;
// Brute Force O(3^N)
int getMinCostPath(int **v, int desr, int desc)
{
  if (desr < 0 || desc < 0)
    return INT_MAX;

  if (desr == 0 && desc == 0)
    return v[desr][desc];

  int x = min(getMinCostPath(v, desr - 1, desc - 1), min(getMinCostPath(v, desr - 1, desc),
                                                         getMinCostPath(v, desr, desc - 1)));

  return v[desr][desc] + x;
}

// DP O(N^2)

int getMinCostPath_Memo(int **v, int desr, int desc, int r, int c, int **dp)
{
  dp[desr][desc] = v[desr][desc];

  for (int i = desc - 1; i >= 0; i--)
    dp[desr][i] = dp[desr][i + 1] + v[desr][i];

  for (int i = desr - 1; i >= 0; i--)
    dp[i][desc] = dp[i + 1][desc] + v[i][desc];

  for (int i = desr - 1; i >= 0; i--)
  {
    for (int j = desc - 1; j >= 0; j--)
    {
      dp[i][j] = v[i][j] + min(dp[i + 1][j + 1], min(dp[i + 1][j], dp[i][j + 1]));
    }
  }

  return dp[0][0];
}

int getMinCostPath_Memo(int **v, int desr, int desc, int r, int c)
{
  int **dp = new int *[r];
  for (int i = 0; i < r; i++)
    dp[i] = new int[c];

  return getMinCostPath_Memo(v, desr, desc, r, c, dp);
}

int main()
{
  int r, c;
  cin >> r >> c;
  int **v = new int *[r];
  for (int i = 0; i < r; i++)
    v[i] = new int[c];
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> v[i][j];
    }
  }
  cout << getMinCostPath(v, r - 1, c - 1) << " ";
  cout << getMinCostPath_Memo(v, r - 1, c - 1, r, c) << endl;
  return 0;
}
