#include <iostream>
#include "Solution.h"
using namespace std;
void test01(Solution& test);
void test10(Solution& test);
void test11(Solution& test);
void test12(Solution& test);
void test27(Solution& test);
void test28(Solution& test);
void test29(Solution& test);
void test30(Solution& test);
void test31(Solution& test);
void test32(Solution& test);
void test33(Solution& test);
void test34(Solution& test);
int main() {
    Solution test;
//    test01(test);
//    test10(test);
//    test11(test);
//    test12(test);
//    test27(test);
//    test28(test);
//    test29(test);
//    test30(test);
//    test31(test);
//    test32(test);
//    test33(test);
    test34(test);
    //system("pause");
    return 0;
}

void test01(Solution& test) {
    vector<int> nums = {3,2,1,0,4};
    cout << test.canJump(nums) << endl;
}

void test10(Solution& test) {
    vector<int> nums={2,3,1,1,4};
    cout<<test.jump(nums)<<endl;
}

void test11(Solution& test) {
    vector<int> nums={3,0,6,1,5};
    cout << test.hIndex(nums) << endl;
}

void test12(Solution& test) {
    vector<int> nums={1,2,3,4};
    vector<int> answer = test.productExceptSelf(nums);
    for_each(answer.begin(),answer.end(),[](int element) {
        cout << element << endl;
    });
}

void test27(Solution& test){
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> twosum = test.twoSum(numbers, target);
    for_each(twosum.begin(), twosum.end(), [](int element){
        cout << element << endl;
    });
}

void test28(Solution& test)
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int V = test.maxArea(height);
    cout << V << endl;
}

void test29(Solution& test)
{
    vector<int> nums = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    vector<vector<int>> result = test.threesum(nums);
    for_each(result.begin(),result.end(),[](vector<int> element){
        cout << '[' << element[0] << ',' << element[1] << ',' << element[2] << ']' << endl;
    });
}

void test30(Solution& test)
{
    vector<int> nums = {12,28,83,4,25,26,25,2,25,25,25,12};
    cout << test.minSubArrayLen(213, nums) << endl;
}

void test31(Solution& test)
{
    string s = "pwwkew";
    cout << test.lengthOfLongestSubstring(s) << endl;
}

void test32(Solution& test)
{
    string s = "paper",t = "title";
    cout << test.isIsomorphic(s, t) << endl;
}

void test33(Solution& test)
{
    string pattern = "abba", s = "dog dog dog dog";
    cout << test.wordPattern(pattern, s) << endl;
}

void test34(Solution& test)
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << test.isValidSudoku(board) << endl;

}