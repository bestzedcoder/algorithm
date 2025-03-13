// /* Problem: Disjoint Segment */

// import java.util.*;
// import java.io.*;

// class Point implements Comparable<Point> {
// private int a, b;

// public Point(int a, int b) {
// this.a = a;
// this.b = b;
// }

// public int getA() {
// return a;
// }

// public int getB() {
// return b;
// }

// @Override
// public int compareTo(Point o) {
// return Integer.compare(this.b, o.b);
// }
// }

// class Solution {
// public static ArrayList<Point> list = new ArrayList<>();

// public static void handleSolution() {
// Collections.sort(list);
// int count = 0, lastEnd = -1;
// for (Point x : list) {
// // System.out.println(x.getA() + " " + x.getB());
// if (x.getA() > lastEnd) {
// count++;
// lastEnd = x.getB();
// }
// }
// System.out.println(count);
// }
// }

// @SuppressWarnings({ "unchecked", "deprecation" })
// public class Main {
// public static void main(String[] args) throws IOException {
// BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
// StringTokenizer st = new StringTokenizer(reader.readLine());
// int n = Integer.parseInt(st.nextToken());
// while (n-- > 0) {
// st = new StringTokenizer(reader.readLine());
// Point point = new Point(Integer.parseInt(st.nextToken()),
// Integer.parseInt(st.nextToken()));
// Solution.list.add(point);
// }
// // System.out.println(Solution.list);
// Solution.handleSolution();

// }
// }
