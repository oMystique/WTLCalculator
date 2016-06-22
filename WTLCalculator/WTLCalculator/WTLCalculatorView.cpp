// WTLCalculatorView.cpp : implementation of the CWTLCalculatorView class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"

#include "WTLCalculatorView.h"

CWTLCalculatorView::CWTLCalculatorView()
{
	m_chars = {
		{ID_0_BUTTON, '0'},
		{ID_1_BUTTON, '1'},
		{ID_2_BUTTON, '2'},
		{ID_3_BUTTON, '3'},
		{ID_4_BUTTON, '4'},
		{ID_5_BUTTON, '5'},
		{ID_6_BUTTON, '6'},
		{ID_7_BUTTON, '7'},
		{ID_8_BUTTON, '8'},
		{ID_9_BUTTON, '9'}
	};
}

BOOL CWTLCalculatorView::PreTranslateMessage(MSG* pMsg)
{
	//if (::GetDlgCtrlID(pMsg->hwnd) == ID_0_BUTTON && pMsg->message == WM_LBUTTONDOWN)
	//{
	//};

	auto current = m_calcLogic.GetCurrentValue();
	if (current)
	{

		BSTR text;
		m_calcDisplay.GetWindowTextW(text);
		if (current.get() != text)
		{

		}
	}
	else
	{
		m_calcDisplay.SetWindowTextW(L"0");
	}
	//if (pMsg->message == WM_MOUSEMOVE && (pMsg->wParam & MK_LBUTTON))
	//{
	//	CPoint p;
	//	GetCursorPos(&p);
	//	CRect r;
	//	GetWindowRect(&r);
	//	if (r.PtInRect(p))
	//	{
	//		ReleaseCapture();
	//		MessageBox(L"LOOL");
	//		return 1;
	//	}
	//}

	return CWindow::IsDialogMessage(pMsg);
}

LRESULT CWTLCalculatorView::OnCreate(UINT, WPARAM, LPARAM, BOOL &)
{
	m_calcDisplay.Create(*this, CRect(10, 50, 200, 100), 0, WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER | WS_DISABLED | ES_WANTRETURN | ES_READONLY | ES_NOHIDESEL);

	CreateButton(CRect(10, 125, 50, 165), "7", ID_7_BUTTON);
	CreateButton(CRect(60, 125, 100, 165), "8", ID_8_BUTTON);
	CreateButton(CRect(110, 125, 150, 165), "9", ID_9_BUTTON);
	CreateButton(CRect(160, 125, 200, 165), "/", ID_DIV_BUTTON);
	CreateButton(CRect(10, 175, 50, 215), "4", ID_4_BUTTON);
	CreateButton(CRect(60, 175, 100, 215), "5", ID_5_BUTTON);
	CreateButton(CRect(110, 175, 150, 215), "6", ID_6_BUTTON);
	CreateButton(CRect(160, 175, 200, 215), "*", ID_MULTIPLY_BUTTON);
	CreateButton(CRect(10, 225, 50, 265), "1", ID_1_BUTTON);
	CreateButton(CRect(60, 225, 100, 265), "2", ID_2_BUTTON);
	CreateButton(CRect(110, 225, 150, 265), "3", ID_3_BUTTON);
	CreateButton(CRect(160, 225, 200, 265), "-", ID_MINUS_BUTTON);
	CreateButton(CRect(10, 275, 100, 315), "0", ID_0_BUTTON);
	CreateButton(CRect(110, 275, 150, 315), "C", ID_CLEAR_BUTTON);
	CreateButton(CRect(160, 275, 200, 315), "+", ID_PLUS_BUTTON);

	return 0;
}

void CWTLCalculatorView::CreateButton(CRect rect, const char * buttonName, UINT id)
{
	CButton button;
	button.Create(*this, rect, LPCTSTR(buttonName), WS_CHILD |
		WS_VISIBLE, WS_EX_CLIENTEDGE , id);
}

LRESULT CWTLCalculatorView::OnInsertNumber(UINT /*uMsg*/, WPARAM /*wParam*/, HWND /*lParam*/, BOOL& /*bHandled*/)
{
	MessageBox(L"Loool");
		
	return 1;
}
