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
#pragma once


#include "MfcServerModel.h"


/**
 * ラップしたデバイスコンテキストである。
 */
class MfcServerView
{
private:
	/// 画像ファイルの格納場所
	static const TCHAR *IMAGE_PATH;

	/// 牌画像の始点 (X 座標)
	static const size_t TILE_IMAGE_X = 0;

	/// 牌画像の始点 (Y 座標)
	static const size_t TILE_IMAGE_Y = 0;


public:
	/// 牌画像の横幅。
	static const size_t TILE_IMAGE_WIDTH = 29;

	/// 牌画像の縦幅。
	static const size_t TILE_IMAGE_HEIGHT = 37;


private:
	/// モデル。
	const MfcServerModel &m_model;

	/// ビットマップ。
	CBitmap *m_bitmap;


public:
	/**
	 * ラップしたデバイスコンテキストを生成する。
	 *
	 * @param[in] wnd ウィンドウ。
	 * @note 本コンストラクタは，マルチスレッド非対応である。
	 *       マルチスレッド環境下で，本コンストラクタを実行しないこと。
	 */
	explicit MfcServerView(const MfcServerModel &model);


private:
	/**
	 * 画面全体を指定された色で塗りつぶす。
	 *
	 * @param[in] color 色。
	 */
	void fill(CPaintDC &dc, COLORREF color);

	/**
	 * 牌を描画する。
	 *
	 * @param[in] tile 牌。
	 * @param[in] x 描画位置 (X 座標)。
	 * @param[in] y 描画位置 (Y 座標)。
	 */
	void paintTile(CPaintDC &dc, const openriichi::Tile &tile, int x, int y);


public:
	/**
	 * モデルを描画する。
	 */
	void paint(CPaintDC &dc);
};
