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
// Brute Force O(2^N)
int lcs(string s, string t)
{
  if (s.size() == 0 || t.size() == 0)
  {
    return 0;
  }

  if (s[0] == t[0])
  {
    return 1 + lcs(s.substr(1), t.substr(1));
  }
  else
  {
    return max(lcs(s.substr(1), t), lcs(s, t.substr(1)));
  }
}

// Memeoization O(M*N)

int lcs_memo(string s, string t)
{
}

int main()
{
  string s, t;
  cin >> s >> t;
  cout << lcs(s, t) << " ";
  cout << lcs_memo(s, t) << endl;

  return 0;
}
