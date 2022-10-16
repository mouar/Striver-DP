#include<bits/stdc++.h>
using namespace std;


int nthFibonacci(int n, vector<int> &dp) {

	if (n <= 1)
		return dp[n] = n;

	if (dp[n] != -1)
		return dp[n];

	return dp[n] = nthFibonacci(n - 1, dp) + nthFibonacci(n - 2, dp);
}

int nthFibonacciTabulation(int n) {

	vector<int> dp(n + 1);
	//initialisation
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

/* in tc - O(n), sc - O(1)
*/
int nthFibonacciSpaceOptimise(int n) {

	int prev2 = 0;
	int prev = 1;

	for (int i = 2; i <= n; i++) {
		int curr = prev + prev2;

		prev2 = prev;
		prev = curr;
	}

	return prev;
}

int main() {

	int n;
	cin >> n;
	vector<int> dp(n + 1, -1);
	cout << "nth fibonacci :: " << nthFibonacci(n, dp);
	cout << "nth fibonacci :: " << nthFibonacciTabulation(n);

	return 0;
}

/*
	TC - O(n)
	f(5) - O(n)
	/  \
  f(4)	f(3) - O(1)
  /  \
f(3)  f(2) - O(1)
 .
 .
 .

 Space Complexity - O(n) - for recursion stack , O(n) - extra space (dp)
*/


