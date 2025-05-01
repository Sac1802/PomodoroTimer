#include "TimeSound.hpp"
#define DR_WAV_IMPLEMENTATION
#include <dr_wav.h>

ALCdevice* device = nullptr;
ALCcontext* context = nullptr;
ALuint source;
ALuint buffer;

TimeSound::TimeSound() : device(nullptr), context(nullptr), source(0), buffer(0) {}

TimeSound::~TimeSound() {
	stopSound();
}


void TimeSound::Initialization() {
	TimeSound::device = alcOpenDevice(NULL);
	ALenum error = alGetError();
	if (!device) {
		std::cerr << "Failed to open audio device." << std::endl;
		std::cerr << "OpenAL Error: " << alGetString(error) << std::endl;
		return;
	}
	TimeSound::context = alcCreateContext(device, NULL);
	if (!context) {
		std::cerr << "Filed to create audio context." << std::endl;
		std::cerr << "OpenAL Error: " << alGetString(error) << std::endl;
		alcCloseDevice(device);
		return;
	}

	alcMakeContextCurrent(context);
}


void TimeSound::loadSound() {
    alGenBuffers(1, &buffer);
    if (alGetError() != AL_NO_ERROR) {
        std::cerr << "Failed to generate buffer." << std::endl;
        return;
    }

    // Cargar archivo WAV con dr_wav
    unsigned int channels;
    unsigned int sampleRate;
    drwav_uint64 totalPCMFrameCount;

    int16_t* pSampleData = drwav_open_file_and_read_pcm_frames_s16(
        "C:/Users/Acost/source/repos/PomodoroTime/PomodoroTime/Audio/clock_digital.wav",
        &channels,
        &sampleRate,
        &totalPCMFrameCount,
        NULL
    );

    if (pSampleData == NULL) {
        std::cerr << "Error cargando el archivo WAV." << std::endl;
        return;
    }

    ALenum format;
    if (channels == 1)
        format = AL_FORMAT_MONO16;
    else if (channels == 2)
        format = AL_FORMAT_STEREO16;
    else {
        std::cerr << "Formato de canal no soportado: " << channels << std::endl;
        drwav_free(pSampleData, NULL);
        return;
    }

    alBufferData(buffer, format, pSampleData,
        static_cast<ALsizei>(totalPCMFrameCount * channels * sizeof(int16_t)),
        sampleRate);

    drwav_free(pSampleData, NULL);

    alGenSources(1, &source);
    if (alGetError() != AL_NO_ERROR) {
        std::cerr << "Failed to generate source." << std::endl;
        return;
    }

    alSourcei(source, AL_BUFFER, buffer);
    playSound();
}

void TimeSound::playSound() {
	alSourcef(source, AL_GAIN, 1.0f); //Set Volumen
	alSourcei(source, AL_LOOPING, AL_FALSE);// Loop the sound FALSE
	ALenum error = alGetError();
	alSourcePlay(source);
	if (alGetError() != AL_NO_ERROR) {
		std::cerr << "Failed to play sound." << std::endl;
		std::cerr << "OpenAL Error: " << alGetString(error) << std::endl;
	}
	ALint state;
	do {
		alGetSourcei(source, AL_SOURCE_STATE, &state);
	} while (state == AL_PLAYING);
}

void TimeSound::stopSound() {
	ALint state;
	alGetSourcei(source, AL_SOURCE_STATE, &state);
	if (state == AL_PLAYING) {
		alSourceStop(source);
	}
	alDeleteBuffers(1, &buffer);
	alDeleteSources(1, &source);
	alcMakeContextCurrent(NULL);
	alcDestroyContext(context);
	//alcCloseDevice(device);
}