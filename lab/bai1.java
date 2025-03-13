// package lab;

// import java.util.*;
// import java.io.*;

// class Point {
// private int x;
// private int y;
// private int dist = 0;

// public Point(int x, int y) {
// this.x = x;
// this.y = y;
// }

// public Point() {
// }

// public int getX() {
// return x;
// }

// public int getY() {
// return y;
// }

// public int getDist() {
// return this.dist;
// }

// public void setDist(int dist) {
// this.dist = 1 + dist;
// }

// public boolean handleSolution(int row, int column) {
// return this.x == 0 || this.y == 0 || this.x == row - 1 || this.y == column -
// 1;
// }
// }

// class Solution {

// public static void bfs(List<List<Integer>> maze, int u, int v) {
// int dx[] = { -1, 1, 0, 0 };
// int dy[] = { 0, 0, -1, 1 };
// int row = maze.size(), column = maze.get(0).size();
// boolean visited[][] = new boolean[row][column];
// Queue<Point> q = new LinkedList<>();
// q.offer(new Point(u, v));
// visited[u][v] = true;
// while (!q.isEmpty()) {
// Point currentPoint = q.poll();
// if (currentPoint.handleSolution(row, column)) {
// System.out.print(currentPoint.getDist() + 1);
// return;
// }
// for (int i = 0; i < 4; i++) {
// int x = currentPoint.getX() + dx[i];
// int y = currentPoint.getY() + dy[i];
// if (x >= 0 && y >= 0 && x < row && y < column && !visited[x][y] &&
// maze.get(x).get(y) == 0) {
// visited[x][y] = true;
// Point ans = new Point(x, y);
// ans.setDist(currentPoint.getDist());
// q.offer(ans);
// }
// }

// }
// System.out.print(-1);
// return;
// }
// }

// public class bai1 {
// public static void main(String[] args) throws IOException {
// BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
// int row, column, u, v;
// row = Integer.parseInt(reader.readLine());
// column = Integer.parseInt(reader.readLine());
// u = Integer.parseInt(reader.readLine());
// v = Integer.parseInt(reader.readLine());

// List<List<Integer>> maze = new ArrayList<>();
// for (int i = 0; i < row; i++) {
// List<Integer> list = new ArrayList<>();
// String[] input = reader.readLine().split(" ");
// for (int j = 0; j < column; j++) {
// list.add(Integer.parseInt(input[i]));
// }
// maze.add(list);
// }

// if (u < 1 || v < 1 || u > row || v > column || maze.get(u - 1).get(v - 1) ==
// 0) {
// System.out.print(-1);
// return;
// }
// Solution.bfs(maze, u - 1, v - 1);
// return;
// }
// }