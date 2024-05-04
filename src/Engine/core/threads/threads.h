#pragma once

#include <string>
#include <thread>

class Thread
{
public:
    Thread();
    ~Thread()=defult;
    SetName()

    template<typename Fn, typename... Args>
    void Dispatch(Fn&& funcs, Args&&... args);
private:
}
