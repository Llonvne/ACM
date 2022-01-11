class Bitmap{
private:
    int N;
    char * M;
public:
    Bitmap(int n = 8){
        M = new char[N = (n+7)/8];
        memset(M,0,N);
    }
    ~Bitmap(){
        delete [] M;
        M = nullptr;
    }
    bool test(int k){
        return M[k >> 3] & (0x80 >> (k & 0x07)); // k >> 3 == k/8     k & 0x07 == k % 8
        // k & 0x07 生成 mask
    }
    void set(int k){
        M[k >> 3] |= (0x80 >> (k & 0x07));
    }
    void clear(int k){
        M[k >> 3] &= ~(0x80 >> (k & 0x07));
    }
};