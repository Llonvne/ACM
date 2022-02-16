//
// Created by 华邵钶 on 2022/2/16.
//

#ifndef PLORG_H
#define PLORG_H


class Plorg
{
    enum class PLORG_C: int{SIZE = 20,DEFAULT_CI = 50};
    char fullname[(int)PLORG_C::SIZE]{};
    int CI = (int)PLORG_C::DEFAULT_CI;
public:
    Plorg();
    explicit Plorg(const char * fn);
    void report() const;
    int getCI() const;
    const Plorg & setCI(int ci);
};


#endif //PLORG_H
