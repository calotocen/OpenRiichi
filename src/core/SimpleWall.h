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
	 * 山である。
	 */
	class SimpleWall
	{
	private:
		/// 牌の個数。
		static const size_t TILES_SIZE = (3 * 9 + 4 + 3) * 4;

		/// 王牌の初期位置。
		static const size_t INITIAL_DEAD_WALL_INDEX = TILES_SIZE - 14;


	public:
		/// 牌配列型。
		using Tiles = LimitedVector<Tile, TILES_SIZE>;

		/// ドラ配列型。
		using Doras = std::vector<Tile>;


	private:
		/// 牌配列。
		Tiles m_tiles;

		/// ドラ配列。
		Doras m_doras;

		/// 裏ドラ配列。
		Doras m_uraDoras;

		/// ツモ位置。
		uint8_t m_index;

		/// 王牌位置。
		uint8_t m_deadWallIndex;

#if defined(OPENRIICHI_ENABLE_ASSERTION)
		/// 最後にドラをめくった位置。
		uint8_t m_lastRevealedDoraIndex;
#endif // defined(OPENRIICHI_ENABLE_ASSERTION)


	public:
		/**
		 * 山を生成する。
		 * 山に積まれる牌の順序は，次の通りである。
		 *     - 筒子 (一筒× 4，二筒× 4，..., 九筒× 4)
		 *     - 索子 (一索× 4，二索× 4，..., 九索× 4)
		 *     - 萬子 (一萬× 4，二萬× 4，..., 九萬× 4)
		 *     - 風牌 (東× 4, 南× 4, 西× 4, 北× 4)
		 *     - 三元牌 (中× 4, 白× 4, 發× 4)
		 */
		SimpleWall();

		/**
		 * 山を生成する。
		 *
		 * @param[in] tiles 牌配列。
		 */
		explicit SimpleWall(const Tiles &tiles);


	public:
		/**
		 * 他の山と等しいか調べる。
		 *
		 * @param[in] other 他の山。
		 */
		bool operator==(const SimpleWall &other) const;

		/**
		 * 他の山と等しくないか調べる。
		 *
		 * @param[in] other 他の山。
		 */
		bool operator!=(const SimpleWall &other) const;


	public:
		/**
		 * 牌を混ぜる。
		 *
		 * @param[in] seed 乱数種。
		 */
		void shuffle(unsigned int seed);

		/**
		 * 山を区切る。
		 *
		 * @param[in] index 区切り位置。
		 * @note 一度，区切った山を再度区切ることはできない。
		 *       再度区切る場合は，その前に shuffle 関数を実行すること。
		 * @note 本関数は，ドラをめくらない。
		 *       ドラをめくる場合は，本関数実行後に revealNewDora 関数を実行すること。
		 */
		void breaks(int index);

		/**
		 * 牌をツモる。
		 *
		 * @return ツモった牌。
		 */
		const Tile &draw();

		/**
		 * 嶺上牌をツモる。
		 *
		 * @note ドラ表示牌も嶺上牌としてツモることができる。
		 * @note 残りツモ回数が 0 回の状態で嶺上牌をツモった場合の動作は，未定義である。
		 * @return ツモった嶺上牌。
		 */
		const Tile &drawReplacementTile();

		/**
		 * 新しいドラを追加する。
		 * 本関数は，(136 - (3 + ＜ツモった嶺上牌の数＞) * 2) の位置にある牌 (ドラ表示牌) の次位牌をドラとする。
		 * なお，ツモった嶺上牌の数によっては，ドラ表示牌の位置が王牌を超えることがある。
		 * その場合でも上式の位置にある牌をドラ表示牌とみなし，対応するドラを追加する。
		 * また，ドラ表示牌の位置にあるべき牌が既にツモられている場合もある。
		 * その場合でも上式の位置にあった牌をドラ表示牌とみなし，対応するドラを追加する。
		 *
		 * @note 同じドラ表示牌を 2 回以上めくった場合の動作は，未定義である。
		 * @note 嶺上牌のツモ数が 65 回を超えている状態でドラ表示牌をめくった場合の動作は，
		 *       めくる対象がないため，未定義である。
		 */
		void revealNewDora();

		/**
		 * 残りツモ回数を返す。
		 *
		 * @return 残りツモ回数。
		 */
		size_t countRemainingTiles();

		/**
		 * 表ドラを返す。
		 *
		 * @return 表ドラ。
		 */
		const Doras &getDoras();

		/**
		 * 裏ドラを返す。
		 *
		 * @return 裏ドラ。
		 */
		const Doras &getUraDoras();
	};
}
