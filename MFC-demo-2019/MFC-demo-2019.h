
// MFC-demo-2019.h: archivo de encabezado principal para la aplicación MFC-demo-2019
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'pch.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"       // Símbolos principales


// CMFCdemo2019App:
// Consulte MFC-demo-2019.cpp para obtener información sobre la implementación de esta clase
//

class CMFCdemo2019App : public CWinAppEx
{
public:
	CMFCdemo2019App() noexcept;


// Reemplazos
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementación
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCdemo2019App theApp;
