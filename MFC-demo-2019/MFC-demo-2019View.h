
// MFC-demo-2019View.h: interfaz de la clase CMFCdemo2019View
//

#pragma once


class CMFCdemo2019View : public CView
{
protected: // Crear sólo a partir de serialización
	CMFCdemo2019View() noexcept;
	DECLARE_DYNCREATE(CMFCdemo2019View)

// Atributos
public:
	CMFCdemo2019Doc* GetDocument() const;

// Operaciones
public:

// Reemplazos
public:
	virtual void OnDraw(CDC* pDC);  // Reemplazado para dibujar esta vista
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementación
public:
	virtual ~CMFCdemo2019View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funciones de asignación de mensajes generadas
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Versión de depuración en MFC-demo-2019View.cpp
inline CMFCdemo2019Doc* CMFCdemo2019View::GetDocument() const
   { return reinterpret_cast<CMFCdemo2019Doc*>(m_pDocument); }
#endif

