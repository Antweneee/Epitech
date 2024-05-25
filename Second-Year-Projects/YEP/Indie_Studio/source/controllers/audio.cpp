/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** audio
*/

#include "Audio.hpp"

Audio::Audio()
{

}

Audio::~Audio()
{

}

//! Audio device management functions
void Audio::closeAudioDevice(void)
{
    CloseAudioDevice();
}

bool Audio::isAudioDeviceReady(void)
{
    return IsAudioDeviceReady();
}

void Audio::setMasterVolume(float volume)
{
    SetMasterVolume(volume);
}

//! Wave/Sound loading/unloading functions
Wave Audio::loadWave(const std::string& fileName)
{
    return LoadWave(fileName.c_str());
}

Wave Audio::loadWaveFromMemory(const std::string& fileType, const std::string& fileData, int dataSize)
{
    return LoadWaveFromMemory(fileType.c_str(), (unsigned const char*)fileData.c_str(), dataSize);
}

Sound Audio::loadSound(const std::string& fileName)
{
    return LoadSound(fileName.c_str());
}

Sound Audio::loadSoundFromWave(Wave wave)
{
    return LoadSoundFromWave(wave);
}

void Audio::udateSound(Sound sound, std::any data, int samplesCount)
{
    UpdateSound(sound, std::any_cast<const void*>(data), samplesCount);
}

void Audio::unloadWave(Wave wave)
{
    UnloadWave(wave);
}

void Audio::unloadSound(Sound sound)
{
    UnloadSound(sound);
}

bool Audio::exportWave(Wave wave, const std::string& fileName)
{
    return ExportWave(wave, fileName.c_str());
}

bool Audio::exportWaveAsCode(Wave wave, const std::string& fileName)
{
    return ExportWaveAsCode(wave, fileName.c_str());
}

//! Wave/Sound management functions
void Audio::playSound(Sound sound)
{
    PlaySound(sound);
}

void Audio::stopSound(Sound sound)
{
    StopSound(sound);
}

void Audio::pauseSound(Sound sound)
{
    PauseSound(sound);
}

void Audio::resumeSound(Sound sound)
{
    ResumeSound(sound);
}

void Audio::playSoundMulti(Sound sound)
{
    PlaySoundMulti(sound);
}

void Audio::stopSoundMulti(void)
{
    StopSoundMulti();
}

int Audio::getSoundsPlaying(void)
{
    return GetSoundsPlaying();
}

bool Audio::isSoundPlaying(Sound sound)
{
    return IsSoundPlaying(sound);
}

void Audio::setSoundVolume(Sound sound, float volume)
{
    SetSoundVolume(sound, volume);
}

void Audio::setSoundPitch(Sound sound, float pitch)
{
    SetSoundPitch(sound, pitch);
}

void Audio::waveFormat(Wave wave, int sampleRate, int sampleSize, int channels)
{
    WaveFormat(&wave, sampleRate, sampleSize, channels);
}

Wave Audio::waveCopy(Wave wave)
{
    return WaveCopy(wave);
}

void Audio::waveCrop(Wave wave, int initSample, int finalSample)
{
    WaveCrop(&wave, initSample, finalSample);
}

std::unique_ptr<float> Audio::loadWaveSamples(Wave wave)
{
    std::unique_ptr<float> data = std::unique_ptr<float>(LoadWaveSamples(wave));
    return data;
}

void Audio::unloadWaveSamples(float samples)
{
    UnloadWaveSamples(&samples);
}

//! Music management functions
Music Audio::loadMusicStream(const std::string& fileName)
{
    return LoadMusicStream(fileName.c_str());
}

Music Audio::loadMusicStreamFromMemory(const std::string& fileType, std::string& data, int dataSize)
{
    return LoadMusicStreamFromMemory(fileType.c_str(), (unsigned char*)data.c_str(), dataSize);
}

void Audio::unloadMusicStream(Music music)
{
    UnloadMusicStream(music);
}

void Audio::playMusicStream(Music music)
{
    PlayMusicStream(music);
}

bool Audio::isMusicStreamPlaying(Music music)
{
    return IsMusicStreamPlaying(music);
}

void Audio::updateMusicStream(Music music)
{
    UpdateMusicStream(music);
}

void Audio::stopMusicStream(Music music)
{
    StopMusicStream(music);
}

void Audio::pauseMusicStream(Music music)
{
    PauseMusicStream(music);
}

void Audio::resumeMusicStream(Music music)
{
    ResumeMusicStream(music);
}

void Audio::seekMusicStream(Music music, float position)
{
    SeekMusicStream(music, position);
}

void Audio::setMusicVolume(Music music, float volume)
{
    SetMusicVolume(music, volume);
}

void Audio::setMusicPitch(Music music, float pitch)
{
    SetMusicPitch(music, pitch);
}

float Audio::getMusicTimeLength(Music music)
{
    return GetMusicTimeLength(music);
}

float Audio::getMusicTimePlayed(Music music)
{
    return GetMusicTimePlayed(music);
}

//! AudioStream management functions
void Audio::initAudioDevice(void)
{
    InitAudioDevice();
}

/*AudioStream initAudioStream(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels)
{
    return InitAudioStream(sampleRate, sampleSize, channels);
}*/

void Audio::updateAudioStream(AudioStream stream, std::any data, int samplesCount)
{
    UpdateAudioStream(stream, std::any_cast<const void*>(data), samplesCount);
}

void Audio::closeAudioStream(AudioStream stream)
{
    closeAudioStream(stream);
}

bool Audio::isAudioStreamProcessed(AudioStream stream)
{
    return IsAudioStreamProcessed(stream);
}

void Audio::playAudioStream(AudioStream stream)
{
    PlayAudioStream(stream);
}

void Audio::pauseAudioStream(AudioStream stream)
{
    PauseAudioStream(stream);
}

void Audio::resumeAudioStream(AudioStream stream)
{
    ResumeAudioStream(stream);
}

bool Audio::isAudioStreamPlaying(AudioStream stream)
{
    return IsAudioStreamPlaying(stream);
}

void Audio::stopAudioStream(AudioStream stream)
{
    StopAudioStream(stream);
}

void Audio::setAudioStreamVolume(AudioStream stream, float volume)
{
    SetAudioStreamVolume(stream, volume);
}

void Audio::setAudioStreamPitch(AudioStream stream, float pitch)
{
    SetAudioStreamPitch(stream, pitch);
}

void Audio::setAudioStreamBufferSizeDefault(int size)
{
    SetAudioStreamBufferSizeDefault(size);
}