// CTRFLib.cpp : Defines the entry point for the application.
//

#include "CTRFLib.h"

namespace ctrf {
	template <typename T>
	byteorder CtrFile<T>::get_byteorder() {
		return _filedata->header.byteorder;
	}

	template <typename T>
	size_t CtrFile<T>::get_filesize() {
		return _filedata->header.size_file;
	}

	template <typename T>
	size_t CtrFile<T>::get_headersize() {
		return _filedata->header.size_header;
	}

	template <typename T>
	uint32_t CtrFile<T>::get_countblocks() {
		return _filedata->header.count_blocks;
	}
}