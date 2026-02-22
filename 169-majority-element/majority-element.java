class Solution {
    public int majorityElement(int[] nums) {
        int val = -1;
        int freq = 0;
        for(int i = 0;i<nums.length;i++){
            if(nums[i] == val) freq++;
            else{
                if(freq == 0){
                    val = nums[i];
                    freq = 1;
                }
                else{
                    freq--;
                }
            }
        }
        return val;
    }
}