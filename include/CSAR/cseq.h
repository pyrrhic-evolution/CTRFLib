#pragma once

#include <cinttypes>
#include <cstdbool>
#include <span>
#include <variant>
#include "../types.h"
#include "../CTRFLib.h"

namespace ctrf::cseq {
    #pragma pack(push, 1)
    const char MAGIC_CSEQDATA[4] = {'D','A','T','A'};
    const char MAGIC_CSEQLABL[4] = { 'L','A','B','L'};

    enum class command_paramtype {
        b8,
        s8,
        u8,
        s16,
        u16,
        s24,
        u24,
        s32,
        u32,
        command
    };
    enum class command_id: uint8_t {
        WAIT = 0x80,
        PROGRAM_CHANGE = 0x81,

        /* Control Commands */

        OPEN_TRACK = 0x88,
        JUMP = 0x89,
        CALL = 0x8A,

        /* Prefix Commands */

        RANDOM = 0xA0,
        VARIABLE = 0xA1,
        IF = 0xA2,
        TIME_CHANGE = 0xA3,
        TIME_RANDOM = 0xA4,
        TIME_VARIABLE = 0xA5,

        /* U8 Commands */

        TIME_BASE = 0xB0,
        HOLD = 0xB1,
        MONOPHONIC = 0xB2,
        VELOCITY_RANGE = 0xB3,
        BIQUAD_TYPE = 0xB4,
        BIQUAD_VALUE = 0xB5,
        BANK_SELECT = 0xB6,

        //B7-BC are unused.

        MOD_PHASE = 0xBD,
        MOD_CURVE = 0xBE,
        FRONT_BYPASS = 0xBF,
        PAN = 0xC0,
        VOLUME = 0xC1,
        MAIN_VOLUME = 0xC2,
        TRANSPOSE = 0xC3,
        PITCH_BEND = 0xC4,
        BEND_RANGE = 0xC5,
        VOICING_PRIORITY = 0xC6,
        NOTE_WAIT = 0xC7,
        TIE = 0xC8,
        PORTAMENTO = 0xC9,
        MOD_DEPTH = 0xCA,
        MOD_SPEED = 0xCB,
        MOD_TYPE = 0xCC,
        MOD_RANGE = 0xCD,
        PORTAMENTO_ENABLED = 0xCE,
        PORTAMENTO_TIME = 0xCF,
        ATTACK = 0xD0,
        DECAY = 0xD1,
        SUSTAIN = 0xD2,
        RELEASE = 0xD3,
        LOOP_START = 0xD4,
        VOLUME_2 = 0xD5,
        PRINT_VAR = 0xD6,
        SURROUND_PAN = 0xD7,
        LPF_CUTOFF = 0xD8,
        FX_SEND_A = 0xD9,
        FX_SEND_B = 0xDA,
        MAIN_SEND = 0xDB,
        INITIAL_PAN = 0xDC,
        MUTE_MODE = 0xDD,
        FX_SEND_C = 0xDE,
        DAMPER = 0xDF,

        /* S16 Commands */

        MOD_DELAY = 0xE0,
        TEMPO_CHANGE = 0xE1,

        //E2 is unused for whatever reason.

        SWEEP_PITCH = 0xE3,
        MOD_PERIOD = 0xE4,

        /* Extended Commands */

        EXTENDED = 0xF0,

        /* Other Commands */

        ENVELOPE_RESET = 0xFB,
        LOOP_END = 0xFC,
        RETURN = 0xFD,
        ALLOCATE_TRACK = 0xFE,
        FIN = 0xFF
	};

    typedef struct {
        command_id id;
        std::byte params[];
    }  cseq_command;

    typedef struct {
        
    } cseqlabel_blockdata;

    typedef struct {
    
    } cseqdata_blockdata;

    typedef int32_t cseq_int24;
    typedef uint32_t cseq_uint24;
    #pragma pack(pop)

    class CseqDataCommandParam {
        command_paramtype paramtype;
        union {
            bool b8;
            int8_t s8;
            uint8_t u8;
            int16_t s16;
            uint16_t u16;
            cseq_int24 s24;
            cseq_uint24 u24;
            int32_t s32;
            uint32_t u32;
            std::shared_ptr<CseqDataCommandParser> command;
        };
    public:
        CseqDataCommandParam(const bool&);
        CseqDataCommandParam(const int8_t&);
        CseqDataCommandParam(const uint8_t&);
        CseqDataCommandParam(const int16_t&);
        CseqDataCommandParam(const uint16_t&);
        CseqDataCommandParam(const cseq_int24&);
        CseqDataCommandParam(const cseq_uint24&);
        CseqDataCommandParam(const int32_t&);
        CseqDataCommandParam(const uint32_t&);
        CseqDataCommandParam(const std::shared_ptr<CseqDataCommandParser>);

        bool    set_type(const command_paramtype&);
        bool    set_value(const bytearray&);
        size_t  get_size();
        bool    update(const command_paramtype&, const bytearray&);
    };

    class CseqDataCommandParser {
        command_id id;
        std::vector<CseqDataCommandParam> params;
    public:
        CseqDataCommandParser(const command_id&);
        bool    read_from(const byteview&);
        bool    change_command(const command_id&);
        size_t  get_size();
        bool    validate_command();
    };

    class CseqDataBlockBuilder : CtrBlockBuilder {
        std::unique_ptr<std::vector<CseqDataCommandParser>> _commands;
    public:
        std::shared_ptr<blockdata> build(const bytearray& const);
    };

    class CseqFile : CtrFile {

    };
}