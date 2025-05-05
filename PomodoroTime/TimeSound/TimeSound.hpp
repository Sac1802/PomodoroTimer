/*****************************************************************//**
 * \file   TimeSound.hpp
 * \brief  Handles audio playback using OpenAL.
 * 
 * Defines the TimeSound class for managing sound initialization,
 * loading, playback, and stopping audio using OpenAL functions.
 * 
 * \author Acost
 * \date   May 2025
 *********************************************************************/
#ifndef TimeSound_HPP
#define TimeSound_HPP

#pragma once

#include <iostream> /// Standard library for input/output operations.
#include <al.h> /// OpenAL library for audio playback.
#include <alc.h> /// OpenAL context management.

 /**
  * @class TimeSound
  * @brief Manages sound playback using OpenAL.
  *
  * This class provides functions to initialize OpenAL,
  * load audio data, play sound, and stop playback.
  */
class TimeSound {
private:
    ALCdevice* device; /// Pointer to the OpenAL audio device.
    ALCcontext* context; /// Pointer to the OpenAL context.
    ALuint source; /// OpenAL sound source.
    ALuint buffer; /// OpenAL audio buffer.

public:
    /**
     * @brief Default constructor.
     *
     * Initializes the TimeSound instance but does not load audio.
     */
    TimeSound();
    /**
     * @brief Destructor.
     *
     * Cleans up OpenAL resources and closes the audio device.
     */
    ~TimeSound();

    /**
     * @brief Initializes OpenAL.
     *
     * Sets up the OpenAL context and prepares for audio playback.
     */
    void Initialization();
    /**
     * @brief Loads sound into the OpenAL buffer.
     *
     * Retrieves audio data and stores it for playback.
     */
    void loadSound();
    /**
     * @brief Plays the loaded sound.
     *
     * Starts playback using the OpenAL source.
     */
    void playSound();
    /**
     * @brief Stops sound playback.
     *
     * Halts the current audio playing and resets the source state.
     */
    void stopSound();
};

#endif // !TimeSound_HPP
