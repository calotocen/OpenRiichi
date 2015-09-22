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
// MfcServerView.cpp : CMfcServerView クラスの実装
//

#include "stdafx.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "MfcServer.h"
#endif

#include "MfcServerDoc.h"
#include "MfcServerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMfcServerView

IMPLEMENT_DYNCREATE(CMfcServerView, CView)

BEGIN_MESSAGE_MAP(CMfcServerView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMfcServerView コンストラクション/デストラクション

CMfcServerView::CMfcServerView()
{
	// TODO: 構築コードをここに追加します。

}

CMfcServerView::~CMfcServerView()
{
}

BOOL CMfcServerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CMfcServerView 描画

void CMfcServerView::OnDraw(CDC* /*pDC*/)
{
	CMfcServerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}

void CMfcServerView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMfcServerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMfcServerView 診断

#ifdef _DEBUG
void CMfcServerView::AssertValid() const
{
	CView::AssertValid();
}

void CMfcServerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMfcServerDoc* CMfcServerView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMfcServerDoc)));
	return (CMfcServerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMfcServerView メッセージ ハンドラー
