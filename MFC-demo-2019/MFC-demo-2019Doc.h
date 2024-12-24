
// MFC-demo-2019Doc.h: interfaz de la clase CMFCdemo2019Doc
//


#pragma once


class CMFCdemo2019Doc : public CDocument
{
protected: // Crear sólo a partir de serialización
	CMFCdemo2019Doc() noexcept;
	DECLARE_DYNCREATE(CMFCdemo2019Doc)

// Atributos
public:

// Operaciones
public:

// Reemplazos
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementación
public:
	virtual ~CMFCdemo2019Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funciones de asignación de mensajes generadas
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Función del asistente que establece contenido de búsqueda para un controlador de búsqueda
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
