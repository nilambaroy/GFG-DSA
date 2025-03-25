//{ Driver Code Starts
import java.io.*;
import java.util.*;

class IntArray {
    public static int[] input(BufferedReader br) throws IOException {
        String[] s = br.readLine().trim().split(" ");
        int n = s.length;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = Integer.parseInt(s[i]);

        return a;
    }

    public static void print(int[] a) {
        for (int e : a) System.out.print(e + " ");
        System.out.println();
    }

    public static void print(ArrayList<Integer> a) {
        for (int e : a) System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            int[] arr = IntArray.input(br);

            Solution obj = new Solution();
            int res = obj.maxValue(arr);

            System.out.println(res);
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Solution {
    //nilambar
    int maxValue(int[] arr) {
        // code here
        int n = arr.length;
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        int case1 = maxLoot(arr, 0, n - 2, dp);
        Arrays.fill(dp, -1);
        int case2 = maxLoot(arr, 1, n - 1, dp);
        
        return Math.max(case1, case2);
    }
    
    int maxLoot(int[] arr, int i, int n, int[] dp){
        if(i > n){
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        int take = arr[i] + maxLoot(arr, i + 2, n, dp);
        int notTake = maxLoot(arr, i + 1, n, dp);
        return dp[i] = Math.max(take, notTake);
    }
}
