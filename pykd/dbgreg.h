#pragma once

#include <string>

/////////////////////////////////////////////////////////////////////////////////

boost::python::object
loadRegister( const std::string &registerName );

ULONG64
loadMSR( ULONG  msr );

/////////////////////////////////////////////////////////////////////////////////