//-----------------------------------------------------------------------------
//								XEndian.h
//								=========
//
// Auteur : F.Becirspahic - Projet Camera Numerique
//
// 07/03/2003
//-----------------------------------------------------------------------------

#ifndef _XENDIAN_H
#define _XENDIAN_H

#include "XBase.h"

class XEndian {
protected:
	bool	m_bByteOrder;	// True : LSB_FIRST (little endian : PC), False : MSB_FIRST (big endian : Mac)
	byte	m_Buf[64];		// Buffer de lecture / ecriture
	byte	m_Swap[64];		// Buffer de swap
public:
	XEndian();
	virtual ~XEndian() {;}

	inline bool ByteOrder() { return m_bByteOrder; }
  bool Read(std::istream* in, bool byteorder, void* data, int size);
  bool Write(std::ostream* out, bool byteorder, void* data, int size);

  bool ReadArray(std::istream* in, bool byteorder, void* data, int size, uint32 nb_elt);

	void Swap(byte* buf, int size);
};

#endif //_XENDIAN_H
