/* Header file automatically generated from inputpanelistener.idl */
/*
 * File built with Microsoft(R) MIDLRT Compiler Engine Version 10.00.0231 
 */

#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif /*COM_NO_WINDOWS_H*/
#ifndef __inputpanelistener_h__
#define __inputpanelistener_h__
#ifndef __inputpanelistener_p_h__
#define __inputpanelistener_p_h__


#pragma once

// Ensure that the setting of the /ns_prefix command line switch is consistent for all headers.
// If you get an error from the compiler indicating "warning C4005: 'CHECK_NS_PREFIX_STATE': macro redefinition", this
// indicates that you have included two different headers with different settings for the /ns_prefix MIDL command line switch
#if !defined(DISABLE_NS_PREFIX_CHECKS)
#if defined(MIDL_NS_PREFIX)
#define CHECK_NS_PREFIX_STATE "always"
#else
#define CHECK_NS_PREFIX_STATE "never"
#endif // MIDL_NS_PREFIX
#endif // !defined(DISABLE_NS_PREFIX_CHECKS)


#pragma push_macro("ABI_CONCAT")
#pragma push_macro("ABI_PARAMETER")
#pragma push_macro("ABI_NAMESPACE_BEGIN")
#pragma push_macro("ABI_NAMESPACE_END")
#pragma push_macro("C_IID")
#undef ABI_CONCAT
#undef ABI_PARAMETER
#undef ABI_NAMESPACE_BEGIN
#undef ABI_NAMESPACE_END
#undef C_IID
#define ABI_CONCAT(x,y)  x##y

// /ns_prefix optional state
#if defined(MIDL_NS_PREFIX)
#if defined(__cplusplus)
#define ABI_PARAMETER(x) ABI::x
#define ABI_NAMESPACE_BEGIN namespace ABI {
#define ABI_NAMESPACE_END }
#else // !defined(__cplusplus)
#define C_ABI_PARAMETER(x) ABI_CONCAT(__x_ABI_C, x)
#endif // !defined(__cplusplus)
#define C_IID(x) ABI_CONCAT(IID___x_ABI_C, x)
#else
#if defined(__cplusplus)
#define ABI_PARAMETER(x) x
#define ABI_NAMESPACE_BEGIN 
#define ABI_NAMESPACE_END 
#else // !defined(__cplusplus)
#define C_ABI_PARAMETER(x) ABI_CONCAT(__x_, x)
#endif // !defined(__cplusplus)
#define C_IID(x) ABI_CONCAT(IID___x_, x)
#endif // defined(MIDL_NS_PREFIX)

#pragma push_macro("MIDL_CONST_ID")
#undef MIDL_CONST_ID
#define MIDL_CONST_ID const __declspec(selectany)


//  API Contract Inclusion Definitions
#if !defined(SPECIFIC_API_CONTRACT_DEFINITIONS)
#if !defined(WINDOWS_APPLICATIONMODEL_CALLS_CALLSPHONECONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_CALLS_CALLSPHONECONTRACT_VERSION 0x60000
#endif // defined(WINDOWS_APPLICATIONMODEL_CALLS_CALLSPHONECONTRACT_VERSION)

#if !defined(WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION)
#define WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION 0x40000
#endif // defined(WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION)

#if !defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)
#define WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION 0xf0000
#endif // defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)

#if !defined(WINDOWS_NETWORKING_SOCKETS_CONTROLCHANNELTRIGGERCONTRACT_VERSION)
#define WINDOWS_NETWORKING_SOCKETS_CONTROLCHANNELTRIGGERCONTRACT_VERSION 0x30000
#endif // defined(WINDOWS_NETWORKING_SOCKETS_CONTROLCHANNELTRIGGERCONTRACT_VERSION)

#if !defined(WINDOWS_PHONE_PHONECONTRACT_VERSION)
#define WINDOWS_PHONE_PHONECONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_PHONE_PHONECONTRACT_VERSION)

