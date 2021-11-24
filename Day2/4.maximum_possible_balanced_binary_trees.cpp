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
const int M = 1e9 + 7;
int mod(int x)
{
  return ((x % M + M) % M);
}
int add(int a, int b)
{
  return mod(mod(a) + mod(b));
}
int mul(int a, int b)
{
  return mod(mod(a) * mod(b));
}
//  O(2^N) Brute Force
int getMaxCount(int h)
{
  if (h <= 1)
    return 1;

  int foronelessheight = getMaxCount(h - 1);
  int fortwolessheight = getMaxCount(h - 2);

  int totalpossible = add(mul(foronelessheight, foronelessheight), mul(2, mul(foronelessheight, fortwolessheight)));

  return totalpossible;
}

// O(N) DP

int getMaxCount_DP(int h)
{
  vector<int> v(h + 1);
  v[0] = 1;
  v[1] = 1;

  for (int i = 2; i <= h; i++)
  {
    v[i] = add(mul(2, mul(v[i - 2], v[i - 1])), mul(v[i - 1], v[i - 1]));
  }
  return v[h];
}

int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cout << getMaxCount_DP(i) << " ";
    cout << getMaxCount(i) << endl;
  }
  return 0;
}
