// dllmain.h : Declaration of module class.

class CScalableCalculatorCOMEventsModule : public ATL::CAtlDllModuleT< CScalableCalculatorCOMEventsModule >
{
public :
	DECLARE_LIBID(LIBID_ScalableCalculatorCOMEventsLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SCALABLECALCULATORCOMEVENTS, "{08760004-aed2-4f9b-9f2d-db519096ca78}")
};

extern class CScalableCalculatorCOMEventsModule _AtlModule;
