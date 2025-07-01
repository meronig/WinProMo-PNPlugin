#include "StdAfx.h"
#include "WPPNDoc.h"
#include "PNEditor/WPPNControlFactory.h"

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

void CWPPNDoc::CreateControlFactory()
{
	if (!m_fact) {
		m_fact = new CWPPNControlFactory;
	}
}
