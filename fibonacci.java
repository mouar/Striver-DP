import java.util.*;



class Fibonacci {

	int nthFibonacci(int n, int[] dp) {

		if (n <= 1)
			return dp[n] = n;

		if (dp[n] != -1)
			return dp[n];

		return dp[n] = nthFibonacci(n - 1, dp) + nthFibonacci(n - 2, dp);
	}


	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);

		int n = cin.nextInt();
		int[] dp = new int[n + 1];

		Arrays.fill(dp, -1);

		Fibonacci obj = new Fibonacci();
		System.out.println("nth fibonacci :: " + obj.nthFibonacci(n, dp));
	}
}