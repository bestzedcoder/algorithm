// /* Problem: Largest black subrectangle */
// package lab;

// import java.io.BufferedReader;
// import java.io.IOException;
// import java.io.InputStreamReader;
// import java.util.*;

// class Solution {
// private static int max_area = Integer.MIN_VALUE;

// private static void maxArea(List<Integer> heights) {
// Stack<Integer> st = new Stack<>();
// for (int i = 0; i < heights.size(); i++) {
// while (!st.empty() && heights.get(i) < heights.get(st.peek())) {
// int height = heights.get(st.pop());
// int width = st.empty() ? i : i - st.peek() - 1;
// max_area = Math.max(max_area, width * height);
// }
// st.push(i);
// }

// while (!st.empty()) {
// int height = heights.get(st.pop());
// int width = st.empty() ? heights.size() : heights.size() - st.peek() - 1;
// int area = height * width;

// max_area = Math.max(max_area, area);
// }
// }

// public static void handleSolution(List<List<Integer>> list) {
// int row = list.size(), column = list.get(0).size();
// List<Integer> currentHeight = new ArrayList<>(list.get(0));
// maxArea(currentHeight);
// for (int i = 1; i < row; i++) {
// for (int j = 0; j < column; j++) {
// if (list.get(i).get(j) == 0)
// currentHeight.set(j, 0);
// else
// currentHeight.set(j, list.get(i).get(j) + currentHeight.get(j));
// }
// maxArea(currentHeight);
// }
// System.out.print(max_area);
// }
// }

// @SuppressWarnings({ "unchecked", "deprecation" })
// public class bai3 {
// public static void main(String[] args) throws IOException {
// BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
// StringTokenizer st = new StringTokenizer(reader.readLine());
// List<List<Integer>> list = new ArrayList<>();
// int n = Integer.parseInt(st.nextToken()), m =
// Integer.parseInt(st.nextToken());
// for (int i = 0; i < n; i++) {
// List<Integer> ans = new ArrayList<>();
// st = new StringTokenizer(reader.readLine());
// for (int j = 0; j < m; j++)
// ans.add(Integer.parseInt(st.nextToken()));
// list.add(ans);
// }
// Solution.handleSolution(list);
// return;
// }
// }
