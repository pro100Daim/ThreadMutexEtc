#ifndef CRITICALSECTION_H
#define CRITICALSECTION_H
#include <iostream>

class CriticalSection
{
public:
    CriticalSection():isLocked(false){}
    virtual ~CriticalSection(){}
    void lock(){
        while(isLocked){}
        isLocked = true;
    }
    void unlock(){isLocked = false;}
private:
    bool isLocked;
};

#endif // CRITICALSECTION_H
