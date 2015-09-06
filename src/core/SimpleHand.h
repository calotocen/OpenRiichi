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
#include "LimitedVector.h"
#include "Set.h"
#include "Tile.h"


namespace openriichi
{
	/**
	 * 手牌である。
	 */
	class SimpleHand
	{
	public:
		/// 牌の最大個数。
		static const size_t MAX_TILES_SIZE = 14;

		/// 面子の最大個数。
		static const size_t MAX_SETS_SIZE = 5;


	private:
		/// 牌配列。
		LimitedVector<Tile, MAX_TILES_SIZE> m_tiles;

		/// 面子配列。
		LimitedVector<Set, MAX_SETS_SIZE> m_sets;


	public:
		/**
		 * 空の手牌を生成する。
		 */
		SimpleHand();


	public:
		/**
		 * 手牌が空であるか調べる。
		 *
		 * @retval true 手牌は空であった。
		 * @retval false 手牌は空ではなかった。
		 */
		bool isEmpty() const;

		/**
		 * 手牌を空にする。
		 */
		void clear();

		/**
		 * 牌配列を返す。
		 *
		 * @return 牌配列。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 */
		LimitedVector<Tile, MAX_TILES_SIZE> &getTiles();

		/**
		 * 面子配列を返す。
		 *
		 * @return 面子配列。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 */
		LimitedVector<Set, MAX_SETS_SIZE> &getSets();
	};
}
