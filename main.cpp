#include <iostream>
#include "Solution.h"
using namespace std;
void test01(Solution& test);
void test10(Solution& test);
void test11(Solution& test);
void test12(Solution& test);
void test27(Solution& test);
void test28(Solution& test);
int main() {
    Solution test;
//    test01(test);
//    test10(test);
//    test11(test);
//    test12(test);
//    test27(test);
    test28(test);

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