#include <iostream>
#include "Solution.h"
using namespace std;
void test01(Solution& test);
void test10(Solution& test);
void test11(Solution& test);
int main() {
    Solution test;
    // vector<int> nums = {7,1,5,3,6,4};
    // int x = test.maxProfit(nums);
    // cout << x <<endl;
    // for_each(nums.begin(),nums.end(),[](int element) {
    //     cout << element << endl;
    // });
    test01(test);
    test10(test);
    test11(test);
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
