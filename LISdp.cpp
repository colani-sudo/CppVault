#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution{
public:
    int lengthOfLIS(vector<int>& nums){
        vector<int> dp(nums.size());    //dynamic array initializes with the elements vector size
        dp[0] = 1;                      //the length of the alias of element 1

        for(int i=1; i < nums.size(); i++)
        {
            dp[i] = 1;                      //the minimum length of alias is 1 for each element
            
            for(int j = i-1; j>=0; j--)     //iterate over the elements before the i-th elements
            {    
                if(nums[j] < nums[i])       //append our i-th element to an alias whose last element is less than our i-th element
                {      
                    dp[i] = max(dp[i], dp[j] + 1);  //length of the longest increasing subsequence including the i-th element
                }                                   //and will be stored in the a-th position of the dp
            }
        }
        return *max_element(dp.begin(), dp.end());  //return the maximum element of the dp, that is equal to the length of the alias
    }

};
//Time complexity: O(n^2)
//Space complexity: O(n)

int main(){



    return 0;
}