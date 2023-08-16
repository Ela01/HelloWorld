#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Leet Code 12. Integer to Roman

Given an integer, convert it to a roman numeral.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

|I| |II|III|
|IV|
|V| |VI|VII|VIII|
|IX|
|X|


I can be placed before V (5) to make 4
I can be placed before X (10) to make 9

X can be placed before L (50) to make 40
X can be placed before C (100) to make 90

C can be placed before D (500)  to make 400
C can be placed before M (1000) to make 900



Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


*/

string intToRoman(int num)
{

    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string thousands[] = {"", "M", "MM", "MMM"};

    return thousands[num / 1000] + hundreds[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
}

int main()
{
    string ans = intToRoman(8);

    cout << ans;

    return 0;
}