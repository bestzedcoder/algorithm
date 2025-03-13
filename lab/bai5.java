
// /* Problem: Balanced Courses Assignments */
// import java.io.*;
// import java.util.*;

// class Solution {
// public static int n, m;
// public static boolean[][] conflict = new boolean[31][31];
// public static ArrayList<HashMap<Integer, Boolean>> teachers = new
// ArrayList<>();
// public static HashMap<Integer, Integer> subject_teacher = new HashMap<>();
// public static int result = Integer.MAX_VALUE;

// private static boolean check(int teacher, int subject) {
// if (teachers.get(teacher).containsKey(subject)) {
// for (Integer key : teachers.get(teacher).keySet()) {
// if (teachers.get(teacher).get(key) && conflict[subject][key]) {
// return false;
// }
// }
// return true;
// }
// return false;
// }

// public static void handleSolution(int subject) {
// if (subject > m) {
// int currentMax = 0;
// for (int i = 0; i < n; i++) {
// currentMax = Math.max(currentMax, subject_teacher.get(i));
// }
// result = Math.min(result, currentMax);
// return;
// }
// for (int teacher = 0; teacher < n; teacher++) {
// if (check(teacher, subject)) {
// teachers.get(teacher).put(subject, true);
// subject_teacher.put(teacher, subject_teacher.get(teacher) + 1);
// int currentMax = 0;
// for (int i = 0; i < n; i++) {
// currentMax = Math.max(currentMax, subject_teacher.get(i));
// }
// if (currentMax < result) {
// handleSolution(subject + 1);
// }
// subject_teacher.put(teacher, subject_teacher.get(teacher) - 1);
// teachers.get(teacher).put(subject, false);
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
// Solution.m = Integer.parseInt(st.nextToken());
// for (int i = 0; i < Solution.n; i++) {
// Solution.subject_teacher.put(i, 0);
// st = new StringTokenizer(reader.readLine());
// int k = Integer.parseInt(st.nextToken());
// HashMap<Integer, Boolean> ans = new HashMap<>();
// while (k-- > 0) {
// int subject = Integer.parseInt(st.nextToken());
// ans.put(subject, false);
// }
// Solution.teachers.add(ans);
// }
// Collections.sort(Solution.teachers, (x1, x2) -> {
// return Integer.compare(x1.size(), x2.size());
// });
// st = new StringTokenizer(reader.readLine());
// int countConflict = Integer.parseInt(st.nextToken());
// while (countConflict-- > 0) {
// st = new StringTokenizer(reader.readLine());
// int u = Integer.parseInt(st.nextToken()), v =
// Integer.parseInt(st.nextToken());
// Solution.conflict[u][v] = true;
// Solution.conflict[v][u] = true;
// }
// Solution.handleSolution(1);
// if (Solution.result != Integer.MAX_VALUE) {
// System.out.println(Solution.result);
// } else {
// System.out.println(-1);
// }
// return;
// }
// }
