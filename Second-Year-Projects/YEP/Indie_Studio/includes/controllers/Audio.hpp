/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** Audio
*/

#ifndef AUDIO_HPP_
    #define AUDIO_HPP_
    #include <raylib.h>
    #include <string>
    #include <memory>
    #include <any>

class Audio {
    public:
        Audio();
        ~Audio();

        //! Audio device management functions
        void closeAudioDevice(void);
        bool isAudioDeviceReady(void);
        void setMasterVolume(float volume);

        //! Wave/Sound loading/unloading functions
        Wave loadWave(const std::string& fileName);
        Wave loadWaveFromMemory(const std::string& fileType, const std::string& fileData, int dataSize);
        Sound loadSound(const std::string& fileName);
        Sound loadSoundFromWave(Wave wave);
        void udateSound(Sound sound, std::any data, int samplesCount);
        void unloadWave(Wave wave);
        void unloadSound(Sound sound);
        bool exportWave(Wave wave, const std::string& fileName);
        bool exportWaveAsCode(Wave wave, const std::string& fileName);

        //! Wave/Sound management functions
        void playSound(Sound sound);
        void stopSound(Sound sound);
        void pauseSound(Sound sound);
        void resumeSound(Sound sound);
        void playSoundMulti(Sound sound);
        void stopSoundMulti(void);
        int getSoundsPlaying(void);
        bool isSoundPlaying(Sound sound);
        void setSoundVolume(Sound sound, float volume);
        void setSoundPitch(Sound sound, float pitch);
        void waveFormat(Wave wave, int sampleRate, int sampleSize, int channels);
        Wave waveCopy(Wave wave);
        void waveCrop(Wave wave, int initSample, int finalSample);
        std::unique_ptr<float> loadWaveSamples(Wave wave);
        void unloadWaveSamples(float samples);

        //! Music management functions
        Music loadMusicStream(const std::string& fileName);
        Music loadMusicStreamFromMemory(const std::string& fileType, std::string& data, int dataSize);
        void unloadMusicStream(Music music);
        void playMusicStream(Music music);
        bool isMusicStreamPlaying(Music music);
        void updateMusicStream(Music music);
        void stopMusicStream(Music music);
        void pauseMusicStream(Music music);
        void resumeMusicStream(Music music);
        void seekMusicStream(Music music, float position);
        void setMusicVolume(Music music, float volume);
        void setMusicPitch(Music music, float pitch);
        float getMusicTimeLength(Music music);
        float getMusicTimePlayed(Music music);

        //! AudioStream management functions
        void initAudioDevice(void);
        void updateAudioStream(AudioStream stream, std::any data, int samplesCount);
        void closeAudioStream(AudioStream stream);
        bool isAudioStreamProcessed(AudioStream stream);
        void playAudioStream(AudioStream stream);
        void pauseAudioStream(AudioStream stream);
        void resumeAudioStream(AudioStream stream);
        bool isAudioStreamPlaying(AudioStream stream);
        void stopAudioStream(AudioStream stream);
        void setAudioStreamVolume(AudioStream stream, float volume);
        void setAudioStreamPitch(AudioStream stream, float pitch);
        void setAudioStreamBufferSizeDefault(int size);

    protected:
    private:
};

#endif /* !AUDIO_HPP_ */
