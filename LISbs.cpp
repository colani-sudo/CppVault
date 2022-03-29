#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
class Solution{
public:
    int binSearch(vector<int> lis, int target)
    {
        int l = 0, h = lis.size() -1, ans = INT_MAX;    //high, low, ans = min()
        while(l <= h)
        {
            int mid = l + (h-l)/2;  //to prevent overflow

            if(lis[mid] >= target)  //if middle element in lis > target
            {
                ans = min(ans, mid);
                h = mid -1;         //move h to mid-1
            }
            else
            {
                l = mid + 1;        //if element not found go to the right side 
            }
            if(ans != INT_MAX) return ans;
            else return -1;         //all elements are smaller
        }
    }

    int lengthLIS(vector<int>& nums)
    {
        vector<int> lis;
        lis.push_back(nums[0]);     //push the 1st element of the nums array
        for(int i=1; i<nums.size(); i++)
        {
            //find smallest element >= to i-th element in nums array
            int a1 = binSearch(lis, nums[i]);
            if(a1 == -1)    //if not found
            {
                lis.push_back(nums[i]);     //push that i-th element into the lis, which means
            }                           //all the elements in the alias are smaller that num[i]
            else
            {
                lis[a1] = nums[i];  //replace the index returned by the i-th element
            }
        }
        return lis.size();      //length of my alias
    }

};
//Time complexity: O(n*log*n)
//Space complexity: O(n)

int main()
{

    return 0;
}