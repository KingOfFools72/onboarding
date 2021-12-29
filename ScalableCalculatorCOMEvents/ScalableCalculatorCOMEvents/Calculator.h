// Calculator.h : Declaration of the CCalculator

#pragma once
#include "resource.h"       // main symbols
#include "_ICalculatorEvents_CP.h"

#include <memory>

#import "ScalableCalculatorCOMEvents.tlb" raw_interfaces_only

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;
using namespace ScalableCalculatorCOMEventsLib;

// CCalculator

class ATL_NO_VTABLE CCalculator :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCalculator, &__uuidof(Calculator)>,
	public IConnectionPointContainerImpl<CCalculator>,
	public CProxy_ICalculatorEvents<CCalculator>,
	public IDispatchImpl<ICalculator, &__uuidof(ICalculator), &__uuidof(__ScalableCalculatorCOMEventsLib), /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CCalculator()
	{

	}

	DECLARE_REGISTRY_RESOURCEID(106)


	BEGIN_COM_MAP(CCalculator)
		COM_INTERFACE_ENTRY(ICalculator)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(CCalculator)
		CONNECTION_POINT_ENTRY(__uuidof(_ICalculatorEvents))
	END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	STDMETHOD(Compute)(CHAR action, LONGLONG lhs, LONGLONG rhs, LONGLONG* res);

};

OBJECT_ENTRY_AUTO(__uuidof(Calculator), CCalculator)
