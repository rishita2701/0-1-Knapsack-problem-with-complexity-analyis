/*

1. AIM: To implement subset 0 - 1 Knapsack problem using dynamic programming.

2. TASK TO BE DONE: 
i.	0-1 Knapsack Problem : A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are n items and weight of ith item is wi and the profit of selecting this item is pi. What items should the thief take?
ii.	To devise algorithm to perform 0-1 Knapsack problem using dynamic programming. 
iii.	To implement the algorithms in C++.
iv.	To analyze the time complexity and space complexity of the code.
3. LOGISTICS USED:  Windows 10, Online C++ Compiler and Microsoft Word
4.  ALGORITHM:
1. Begin
2. Input set of items each with a weight and a value
3. Set knapsack capacity
4. Create a function that returns maximum of two integers.
5. Create a function which returns the maximum value that can be put in a knapsack of capacity W

6. int knapSack(int W, int w[], int v[], int n)
int i, wt;
int K[n + 1][W + 1]
for i = 0 to n
for wt = 0 to W
if (i == 0 or wt == 0)
  Do K[i][wt] = 0
else if (w[i - 1] <= wt)
  Compute: K[i][wt] = max(v[i - 1] + K[i - 1][wt - w[i - 1]], K[i -1][wt])
else
  K[i][wt] = K[i - 1][wt]
  return K[n][W]
7. Call the function and print the result.
8. End
5. CODE:
*/

#include <iostream>

using namespace std;

int max(int x, int y) 
{
  
return (x > y) ? x : y;
}

int knapSack(int W, int w[], int v[], int n) 
{
  int i, wt;
  int K[n + 1][W + 1];
  for (i = 0; i <= n; i++) {
   for (wt = 0; wt <= W; wt++) {
     if (i == 0 || wt == 0)
     K[i][wt] = 0;
     else if (w[i - 1] <= wt)
     K[i][wt] = max(v[i - 1] + K[i - 1][wt - w[i - 1]], K[i - 1][wt]);
     else
    K[i][wt] = K[i - 1][wt];
   }
  }
  return K[n][W];
}
int main() 
{
  cout << "Enter the number of items in a Knapsack : ";
  int n, W;
  cin >> n;
  int v[n], w[n];
  for (int i = 0; i < n; i++) {
   cout << "\nEnter value and weight for item " << i << " : \n";
   cin >> v[i];
   cin >> w[i];
  }
  cout << "Enter the capacity of knapsack : ";
  cin >> W;
  cout << "Optimal value : " << knapSack(W, w, v, n);
  return 0;
}

/*
6. COMPLEXITY ANALYSIS:

•	Space Complexity : Θ(n*W)

•	Time Complexity : O(n*W)

 [n=number of items; W=capacity]

*/


