// /* Problem: Telco data check & query */
// package lab;

// import java.util.HashMap;
// import java.util.Map;
// import java.util.Scanner;

// class NumberPhone {
// private int total_calls;
// private int total_call_from;
// private int total_time_call = 0;

// public int getTotal_calls() {
// return total_calls;
// }

// public void setTotal_calls() {
// this.total_calls++;
// }

// public int getTotal_call_from() {
// return total_call_from;
// }

// public void setTotal_call_from() {
// this.total_call_from++;
// }

// public int getTotal_time_call() {
// return total_time_call;
// }

// public void setTotal_time_call(int time) {
// this.total_time_call += time;
// this.setTotal_call_from();
// }

// }

// public class bai2 {
// private static int handleTime(String date) {
// String[] subStrings = date.split(":");
// return Integer.parseInt(subStrings[0]) * 3600 +
// Integer.parseInt(subStrings[1]) * 60
// + Integer.parseInt(subStrings[2]);
// }

// public static void main(String[] args) {
// Scanner sc = new Scanner(System.in);
// int total_calls = 0;
// boolean check_phone = true;
// Map<String, NumberPhone> mp = new HashMap<>();
// while (true) {
// String str = sc.nextLine();
// if (str.equals("#"))
// break;
// total_calls++;
// String[] input = str.split(" ");
// for (int i = 1; i <= 2; i++) {
// if (check_phone && (!input[i].matches("\\d{10}")))
// check_phone = false;
// int start_time = handleTime(input[4]);
// int end_time = handleTime(input[5]);
// int time_call = Math.max(0, end_time - start_time);
// if (mp.containsKey(input[i])) {
// if (i == 1)
// mp.get(input[i]).setTotal_time_call(time_call);
// } else {
// NumberPhone ans = new NumberPhone();
// if (i == 1)
// ans.setTotal_time_call(time_call);
// mp.put(input[i], ans);
// }
// }
// }

// while (true) {
// String str = sc.next();
// if (str.equals("#"))
// break;
// if (str.equals("?check_phone_number")) {
// System.out.println(check_phone ? 1 : 0);
// } else if (str.equals("?number_calls_from")) {
// String number = sc.next();
// if (mp.containsKey(number))
// System.out.println(mp.get(number).getTotal_call_from());
// else
// System.out.println(0);
// } else if (str.equals("?number_total_calls")) {
// System.out.println(total_calls);
// } else {
// String number = sc.next();
// if (mp.containsKey(number))
// System.out.println(mp.get(number).getTotal_time_call());
// else
// System.out.println(0);
// }
// }

// return;
// }
// }
