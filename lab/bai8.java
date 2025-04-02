// /* Problem: Inversion */

// import java.io.*;
// import java.util.StringTokenizer;

// class Solution {
// private final static int MODE = 1000000007;
// public static int[] arr;
// private static int countPair = 0;

// private static void merger(int left, int mid, int right) {
// int i = left, j = mid + 1, k = 0;
// int[] ans = new int[right - left + 1];
// while (i <= mid && j <= right) {
// if (arr[i] <= arr[j]) {
// ans[k] = arr[i];
// k++;
// i++;
// } else {
// ans[k] = arr[j];
// countPair += mid - i + 1;
// countPair = countPair % MODE;
// k++;
// j++;
// }
// }
// while (i <= mid) {
// ans[k++] = arr[i++];
// }
// while (j <= right) {
// ans[k++] = arr[j++];
// }
// for (int index = 0; index < right - left + 1; index++) {
// arr[left + index] = ans[index];
// }
// }

// private static void mergerSort(int left, int right) {
// if (left >= right)
// return;
// int mid = left + (right - left) / 2;
// mergerSort(left, mid);
// mergerSort(mid + 1, right);
// merger(left, mid, right);
// }

// public static void handleSolution() {
// mergerSort(0, arr.length - 1);
// System.out.println(countPair);
// }
// }

// @SuppressWarnings({ "unchecked", "deprecation" })
// public class Main {
// public static void main(String[] args) throws IOException {
// BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
// StringTokenizer st = new StringTokenizer(reader.readLine());
// int n = Integer.parseInt(st.nextToken());
// Solution.arr = new int[n];
// st = new StringTokenizer(reader.readLine());
// for (int i = 0; i < n; i++) {
// Solution.arr[i] = Integer.parseInt(st.nextToken());
// }
// // System.out.println(Solution.arr + " " + n);
// Solution.handleSolution();
// }
// }
