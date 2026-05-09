// CTRFLib.cpp : Defines the entry point for the application.
//

#include "CTRFLib.h"

namespace ctrf {
	byteorder CtrFile::get_byteorder() {
		return _filedata->header.byteorder;
	}

	size_t CtrFile::get_filesize() {
		return _filedata->header.size_file;
	}

	size_t CtrFile::get_headersize() {
		return _filedata->header.size_header;
	}

	uint32_t CtrFile::get_countblocks() {
		return _filedata->header.count_blocks;
	}
}