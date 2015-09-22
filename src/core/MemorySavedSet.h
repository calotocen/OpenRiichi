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
	 * 省メモリの面子である。
	 */
	class MemorySavedSet
	{
	private:
		/**
		 * 面子種別値である。
		 */
		enum ArrangementValue : uint8_t
		{
			/// 順子。
			CHOW = 0x01,

			/// 対子。
			PAIR = 0x02,

			/// 刻子。
			PUNG = 0x03,

			/// 槓子。
			KONG = 0x04,
		};

		/**
		 * 鳴き種別値である。
		 */
		enum MeldTypeValue : uint8_t
		{
			/// 面前であることを表す。
			NONE = 0x00,

			/// 上家の牌を鳴いたことを表す。
			LEFT = 0x10,

			/// 対面の牌を鳴いたことを表す。 
			ACROSS = 0x20,

			/// 下家の牌を鳴いたことを表す。 
			RIGHT = 0x30,
		};

		/**
		 * 鳴き槓子種別値である。
		 */
		enum MeldedKongTypeValue : uint8_t
		{
			/// 鳴き槓子でないことを表す。
			NO = 0x00,

			/// 小明槓 (加槓) を表す。
			LITTLE = 0x40,

			/// 大明槓を表す。
			BIG = 0x80,
		};

		/**
		 * マスクである。
		 */
		enum Mask : uint8_t
		{
			/// 面子種別のマスク。
			ARRANGEMENT = 0x0f,

			/// 鳴き種別のマスク。
			MELD_TYPE = 0x30,

			/// 鳴き槓子種別のマスク。
			MELDED_KONG_TYPE = 0xc0,
		};


	public:
		/// 牌の最大個数。
		static const size_t MAX_TILES_SIZE = 4;


	public:
		/// 牌配列型。
		using Tiles = LimitedVector<Tile, MAX_TILES_SIZE>;


	private:
		/**
		 * 面子属性値。
		 * 値の構成は次の通りである (ビットの番号は最上位を 1 番目，最下位を 8 番目とする)。
		 *     - 1 ～ 2 ビット目 ... 鳴き槓子種別。
		 *     - 3 ～ 4 ビット目 ... 鳴き種別。
		 *     - 5 ～ 8 ビット目 ... 面子種別。
		 */
		uint8_t m_value;

		/// 牌配列。
		Tiles m_tiles;


	public:
		/**
		 * 筒子の 1 から始まる暗順を生成する。
		 */
		MemorySavedSet();

		/**
		 * 対子を生成する。
		 * 牌の指定ルールは次の通りである。
		 *     - 牌属性の ID 順に指定する。
		 *
		 * @param[in] tile1 面子を構成する牌。
		 * @param[in] tile2 面子を構成する牌。
		 * @note 対子でない面子を指定した場合の動作は，未定義である。
		 * @note 牌の指定ルールに従わなかった場合の動作は，未定義である。
		 */
		MemorySavedSet(const Tile &tile1, const Tile &tile2);

		/**
		 * 順子，または刻子を生成する。
		 * 牌の指定ルールは次の通りである。
		 *     - 暗順の場合
		 *         - tile1 に一番数字の小さな牌を，tile2 に数字の真ん中な牌を，tile3 に残りの牌を指定する。
		 *     - 明順の場合
		 *         - tile1 に鳴いた牌を，tile2 に残りの牌の中で一番数字の小さな牌を，tile3 に残りの牌を指定する。
		 *     - 暗刻の場合
		 *         - 牌属性の ID 順に指定する。
		 *     - 明刻の場合
		 *         - tile1 ～ tile3 の対応する位置に鳴かれた牌を指定する。
		 *         - 残りの牌は，牌属性の ID 順に指定する。
		 *
		 * @param[in] tile1 面子を構成する牌。
		 * @param[in] tile2 面子を構成する牌。
		 * @param[in] tile3 面子を構成する牌。
		 * @param[in] meldType 鳴き種別。
		 * @note 順子，または刻子でない面子を指定した場合の動作は，未定義である。
		 * @note 牌の指定ルールに従わなかった場合の動作は，未定義である。
		 */
		MemorySavedSet(const Tile &tile1, const Tile &tile2, const Tile &tile3, const MeldType &meldType = MeldTypes::NONE);

		/**
		 * 槓子を生成する。
		 * 牌の指定ルールは次の通りである。
		 *     - 暗槓の場合
		 *         - 牌属性の ID 順に指定する。
		 *     - 小明槓 (加槓) の場合
		 *         - tile2 に鳴いた牌を指定する。
		 *         - 残りの牌は，牌属性の ID 順に指定する。
		 *     - 大明槓の場合
		 *         - tile2 に鳴いた牌を指定する。
		 *         - 残りの牌は，牌属性の ID 順に指定する。
		 *
		 * @param[in] tile1 面子を構成する牌。
		 * @param[in] tile2 面子を構成する牌。
		 * @param[in] tile3 面子を構成する牌。
		 * @param[in] tile4 面子を構成する牌。
		 * @param[in] meldedKongType 鳴き槓子種別。
		 * @param[in] meldType 鳴き種別。
		 * @note 槓子でない面子を指定した場合の動作は，未定義である。
		 * @note 牌の指定ルールに従わなかった場合の動作は，未定義である。
		 */
		MemorySavedSet(const Tile &tile1, const Tile &tile2, const Tile &tile3, const Tile &tile4, const MeldedKongType &meldedKongType = MeldedKongTypes::NO, const MeldType &meldType = MeldTypes::NONE);


	public:
		/**
		 * 他の面子と等しいか調べる。
		 *
		 * @param[in] other 他の面子。
		 */
		bool operator==(const MemorySavedSet &other) const;

		/**
		 * 他の面子と等しくないか調べる。
		 *
		 * @param[in] other 他の面子。
		 */
		bool operator!=(const MemorySavedSet &other) const;


	private:
		/**
		 * 面子種別を設定する。
		 *
		 * @param[in] setArrangement 面子種別。
		 */
		void setArrangement(const SetArrangement &setArrangement);

		/**
		 * 鳴き種別を設定する。
		 *
		 * @param[in] meldType 鳴き種別。
		 */
		void setMeldType(const MeldType &meldType);

		/**
		 * 鳴き槓子種別を設定する。
		 *
		 * @param[in] 鳴き槓子種別。
		 */
		void setMeldedKongType(const MeldedKongType &meldedKongType);


	public:
		/**
		 * 面子種別を返す。
		 *
		 * @return 面子種別。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数の戻り値が使用するリソースを本関数の呼び出し側で管理する必要はない。
		 */
		const SetArrangement &getArrangement() const;

		/**
		 * 鳴き種別を返す。
		 *
		 * @return 鳴き種別。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数の戻り値が使用するリソースを本関数の呼び出し側で管理する必要はない。
		 */
		const MeldType &getMeldType() const;

		/**
		 * 鳴き槓子種別を返す。
		 *
		 * @return 鳴き槓子種別。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数の戻り値が使用するリソースを本関数の呼び出し側で管理する必要はない。
		 */
		const MeldedKongType &getMeldedKongType() const;

		/**
		 * 牌配列を返す。
		 *
		 * @return 牌配列。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数の戻り値が使用するリソースを本関数の呼び出し側で管理する必要はない。
		 */
		const Tiles &getTiles() const;

		/**
		 * 順子であるかを調べる。
		 *
		 * @retval true 順子であった。
		 * @retval false 順子ではなかった。
		 */
		bool isChow() const;

		/**
		 * 対子であるかを調べる。
		 *
		 * @retval true 順子であった。
		 * @retval false 順子ではなかった。
		 */
		bool isPair() const;

		/**
		 * 刻子であるかを調べる。
		 *
		 * @retval true 刻子であった。
		 * @retval false 刻子ではなかった。
		 */
		bool isPung() const;

		/**
		 * 槓子であるかを調べる。
		 *
		 * @retval true 槓子であった。
		 * @retval false 槓子ではなかった。
		 */
		bool isKong() const;

		/**
		 * 面前面子であるかを調べる。
		 *
		 * @retval true 面前面子であった。
		 * @retval false 面前面子ではなかった。
		 */
		bool isConcealed() const;

		/**
		 * 鳴き面子であるかを調べる。
		 *
		 * @retval true 鳴き面子であった。
		 * @retval false 鳴き面子ではなかった。
		 */
		bool isMelded() const;
	};
}
