//Approach 1: binary search plus linear traversal
/*
traverse across the row only in which the target can be found since the rows are sorted
the search for the target in that row using binary search
*/
//Time Complexity: O(log(m*n)) =O(log(m) + log(n)); Space complexity: O(1)

class Solution {
public:
    bool binarySearch(vector<int>& vec, int target) {
        int l = 0, r = vec.size();
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (vec[mid] == target)
                return true;
            else if (vec[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if ((matrix.size() == 0) || (matrix[0].size() == 0)) return false;
        int row = 0;
        while ((row < matrix.size()) && (matrix[row].back() < target))
            row++;
        
        if (row >= matrix.size()) return false;
        
        return binarySearch(matrix[row], target);
    }
};

//-------------------------------------------------------------------------
//Approach 2: aka the cool BST approach (tilt the matrix)
//Time Complexity: O(m+n); Space complexity: O(1)
//matrix.size() returns how many vector of int in the matrix; matrix[0].size() returns how many int in the vector matrix[0]

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(),
			cols = matrix[0].size(),
            row = 0, col = cols - 1;
			
        while (row < rows && col > -1) {
            int cur = matrix[row][col];
            if (cur == target) return true;
            if (target > cur) row++;
            else col--;
        }
        
        return false;
    }
};

//---------------------------------------------------------------------------
//Approach 3: Brute
//TC: O(m*n); SC: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		// running a forloop till size of matrix
        for(int i  = 0; i<matrix.size(); ++i)
        {
		// nested for for ietrating each row element
            for(int j = 0; j<matrix[0].size(); ++j)
            {
				// if found return true
                if(matrix[i][j] == target)
                    return true;
            }
        }
		// after traversal if not found
		// return false
        return false;
    }
};