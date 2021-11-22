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
// O(2^n) Brute Force
int fibo(int n)
{
  if (n <= 1)
  {
    return n;
  }
  int a = fibo(n - 1);
  int b = fibo(n - 2);
  return a + b;
}

// O(N) Memoization
int fibo_better(int n, int *v)
{
  if (n <= 1)
  {
    v[n] = n;
    return n;
  }

  if (v[n - 1] == -1)
  {
    v[n - 1] = fibo_better(n - 1, v);
  }
  if (v[n - 2] == -1)
  {
    v[n - 2] = fibo_better(n - 2, v);
  }

  v[n] = v[n - 1] + v[n - 2];
  return v[n];
}

int fibo_better(int n)
{
  int *v = new int[n + 1];
  for (int i = 0; i <= n; i++)
    v[i] = -1;
  return fibo_better(n, v);
}

// O(N) Dynamic Programming
int fibo_DP(int n)
{
  vector<int> v;
  v.push_back(0);
  v.push_back(1);
  for (int i = 2; i <= n; i++)
    v.push_back(v[i - 1] + v[i - 2]);
  return v[n];
}

int main()
{
  int n;
  cin >> n;
  cout << fibo(n) << endl;
  cout << fibo_better(n) << endl;
  cout << fibo_DP(n) << endl;

  return 0;
}
