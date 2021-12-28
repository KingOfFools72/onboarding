// CalculaorOutCOM.cpp : Implementation of WinMain


#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "CalculaorOutCOM_i.h"


using namespace ATL;


class CCalculaorOutCOMModule : public ATL::CAtlExeModuleT< CCalculaorOutCOMModule >
{
public :
	DECLARE_LIBID(LIBID_CalculaorOutCOMLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CALCULAOROUTCOM, "{8dd22155-99e0-481e-ad26-3b5b63fd556d}")
};

CCalculaorOutCOMModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/,
								LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	return _AtlModule.WinMain(nShowCmd);
}

