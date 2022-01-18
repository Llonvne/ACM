// CoverMissingConnerBoard Recursion Algorithm
class CoverMissingConnerBoard{
    // 棋盘
    vector<vector<int> > _board;
    // 辨识每块木块的颜色标记
    uint64_t _color;
    
    // cover 算法
    void cover(int n,int x,int y,int dx,int dy){
        
        // 子问题的阶次
        int s = 1 << (n-1);
        
        // 在中心放置一块缺口朝棋盘缺口的L型
        place(x + dx*(s-1),y + dy*(s-1),dx,dy);
        
        // 在问题 > 1 时 
        if (1 < n){
            
            // 正向缺口方向覆盖
            cover(n-1,x,y,dx,dy);
            
            // 逆向缺口方向覆盖
            cover(n-1,x + dx * s,y + dy * s,dx,dy);
            
            // 垂直缺口一个方向
            cover(n-1,x + dx*(2*s - 1),y,-dx,dy);
            
            // 垂直缺口另外一个方向
            cover(n-1,x,y + dy*(2*s -1),dx,-dy);
        }
    }
    
    // 放木块
    void place(int x,int y,int dx,int dy){
        _board[x][y] = _board[x + dx][y] = _board[x][y+dy] = (int)_color++;
    }

public:
// 初始化
    CoverMissingConnerBoard(vector<vector<int> > & board,int dx,int dy){
        _board = move(board);
        _color = 0;
        int n = (int)sqrt((int)_board.size());
        cover(n,0,0,dx,dy);
    }

    // 获得棋盘
    vector<vector<int> > & returnBoard() {
        return _board;
    }

    // 打印棋盘
    void printBoard(){
        for (int i = 0; i < _board.size(); ++i) {
            for (int j = 0; j < _board[i].size(); ++j) {
                printf("%-3d",_board[i][j]);
            }
            cout << endl;
        }
    }

};