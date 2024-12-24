
// MFC-demo-2019View.cpp: implementación de la clase CMFCdemo2019View
//

#include "pch.h"
#include "framework.h"
// Se pueden definir SHARED_HANDLERS en un proyecto ATL implementando controladores de vista previa, miniatura
// y filtro de búsqueda, y permiten compartir código de documentos con ese proyecto.
#ifndef SHARED_HANDLERS
#include "MFC-demo-2019.h"
#endif

#include "MFC-demo-2019Doc.h"
#include "MFC-demo-2019View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCdemo2019View

IMPLEMENT_DYNCREATE(CMFCdemo2019View, CView)

BEGIN_MESSAGE_MAP(CMFCdemo2019View, CView)
	// Comandos de impresión estándar
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCdemo2019View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Construcción o destrucción de CMFCdemo2019View

CMFCdemo2019View::CMFCdemo2019View() noexcept
{
	// TODO: agregar aquí el código de construcción

}

CMFCdemo2019View::~CMFCdemo2019View()
{
}

BOOL CMFCdemo2019View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modificar aquí la clase Window o los estilos cambiando
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Dibujo de CMFCdemo2019View

void CMFCdemo2019View::OnDraw(CDC* /*pDC*/)
{
	CMFCdemo2019Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: agregar aquí el código de dibujo para datos nativos
}


// Impresión de CMFCdemo2019View


void CMFCdemo2019View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCdemo2019View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Preparación predeterminada
	return DoPreparePrinting(pInfo);
}

void CMFCdemo2019View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: agregar inicialización adicional antes de imprimir
}

void CMFCdemo2019View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: agregar limpieza después de imprimir
}

void CMFCdemo2019View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCdemo2019View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Diagnósticos de CMFCdemo2019View

#ifdef _DEBUG
void CMFCdemo2019View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCdemo2019View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCdemo2019Doc* CMFCdemo2019View::GetDocument() const // La versión de no depuración está alineada
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCdemo2019Doc)));
	return (CMFCdemo2019Doc*)m_pDocument;
}
#endif //_DEBUG


// Controladores de mensajes de CMFCdemo2019View
