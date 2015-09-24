/*
 * Copyright 2015 calotocen
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
// MfcServerDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "MfcServer.h"
#include "MfcServerDlg.h"
#include "afxdialogex.h"
#include "WrapperdPaintDC.h"


using namespace openriichi;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
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


// CMfcServerDlg ダイアログ



CMfcServerDlg::CMfcServerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCSERVER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMfcServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMfcServerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_ABOUT_MENUITEM, &CMfcServerDlg::OnAboutMenuitem)
	ON_COMMAND(ID_QUIT_MENUITEM, &CMfcServerDlg::OnQuitMenuitem)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CMfcServerDlg メッセージ ハンドラー

BOOL CMfcServerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CMfcServerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		WrappedPaintDC dc(this);

		// 背景色を描画する。
		dc.fill(RGB(0x3c, 0xb3, 0x71));

		// 試しに画像を表示する。
		int weightX = WrappedPaintDC::TILE_IMAGE_WIDTH + 5;
		int weightY = WrappedPaintDC::TILE_IMAGE_HEIGHT + 5;
		dc.paintTile(P1, 10 + weightX * 0, 10 + weightY * 0);
		dc.paintTile(P2, 10 + weightX * 1, 10 + weightY * 0);
		dc.paintTile(P3, 10 + weightX * 2, 10 + weightY * 0);
		dc.paintTile(P4, 10 + weightX * 3, 10 + weightY * 0);
		dc.paintTile(P5, 10 + weightX * 4, 10 + weightY * 0);
		dc.paintTile(P6, 10 + weightX * 5, 10 + weightY * 0);
		dc.paintTile(P7, 10 + weightX * 6, 10 + weightY * 0);
		dc.paintTile(P8, 10 + weightX * 7, 10 + weightY * 0);
		dc.paintTile(P9, 10 + weightX * 8, 10 + weightY * 0);
		dc.paintTile(P5R, 10 + weightX * 9, 10 + weightY * 0);
		dc.paintTile(S1, 10 + weightX * 0, 10 + weightY * 1);
		dc.paintTile(S2, 10 + weightX * 1, 10 + weightY * 1);
		dc.paintTile(S3, 10 + weightX * 2, 10 + weightY * 1);
		dc.paintTile(S4, 10 + weightX * 3, 10 + weightY * 1);
		dc.paintTile(S5, 10 + weightX * 4, 10 + weightY * 1);
		dc.paintTile(S6, 10 + weightX * 5, 10 + weightY * 1);
		dc.paintTile(S7, 10 + weightX * 6, 10 + weightY * 1);
		dc.paintTile(S8, 10 + weightX * 7, 10 + weightY * 1);
		dc.paintTile(S9, 10 + weightX * 8, 10 + weightY * 1);
		dc.paintTile(S5R, 10 + weightX * 9, 10 + weightY * 1);
		dc.paintTile(M1, 10 + weightX * 0, 10 + weightY * 2);
		dc.paintTile(M2, 10 + weightX * 1, 10 + weightY * 2);
		dc.paintTile(M3, 10 + weightX * 2, 10 + weightY * 2);
		dc.paintTile(M4, 10 + weightX * 3, 10 + weightY * 2);
		dc.paintTile(M5, 10 + weightX * 4, 10 + weightY * 2);
		dc.paintTile(M6, 10 + weightX * 5, 10 + weightY * 2);
		dc.paintTile(M7, 10 + weightX * 6, 10 + weightY * 2);
		dc.paintTile(M8, 10 + weightX * 7, 10 + weightY * 2);
		dc.paintTile(M9, 10 + weightX * 8, 10 + weightY * 2);
		dc.paintTile(M5R, 10 + weightX * 9, 10 + weightY * 2);
		dc.paintTile(TN, 10 + weightX * 0, 10 + weightY * 3);
		dc.paintTile(NN, 10 + weightX * 1, 10 + weightY * 3);
		dc.paintTile(SH, 10 + weightX * 2, 10 + weightY * 3);
		dc.paintTile(PE, 10 + weightX * 3, 10 + weightY * 3);
		dc.paintTile(HK, 10 + weightX * 4, 10 + weightY * 3);
		dc.paintTile(HT, 10 + weightX * 5, 10 + weightY * 3);
		dc.paintTile(CH, 10 + weightX * 6, 10 + weightY * 3);

		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CMfcServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMfcServerDlg::OnAboutMenuitem()
{
	CAboutDlg dlgAbout;

	dlgAbout.DoModal();
}


void CMfcServerDlg::OnQuitMenuitem()
{
	OnCancel();
}


void CMfcServerDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CDialogEx::OnMouseMove(nFlags, point);
}
