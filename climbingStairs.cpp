#include<bits/stdc++.h>
using namespace std;


int noOfWaysToClimbByResursion(int n) {

	if (n <= 2)
		return n;

	return noOfWaysToClimbByResursion(n - 1) + noOfWaysToClimbByResursion(n - 2);
}

int noOfWaysToClimbByMemo(int n, vector<int> &dp) {

	if (n <= 2)
		return dp[n] = n;

	if (dp[n] != -1)
		return dp[n];

	return dp[n] = noOfWaysToClimbByMemo(n - 1, dp) + noOfWaysToClimbByMemo(n - 2, dp);
}

int noOfWaysToClimbByTabulation(int n) {

	vector<int> dp(n + 1);

	// initialisation
	dp[0] = 0; dp[1] = 1; dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int noOfWaysToClimbSpaceOptimise(int n) {

	int prev2 = 1;
	int prev = 2;

	for (int i = 3; i <= n; i++) {

		int temp = prev2 + prev;
		prev2 = prev;
		prev = temp;
	}

	return prev;
}


int main() {

	int n;
	cin >> n;
	vector<int> dp(n + 1, -1);


	cout << "no of ways to climb :: " << noOfWaysToClimbByResursion(n) << "\n";
	cout << "no of ways to climb :: " << noOfWaysToClimbByMemo(n, dp) << "\n";
	cout << "no of ways to climb :: " << noOfWaysToClimbByTabulation(n) << "\n";
	cout << "no of ways to climb :: " << noOfWaysToClimbSpaceOptimise(n) << "\n";

}