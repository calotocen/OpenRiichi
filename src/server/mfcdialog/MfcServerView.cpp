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


using namespace std;
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


void MfcServerView::paintImage(CPaintDC &dc, int srcX, int srcY, int srcWidth, int srcHeight, int x, int y, ImageRotationalAngle rotationalAngle, ImageEffect effect)
{
	CDC dcImage;
	if (!dcImage.CreateCompatibleDC(&dc)) {
		return;
	}

	CBitmap *oldBitmap = dcImage.SelectObject(m_bitmap);
	if (rotationalAngle == IRA_NONE) {
		dc.BitBlt(
			x,
			y,
			srcWidth,
			srcHeight,
			&dcImage,
			srcX,
			srcY,
			SRCCOPY);
	} else {
		POINT points[3] = { 0 };

		switch (rotationalAngle) {
		case IRA_90:
			points[0].x = x + srcHeight;
			points[0].y = y;
			points[1].x = x + srcHeight;
			points[1].y = y + srcWidth;
			points[2].x = x;
			points[2].y = y;
			break;

		case IRA_180:
			// 描画位置を (x, y) に合わせるためには，なぜか -1 しないといけない。
			// (0, 0) に描画する場合，PlgBlt には (-1, -1) に描画するよう指定することになるが，
			// エラーになることなく (0, 0) の位置に描画される。
			points[0].x = x + srcWidth - 1;
			points[0].y = y + srcHeight - 1;
			points[1].x = x - 1;
			points[1].y = y + srcHeight - 1;
			points[2].x = x + srcWidth - 1;
			points[2].y = y - 1;
#if 0
			points[0].x = x + srcWidth;
			points[0].y = y + srcHeight;
			points[1].x = x;
			points[1].y = y + srcHeight;
			points[2].x = x + srcWidth;
			points[2].y = y;
#endif
			break;

		case IRA_270:
			points[0].x = x;
			points[0].y = y + srcWidth;
			points[1].x = x;
			points[1].y = y;
			points[2].x = x + srcHeight;
			points[2].y = y + srcWidth;
			break;
		}

		dc.PlgBlt(points, &dcImage, srcX, srcY, srcWidth, srcHeight, CBitmap(), 0, 0);
	}
	dcImage.SelectObject(oldBitmap);
}


void MfcServerView::paintImage(CPaintDC &dc, const Tile &tile, int x, int y, ImageRotationalAngle rotationalAngle, ImageEffect effect)
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

	paintImage(
		dc,
		TILE_IMAGE_X + TILE_IMAGE_WIDTH * row,
		TILE_IMAGE_Y + TILE_IMAGE_HEIGHT * column,
		TILE_IMAGE_WIDTH,
		TILE_IMAGE_HEIGHT,
		x,
		y,
		rotationalAngle,
		effect);
}


