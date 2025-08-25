def solution(board, h, w):
    answer = 0
    dx = [0, 1, -1, 0]
    dy = [1, 0, 0, -1]
    
    for i in range(4):
        x = h + dx[i]
        y = w + dy[i]
        
        if(x >= 0 and x < len(board)
           and y >= 0 and y < len(board)
           and board[h][w] == board[x][y]):
            answer += 1
            
    return answer