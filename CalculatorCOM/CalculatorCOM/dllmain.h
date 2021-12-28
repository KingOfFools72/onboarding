// dllmain.h : Declaration of module class.

class CCalculatorCOMModule : public ATL::CAtlDllModuleT< CCalculatorCOMModule >
{
public :
	DECLARE_LIBID(LIBID_CalculatorCOMLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CALCULATORCOM, "{5ce12cce-e619-45b4-ba61-5e5e11724659}")
};

extern class CCalculatorCOMModule _AtlModule;
