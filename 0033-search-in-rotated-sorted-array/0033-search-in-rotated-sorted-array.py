class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n= len(nums)
        start,end=0,n-1
        while start<end:
            mid=start+(end-start)//2
            if nums[mid]>nums[n-1]:
                start=mid+1
            else:
                end=mid 
        pivot=start           
        if target>=nums[pivot] and target<=nums[n-1]:
            start,end=pivot,n-1     
        else:
            start,end=0,pivot-1
        while start<=end:
            mid=start+(end-start)//2
            if nums[mid]==target:
                return mid
            elif nums[mid]>target:
                end=mid-1
            else:
                start=mid+1            
        return -1        