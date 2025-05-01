#ifndef TimeSound_HPP
#define TimeSound_HPP

#pragma once

#include <iostream>
#include <al.h>
#include <alc.h>

class TimeSound {
private:
    ALCdevice* device;
    ALCcontext* context;
    ALuint source;
    ALuint buffer;

public:
    TimeSound();
    ~TimeSound();

    void Initialization();
    void loadSound();
    void playSound();
    void stopSound();
};

#endif // !TimeSound_HPP
