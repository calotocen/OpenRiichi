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


#include <cstdint>
#include "Tile.h"


namespace openriichi
{
	class DiscardSource;


	/**
	 * 省メモリの捨て牌である。
	 */
	class MemorySavedDiscard
	{
	private:
		/**
		 * 鳴かれたか牌であるかを表す値である。
		 */
		enum TakenValue
		{
			/// 鳴かれた牌ではない。
			TV_FALSE = 0x00,

			/// 鳴かれた牌である。
			TV_TRUE = 0x01,
		};

		/**
		 * 立直宣言牌であるかを表す値である。
		 */
		enum RiichiDeclaredValue
		{
			/// 立直宣言牌ではない。
			RDV_FALSE = 0x00,

			/// 立直宣言牌である。
			RDV_TRUE = 0x02,
		};

		/**
		 * 捨て元を表す値である。
		 */
		enum SourceValue : uint8_t
		{
			/// ツモ牌 (ツモ切り)。
			DRAWED = 0x04,

			/// 手持ち牌 (手出し)。
			HELD = 0x08,
		};

		/**
		 * マスクである。
		 */
		enum Mask : uint8_t
		{
			/// 鳴かれたかを表す値のマスク。
			TAKEN = 0x01,

			/// 立直宣言かを表す値のマスク。
			RIICHI_DECLARED = 0x02,

			/// 捨て元値のマスク。
			SOURCE = 0x0c,
		};


	private:
		/**
		 * 捨て牌の属性を表す値。
		 * 値の構成は次の通りである (ビットの番号は最上位を 1 番目，最下位を 8 番目とする)。
		 *     - 1 ～ 4 ビット目 ... 予約 (常に 0)。
		 *     - 5 ～ 6 ビット目 ... 捨て元。
		 *     - 7 ビット目      ... 立直宣言牌か。
		 *     - 8 ビット目      ... 鳴かれた牌か。
		 */
		uint8_t m_value;

		/**
		 * 捨て牌。
		 */
		Tile m_tile;


	public:
		/**
		 * ツモ切りした一筒の捨て牌を生成する。
		 */
		MemorySavedDiscard();

		/**
		 * 捨て牌を生成する。
		 *
		 * @param[in] tile 牌。
		 * @param[in] source 捨て元。
		 * @param[in] riichiDeclared 立直宣言牌か。
		 *                           立直宣言牌である場合は true，それ以外は false を指定する。
		 * @param[in] taken 鳴かれた牌か。
		 *                  鳴かれた牌である場合は true，それ以外は false を指定する。
		 */
		MemorySavedDiscard(const Tile &tile, const DiscardSource &source, bool riichiDeclared = false, bool taken = false);

		/**
		 * 牌を返す。
		 *
		 * @return 牌。
		 */
		const Tile &getTile() const;

		/**
		 * 捨て元を返す。
		 *
		 * @return 捨て元。
		 */
		const DiscardSource &getSource() const;

		/**
		 * 立直宣言牌であるかを返す。
		 *
		 * @retval true 立直宣言牌であった。
		 * @retval false 立直宣言牌ではなかった。
		 */
		bool isRiichiDeclared() const;

		/**
		 * 鳴かれた牌であるかを返す。
		 *
		 * @return true 鳴かれた牌であった。
		 * @return false 鳴かれた牌ではなかった。
		 */
		bool isTaken() const;
	};
}
