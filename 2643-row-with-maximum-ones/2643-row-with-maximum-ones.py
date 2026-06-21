class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        maxCount,maxRow=0,0
        for i in range(len(mat)):
            count=0
            for j in range(len(mat[0])):
                if mat[i][j]==1:
                    count +=1
            if count>maxCount:
                maxCount=count
                maxRow=i
        return [maxRow,maxCount]
