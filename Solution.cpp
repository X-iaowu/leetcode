//
// Created by qiwei2-27267 on 24-7-31.
//

#include "Solution.h"

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

int Solution::lengthOfLongestSubstring(string s){
    int n = s.size();
    vector<char> temp(0);
    int k = 0,flag = 0;
    int m = 0;
    while(k < n)
    {
        flag = 1;
        for(int i = temp.size() - 1;i >= 0;i--)
        {
            if(s[k] == temp[i])
            {
                flag = 0;
                if(temp.size() >= m) m = temp.size();
                if(i == 0) temp.erase(temp.begin());
                else temp.erase(temp.begin(), temp.begin() + i + 1);
                temp.push_back(s[k]);
                break;
            }
        }
        if(flag) temp.push_back(s[k]);
        int len = temp.size();
        m = max(m, len);
        k++;
    }
    return m;
}

bool Solution::canConstruct(std::string ransomNote, std::string magazine) {
    unordered_map<char, int> hash;
    for(char m:magazine)
    {
        if(hash.find(m) != hash.end())//已经存储过
        {
            hash.find(m) -> second++;
        }
        else
        {
            hash.insert(make_pair(m, 1));//加入到哈希表中
        }
    }
    for(char r: ransomNote)
    {
        if(hash.find(r) != hash.end() && hash.find(r) -> second > 0)
        {
            hash.find(r) -> second--;
        }
        else
            return false;
    }
    return true;
}

bool Solution::isIsomorphic(std::string s, std::string t) {
    unordered_map<char, char> hash1,hash2;
    for(int i = 0; i < s.size();i++)
    {
        char a = s[i],b = t[i];
        if(hash1.find(a) != hash1.end() && hash1[a] != b || hash2.find(b) != hash2.end() && hash2[b] != a)
        {
            return false;
        }
        hash1[a] = b;
        hash2[b] = a;
    }
    return true;
}

bool Solution::wordPattern(string pattern, string s){
    unordered_map<char, string> hash1;
    unordered_map<string, char> hash2;
    vector<string> word;
    istringstream ss(s);
    string temp;
    while(ss >> temp)
    {
        word.push_back(temp);
    }
    int i = 0;
    for(char a : pattern)
    {
        if(hash1.find(a) != hash1.end() && hash1[a].compare(word[i]) ||
            hash2.find(word[i]) != hash2.end() && hash2[word[i]] != a)
        {
            return false;
        }
        hash1[a] = word[i];
        hash2[word[i]] = a;
        i++;
    }
    return true;
}

bool Solution::isValidSudoku(vector<vector<char>> &board) {
    int raw[10][10] = {0};
    int col[10][10] = {0};
    int box[10][10] = {0};
    for(int i = 0;i < 9;i++)
    {
        for(int j = 0;j < 9;j++)
        {
            char c = board[i][j];
            if(c == '.') continue;
            int num = c - '0';
            if(raw[i + 1][num] || col[j + 1][num] || box[j / 3 + (i / 3) * 3][num]) return false;
            raw[i + 1][num] = 1;
            col[j + 1][num] = 1;
            box[j / 3 + (i / 3) * 3][num] = 1;

        }
    }
    return true;
}

bool Solution::isValid(string s) {
    stack<char> std;
    int len = s.size();
    int i = 0;
    while(len--)
    {
        char c = s[i];
        if(c == '(' || c == '[' || c == '{')    std.push(c);
        else if(c == ')')
        {
            if(std.size() > 0 && std.top() == '(')    std.pop();
            else    return false;
        }
        else if(c == ']')
        {
            if(std.size() > 0 && std.top() == '[')    std.pop();
            else    return false;
        }
        else
        {
            if(std.size() > 0 && std.top() == '{')    std.pop();
            else    return false;
        }
        i++;
    }
    if(std.size() == 0) return true;
    else    return false;
}

string Solution::simplifyPath(std::string path) {
    // 划分字符串，使用Lambda表达式
    // []中可以放上下文中定义的参数,(const string& s, char delim)就是参数,vector<string>是返回值,后面就是函数体
    auto split = [](const string& s, char delim) -> vector<string> {
        vector<string> ans;
        string cur;
        for(char ch : s)
        {
            if(ch == delim)
            {
                ans.push_back(move(cur));
                cur.clear();
            }
            else
            {
                cur += ch;
            }
        }
        // move(obj)函数的功能是把obj当作右值处理，可以应用在对象的移动上
        ans.push_back(move(cur));
        return ans;
    };
    // 把原路径path根据 / 进行划分
    vector<string> names = split(path, '/');
    // 用一个栈来维护路径中的每一个目录名
    stack<string> st;
    for(string name : names)
    {
        // 如果是 ".." ,就出栈,相当于返回上一级目录
        if(name == "..")
        {
            if(!st.empty())
                st.pop();
        }
        else if(!name.empty() && name != ".")
        {
            st.push(move(name));
        }
    }
    string ans;
    if(st.empty())
        ans = "/";
    else
    {
        while(!st.empty())
        {
            ans.insert(0, '/' + st.top());
            st.pop();
        }
    }
    return ans;
}

// 二叉树的最大深度-深度优先搜索
int Solution::maxDepth(TreeNode *root) {
    if(root == nullptr) return 0;
    return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
}

// 判断二叉树是否相同
bool Solution::isSameTree(TreeNode *p, TreeNode *q) {
    if(p == nullptr && q == nullptr)    return true;
    else if(p == nullptr || q == nullptr)   return false;
    else if(p -> val != q -> val)   return false;
    else return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
}

// 翻转二叉树
TreeNode* Solution::invertTree(TreeNode *root) {
    if(root == nullptr) return nullptr;
    TreeNode* left = invertTree(root -> left);
    TreeNode* right = invertTree(root -> right);
    root -> left = right;
    root -> right = left;
    return root;
}

// 对称二叉树
bool Solution::isSymmetric(TreeNode *root) {
    if(root == nullptr) return true;
    else if(root -> left == nullptr && root -> right == nullptr)    return true;
    else if(root -> left == nullptr || root -> right == nullptr || root -> left -> val != root -> right -> val)    return false;
    else return isSymmetric(root -> left) && isSymmetric(root -> right);
}

