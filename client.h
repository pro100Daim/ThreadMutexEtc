#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>

class IClient
{
public:
    IClient(){}
    IClient(int id):_id(id){}
    virtual ~IClient(){}
    void respond()
    {
        std::cout << "respond of Client" << _id << std::endl;
    }
private:
    int _id;
};

#endif // CLIENT_H
