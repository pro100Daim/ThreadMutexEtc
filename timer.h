#ifndef TIMER_H
#define TIMER_H

#include <ctime>
#include <mutex>
#include <map>
#include <chrono>
#include <thread>
#include "criticalsection.h"
#include "client.h"

class Timer
{
public:
    Timer():m_Thread(nullptr){}
    virtual ~Timer(){}

    void runTimer(int delay, IClient* client)
    {
        std::time_t inpTime = std::time(nullptr);
        criticalSection.lock();
        m_CurrentUsers.insert(std::pair<std::time_t, IClient*>((inpTime + delay), client));
        criticalSection.unlock();
        if(m_Thread == nullptr)
        {
            m_Thread = new std::thread(&Timer::start, this);
        }
    }

    void check()
    {
        m_Thread->join();
    }

private:
    void start()
    {
        while(!m_CurrentUsers.empty())
        {
            std::time_t currTime = std::time(nullptr);
            std::multimap<std::time_t,IClient*>::iterator it = m_CurrentUsers.find(currTime);
            if(it != m_CurrentUsers.end())
            {
                criticalSection.lock();
                while(it != m_CurrentUsers.end())
                {
                    it->second->respond();
                    m_CurrentUsers.erase(it);
                    it = m_CurrentUsers.find(currTime);
                }
                criticalSection.unlock();
            }
        }
    }
protected:
    CriticalSection criticalSection;
    std::multimap<std::time_t,IClient*> m_CurrentUsers;
    std::thread *m_Thread;
};

#endif // TIMER_H
