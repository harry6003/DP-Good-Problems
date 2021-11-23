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

// O(N^3) Brute Force
int getminsteps(int n)
{
  if (n == 1)
    return 0;

  int c = getminsteps(n - 1);
  int a = INT_MAX, b = INT_MAX;

  if ((n % 2) == 0)
    b = getminsteps(n / 2);

  if ((n % 3) == 0)
    a = getminsteps(n / 3);

  return (min(a, min(b, c)) + 1);
}

// O(N) Memoization
int getminsteps_better(int n, vector<int> &v)
{
  if (n <= 1)
  {
    v[n] = 0;
    return 0;
  }

  int a = INT_MAX, b = INT_MAX;
  if (v[n - 1] == -1)
    v[n - 1] = getminsteps_better(n - 1, v);

  if (n % 2 == 0)
  {
    if (v[n / 2] == -1)
      v[n / 2] = getminsteps_better(n / 2, v);
    a = v[n / 2];
  }

  if (n % 3 == 0)
  {
    if (v[n / 3] == -1)
      v[n / 3] = getminsteps_better(n / 3, v);
    b = v[n / 3];
  }

  v[n] = min(v[n - 1], min(a, b)) + 1;

  return v[n];
}

int getminsteps_better(int n)
{
  vector<int> v(n + 1, -1);
  return getminsteps_better(n, v);
}

// O(N) DP

int getminsteps_DP(int n)
{
  vector<int> v;
  v.push_back(0);
  v.push_back(0);
  v.push_back(1);

  for (int i = 3; i <= n; i++)
  {
    int mini = INT_MAX;

    mini = min(v[i - 1], mini);
    if (i % 2 == 0)
      mini = min(v[i / 2], mini);

    if (i % 3 == 0)
      mini = min(v[i / 3], mini);

    v.push_back(mini + 1);
  }
  return v[n];
}

int main()
{
  int n;
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    cout << getminsteps(i) << " ";
    cout << getminsteps_better(i) << " ";
    cout << getminsteps_DP(i) << endl;
  }

  return 0;
}
