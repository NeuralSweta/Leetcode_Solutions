class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] arr= new int[2];
        int start=0;
        int end =nums.length-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(target<nums[mid]){
                end =mid-1;
            }
            else if(target>nums[mid]){
                start= mid+1;
            }
            else{
                int x=mid, y=mid;
               while(x>=0 && nums[x]==nums[mid]){
                x--;
               }
               while(y<nums.length && nums[y]==nums[mid]){
                y++;
               }
            return new int[]{x+1,y-1};
        }
    }
        return new int[]{-1,-1};
    }
}