#if !defined(WINDOWS_PHONE_PHONEINTERNALCONTRACT_VERSION)
#define WINDOWS_PHONE_PHONEINTERNALCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_PHONE_PHONEINTERNALCONTRACT_VERSION)

#if !defined(WINDOWS_UI_WEBUI_CORE_WEBUICOMMANDBARCONTRACT_VERSION)
#define WINDOWS_UI_WEBUI_CORE_WEBUICOMMANDBARCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_UI_WEBUI_CORE_WEBUICOMMANDBARCONTRACT_VERSION)

#endif // defined(SPECIFIC_API_CONTRACT_DEFINITIONS)


// Header files for imported files
#include "oaidl.h"
#include "inspectable.h"
#include "windows.foundation.h"

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener_FWD_DEFINED__
#define ____x_Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener_FWD_DEFINED__
ABI_NAMESPACE_BEGIN 
namespace Microsoft {
    namespace Internal {
        namespace FrameworkUdk {
            interface IInputPaneVisibilityChangedListener;
        } /* FrameworkUdk */
    } /* Internal */
} /* Microsoft */
ABI_NAMESPACE_END
#define __x_Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener ABI_PARAMETER(Microsoft::Internal::FrameworkUdk::IInputPaneVisibilityChangedListener)

#endif // ____x_Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener_FWD_DEFINED__



#pragma warning (push)
#pragma warning (disable:4668) 
#pragma warning (disable:4001) 
#pragma once 
#pragma warning (pop)

/*
 *
 * Interface Microsoft.Internal.FrameworkUdk.IInputPaneVisibilityChangedListener
 *
 */
#if !defined(____x_Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener_INTERFACE_DEFINED__)
#define ____x_Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Internal_FrameworkUdk_IInputPaneVisibilityChangedListener[] = L"Microsoft.Internal.FrameworkUdk.IInputPaneVisibilityChangedListener";
ABI_NAMESPACE_BEGIN 
namespace Microsoft {
    namespace Internal {
        namespace FrameworkUdk {
            /* [object, uuid("AC4AF7F8-B273-4AE8-865B-6415380EF87F"), version] */
            MIDL_INTERFACE("AC4AF7F8-B273-4AE8-865B-6415380EF87F")
            IInputPaneVisibilityChangedListener : public IInspectable
            {
            public:
                virtual HRESULT STDMETHODCALLTYPE OnFrameworkInputPaneVisibilityChanged(
                    /* [in] */ABI_PARAMETER(Windows::Foundation::Rect) rcInputPane,
                    /* [in] */::boolean isVisible,
                    /* [in] */::boolean ensureFocusedElementInView,
                    /* [in] */::boolean notifyEditFocusLostOnHiding
                    ) = 0;
                
            };

            MIDL_CONST_ID IID & IID_IInputPaneVisibilityChangedListener=_uuidof(IInputPaneVisibilityChangedListener);
            
        } /* FrameworkUdk */
    } /* Internal */
} /* Microsoft */
ABI_NAMESPACE_END

EXTERN_C const IID C_IID(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener);
#endif /* !defined(____x_Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener_INTERFACE_DEFINED__) */


#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener_FWD_DEFINED__
#define ____x_Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener_FWD_DEFINED__
typedef interface C_ABI_PARAMETER(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener) C_ABI_PARAMETER(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener);

#endif // ____x_Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener_FWD_DEFINED__


#pragma warning (push)
#pragma warning (disable:4668) 
#pragma warning (disable:4001) 
#pragma once 
#pragma warning (pop)

/*
 *
 * Interface Microsoft.Internal.FrameworkUdk.IInputPaneVisibilityChangedListener
 *
 */
