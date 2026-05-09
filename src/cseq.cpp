#include <memory>
#include <span>
#include <vector>
#include "CSAR/cseq.h"

namespace ctrf::cseq {

    CseqDataCommandParser::CseqDataCommandParser(const command_id& id) : id(id){
        params = std::vector<CseqDataCommandParam>();
    }
    bool CseqDataCommandParser::read_from(const byteview& data) {
        id = (command_id) *data.subspan(0, sizeof(command_id)).data();
        // TODO: add logic to gather parameters
        switch (id)
        {
            case command_id::WAIT:
                break;
            case command_id::PROGRAM_CHANGE:
                break;
            case command_id::OPEN_TRACK:
                break;
            case command_id::JUMP:
                break;
            case command_id::CALL:
                break;
            case command_id::RANDOM:
                break;
            case command_id::VARIABLE:
                break;
            case command_id::IF:
                break;
            case command_id::TIME_CHANGE:
                break;
            case command_id::TIME_RANDOM:
                break;
            case command_id::TIME_VARIABLE:
                break;
            case command_id::TIME_BASE:
                break;
            case command_id::HOLD:
                break;
            case command_id::MONOPHONIC:
                break;
            case command_id::VELOCITY_RANGE:
                break;
            case command_id::BIQUAD_TYPE:
                break;
            case command_id::BIQUAD_VALUE:
                break;
            case command_id::BANK_SELECT:
                break;
            case command_id::MOD_PHASE:
                break;
            case command_id::MOD_CURVE:
                break;
            case command_id::FRONT_BYPASS:
                break;
            case command_id::PAN:
                break;
            case command_id::VOLUME:
                break;
            case command_id::MAIN_VOLUME:
                break;
            case command_id::TRANSPOSE:
                break;
            case command_id::PITCH_BEND:
                break;
            case command_id::BEND_RANGE:
                break;
            case command_id::VOICING_PRIORITY:
                break;
            case command_id::NOTE_WAIT:
                break;
            case command_id::TIE:
                break;
            case command_id::PORTAMENTO:
                break;
            case command_id::MOD_DEPTH:
                break;
            case command_id::MOD_SPEED:
                break;
            case command_id::MOD_TYPE:
                break;
            case command_id::MOD_RANGE:
                break;
            case command_id::PORTAMENTO_ENABLED:
                break;
            case command_id::PORTAMENTO_TIME:
                break;
            case command_id::ATTACK:
                break;
            case command_id::DECAY:
                break;
            case command_id::SUSTAIN:
                break;
            case command_id::RELEASE:
                break;
            case command_id::LOOP_START:
                break;
            case command_id::VOLUME_2:
                break;
            case command_id::PRINT_VAR:
                break;
            case command_id::SURROUND_PAN:
                break;
            case command_id::LPF_CUTOFF:
                break;
            case command_id::FX_SEND_A:
                break;
            case command_id::FX_SEND_B:
                break;
            case command_id::MAIN_SEND:
                break;
            case command_id::INITIAL_PAN:
                break;
            case command_id::MUTE_MODE:
                break;
            case command_id::FX_SEND_C:
                break;
            case command_id::DAMPER:
                break;
            case command_id::MOD_DELAY:
                break;
            case command_id::TEMPO_CHANGE:
                break;
            case command_id::SWEEP_PITCH:
                break;
            case command_id::MOD_PERIOD:
                break;
            case command_id::EXTENDED:
                break;
            case command_id::ENVELOPE_RESET:
                break;
            case command_id::LOOP_END:
                break;
            case command_id::RETURN:
                break;
            case command_id::ALLOCATE_TRACK:
                break;
            case command_id::FIN:
                break;
            default:
                break;
            }
        return false;
    }

	CseqDataCommandParam::CseqDataCommandParam(const bool& param) :
        b8(param), paramtype(command_paramtype::b8) {}
    CseqDataCommandParam::CseqDataCommandParam(const int8_t& param) :
        s8(param), paramtype(command_paramtype::s8) {}
    CseqDataCommandParam::CseqDataCommandParam(const uint8_t& param) :
        u8(param), paramtype(command_paramtype::u8) {}
    CseqDataCommandParam::CseqDataCommandParam(const int16_t& param) :
        s16(param), paramtype(command_paramtype::s16) {}
    CseqDataCommandParam::CseqDataCommandParam(const uint16_t& param) :
        u16(param), paramtype(command_paramtype::u16) {}
    CseqDataCommandParam::CseqDataCommandParam(const cseq_int24& param) :
        paramtype(command_paramtype::s24) {
        s24 = 0xFFFFFF & param;
    }
    CseqDataCommandParam::CseqDataCommandParam(const cseq_uint24& param) :
        paramtype(command_paramtype::u24) {
        u24 = 0xFFFFFF & param;
    }
    CseqDataCommandParam::CseqDataCommandParam(const int32_t& param) :
        s32(param), paramtype(command_paramtype::s32) {}
    CseqDataCommandParam::CseqDataCommandParam(const uint32_t& param) :
        u32(param), paramtype(command_paramtype::u32) {}
    CseqDataCommandParam::CseqDataCommandParam(const std::shared_ptr<CseqDataCommandParser> param) :
        command(param), paramtype(command_paramtype::command) {}
    size_t CseqDataCommandParam::get_size() {
        switch (paramtype)
        {
            case command_paramtype::b8:
            case command_paramtype::s8:
            case command_paramtype::u8:
                return 1;
            case command_paramtype::s16:
            case command_paramtype::u16:
                return 2;
            case command_paramtype::s24:
            case command_paramtype::u24:
                return 3;
            case command_paramtype::s32:
            case command_paramtype::u32:
                return 4;
            case command_paramtype::command:
                return command->get_size();
            default:
                return -1;
        }
    }


	std::shared_ptr<blockdata> CseqDataBlockBuilder::build(const bytearray& const writeaddr) {
		return nullptr;
	}
}