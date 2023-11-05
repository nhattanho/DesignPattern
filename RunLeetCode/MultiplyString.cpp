// RunLeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    ~Solution() {}
    Solution() {}
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int len1 = num1.size();
        int len2 = num2.size();

        vector<int> res(len1 + len2, 0);

        int carry = 0;
        for (int i2 = len2 - 1; i2 >= 0; i2--) {
            int digit2 = num2[i2] - '0';
            carry = 0;
            for (int i1 = len1 - 1; i1 >= 0; i1--) {
                int digit1 = num1[i1] - '0';
                int temp = digit1 * digit2 + carry;

                carry = temp / 10;
                temp = temp % 10;

                res[i1 + i2 + 1] += temp;

                carry += res[i1 + i2 + 1] / 10;
                res[i1 + i2 + 1] = res[i1 + i2 + 1] % 10;
            }
            if (carry != 0) res[i2] = carry;
        }
        if (carry != 0) res[0] = carry;
        string ans = "";
        int  i = 0;
        for (i = 0; i < res.size(); i++)
        {
            if (res[i] == 0) break;
        }
        i++;
        for (; i < res.size(); i++) {
            ans += to_string(res[i]);
        }
        return ans;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    Solution* solution = new Solution();
    cout << solution->multiply("123", "456");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
