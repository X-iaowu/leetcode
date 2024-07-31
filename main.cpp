#include <iostream>
#include "Solution.h"
using namespace std;
int main() {
    Solution test;
    vector<int> nums = {7,1,5,3,6,4};
    int x = test.maxProfit(nums);
    cout << x <<endl;
    // for_each(nums.begin(),nums.end(),[](int element) {
    //     cout << element << endl;
    // });

    system("pause");
    return 0;
}
