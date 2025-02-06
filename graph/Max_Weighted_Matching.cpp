/*
Bài toán: Max weighted matching

Đề bài:
Cho một đồ thị hai phía G = (X, Y, E), trong đó:
X có n đỉnh và Y có m đỉnh.
Mỗi cạnh (i, j) (với i ∈ X và j ∈ Y) có trọng số w = c(i, j).
Một matching là một tập hợp các cạnh sao cho mỗi đỉnh chỉ thuộc tối đa một cạnh.
Hãy tìm matching có tổng trọng số lớn nhất trong đồ thị này.

Dữ liệu vào:
Dòng 1: Hai số nguyên n và m — số đỉnh trong tập X và tập Y.
Dòng 2: Một số nguyên dương K — số cạnh trong đồ thị G.
Dòng thứ k+2 (với k = 1, 2, ..., K): Ba số nguyên u, v, w:
u là đỉnh thuộc tập X.
v là đỉnh thuộc tập Y.
w = c(u, v) là trọng số của cạnh (u, v).

Dữ liệu ra:
Xuất ra tổng trọng số lớn nhất của một matching tìm được.
Ví dụ
Dữ liệu vào
4 4  
8  
1 2 1  
1 4 7  
2 1 1  
2 3 2  
3 2 6  
3 3 9  
4 3 8  
4 4 9  
Dữ liệu ra
22
*/