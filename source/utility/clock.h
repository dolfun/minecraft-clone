#pragma once
#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED

class Clock {
public:
    static double getTime();
    static double getDeltaTime();
private:
    static double previous_time, current_time, delta_time;
};

#endif