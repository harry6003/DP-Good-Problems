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
int knapsack(int n, int W, int w[], int val[])
{
  if (W == 0 || n == 0)
    return 0;

  if (w[n - 1] <= W)
  {
    return max(val[n - 1] + knapsack(n - 1, W - w[n - 1], w, val), knapsack(n - 1, W, w, val));
  }
  else
  {
    return knapsack(n - 1, W, w, val);
  }
}

// O(N*W)
int knapSack_DP(int n, int W, int wt[], int val[])
{
  int i, w;
  int K[n + 1][W + 1];

  for (i = 0; i <= n; i++)
  {
    for (w = 0; w <= W; w++)
    {
      if (i == 0 || w == 0)
        K[i][w] = 0;
      else if (wt[i - 1] <= w)
        K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]],
                      K[i - 1][w]);
      else
        K[i][w] = K[i - 1][w];
    }
  }

  return K[n][W];
}
int main()
{
  int n;
  cin >> n;
  int W;
  cin >> W;
  int w[n];
  int val[n];

  for (int i = 0; i < n; i++)
    cin >> w[i];
  for (int i = 0; i < n; i++)
    cin >> val[i];

  cout << knapsack(n, W, w, val) << endl;
  cout << knapsack(n, W, w, val) << endl;
  return 0;
}
