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
int edit_distance_another(string s, string t)
{
  if (s.size() == 0 || t.size() == 0)
    return max(s.size(), t.size());

  if (s[0] == t[0])
    return edit_distance_another(s.substr(1), t.substr(1));
  else
  {
    int x = edit_distance_another(s.substr(1), t) + 1;           // insert
    int y = edit_distance_another(s, t.substr(1)) + 1;           // delete
    int z = edit_distance_another(s.substr(1), t.substr(1)) + 1; // replace
    return min(x, min(y, z));
  }
}

// memoization O(M*N)
int edit_distance_memo_helper(string s, string t, int **dp)
{
  int m = s.size();
  int n = t.size();
  if (n == 0 || m == 0)
  {
    return max(m, n);
  }

  if (dp[m][n] != -1)
    return dp[m][n];

  if (s[0] == t[0])
  {
    dp[m][n] = edit_distance_memo_helper(s.substr(1), t.substr(1), dp);
  }
  else
  {
    dp[m - 1][n] = edit_distance_memo_helper(s.substr(1), t, dp);
    dp[m][n - 1] = edit_distance_memo_helper(s, t.substr(1), dp);
    dp[m - 1][n - 1] = edit_distance_memo_helper(s.substr(1), t.substr(1), dp);

    dp[m][n] = 1 + min(dp[m - 1][n], min(dp[m][n - 1], dp[m - 1][n - 1]));
  }
  return dp[m][n];
}
int edit_distance_memo(string s, string t)
{

  int m = s.size();
  int n = t.size();
  int **dp = new int *[m + 1];
  for (int i = 0; i <= m; i++)
    dp[i] = new int[n + 1];

  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++)
      dp[i][j] = -1;

  // for (int i = 0; i <= m; i++)
  // {
  //   for (int j = 0; j <= n; j++)
  //   {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  return edit_distance_memo_helper(s, t, dp);
}

// DP O(M*N)
int edit_distance_dp(string s, string t)
{

  int m = s.size();
  int n = t.size();
  int **dp = new int *[m + 1];
  for (int i = 0; i <= m; i++)
    dp[i] = new int[n + 1];

  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i == 0)
      {
        dp[i][j] = j;
      }
      else if (j == 0)
      {
        dp[i][j] = i;
      }
      else
      {
        if (s[i - 1] == t[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
      }
    }
  }

  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  return dp[m][n];
}

int main()
{
  string s, t;
  cin >> s >> t;
  cout << edit_distance_another(s, t) << endl;
  cout << edit_distance_memo(s, t) << endl;
  int d = edit_distance_dp(s, t);
  cout << d << endl;
  return 0;
}
