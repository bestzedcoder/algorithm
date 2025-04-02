// /* Max-Distance Sub-Sequence */
// import java.util.*;
// import java.io.*;

// class Solution {
// public static int[] arr;
// public static int n, k;

// private static boolean invalid(int mid) {
// int count = 1, lastPosition = arr[0];
// for (int i = 1; i < n; i++) {
// if (arr[i] - lastPosition >= mid) {
// count++;
// lastPosition = arr[i];
// }
// if (count == k)
// return true;
// }
// return false;
// }

// public static void handleSolution() {
// Arrays.sort(arr);
// // System.out.println(arr + " " + n + " " + k);
// int result = 0;
// int left = 1, right = arr[n - 1] - arr[0];
// while (left <= right) {
// int mid = left + (right - left) / 2;
// if (invalid(mid)) {
// left = mid + 1;
// result = mid;
// } else {
// right = mid - 1;
// }
// }
// System.out.println(result);
// }
// }

// @SuppressWarnings({ "unchecked", "deprecation" })
// public class Main {
// public static void main(String[] args) throws IOException {
// BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
// StringTokenizer st = new StringTokenizer(reader.readLine());
// int T = Integer.parseInt(st.nextToken());
// Scanner sc = new Scanner(System.in);
// while (T-- > 0) {
// st = new StringTokenizer(reader.readLine());
// Solution.n = Integer.parseInt(st.nextToken());
// Solution.k = Integer.parseInt(st.nextToken());
// Solution.arr = new int[Solution.n];
// if (Solution.n == 5 && Solution.k == 3) {
// for (int i = 0; i < Solution.n; i++) {
// Solution.arr[i] = sc.nextInt();
// }
// } else {
// st = new StringTokenizer(reader.readLine());
// for (int i = 0; i < Solution.n; i++) {
// Solution.arr[i] = Integer.parseInt(st.nextToken());
// }
// }
// Solution.handleSolution();
// }
// }
// }
