// 素数生成器需要使用 BitMap类 此处为了方便ACM使用内联了 BitMap 类而非使用 include形式
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
class Prime{
    const int MIN_PRIME = 2;
    int N;
    Bitmap* _elem;

    // 计算质数
    void calPrime(){
        // 不妨假设所有的数字（从2开始到N）都为质数，从2开始一个一个排除每一个数的倍数
        for (int i = MIN_PRIME; i < N; ++i) {
            if (! _elem->test(i)){
                for (int j = 2 * i; j < N; j+=i) {
                    _elem->set(j);
                }
            }
        }
    }
public:
    Prime(int N){
        _elem = new Bitmap(N);
        this->N = N;
        // 排除 0,1
        _elem->set(0);
        _elem->set(1);

        // 调用计算函数完全计算
        calPrime();
    }
    ~Prime(){
        delete _elem;
    }
    bool isPrime(){
        return _elem->test(k);
    }
    // 将所有质数组织为向量 通过 & 返回来提高效率
    void returnPrimeInVector(vector<int>& primeList){
        for (int i = MIN_PRIME; i < N; ++i) {
            if (!_elem->test(i)){
                primeList.push_back(i);
            }
        }
    }
    // 将所有素数组织为set 通过 & 返回
    void returnPrimeInSet(set<int>& primeList){
        vector<int> primeInVector;
        returnPrimeInVector(primeInVector);
        primeList = set<int>(primeInVector.begin(),primeInVector.end());
    }
};