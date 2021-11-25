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

// O(N^N/2) Brute Force
int getMinimumCount(int n)
{
  if (n <= 3)
  {
    return n;
  }
  int mini = INT_MAX;
  for (int i = 1; i <= ((int)sqrt(n)); i++)
  {
    mini = min(1 + getMinimumCount(n - (i * i)), mini);
  }
  return mini == INT_MAX ? -1 : mini;
}

// O(N*SQRT(N)) DP

int getMinimumCount_DP(int n)
{
  vector<int> v(n + 1);
  v[0] = 0;
  v[1] = 1;
  v[2] = 2;
  v[3] = 3;

  for (int i = 4; i <= n; i++)
  {
    v[i] = i;
    for (int j = 1; j <= ceil(sqrt(i)); j++)
    {
      int temp = j * j;
      if (temp > i)
        break;

      v[i] = min(v[i], 1 + v[i - temp]);
    }
  }
  return v[n];
}

int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cout << getMinimumCount_DP(i) << " ";
    cout << getMinimumCount(i) << endl;
  }
  return 0;
}
