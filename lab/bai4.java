
// /* Problem: Count solutions to an integer linear equation */
// import java.util.*;
// import java.io.*;

// class Solution {
// private static LinkedList<Integer> solve = new LinkedList<>();
// public static int result = 0;
// private static int d = 0;

// private static boolean check(int value, List<Integer> numbers, int c) {
// if (value * numbers.get(solve.size()) > c)
// return false;
// return true;
// }

// public static void handleSolution(List<Integer> numbers, int c, int Cmin) {
// for (int i = 1; i <= c; i++) {
// if (check(i, numbers, c)) {
// solve.add(i);
// d += solve.getLast() * numbers.get(solve.size() - 1);
// if (solve.size() == numbers.size()) {

// if (d == c)
// result++;
// } else {
// if (Cmin * (numbers.size() - solve.size()) + d <= c)
// handleSolution(numbers, c, Cmin);
// }
// d -= solve.getLast() * numbers.get(solve.size() - 1);
// solve.removeLast();
// }
// }
// }
// }

// @SuppressWarnings({ "unchecked", "deprecation" })
// public class bai4 {
// public static void main(String[] args) throws IOException {
// BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
// StringTokenizer st = new StringTokenizer(reader.readLine());
// int n = Integer.parseInt(st.nextToken());
// int c = Integer.parseInt(st.nextToken());
// List<Integer> numbers = new ArrayList<>();
// st = new StringTokenizer(reader.readLine());
// int Cmin = Integer.MAX_VALUE;
// while (n-- > 0) {
// int x = Integer.parseInt(st.nextToken());
// Cmin = Math.min(Cmin, x);
// numbers.add(x);
// }
// Solution.handleSolution(numbers, c, Cmin);
// System.out.println(Solution.result);
// }
// }
