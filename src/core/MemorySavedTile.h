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


#include "Tile.h"
#include "TileAttributes.h"


namespace openriichi {
	class TileDesign;


	/**
	 * 省メモリの牌である。
	 *
	 * 本牌が扱える図柄，数字，および属性は次の通りである。
	 *     - 図柄 ... 筒子，索子，萬子，東，南，西，北，中，發，および白。
	 *     - 数字 ... 1 以上 9 以下。
	 *     - 属性 ... 属性なし，および赤。赤は数牌にのみ指定可。
	 */
	class MemorySavedTile {
	private:
		/**
		 * 図柄値である。
		 */
		enum DesignValue : unsigned char
		{
			/// 筒子。
			CIRCLES = 0x10,

			/// 索子。
			BAMBOO = 0x20,

			/// 萬子。
			CHARACTERS = 0x30,

			/// 東。
			EAST = 0x41,

			/// 南。
			SOUTH = 0x42,

			/// 西。
			WEST = 0x43,

			/// 北。
			NORTH = 0x44,

			/// 中。
			DV_RED = 0x51,

			/// 發。
			GREEN = 0x52,

			/// 白。
			WHITE = 0x53,
		};

		/**
		 * 属性値である。
		 */
		enum AttributeValue : unsigned char
		{
			/// 属性なし。
			NONE = 0x00,

			/// 赤。
			AV_RED = 0x80,
		};

		/**
		 * マスクである。
		 */
		enum Mask : unsigned char
		{
			/**
			 * 図柄種別のマスク。
			 * 数牌に適用した場合は，図柄を得られる。
			 * 字牌に適用した場合は，図柄の種別を得られる。
			 */
			DESIGN_TYPE = 0x70,

			/// 数字のマスク。
			NUMBER = 0x0f,

			/// 属性のマスク。
			ATTRIBUTE = 0x80,
		};

		/**
		 * 値の範囲である。
		 */
		enum Range : unsigned char
		{
			/// 数字の最小値。
			MINIMUM_NUMBER = 1,

			/// 数字の最大値。
			MAXIMUM_NUMBER = 9,
			
			/// 数牌の最小値。
			MINIMUM_DESIGN_TYPE_SUIT = 0x10,

			/// 数牌の最大値。
			MAXIMUM_DESIGN_TYPE_SUIT = 0x3f,

			/// 字牌の最小値。
			MINIMUM_DESIGN_TYPE_HONOUR = 0x40,

			/// 字牌の最大値。
			MAXIMUM_DESIGN_TYPE_HONOUR = 0x5f,

			/// 風牌の最小値。
			MINIMUM_DESIGN_TYPE_WIND = 0x40,

			/// 風牌の最大値。
			MAXIMUM_DESIGN_TYPE_WIND = 0x4f,
			
			/// 三元牌の最小値。
			MINIMUM_DESIGN_TYPE_DRAGON = 0x50,

			/// 三元牌の最大値。
			MAXIMUM_DESIGN_TYPE_DRAGON = 0x5f,
		};


	private:
		/**
		 * 図柄，数字，および属性を表す値。
		 * 値の構成は次の通りである (ビットの番号は最上位を 1 番目，最下位を 8 番目とする)。
		 *     - 数牌の値構成。
		 *         - 1 ビット目      ... 属性。
		 *         - 2 ～ 4 ビット目 ... 図柄。
		 *         - 5 ～ 8 ビット目 ... 数字 (1 ～ 9)。
		 *     - 字牌の値構成。
		 *         - 1 ビット目      ... 属性。
		 *         - 2 ～ 7 ビット目 ... 図柄。
		 */
		unsigned char m_value;


	public:
		/**
		 * 字牌を生成する。
		 * 
		 * @param[in] design 図柄。字牌の図柄を指定する。
		 * @param[in] attribute 属性。常に属性なしを指定する。
		 */
		MemorySavedTile(const TileDesign &design, const TileAttribute &attribute = TileAttributes::NONE);

		/**
		 * 数牌を生成する。
		 *
		 * @param[in] design 図柄。数牌の図柄を指定する。
		 * @param[in] number 数字。1 以上 9 以下の数字を指定する。
		 * @param[in] attribute 属性。属性なし，または赤を指定する。
		 */
		MemorySavedTile(const TileDesign &design, int number, const TileAttribute &attribute = TileAttributes::NONE);

		/**
		 * 図柄を返す。
		 *
		 * @return 図柄。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数の戻り値が使用するリソースを本関数の呼び出し側で管理する必要はない。
		 */
		const TileDesign *getDesign() const;

		/**
		 * 数字を返す。
		 *
		 * @return 数牌の場合は数字。字牌の場合は 0。
		 */
		int getNumber() const;

		/**
		 * 属性を返す。
		 *
		 * @return 属性。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数の戻り値が使用するリソースを本関数の呼び出し側で管理する必要はない。
		 */
		const TileAttribute *getAttribute() const;

		/**
		 * 数牌であるかを調べる。
		 *
		 * @retval true 数牌であった。
		 * @retval false 数牌ではなかった。
		 */
		bool isSuit() const;

		/**
		 * 字牌であるかを調べる。
		 *
		 * @retval true 字牌であった。
		 * @retval false 字牌ではなかった。
		 */
		bool isHonour() const;

		/**
		 * 風牌であるかを調べる。
		 *
		 * @retval true 風牌であった。
		 * @retval false 風牌ではなかった。
		 */
		bool isWind() const;

		/**
		 * 三元牌であるかを調べる。
		 *
		 * @retval true 三元牌であった。
		 * @retval false 三元牌ではなかった。
		 */
		bool isDragon() const;

		/**
		 * 中張牌であるかを調べる。
		 *
		 * @retval true 中張牌であった。
		 * @retval false 中張牌ではなかった。
		 */
		bool isSimple() const;

		/**
		 * 老頭牌であるかを調べる。
		 *
		 * @retval true 老頭牌であった。
		 * @retval false 老頭牌ではなかった。
		 */
		bool isTerminal() const;

		/**
		 * 幺九牌であるかを調べる。
		 *
		 * @retval true 幺九牌であった。
		 * @retval false 幺九牌ではなかった。
		 */
		bool isTerminalOrHonour() const;
	};
}
