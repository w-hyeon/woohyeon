
// gPrjDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "gPrj.h"
#include "gPrjDlg.h"
#include "afxdialogex.h"

#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CgPrjDlg ��ȭ ����



CgPrjDlg::CgPrjDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GPRJ_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgPrjDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CgPrjDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_TEST, &CgPrjDlg::OnBnClickedBtnTest)
	ON_BN_CLICKED(IDC_BTN_MAKE_PATTERN, &CgPrjDlg::OnBnClickedBtnMakePattern)
	ON_BN_CLICKED(IDC_BTN_GET_DATA, &CgPrjDlg::OnBnClickedBtnGetData)
END_MESSAGE_MAP()


// CgPrjDlg �޽��� ó����

BOOL CgPrjDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//ShowWindow(SW_SHOWMAXIMIZED);
	MoveWindow(0, 0, 1280, 800);
	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_DLGIMAGE, this);
	m_pDlgImage->ShowWindow(SW_SHOW);

	m_pDlgImgResult = new CDlgImage;
	m_pDlgImgResult->Create(IDD_DLGIMAGE, this);
	m_pDlgImgResult->ShowWindow(SW_SHOW);
	m_pDlgImgResult->MoveWindow(640, 0, 640, 480);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CgPrjDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CgPrjDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CgPrjDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CgPrjDlg::OnBnClickedBtnDlg()
//{
//	m_pDlgImage->ShowWindow(SW_SHOW);
//}


void CgPrjDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if(m_pDlgImage)		delete m_pDlgImage;
	if(m_pDlgImgResult)	delete m_pDlgImgResult;
}

void CgPrjDlg::callFunc(int n)
{
	std::cout << n << std::endl;
}

void CgPrjDlg::OnBnClickedBtnTest()
{
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();
	memset(fm, 0, nWidth*nHeight);

	for (int k = 0; k < MAX_POINT; k++) {
		int x = rand() % nWidth;
		int y = rand() % nHeight;
		fm[y * nPitch + x] = rand()%0xff;
	}

	int nIndex = 0;
	int nTh = 100;
	for (int j = 0; j < nHeight; j++) {
		for (int i = 0; i < nWidth; i++) {
			if (fm[j*nPitch + i] > nTh) {
				if (m_pDlgImgResult->m_nDataCount < MAX_POINT) {
					m_pDlgImgResult->m_ptData[nIndex].x = i;
					m_pDlgImgResult->m_ptData[nIndex].y = j;
					m_pDlgImgResult->m_nDataCount = ++nIndex;
				}
			}
		}
	}

	m_pDlgImage->Invalidate();
	m_pDlgImgResult->Invalidate();

}

#include "Process.h"
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;


void CgPrjDlg::OnBnClickedBtnMakePattern()
{
	CRect rect(100, 100, 200, 200); 


	int centerX = (rect.left + rect.right) / 2;
	int centerY = (rect.top + rect.bottom) / 2;
	int radius = min(rect.Width(), rect.Height()) / 2;

	CDC* pDC = m_pDlgImage->GetDC();
	CPen pen(PS_SOLID, 3, RGB(255, 255, 0));
	CPen* pOldPen = pDC->SelectObject(&pen);
	pDC->Ellipse(centerX - radius, centerY - radius, centerX + radius, centerY + radius);
	pDC->SelectObject(pOldPen);

	
	for (int y = centerY - radius; y <= centerY + radius; y++) {
		for (int x = centerX - radius; x <= centerX + radius; x++) {
			if ((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY) <= radius * radius) {
				int crossSize = 20; 
				if (abs(y - centerY) <= crossSize || (x - centerX) * (x - centerX) + (y - centerY) * (y - centerY) <= (radius - crossSize) * (radius - crossSize)) {
					pDC->SetPixel(x, y, RGB(255, 0, 0));
				}
				if (abs(x - centerX) <= crossSize || (x - centerX) * (x - centerX) + (y - centerY) * (y - centerY) <= (radius - crossSize) * (radius - crossSize)) {
					pDC->SetPixel(x, y, RGB(255, 0, 0));
				}
			}
		}
	}

	m_pDlgImage->ReleaseDC(pDC);
	m_pDlgImage->Invalidate();
}


void CgPrjDlg::OnBnClickedBtnGetData()
{
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();

	int nTh = 0x80;
	int nSumX = 0;
	int nSumY = 0;
	int nCount = 0;
	CRect rect(0, 0, nWidth, nHeight);
	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			if (fm[j * nPitch + i] > nTh) {
				nSumX += i;
				nSumY += j;
				nCount++;
			}
		}
	}
	double dCenterX = (double)nSumX / nCount;
	double dCenterY = (double)nSumY / nCount;

	cout << dCenterX << "\t" << dCenterY << endl;

	m_pDlgImage->Invalidate();
}
