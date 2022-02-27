// Hailstone 序列生成器
// 两个函数一个用于获取Hailstone序列，一个用于直接获取Hailstone序列的长度。
class Hailstone{
public:
    static vector<int> HailstoneGenerator(int start){
        vector<int> result;
        result.push_back(start);
        while (start != 1){
            if (start % 2 == 1){
                start = start * 3 + 1;
            }
            else {
                start /= 2;
            }
            result.push_back(start);
        }
        return result;
    }
    static int getHailstoneLength(int start){
        return (int)HailstoneGenerator(start).size();
    }
};