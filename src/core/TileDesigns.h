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


namespace openriichi
{
	/**
	 * 牌図柄である。
	 */
	class TileDesign : public Enumeration<TileDesign>
	{
	public:
		/// 数牌の種別。
		static const int SUITS_TYPE = 1;

		/// 風牌の種別。
		static const int WINDS_TYPE = 2;

		/// 三元牌の種別。
		static const int DRAGONS_TYPE = 3;


	private:
		/// 種別。
		int m_type;


	public:
		/**
		 * 牌図柄を生成する。
		 */
		TileDesign() = default;

		/**
		 * 牌図柄を生成する。
		 *
		 * @param[in] id ID。
		 * @param[in] type 種別。数牌の場合は 0，風牌の場合は 1，三元牌の場合は 2 を指定する。
		 */
		TileDesign(int id, int type);

		/**
		 * 牌図柄を破棄する。
		 */
		virtual ~TileDesign() = default;


	public:
		/**
		 * 数牌であるかを調べる。
		 *
		 * @retval true 数牌であった。
		 * @retval false 数牌ではなかった。
		 */
		bool isSuits() const;

		/**
		 * 字牌であるかを調べる。
		 *
		 * @retval true 字牌であった。
		 * @retval false 字牌ではなかった。
		 */
		bool isHonours() const;

		/**
		 * 風牌であるかを調べる。
		 *
		 * @retval true 風牌であった。
		 * @retval false 風牌ではなかった。
		 */
		bool isWinds() const;

		/**
		 * 三元牌であるかを調べる。
		 *
		 * @retval true 三元牌であった。
		 * @retval false 三元牌ではなかった。
		 */
		bool isDragons() const;
	};


	/**
	 * 牌図柄の集合である。
	 */
	class TileDesigns
	{
	public:
		enum ID : int
		{
			/// 筒子の牌図柄の ID。
			CIRCLES_ID = 1,

			/// 索子の牌図柄の ID。
			BAMBOO_ID = 2,

			/// 萬子の牌図柄の ID。
			CHARACTERS_ID = 3,

			/// 東の牌図柄の ID。
			EAST_ID = 4,

			/// 南の牌図柄の ID。
			SOUTH_ID = 5,

			/// 西の牌図柄の ID。
			WEST_ID = 6,

			/// 北の牌図柄の ID。
			NORTH_ID = 7,

			/// 中の牌図柄の ID。
			RED_ID = 8,

			/// 白の牌図柄の ID。
			WHITE_ID = 9,

			/// 發の牌図柄の ID。
			GREEN_ID = 10,
		};


	public:
		/// 筒子の牌図柄。
		static const TileDesign CIRCLES;

		/// 索子の牌図柄。
		static const TileDesign BAMBOO;

		/// 萬子の牌図柄。
		static const TileDesign CHARACTERS;

		/// 東の牌図柄。
		static const TileDesign EAST;

		/// 南の牌図柄。
		static const TileDesign SOUTH;

		/// 西の牌図柄。
		static const TileDesign WEST;

		/// 北の牌図柄。
		static const TileDesign NORTH;

		/// 中の牌図柄。
		static const TileDesign RED;

		/// 白の牌図柄。
		static const TileDesign WHITE;

		/// 發の牌図柄。
		static const TileDesign GREEN;
	};
}
