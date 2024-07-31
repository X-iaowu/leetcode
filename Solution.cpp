//
// Created by qiwei2-27267 on 24-7-31.
//

#include "Solution.h"

#include <algorithm>

void Solution::merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> nums3(m + n,0);
    int i,j,k;
    i = 0,j = 0;
    for(k = 0;k < m + n;k++) {
        if(i == m) {
            nums3[k] = nums2[j];
            j++;
            continue;
        }
        if(j == n) {
            nums3[k] = nums1[i];
            i++;
            continue;
        }

        if(nums1[i] >= nums2[j]) {
            nums3[k] = nums2[j];
            j++;
        }
        else {
            nums3[k] = nums1[i];
            i++;
        }
    }
    nums1.swap(nums3);

}

int Solution::removeelement(vector<int> &nums, int val) {
    int n = nums.size();
    auto iter = nums.begin();
    while(iter != nums.end()) {
        if(*iter == val) {
            nums.erase(iter);
            n--;
        }
        else {
            iter++;
        }
    }
    return n;
}

int Solution::removeDuplicates(vector<int> &nums) {
    int k = nums.size();
    auto iter1 = nums.begin();
    auto iter2 = iter1 + 1;
    while(iter2 != nums.end()) {
        if(*iter1 == *iter2) {
            nums.erase(iter2);
            k--;
        }
        else {
            iter1++;
            iter2++;
        }
    }
    return k;
}

int Solution::majorityElement(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    return nums[n/2 + n%2 - 1];
}

void Solution::rotate(vector<int> &nums, int k) {
    int move = k % nums.size();
    if(move == 0)   return;
    else {
        vector<int> temp(nums.size());
        for(int i = 0;i < nums.size();i++) {
            int position = (i + move) % nums.size();
            temp[position] = nums[i];
        }
        nums.swap(temp);
    }
}

int Solution::maxProfit(vector<int> &prices) {
    int maxprofit = 0;
    int i;
    int min = prices[0];
    for(i = 1;i < prices.size();i++) {
        if(prices[i] < min) min = prices[i];
        int profit = prices[i] - min;
        if(profit > maxprofit)  maxprofit = profit;
    }
    return maxprofit;
}

int Solution::maxprofit2(vector<int> &prices) {
    int profit = 0;

    for(int i = 1;i < prices.size();i++) {
        if(prices[i] - prices[i - 1] > 0) profit += prices[i] - prices[i - 1];
    }
    return profit;
}

bool Solution::canJump(vector<int> &nums) {
    int i = 0;
    int position = 0;
    for(i = 0;i < nums.size();i++) {
        if(position >= i) {
            int step = i + nums[i];
            if(step > position) position = step;
        }
        else {
            return false;
        }
        if(position >= nums.size() - 1) return true;
    }
}

int Solution::jump(vector<int> &nums) {
    if(nums.size() == 1) return 0;
    int i,j,position;
    i = 0,j = 0;
    position = i + nums[i];
    int step = 1;
    while(position < nums.size() - 1) {
        int temp = position;
        for(j = i + 1;j <= position;j++) {
            if(j + nums[j] < temp) continue;
            if(j + nums[j] > temp) temp = j + nums[j];
        }
        position = temp;
        step++;
    }
    return step;
}

int Solution::hIndex(vector<int> &citations) {
    int h = citations.size();
    sort(citations.begin(),citations.end());
    while(1) {
        if(citations[citations.size() - h] >= h) return h;
        else {
            h--;
        }
        if(h == 0) break;
    }
    return h;
}

