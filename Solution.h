//
// Created by qiwei2-27267 on 24-7-31.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;
#ifndef SOLUTION_H
#define SOLUTION_H

class Solution {
public:
    void merge(vector<int>& nums1,int m,vector<int>& nums2,int n);
    int removeelement(vector<int>& nums,int val);
    int removeDuplicates(vector<int>& nums);
    int majorityElement(vector<int>& nums);
    void rotate(vector<int>& nums,int k);
    int maxProfit(vector<int>& prices);
    int maxprofit2(vector<int>& prices);
    bool canJump(vector<int>& nums);
    int jump(vector<int>& nums);
    int hIndex(vector<int>& citations);
    vector<int> productExceptSelf(vector<int>& nums);
    vector<int> twoSum(vector<int>& numbers, int target);
    int maxArea(vector<int>& height);
    vector<vector<int>> threesum(vector<int>& nums);
    int minSubArrayLen(int target, vector<int>& nums);
    int lengthOfLongestSubstring(string s);
    bool canConstruct(string ransomNote, string magazine);
    bool isIsomorphic(string s, string t);
    bool wordPattern(string pattern, string s);
    bool isValidSudoku(vector<vector<char>>& board);
    bool isValid(string s);
    string simplifyPath(string path);
};



#endif //SOLUTION_H
