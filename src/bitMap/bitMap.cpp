/*
\brief: BitMap , Smaller memory footprint flag arrays 

\Usage: 
Constructors function :
@params: int n; The number of identification bits you need
All flag bits will be initialised to 0 by default
@return void;

Member functions :
bool test(int k);
@params int k; The serial number of the flag bits you need to test
@return bool; Whether the value on the flag bit is 1 , 1 returns true, 0 returns false

void set(int k);
@params: int k;The serial number of the flag bits you need to set to 1;
The kth flag bit will be set to 1
@return void;

void clear(int k);
@params: int k;The serial number of the flag bits you need to set to 0;
The kth flag bit will be set to 0;
@return void;

\details: The BitMap class uses char as the base type, 
splitting a byte of char into 8 bits for each of the eight flag bits, 
allowing for a small memory footprint and ensuring fast computation through bit manipulation.

However, BitMap uses the int parameter by default, 
if you need a larger range of flags, 
you can modify it yourself.
*/

class Bitmap{
private:

    // N records the number of flag bits
    int N;

    // Use char arrays to store the array of flag bits
    char * M;
public:

    // Constructors function : Allocate a suitable amount of memory to the char array and set all flag positions to 0
    Bitmap(int n = 8){
        M = new char[N = (n+7)/8];
        memset(M,0,N);
    }
    ~Bitmap(){
        delete [] M;
        M = nullptr;
    }
    // test kth is 1
    bool test(int k){
        return M[k >> 3] & (0x80 >> (k & 0x07)); // k >> 3 == k/8     k & 0x07 == k % 8
        // k & 0x07 生成 mask
    }
    // set kth to 1
    void set(int k){
        M[k >> 3] |= (0x80 >> (k & 0x07));
    }
    // set kth to 0
    void clear(int k){
        M[k >> 3] &= ~(0x80 >> (k & 0x07));
    }
};