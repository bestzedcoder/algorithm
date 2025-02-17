/*
Description
Given a TEXT which consists of a sequence of words. Each word is defined to be a sequence of contiguous characters of the alphabet (a, ..., z, A, ..., Z) and digits (0, 1, ..., 9). Other special characters are considered as delimiters between words. 
Write a program to count the number of occurrences o(w) of each word w of the given TEXT.
Input
The TEXT (each word of the TEXT has length <= 20)

Output
Each line contains a word w and o(w) (separated by a SPACE). The words (printed to lines of the stdout) are sorted in a lexicographic order. 

Example
Input
abc  def abc 
abc abcd def 

Output 
abc 3
abcd 1
def 2
*/

// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     unordered_map<string,int> wordCount;
//     string text,word;
//     getline(cin,text,'\0');
//     stringstream ss(text);
//     while(ss>>word) {
//         wordCount[word]++;
//     }

//     for(pair<string,int> x : wordCount) {
//         cout<<x.first<<" "<<x.second<<"\n";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> wordCount;

    string word;
    while (cin >> word) {
        string cleanWord = "";
        for (char c : word) {
            if (isalnum(c)) {
                cleanWord += c;
            }
        }
        if (!cleanWord.empty()) {
            wordCount[cleanWord]++;
        }
    }
    for (auto& entry : wordCount) {
        cout << entry.first << " " << entry.second << endl;
    }

    return 0;
}


