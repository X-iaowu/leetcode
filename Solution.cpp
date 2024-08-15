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

vector<int> Solution::productExceptSelf(vector<int> &nums) {
    vector<int> temp1(nums.size(),1);
    vector<int> temp2(nums.size(),1);
    for(int i = 0;i < nums.size();i++) {
        temp1[i] *= nums[i];
        temp2[nums.size() - i - 1] *= nums[nums.size() - 1 - i];
    }

    vector<int> answer(nums.size(),1);
    for(int i = 1;i < nums.size();i++) {
        answer[i] = temp1[i - 1] * temp2[nums.size() - i - 2];
    }
    return answer;
}

vector<int> Solution::twoSum(vector<int>& numbers, int target){
    int len = numbers.size();
    int i,j;
    j = len - 1;
    int sum;
    vector<int> twosum(2,0);
    for(i = 0;i < len - 1;)
    {
        sum = numbers[i] + numbers[j];
        if(sum == target)
        {
            twosum[0] = i + 1;
            twosum[1] = j + 1;
            break;
        }
        else if(sum < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return twosum;
}

int Solution::maxArea(vector<int> &height) {
    int len = height.size();
    int i,j;
    i = 0,j = len - 1;
    int V = 0;
    while(i != j)
    {
        int curr_V = min(height[i], height[j]) * (j - i);
        if(curr_V > V) V = curr_V;
        height[i] > height[j] ? j-- : i++;
    }
    return V;
}

vector<vector<int>> Solution::threesum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int left,right;
    int threesum;
    left = 0, right = nums.size() - 1;
    for(int i = 0;i < nums.size() - 1;i++)
    {
        if(i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int twosum = 0 - nums[i];
        for(left = i + 1,right = nums.size() - 1;left < right;)
        {
            if(left > i + 1 && nums[left] == nums[left] - 1)
            {
                left++;
                continue;
            }
            if(right < nums.size() - 1 && nums[right] == nums[right + 1])
            {
                right--;
                continue;
            }
            if(nums[left] + nums[right] > twosum)
            {
                right--;
                continue;
            }
            else if(nums[left] + nums[right] < twosum)
            {
                left++;
                continue;
            }
            else
            {
                vector<int> three(3);
                three[0] = nums[i],three[1] = nums[left],three[2] = nums[right];
                result.insert(result.begin(), three);
                left++;
                right--;
            }
        }
    }
    return result;
}

int Solution::minSubArrayLen(int target, vector<int> &nums) {
    int n = nums.size();
    if(n == 0)
    {
        return 0;
    }
    int ans = INT_MAX;
    vector<int> sums(n + 1,0);
    for(int i = 0;i <= n;i++)
    {
        sums[i] = sums[i - 1] + nums[i - 1];
    }
    for(int i = 1;i <= n;i++)
    {
        int temp = target + sums[i - 1];
        auto bound = lower_bound(sums.begin(),sums.end(),temp);
        if(bound != sums.end())
        {
            ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
        }
    }
    return ans == INT_MAX ? 0 : ans;
}
