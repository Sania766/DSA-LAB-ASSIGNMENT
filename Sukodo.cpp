class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

    const int size = 9;
    
    
    for (int i = 0; i < size; ++i) {
        unordered_set<char> row_set;
        for (int j = 0; j < size; ++j) {
            char c = board[i][j];
            if (c != '.') {
                if (row_set.count(c)) {
                    return false;
                }
                row_set.insert(c);
            }
        }
    }
    
   
    for (int j = 0; j < size; ++j) {
        unordered_set<char> col_set;
        for (int i = 0; i < size; ++i) {
            char c = board[i][j];
            if (c != '.') {
                if (col_set.count(c)) {
                    return false;
                }
                col_set.insert(c);
            }
        }
    }
    
    
    for (int box = 0; box < size; ++box) {
        unordered_set<char> box_set;
        int start_row = (box / 3) * 3;
        int start_col = (box % 3) * 3;
        
        for (int i = start_row; i < start_row + 3; ++i) {
            for (int j = start_col; j < start_col + 3; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    if (box_set.count(c)) {
                        return false;
                    }
                    box_set.insert(c);
                }
            }
        }
    }
    
    return true;
}
};
