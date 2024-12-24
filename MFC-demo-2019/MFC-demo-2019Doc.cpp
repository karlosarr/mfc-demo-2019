
// MFC-demo-2019Doc.cpp: implementación de la clase CMFCdemo2019Doc
//

#include "pch.h"
#include "framework.h"
// Se pueden definir SHARED_HANDLERS en un proyecto ATL implementando controladores de vista previa, miniatura
// y filtro de búsqueda, y permiten compartir código de documentos con ese proyecto.
#ifndef SHARED_HANDLERS
#include "MFC-demo-2019.h"
#endif

#include "MFC-demo-2019Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCdemo2019Doc

IMPLEMENT_DYNCREATE(CMFCdemo2019Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCdemo2019Doc, CDocument)
END_MESSAGE_MAP()


// Construcción o destrucción de CMFCdemo2019Doc

CMFCdemo2019Doc::CMFCdemo2019Doc() noexcept
{
	// TODO: agregar aquí el código de construcción único

}

CMFCdemo2019Doc::~CMFCdemo2019Doc()
{
}

BOOL CMFCdemo2019Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: agregar aquí código de reinicio
	// (los documentos SDI volverán a utilizar este documento)

	return TRUE;
}




// Serialización de CMFCdemo2019Doc

void CMFCdemo2019Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: agregar aquí el código de almacenamiento
	}
	else
	{
		// TODO: agregar aquí el código de carga
	}
}

#ifdef SHARED_HANDLERS

// Compatibilidad con miniaturas
void CMFCdemo2019Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modifique este código para dibujar los datos del documento
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Compatibilidad con controladores de búsqueda
void CMFCdemo2019Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Establezca contenido de búsqueda a partir de los datos del documento.
	// Las partes de contenido deben ir separadas por ";"

	// Por ejemplo:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCdemo2019Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Diagnósticos de CMFCdemo2019Doc

#ifdef _DEBUG
void CMFCdemo2019Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCdemo2019Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Comandos de CMFCdemo2019Doc
