// CTRFLib.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include <memory>
#include <vector>
#include "types.h"

namespace ctrf {
	class CtrFile {
		std::unique_ptr<filedata> _filedata;
		std::vector<byteview> blocks;
	public:
		size_t get_filesize();
		size_t get_headersize();
		uint32_t get_count_blocks();
		virtual void* get_block(uint32_t index_block);
	};
}

// TODO: Reference additional headers your program requires here.
