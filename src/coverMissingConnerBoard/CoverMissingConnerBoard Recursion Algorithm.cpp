// CoverMissingConnerBoard Recursion Algorithm
class CoverMissingConnerBoard{
    // 棋盘
    vector<vector<int> > _board;
    // 辨识每块木块的颜色标记
    uint64_t _color;
    
    // 覆盖递归算法
    void cover(int n,int x,int y,int dx,int dy){
        int s = 1 << (n-1);
        place(x + dx*(s-1),y + dy*(s-1),dx,dy);
        if (1 < n){
            cover(n-1,x,y,dx,dy);
            cover(n-1,x + dx * s,y + dy * s,dx,dy);
            cover(n-1,x + dx*(2*s - 1),y,-dx,dy);
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