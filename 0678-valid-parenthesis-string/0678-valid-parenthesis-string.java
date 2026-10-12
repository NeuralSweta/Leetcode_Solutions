class Solution {
    public boolean checkValidString(String s) {
        int n = s.length();
        int leftcount=0;
        int rightcount=0;
        for( int i=0; i<n; i++){
           char ch = s.charAt(i);
           if(ch=='('||ch=='*') 
             leftcount++;
             else 
                leftcount--;
            if(leftcount <0) return false;
            char ch1=s.charAt(n-i-1);
            if(ch1==')' || ch1=='*')
            rightcount++;
            else rightcount--;
            if(rightcount<0) return false; 
        }
        return true;
    }
}

// greedy technique Time Complexity is O(N) and space Complexity is O(1)
