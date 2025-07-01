#include "StdAfx.h"
#include "WPPNDoc.h"

IMPLEMENT_DYNCREATE(CWPPNDoc, CWinProMoDoc)

CWPPNDoc::CWPPNDoc()
{
	
}

CWPPNDoc::~CWPPNDoc()
{

}

void CWPPNDoc::CreateContainer()
{
	if (!m_objs) {
		m_objs = new CProMoEntityContainer("pnPlugin");
	}
}
