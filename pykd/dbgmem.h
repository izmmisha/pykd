#pragma once

namespace pykd {

///////////////////////////////////////////////////////////////////////////////////

ULONG64
addr64( ULONG64  addr );

///////////////////////////////////////////////////////////////////////////////////

void
readMemory( ULONG64 address, PVOID buffer, ULONG length, BOOLEAN phyAddr = FALSE );

void
writeMemory( ULONG64 address, PVOID buffer, ULONG length, BOOLEAN phyAddr = FALSE );

bool 
compareMemory( ULONG64 addr1, ULONG64 addr2, ULONG length, bool phyAddr = FALSE );

///////////////////////////////////////////////////////////////////////////////////

std::string loadChars( ULONG64 address, ULONG  number, bool phyAddr = FALSE );

std::wstring loadWChars( ULONG64 address, ULONG  number, bool phyAddr = FALSE );

python::list loadBytes( ULONG64 offset, ULONG count, bool phyAddr = FALSE );

python::list loadWords( ULONG64 offset, ULONG count, bool phyAddr = FALSE );

python::list loadDWords( ULONG64 offset, ULONG count, bool phyAddr = FALSE );

python::list loadQWords( ULONG64 offset, ULONG count, bool phyAddr = FALSE );

python::list loadSignBytes( ULONG64 offset, ULONG count, bool phyAddr = FALSE );

python::list loadSignWords( ULONG64 offset, ULONG count, bool phyAddr = FALSE );

python::list loadSignDWords( ULONG64 offset, ULONG count, bool phyAddr = FALSE );

python::list loadSignQWords( ULONG64 offset, ULONG count, bool phyAddr = FALSE );

ULONG64 ptrByte( ULONG64 offset );

ULONG64 ptrWord( ULONG64 offset );

ULONG64 ptrDWord( ULONG64 offset );

ULONG64 ptrQWord( ULONG64 offset );

ULONG64 ptrMWord( ULONG64 offset );

LONG64 ptrSignByte( ULONG64 offset );

LONG64 ptrSignWord( ULONG64 offset );

LONG64 ptrSignDWord( ULONG64 offset );

LONG64 ptrSignQWord( ULONG64 offset );

LONG64 ptrSignMWord( ULONG64 offset );

ULONG64 ptrPtr( ULONG64 offset );

///////////////////////////////////////////////////////////////////////////////////

};

