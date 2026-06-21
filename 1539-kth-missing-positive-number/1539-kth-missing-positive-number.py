class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        start,end=0,len(arr)-1
        while start<=end:
            mid=start+(end-start)//2
            correctNum=mid+1
            missing=arr[mid]-correctNum
            if missing>=k:
                end=mid-1
            else:
                start=mid+1
        return start+k               
