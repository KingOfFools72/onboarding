

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 06:14:07 2038
 */
/* Compiler settings for CalculatorCOM.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __CalculatorCOM_i_h__
#define __CalculatorCOM_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IInCOMCalculator_FWD_DEFINED__
#define __IInCOMCalculator_FWD_DEFINED__
typedef interface IInCOMCalculator IInCOMCalculator;

#endif 	/* __IInCOMCalculator_FWD_DEFINED__ */


#ifndef __InCOMCalculator_FWD_DEFINED__
#define __InCOMCalculator_FWD_DEFINED__

#ifdef __cplusplus
typedef class InCOMCalculator InCOMCalculator;
#else
typedef struct InCOMCalculator InCOMCalculator;
#endif /* __cplusplus */

#endif 	/* __InCOMCalculator_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IInCOMCalculator_INTERFACE_DEFINED__
#define __IInCOMCalculator_INTERFACE_DEFINED__

/* interface IInCOMCalculator */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInCOMCalculator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("883435eb-be42-4e1c-87bc-4e79a4e74e5d")
    IInCOMCalculator : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ UINT a,
            /* [in] */ UINT b,
            /* [retval][out] */ UINT *res) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Sub( 
            /* [in] */ UINT a,
            /* [in] */ UINT b,
            /* [retval][out] */ UINT *res) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Div( 
            /* [in] */ UINT a,
            /* [in] */ UINT b,
            /* [retval][out] */ UINT *res) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Mul( 
            /* [in] */ UINT a,
            /* [in] */ UINT b,
            /* [retval][out] */ UINT *res) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IInCOMCalculatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInCOMCalculator * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInCOMCalculator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInCOMCalculator * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInCOMCalculator * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInCOMCalculator * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInCOMCalculator * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInCOMCalculator * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInCOMCalculator * This,
            /* [in] */ UINT a,
            /* [in] */ UINT b,
            /* [retval][out] */ UINT *res);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Sub )( 
            IInCOMCalculator * This,
            /* [in] */ UINT a,
            /* [in] */ UINT b,
            /* [retval][out] */ UINT *res);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Div )( 
            IInCOMCalculator * This,
            /* [in] */ UINT a,
            /* [in] */ UINT b,
            /* [retval][out] */ UINT *res);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Mul )( 
            IInCOMCalculator * This,
            /* [in] */ UINT a,
            /* [in] */ UINT b,
            /* [retval][out] */ UINT *res);
        
        END_INTERFACE
    } IInCOMCalculatorVtbl;

    interface IInCOMCalculator
    {
        CONST_VTBL struct IInCOMCalculatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInCOMCalculator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInCOMCalculator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInCOMCalculator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInCOMCalculator_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInCOMCalculator_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInCOMCalculator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInCOMCalculator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInCOMCalculator_Add(This,a,b,res)	\
    ( (This)->lpVtbl -> Add(This,a,b,res) ) 

#define IInCOMCalculator_Sub(This,a,b,res)	\
    ( (This)->lpVtbl -> Sub(This,a,b,res) ) 

#define IInCOMCalculator_Div(This,a,b,res)	\
    ( (This)->lpVtbl -> Div(This,a,b,res) ) 

#define IInCOMCalculator_Mul(This,a,b,res)	\
    ( (This)->lpVtbl -> Mul(This,a,b,res) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInCOMCalculator_INTERFACE_DEFINED__ */



#ifndef __CalculatorCOMLib_LIBRARY_DEFINED__
#define __CalculatorCOMLib_LIBRARY_DEFINED__

/* library CalculatorCOMLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_CalculatorCOMLib;

EXTERN_C const CLSID CLSID_InCOMCalculator;

#ifdef __cplusplus

class DECLSPEC_UUID("98b0410e-9575-48e6-8419-f4bc9dd4fa36")
InCOMCalculator;
#endif
#endif /* __CalculatorCOMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


