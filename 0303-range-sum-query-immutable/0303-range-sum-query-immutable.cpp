class NumArray {

    vector<int> pre;
public:
       
    NumArray(vector<int>& nums) {
       partial_sum(nums.begin(),nums.end(),back_inserter(pre));
    }
    
    int sumRange(int left, int right) {
       if(left==0)
       { return pre[right];
       }
       return pre[right]-pre[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */