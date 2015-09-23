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
#include "WrapperdPaintDC.h"


using namespace openriichi;


const TCHAR *WrappedPaintDC::IMAGE_PATH = _T("res/image/main.bmp");
CBitmap *WrappedPaintDC::st_bitmap = nullptr;


WrappedPaintDC::WrappedPaintDC(CWnd *wnd)
	: m_dc(wnd)
{
	if (st_bitmap == nullptr) {
		HBITMAP bitmap = (HBITMAP)LoadImage(nullptr, IMAGE_PATH, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		if (bitmap != nullptr) {
			st_bitmap = CBitmap::FromHandle(bitmap);
			if (st_bitmap == nullptr) {
				DeleteObject(bitmap);
			}
		}
	}
}


void WrappedPaintDC::fill(COLORREF color)
{
	CRect rect;

	m_dc.GetWindow()->GetClientRect(&rect);
	m_dc.FillSolidRect(0, 0, rect.Width(), rect.Height(), color);
}


void WrappedPaintDC::paintTile(const Tile &tile, int x, int y)
{
	int column = 0;
	int row = 0;

	if (st_bitmap == nullptr) {
		return;
	}

	CDC dcImage;
	if (!dcImage.CreateCompatibleDC(&m_dc)) {
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

	CBitmap *oldBitmap = dcImage.SelectObject(st_bitmap);
	m_dc.BitBlt(
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
