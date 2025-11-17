class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev=-1,pos; 
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                pos=i;
                if((pos-prev)<=k && prev!=-1) 
                    return false;
                prev=pos;
            }
        }
        return true;
    }
};