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
#include "stdafx.h"
#include "MfcServerView.h"


using namespace openriichi;


const TCHAR *MfcServerView::IMAGE_PATH = _T("res/image/main.bmp");


MfcServerView::MfcServerView(const MfcServerModel &model)
	: m_model(model)
	, m_bitmap(nullptr)
{
	HBITMAP bitmap = (HBITMAP)LoadImage(nullptr, IMAGE_PATH, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	if (bitmap != nullptr) {
		m_bitmap = CBitmap::FromHandle(bitmap);
		if (m_bitmap == nullptr) {
			DeleteObject(bitmap);
		}
	}
}


void MfcServerView::fill(CPaintDC &dc, COLORREF color)
{
	CRect rect;

	dc.GetWindow()->GetClientRect(&rect);
	dc.FillSolidRect(0, 0, rect.Width(), rect.Height(), color);
}


void MfcServerView::paintTile(CPaintDC &dc, const Tile &tile, int x, int y)
{
	int column = 0;
	int row = 0;

	if (m_bitmap == nullptr) {
		return;
	}

	CDC dcImage;
	if (!dcImage.CreateCompatibleDC(&dc)) {
		return;
	}

	int number = tile.getNumber();
	switch (tile.getDesign().getId()) {
	case TileDesigns::CIRCLES_ID:
		column = 0;
		row = number - 1;
		break;

	case TileDesigns::BAMBOO_ID:
		column = 1;
		row = number - 1;
		break;

	case TileDesigns::CHARACTERS_ID:
		column = 2;
		row = number - 1;
		break;

	case TileDesigns::EAST_ID:
		column = 3;
		row = 0;
		break;

	case TileDesigns::SOUTH_ID:
		column = 3;
		row = 1;
		break;

	case TileDesigns::WEST_ID:
		column = 3;
		row = 2;
		break;

	case TileDesigns::NORTH_ID:
		column = 3;
		row = 3;
		break;

	case TileDesigns::RED_ID:
		column = 3;
		row = 4;
		break;

	case TileDesigns::WHITE_ID:
		column = 3;
		row = 5;
		break;

	case TileDesigns::GREEN_ID:
		column = 3;
		row = 6;
		break;
	}

	if (tile.getAttribute() == TileAttributes::RED) {
		row = 9;
	}

	CBitmap *oldBitmap = dcImage.SelectObject(m_bitmap);
	dc.BitBlt(
		x,
		y,
		TILE_IMAGE_WIDTH,
		TILE_IMAGE_HEIGHT,
		&dcImage,
		TILE_IMAGE_X + TILE_IMAGE_WIDTH * row,
		TILE_IMAGE_Y + TILE_IMAGE_HEIGHT * column,
		SRCCOPY);
	dcImage.SelectObject(oldBitmap);
}


void MfcServerView::paintInitial(CPaintDC &dc)
{
	// 背景色を描画する。
	fill(dc, MEDIUMSEAGREEN);

	// タイトルロゴを描画する。
	CRect rect;
	CFont font;
	dc.GetWindow()->GetClientRect(rect);
	font.CreateFont(
		50,										// 縦幅。0 ならデフォルト。
		0,										// 横幅。0 なら縦幅にあった値。
		0,										// 回転角。0.1 度単位。
		0,										// ベースラインと x 軸との角度。0.1 度単位。
		FW_BOLD,								// 太さ。
		TRUE,									// イタリック。
		FALSE,									// 下線。
		FALSE,									// 取り消し線。
		DEFAULT_CHARSET,						// 文字セット。日本語の場合は SHIFTJIS_CHARSET を指定する。
		OUT_DEFAULT_PRECIS,						// 出力精度。
		CLIP_DEFAULT_PRECIS,					// クリッピング制度
		PROOF_QUALITY,							// 出力品質。
		FIXED_PITCH | FF_MODERN,				// ピッチとファミリー。
		_T("Century"));							// タイプフェイス。
	CFont *oldFont = dc.SelectObject(&font);
	dc.TextOutW(-125 + rect.Width() / 2, -40 + rect.Height() / 2, CString("OpenRiichi"));
	dc.SelectObject(oldFont);
}


void MfcServerView::paintPlaying(CPaintDC &dc)
{
	// 背景色を描画する。
	fill(dc, MEDIUMSEAGREEN);

	const Hand &hand = m_model.table().getPlayerInfo(Winds::EAST).getHand();
	for (size_t i = 0; i < hand.getTiles().size(); ++i)
	{
		paintTile(dc, hand.getTiles()[i], 10 + TILE_IMAGE_WIDTH * static_cast<int>(i), 10);
	}
}


void MfcServerView::paint(CPaintDC &dc)
{
	switch (m_model.getGameStatus()) {
	case MfcServerModel::INITIAL:
		paintInitial(dc);
		break;

	case MfcServerModel::PLAYING:
		paintPlaying(dc);
		break;
	}
}
