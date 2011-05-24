#include "stdafx.h"

#include "dbgext.h"
#include "dbgreg.h"
#include "dbgexcept.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////

boost::python::object
loadRegister( const std::string &registerName )
{
    HRESULT         hres;   
    
    ULONG    registerIndex = 0;

    hres = dbgExt->registers->GetIndexByName( registerName.c_str(), &registerIndex );
    if ( FAILED( hres ) )
        throw DbgException( "IDebugRegister::GetIndexByName  failed" );
        
    DEBUG_VALUE    debugValue;            
    hres = dbgExt->registers->GetValue( registerIndex, &debugValue );
    if ( FAILED( hres ) )
        throw DbgException( "IDebugRegister::GetValue  failed" );
        
    switch( debugValue.Type )
    {
    case DEBUG_VALUE_INT8:
        return boost::python::long_( debugValue.I8 );
        break;
        
    case DEBUG_VALUE_INT16:
        return boost::python::long_( debugValue.I16 );
        break;
        
    case DEBUG_VALUE_INT32:
        return boost::python::long_( debugValue.I32 );
        break;
        
    case DEBUG_VALUE_INT64:
        return boost::python::long_(debugValue.I64 );
        break;
   }

   throw DbgException( "Invalid register value" );  
}

///////////////////////////////////////////////////////////////////////////////////

ULONG64
loadMSR( ULONG  msr )
{
    HRESULT     hres;
    ULONG64     value;    
    
    hres = dbgExt->dataSpaces->ReadMsr( msr, &value );
    if ( FAILED( hres ) )
         throw DbgException( "IDebugDataSpaces::ReadMsr  failed" );            
         
    return value;         
}

///////////////////////////////////////////////////////////////////////////////////
