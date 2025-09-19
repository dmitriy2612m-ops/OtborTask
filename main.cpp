#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

/*Задача 1*/
bool validParentheses(string s) {
    string stack = "";
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push_back(c);
        } else {
            if (stack.empty()) return false;
            char last = stack.back();
            if ((c == ')' && last != '(') ||
                (c == ']' && last != '[') ||
                (c == '}' && last != '{')) {
                return false;
            }
            stack.pop_back();
        }
    }
    return stack.empty();
}
void task1() {
    cout << "Задача 1:\n";
    cout << "() -> " << (validParentheses("()") ? "true" : "false") << endl;
    cout << "(] -> " << (validParentheses("(]") ? "true" : "false") << endl;
    cout << "([]) -> " << (validParentheses("([])") ? "true" : "false") << endl;
    cout << endl;
}

/*Задача 2*/
void mergeArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
}
void task2() {
    cout << "Задача 2:\n";
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    mergeArrays(nums1, 3, nums2, 3);
    for (int x : nums1) cout << x << " ";
    cout << endl << endl;
}

/*Задача 3*/
int maxProfit(vector<int>& prices) {
    int minPrice = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < minPrice) minPrice = prices[i];
        else profit = max(profit, prices[i] - minPrice);
    }
    return profit;
}
void task3() {
    cout << "Задача 3:\n";
    vector<int> prices = {7,1,5,3,6,4};
    cout << "Максимальная прибыль = " << maxProfit(prices) << endl << endl;
}

/*Задача 4*/
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    int count[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        count[s[i]-'a']++;
        count[t[i]-'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }
    return true;
}
void task4() {
    cout << "Задача 4:\n";
    cout << "anagram / nagaram -> " << (isAnagram("anagram","nagaram") ? "true" : "false") << endl;
    cout << "rat / car -> " << (isAnagram("rat","car") ? "true" : "false") << endl;
    cout << endl;
}

/*Задача 5*/
class RecentCounter {
    queue<int> q;
public:
    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};
void task5() {
    cout << "Задача 5:\n";
    RecentCounter rc;
    cout << rc.ping(1) << endl;     // 1
    cout << rc.ping(100) << endl;   // 2
    cout << rc.ping(3001) << endl;  // 3
    cout << rc.ping(3002) << endl;  // 3
    cout << endl;
}


int main() {
    setlocale(LC_ALL, "");
    task1();
    task2();
    task3();
    task4();
    task5();
    return 0;
}