void MfcServerView::paintImage(CPaintDC &dc, const string &name, int x, int y, ImageRotationalAngle rotationalAngle, ImageEffect effect)
{
	int srcX = 0;
	int srcY = 0;
	int srcWidth = 0;
	int srcHeight = 0;

	if (name == "Rear") {
		srcX = 203;
		srcY = 111;
		srcWidth = TILE_IMAGE_WIDTH;
		srcHeight = TILE_IMAGE_HEIGHT;
	} else if (name == "Stack") {
		srcX = 232;
		srcY = 111;
		srcWidth = TILE_IMAGE_WIDTH;
		srcHeight = TILE_IMAGE_HEIGHT;
	} else if (name == "Side") {
		srcX = 261;
		srcY = 111;
		srcWidth = TILE_IMAGE_WIDTH;
		srcHeight = TILE_IMAGE_DEPTH;
	}

	paintImage(
		dc,
		srcX,
		srcY,
		srcWidth,
		srcHeight,
		x,
		y,
		rotationalAngle,
		effect);
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


void MfcServerView::paintWall(CPaintDC &dc, int x, int y)
{
	// TODO: 東家の位置に応じて山の描画を変更するようにする。
	// TODO: ドラ表示牌を表示する。
	// TODO: 王牌の切れ目を表示する。
	const Wall &wall = m_model.table().wall();
	auto paint = [&](CPaintDC &dc, bool upper, bool lower, int x, int y, ImageRotationalAngle rotationalAngle) {
		const char *name = nullptr;

		if (!lower) {
			name = "Stack";
		} else if (!upper) {
			name = "Rear";
		} else {
			name = "Rear";
		}

		if (name != nullptr) {
			paintImage(dc, name, x, y, rotationalAngle, IE_NONE);
		}
	};

	for (auto i = 0; i < 4; ++i) {
		for (auto j = 0, k = static_cast<int>(wall.TILES_SIZE) / 4 * i; j < wall.TILES_SIZE / 8; ++j, k += 2) {
			switch (i) {
			case 0:
				paint(
					dc,
					wall.isDrawed(k),
					wall.isDrawed(k + 1),
					TILE_IMAGE_WIDTH * (wall.TILES_SIZE / 8 - j - 1) + (TILE_IMAGE_HEIGHT + x),
					TILE_IMAGE_WIDTH * (wall.TILES_SIZE / 8) + y,
					IRA_NONE);
				break;

			case 1:
				paint(
					dc,
					wall.isDrawed(k),
					wall.isDrawed(k + 1),
					x,
					TILE_IMAGE_WIDTH * (wall.TILES_SIZE / 8 - j - 1) + (TILE_IMAGE_HEIGHT + y),
					IRA_90);
				break;

			case 2:
				paint(
					dc,
					wall.isDrawed(k),
					wall.isDrawed(k + 1),
					TILE_IMAGE_WIDTH * j + x,
					y,
					IRA_180);
				break;

			case 3:
				paint(
					dc,
					wall.isDrawed(k),
					wall.isDrawed(k + 1),
					(TILE_IMAGE_WIDTH * (wall.TILES_SIZE / 8)) + x,
					TILE_IMAGE_WIDTH * j + y,
					IRA_270);
				break;
			}
		}
	}
}


void MfcServerView::paintLeftHand(CPaintDC & dc, int x, int y, bool opened)
{
	// TODO: 自家に応じた手牌を取得するよう変更する。
	const Hand &hand = m_model.table().getPlayerInfo(Winds::NORTH).hand();
	const Hand::Tiles tiles = hand.tiles();

	for (size_t i = 0; i < tiles.size(); ++i) {
		int dstX = x;
		int dstY = y + TILE_IMAGE_WIDTH * static_cast<int>(i);
		if (opened) {
			paintImage(dc, tiles[i], dstX, dstY, IRA_90, IE_NONE);
		} else {
			paintImage(dc, "Side", dstX, dstY, IRA_90, IE_NONE);
		}
	}

	// TODO: 鳴き面子を表示する。
}


void MfcServerView::paintAcrossHand(CPaintDC &dc, int x, int y, bool opened)
{
	// TODO: 自家に応じた手牌を取得するよう変更する。
	const Hand &hand = m_model.table().getPlayerInfo(Winds::WEST).hand();
	const Hand::Tiles tiles = hand.tiles();

	int marginX = TILE_IMAGE_WIDTH * 4 + TILE_IMAGE_HEIGHT + WALL_MARGIN;
	for (size_t i = 0; i < tiles.size(); ++i) {
		int dstX = x + TILE_IMAGE_WIDTH * static_cast<int>(i) + marginX;
		int dstY = y;
		if (opened) {
			paintImage(dc, tiles[i], dstX, dstY, IRA_180, IE_NONE);
		} else {
			paintImage(dc, "Side", dstX, dstY, IRA_180, IE_NONE);
		}
	}

	// TODO: 鳴き面子を表示する。
}


void MfcServerView::paintPlaying(CPaintDC &dc)
{
	// 背景色を描画する。
	fill(dc, MEDIUMSEAGREEN);

	// 山を描画する。
	paintWall(dc, WALL_MARGIN, WALL_MARGIN);

	// 上家の手牌を描画する。
	paintLeftHand(dc, 0, WALL_MARGIN, true);


	// 対面の手牌を描画する。
	paintAcrossHand(dc, 0, 0, true);
#if 0
	Wind winds[] = { Winds::EAST, Winds::SOUTH, Winds::WEST, Winds::NORTH };
	for (size_t y = 0; y < sizeof(winds) / sizeof(*winds); ++y) {
		const Hand &hand = m_model.table().getPlayerInfo(winds[y]).getHand();
		for (size_t x = 0; x < hand.getTiles().size(); ++x)
		{
			paintImage(dc, hand.getTiles()[x], 10 + TILE_IMAGE_WIDTH * static_cast<int>(x), 10 + TILE_IMAGE_HEIGHT * static_cast<int>(y));
		}
	}
	paintImage(dc, "Stack", 10 + TILE_IMAGE_WIDTH * 1, 10 + TILE_IMAGE_HEIGHT * 4);
	paintImage(dc, "Side", 10 + TILE_IMAGE_WIDTH * 2, 10 + TILE_IMAGE_HEIGHT * 4);
#endif
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
