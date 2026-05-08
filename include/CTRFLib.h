// CTRFLib.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include <memory>
#include <vector>
#include <list>
#include "types.h"

namespace ctrf {
	typedef std::vector<std::byte> bytearray;
	typedef std::span<std::byte> byteview;

	template <typename T>
	class CtrFile {
		std::unique_ptr<filedata> _filedata;
		std::vector<byteview> _raw_blocks;
		std::list<T> _blocklist;
	public:
		byteorder get_byteorder();
		size_t get_filesize();
		size_t get_headersize();
		uint32_t get_countblocks();
		virtual void* get_block(uint32_t index_block);
	};

	class CtrBlockBuilder{
	public:
		virtual std::shared_ptr<block> build();
	};

	template <typename T>
	class CtrFileBuilder {
		std::vector<CtrBlockBuilder> builders_blocks;
	public:
		virtual std::shared_ptr<CtrFile<T>> build();
	};
}

// TODO: Reference additional headers your program requires here.
