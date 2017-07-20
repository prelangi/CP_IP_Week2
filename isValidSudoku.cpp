int Solution::isValidSudoku(const vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
        map<char, bool> row;
        map<char, bool> col;
        map<char, bool> block;
         
        for (int i=0;i<9;i++){
            col.clear();
            row.clear();
            for (int j=0;j<9;j++){
                if (A[i][j]!='.'){
                    if (col[A[i][j]]){
                        return false;
                    }else{
                        col[A[i][j]]=true;
                    } 
                }
                if (A[j][i]!='.'){
                    if (row[A[j][i]]){
                        return false;
                    }else{
                        row[A[j][i]]=true;
                    } 
                }
            }
        }
                 
        for (int ii=0;ii<9;ii=ii+3){
            for (int jj=0;jj<9;jj=jj+3){
                block.clear();
                for (int i=ii;i<ii+3;i++){
                    for (int j=jj;j<jj+3;j++){
                        if (A[i][j]!='.'){
                            if (block[A[i][j]]){
                                return false;
                            }else{
                                block[A[i][j]]=true;
                            } 
                        }
                    }
                }        
            }
        }
         
        return true;
}
