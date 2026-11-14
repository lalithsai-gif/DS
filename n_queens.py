class Queen:    
    def backtrack(self,col,n,board,left_row,left_dia,right_dia,ans):
        
        if(n==col):
            ans.append([''.join(row) for row in board])
            return 
            
        for i in range(n):
                if(board[i][col]=='.' and left_row[i]==0 and left_dia[i+col]==0 and right_dia[n-1+(col-i)]==0):
                    board[i][col]='Q'
                    left_row[i]=1
                    left_dia[i+col]=1
                    right_dia[n-1+(col-i)]=1
                    self.backtrack(col+1,n,board,left_row,left_dia,right_dia,ans)
                    board[i][col]='.'
                    left_row[i]=0
                    left_dia[i+col]=0
                    right_dia[n-1+(col-i)]=0


    def queen(self,n):
        board=[['.']*n for _ in range(n)]
        ans=[]
        left_row=[0]*n
        left_dia=[0]*(2*n-1)
        right_dia=[0]*(2*n-1)
        self.backtrack(0,n,board,left_row,left_dia,right_dia,ans)

        return ans

Q1=Queen()

print("N-Queens: ",Q1.queen(4))

