
// MFC_projectDoc.h : interface of the CPaintAppDoc class
//


#pragma once

class CPaintAppDoc : public CDocument
{
protected: // create from serialization only
	CPaintAppDoc();
	DECLARE_DYNCREATE(CPaintAppDoc)

// Attributes
public:

// Operations
public:
	int m_Width;
	int m_Height;
// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CPaintAppDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
