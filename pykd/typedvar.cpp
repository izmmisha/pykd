#include "stdafx.h"    

#include "typedvar.h"
#include "dbgclient.h"

namespace pykd {

///////////////////////////////////////////////////////////////////////////////////

TypedVarPtr   TypedVar::getTypedVar( IDebugClient4 *client, const TypeInfoPtr& typeInfo, ULONG64 offset )
{
    TypedVarPtr     tv;

    if ( typeInfo->isBasicType() )
    {
        tv.reset( new BasicTypedVar( client, typeInfo, offset) );
        return tv;
    }

    if ( typeInfo->isPointer() )
    {
        tv.reset( new PtrTypedVar( client, typeInfo, offset ) );
        return tv;
    }

    if ( typeInfo->isArray() )
    {
        tv.reset( new ArrayTypedVar( client, typeInfo, offset  ) );
        return tv;
    }

    if ( typeInfo->isUserDefined() )       
    {
        tv.reset( new UdtTypedVar( client, typeInfo, offset ) );
        return tv;
    }

    throw DbgException( "can not get field" );

    return tv;
}

///////////////////////////////////////////////////////////////////////////////////

TypedVar::TypedVar ( IDebugClient4 *client, const TypeInfoPtr& typeInfo, ULONG64 offset ) :
    DbgObject( client ),
    m_typeInfo( typeInfo ),
    m_offset( offset )
{
    m_size = m_typeInfo->getSize();
}
///////////////////////////////////////////////////////////////////////////////////

ULONG64  
BasicTypedVar::getValue() const
{
    HRESULT     hres;
    ULONG64     val = 0;

    hres = m_dataSpaces->ReadVirtual( m_offset, &val, getSize(), NULL );

    if ( FAILED( hres ) )
        throw MemoryException( m_offset, false );

    return val;
}

///////////////////////////////////////////////////////////////////////////////////

ULONG64
PtrTypedVar::getValue() const
{
    HRESULT     hres;
    ULONG64     val = 0;

    hres = m_dataSpaces->ReadPointersVirtual( 1, m_offset, &val );
    if ( FAILED( hres ) )
        throw MemoryException( m_offset, false );

    return val;
}

///////////////////////////////////////////////////////////////////////////////////

TypedVarPtr
UdtTypedVar::getField( const std::string &fieldName ) 
{
    TypeInfoPtr fieldType = m_typeInfo->getField( fieldName );

    return  TypedVar::getTypedVar( m_client, fieldType, m_offset + fieldType->getOffset() );
}

///////////////////////////////////////////////////////////////////////////////////

} // end pykd namespace