#if !defined(____x_Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener_INTERFACE_DEFINED__)
#define ____x_Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_Internal_FrameworkUdk_IInputPaneVisibilityChangedListener[] = L"Microsoft.Internal.FrameworkUdk.IInputPaneVisibilityChangedListener";
/* [object, uuid("AC4AF7F8-B273-4AE8-865B-6415380EF87F"), version] */
typedef struct C_ABI_PARAMETER(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListenerVtbl)
{
    BEGIN_INTERFACE
    HRESULT ( STDMETHODCALLTYPE *QueryInterface)(
    __RPC__in C_ABI_PARAMETER(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener) * This,
    /* [in] */ __RPC__in REFIID riid,
    /* [annotation][iid_is][out] */
    _COM_Outptr_  void **ppvObject
    );

ULONG ( STDMETHODCALLTYPE *AddRef )(
    __RPC__in C_ABI_PARAMETER(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener) * This
    );

ULONG ( STDMETHODCALLTYPE *Release )(
    __RPC__in C_ABI_PARAMETER(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener) * This
    );

HRESULT ( STDMETHODCALLTYPE *GetIids )(
    __RPC__in C_ABI_PARAMETER(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener) * This,
    /* [out] */ __RPC__out ULONG *iidCount,
    /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids
    );

HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )(
    __RPC__in C_ABI_PARAMETER(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener) * This,
    /* [out] */ __RPC__deref_out_opt HSTRING *className
    );

HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )(
    __RPC__in C_ABI_PARAMETER(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener) * This,
    /* [OUT ] */ __RPC__out TrustLevel *trustLevel
    );
HRESULT ( STDMETHODCALLTYPE *OnFrameworkInputPaneVisibilityChanged )(
        C_ABI_PARAMETER(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener) * This,
        /* [in] */C_ABI_PARAMETER(Windows_CFoundation_CRect) rcInputPane,
        /* [in] */boolean isVisible,
        /* [in] */boolean ensureFocusedElementInView,
        /* [in] */boolean notifyEditFocusLostOnHiding
        );
    END_INTERFACE
    
} C_ABI_PARAMETER(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListenerVtbl);

interface C_ABI_PARAMETER(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener)
{
    CONST_VTBL struct C_ABI_PARAMETER(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListenerVtbl) *lpVtbl;
};

#ifdef COBJMACROS
#define C_ABI_PARAMETER(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener)_QueryInterface(This,riid,ppvObject) \
( (This)->lpVtbl->QueryInterface(This,riid,ppvObject) )

#define C_ABI_PARAMETER(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener)_AddRef(This) \
        ( (This)->lpVtbl->AddRef(This) )

#define C_ABI_PARAMETER(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener)_Release(This) \
        ( (This)->lpVtbl->Release(This) )

#define C_ABI_PARAMETER(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener)_GetIids(This,iidCount,iids) \
        ( (This)->lpVtbl->GetIids(This,iidCount,iids) )

#define C_ABI_PARAMETER(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener)_GetRuntimeClassName(This,className) \
        ( (This)->lpVtbl->GetRuntimeClassName(This,className) )

#define C_ABI_PARAMETER(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener)_GetTrustLevel(This,trustLevel) \
        ( (This)->lpVtbl->GetTrustLevel(This,trustLevel) )

#define __x_Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener_OnFrameworkInputPaneVisibilityChanged(This,rcInputPane,isVisible,ensureFocusedElementInView,notifyEditFocusLostOnHiding) \
    ( (This)->lpVtbl->OnFrameworkInputPaneVisibilityChanged(This,rcInputPane,isVisible,ensureFocusedElementInView,notifyEditFocusLostOnHiding) )


#endif /* COBJMACROS */


EXTERN_C const IID C_IID(Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener);
#endif /* !defined(____x_Microsoft_CInternal_CFrameworkUdk_CIInputPaneVisibilityChangedListener_INTERFACE_DEFINED__) */


#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
#pragma pop_macro("C_IID")
#pragma pop_macro("ABI_CONCAT")
#pragma pop_macro("ABI_PARAMETER")
#pragma pop_macro("ABI_NAMESPACE_BEGIN")
#pragma pop_macro("ABI_NAMESPACE_END")


#endif // __inputpanelistener_p_h__

#endif // __inputpanelistener_h__
