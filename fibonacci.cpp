#include<bits/stdc++.h>
using namespace std;


int nthFibonscci(int n, vector<int> &dp) {

	if (n <= 1)
		return dp[n] = n;

	if (dp[n] != -1)
		return dp[n];

	return dp[n] = nthFibonscci(n - 1, dp) + nthFibonscci(n - 2, dp);
}


int main() {

	int n;
	cin >> n;
	vector<int> dp(n + 1, -1);
	cout << "nth fibonacci :: " << nthFibonscci(n, dp);

	return 0;
}