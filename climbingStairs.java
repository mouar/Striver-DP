import java.util.*;


class ClimbingStairs {


	static int noOfWaysToClimbByResursion(int n) {
		if (n <= 2) {
			return n;
		}
		return noOfWaysToClimbByResursion(n - 1) + noOfWaysToClimbByResursion(n - 2);
	}

	static int noOfWaysToClimbByMemo(int n, int[] dp) {
		if (n <= 2) {
			return dp[n] = n;
		}

		if (dp[n] != -1) {
			return dp[n];
		}

		return dp[n] = noOfWaysToClimbByMemo(n - 1, dp) + noOfWaysToClimbByMemo(n - 2, dp);
	}

	static int noOfWaysToClimbByTabulation(int n) {

		int[] dp = new int[n + 1];

		//initialisation
		dp[1] = 1; dp[2] = 2;

		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		return dp[n];
	}

	static int noOfWaysToClimbSpaceOptimise(int n) {

		int prev2 = 1;
		int prev = 2;

		for (int i = 3; i <= n; i++) {
			int temp = prev + prev2;
			prev2 = prev;
			prev = temp;
		}

		return prev;
	}

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n;
		n = in.nextInt();

		int [] dp = new int[n + 1];
		Arrays.fill(dp, -1);
		System.out.println("no of ways to climb :: " + noOfWaysToClimbByResursion(n));
		System.out.println("no of ways to climb :: " + noOfWaysToClimbByMemo(n, dp));
		System.out.println("no of ways to climb :: " + noOfWaysToClimbByTabulation(n));
		System.out.println("no of ways to climb :: " + noOfWaysToClimbSpaceOptimise(n));
	}
}