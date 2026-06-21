class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m=len(matrix)
        n=len(matrix[0])
        start,end=0,m*n-1
        while start<=end:
            mid=start+(end-start)//2
            midElement= matrix[mid//n][mid%n]
            if midElement==target:
                return True
            elif midElement>target:
                end=mid-1
            else:
                start=mid+1
        return False                
        