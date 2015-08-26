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


#include "TileDesign.h"


namespace openriichi
{
	/**
	 * 牌図柄の集合である。
	 */
	class TileDesigns
	{
	public:
		/// 筒子の牌図柄。
		static const CirclesTileDesign CIRCLES;


		/// 索子の牌図柄。
		static const BambooTileDesign BAMBOO;


		/// 萬子の牌図柄。
		static const CharactersTileDesign CHARACTERS;


		/// 東の牌図柄。
		static const EastTileDesign EAST;


		/// 南の牌図柄。
		static const SouthTileDesign SOUTH;


		/// 西の牌図柄。
		static const WestTileDesign WEST;


		/// 北の牌図柄。
		static const NorthTileDesign NORTH;


		/// 中の牌図柄。
		static const RedTileDesign RED;


		/// 白の牌図柄。
		static const WhiteTileDesign WHITE;


		/// 發の牌図柄。
		static const GreenTileDesign GREEN;
	};
}
