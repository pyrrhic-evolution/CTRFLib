// CTRFLib.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include <memory>
#include <vector>
#include <list>
#include "types.h"

namespace ctrf {
	typedef std::vector<std::byte> bytevector;
	typedef std::span<std::byte> bytearray;
	typedef std::span<const std::byte> byteview;

	class CtrFile {
		std::unique_ptr<filedata> _filedata;
		std::vector<bytearray> _raw_blocks;
	public:
		byteorder get_byteorder();
		size_t get_filesize();
		size_t get_headersize();
		uint32_t get_countblocks();
		virtual void* get_block(uint32_t index_block);
	};

	class CtrBlockBuilder{
	public:
		virtual std::shared_ptr<blockdata> build();
	};

	class CtrFileBuilder {
		std::vector<CtrBlockBuilder> builders_blocks;
	public:
		virtual std::shared_ptr<CtrFile> build();
	};
}

// TODO: Reference additional headers your program requires here.
