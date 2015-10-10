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
	/**
	 * 画像回転角である。
	 * 上方向を基点，回転方向は右回りとする。
	 */
	enum ImageRotationalAngle
	{
		/// なし。
		IRA_NONE,

		/// 0 度。
		IRA_0 = IRA_NONE,

		/// 90 度。
		IRA_90,

		/// 180 度。
		IRA_180,

		/// 270 度。
		IRA_270
	};

	/**
	 * 画像エフェクトである。
	 */
	enum ImageEffect
	{
		/// なし。
		IE_NONE,
	};

private:
	/// 画像ファイルの格納場所
	static const TCHAR *IMAGE_PATH;

	/// 牌画像の始点 (X 座標)
	static const size_t TILE_IMAGE_X = 0;

	/// 牌画像の始点 (Y 座標)
	static const size_t TILE_IMAGE_Y = 0;

	/// 色 (mediumseagreen)
	static const COLORREF MEDIUMSEAGREEN = RGB(0x3c, 0xb3, 0x71);


public:
	/// 牌画像の横幅。
	static const size_t TILE_IMAGE_WIDTH = 29;

	/// 牌画像の縦幅。
	static const size_t TILE_IMAGE_HEIGHT = 37;

	/// 牌画像の奥行。
	static const size_t TILE_IMAGE_DEPTH = 20;


private:
	/// 画面端から山までのマージン。
	static const size_t WALL_MARGIN = TILE_IMAGE_HEIGHT + 20;


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
	 * @param[in] dc デバイスコンテキスト。
	 * @param[in] color 色。
	 */
	void fill(CPaintDC &dc, COLORREF color);

	/**
	 * 画像を描画する。
	 *
	 * @param[in] dc デバイスコンテキスト。
	 * @param[in] x 描画位置 (X 座標)。
	 * @param[in] y 描画位置 (Y 座標)。
	 * @param[in] srcX 切り抜き画像始点 (X 座標)。
	 * @param[in] srcY 切り抜き画像始点 (Y 座標)。
	 * @param[in] srcWidth 切り抜き画像の横幅。
	 * @param[in] srcHeight 切り抜き画像の縦幅。
	 * @param[in] rotationalAngle 回転角 (上始点の右回り)。
	 * @param[in] effect エフェクト。
	 */
	void paintImage(CPaintDC &dc, int srcX, int srcY, int srcWidth, int srcHeight, int x, int y, ImageRotationalAngle rotationalAngle, ImageEffect effect);

	/**
	 * 画像を描画する。
	 *
	 * @param[in] dc デバイスコンテキスト。
	 * @param[in] tile 牌。
	 * @param[in] x 描画位置 (X 座標)。
	 * @param[in] y 描画位置 (Y 座標)。
	 */
	void paintImage(CPaintDC &dc, const openriichi::Tile &tile, int x, int y, ImageRotationalAngle rotationalAngle, ImageEffect effect);

	/**
	 * 画像を描画する。
	 *
	 * @param[in] dc デバイスコンテキスト。
	 * @param[in] name 画像名。
	 * @param[in] x 描画位置 (X 座標)。
	 * @param[in] y 描画位置 (Y 座標)。
	 */
	void paintImage(CPaintDC &dc, const std::string &name, int x, int y, ImageRotationalAngle rotationalAngle, ImageEffect effect);

	/**
	 * 初期状態を描画する。
	 *
	 * @param[in] dc デバイスコンテキスト。
	 */
	void paintInitial(CPaintDC &dc);
						
	/**
	 * 山を描画する。
	 *
	 * @param[in] dc デバイスコンテキスト。
	 * @param[in] x 描画位置 (X 座標)。
	 * @param[in] y 描画位置 (Y 座標)。
	 */
	void paintWall(CPaintDC &dc, int x, int y);

	/**
	 * 上家の手牌を描画する。
	 *
	 * @param[in] dc デバイスコンテキスト。
	 * @param[in] x 描画位置 (X 座標)。
	 * @param[in] y 描画位置 (Y 座標)。
	 */
	void paintLeftHand(CPaintDC &dc, int x, int y, bool opened);

	/**
	 * 対面の手牌を描画する。
	 *
	 * @param[in] dc デバイスコンテキスト。
	 * @param[in] x 描画位置 (X 座標)。
	 * @param[in] y 描画位置 (Y 座標)。
	 */
	void paintAcrossHand(CPaintDC &dc, int x, int y, bool opened);

	/**
	 * 対局中状態を描画する。
	 *
	 * @param[in] dc デバイスコンテキスト。
	 */
	void paintPlaying(CPaintDC &dc);


public:
	/**
	 * 描画する。
	 *
	 * @param[in] dc デバイスコンテキスト。
	 */
	void paint(CPaintDC &dc);
};
