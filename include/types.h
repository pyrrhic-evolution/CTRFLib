#pragma once

#include <cinttypes>
#include <memory>
#include <span>
#include <vector>

namespace ctrf {
	#pragma pack(push, 1)
	enum class byteorder : uint16_t {
		LittleEndian = 0xFFFE,
		BigEndian = 0xFEFF
	};

	enum class patriciatype : uint16_t {
		TypeTest = 0,
		TypeName = 1
	};

	typedef char magic[4];

	typedef struct {
		patriciatype type;
		uint16_t bit_test;
		uint32_t next_left;
		uint32_t next_right;
		uint32_t index_name;
		uint32_t resource_id;
	} patricia_entry_meta;

	typedef struct {
		uint32_t index_first;
		uint32_t count_elems;
		patricia_entry_meta entries[];
	} patricia_tree;

	template <typename T>
	struct blocklist{
		uint32_t count_elems;
		T elements[];
	};

	typedef struct {
		uint32_t reference_id;
		uint32_t offset;
	} blockref;

	typedef struct : blockref {
		uint32_t size_block;
	} sized_blockref;

	typedef struct {
		magic magic;
		uint32_t size;
		std::byte data[];
	} block;

	typedef struct {
		magic magic;
		byteorder byteorder;
		uint16_t size_header;
		uint32_t version;
		uint32_t size_file;
		uint32_t count_blocks;
	} fileheader;

	typedef union {
		fileheader header;
		std::byte stream[];
	} filedata;

	#pragma pack(pop)
}