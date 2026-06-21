class Solution:
    def arrangeCoins(self, n: int) -> int:
        start,end=0,n
        while start<=end:
            mid=start+(end-start)//2
            coinUsed=mid*(mid+1)//2
            if coinUsed==n:
                return mid
            elif coinUsed<n:
                start=mid+1    
            else:
                end=mid-1
        return end            
