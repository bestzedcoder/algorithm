
// /* CBUS */
// import java.util.*;
// import java.io.*;

// class Solution {
// public static boolean[] visited;
// public static int[][] c;
// public static int n, k, Cmin = Integer.MAX_VALUE, result = Integer.MAX_VALUE;

// private static int[] X = new int[23];
// private static int d = 0, is_can = 0;

// private static boolean check(int i, int x) {
// if (i <= n) {
// if (is_can + 1 > k)
// return false;
// return !visited[i];
// } else
// return visited[i - n] && !visited[i];
// }

// public static void CBUS(int x) {
// for (int i = 1; i <= n * 2; i++) {
// if (check(i, x)) {
// X[x] = i;
// d += c[X[x - 1]][X[x]];
// visited[i] = true;
// if (i <= n)
// is_can++;
// else
// is_can--;
// if (x == 2 * n) {
// // for (int j = 0; j <= n * 2; j++) {
// // System.out.print(X[j] + " ");
// // }

// // System.out.println("\n" + result);
// result = Math.min(result, d + c[X[x]][0]);
// } else {
// if (Cmin * (2 * n - x + 1) + d < result) {
// CBUS(x + 1);
// }
// }
// d -= c[X[x - 1]][X[x]];
// visited[i] = false;
// if (i <= n)
// is_can--;
// else
// is_can++;
// }
// }
// }
// }

// @SuppressWarnings({ "unchecked", "deprecation" })
// public class Main {
// public static void main(String[] args) throws IOException {
// BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
// StringTokenizer st = new StringTokenizer(reader.readLine());
// Solution.n = Integer.parseInt(st.nextToken());
// Solution.k = Integer.parseInt(st.nextToken());
// Solution.visited = new boolean[Solution.n * 2 + 1];
// Solution.c = new int[Solution.n * 2 + 1][Solution.n * 2 + 1];
// for (int i = 0; i <= Solution.n * 2; i++) {
// st = new StringTokenizer(reader.readLine());
// for (int j = 0; j <= Solution.n * 2; j++) {
// Solution.c[i][j] = Integer.parseInt(st.nextToken());
// if (i != j)
// Solution.Cmin = Math.min(Solution.Cmin, Solution.c[i][j]);
// }
// }
// Solution.CBUS(1);
// System.out.print(Solution.result);
// }
// }
