#pragma once

#include "SoundRender_Target.h"
#include "SoundRender_CoreA.h"

class CSoundRender_TargetA : public CSoundRender_Target
{
    using inherited = CSoundRender_Target;

    // OpenAL
    ALuint pSource;
    ALuint pBuffers[sdef_target_count];
    float cache_gain;
    float cache_pitch;

#ifdef USE_PHONON
    IPLAudioBuffer ipl_buffer_input{};
    IPLAudioBuffer ipl_buffer_output{};
    IPLAudioBuffer ipl_buffer_ambi{};
    IPLAudioBuffer ipl_buffer_mono{};
    IPLAudioBuffer ipl_buffer_stereo{};
    IPLAmbisonicsDecodeEffect ipl_decode{};
#endif

    ALsizei buf_block;
    void fill_block(ALuint BufferID);

public:
    CSoundRender_TargetA();
    virtual ~CSoundRender_TargetA();

    bool _initialize() override;
    void _destroy() override;
    void _restart() override;

    void start(CSoundRender_Emitter* E) override;
    void render() override;
    void rewind() override;
    void stop() override;
    void update() override;
    void fill_parameters() override;
    void source_changed();
};
