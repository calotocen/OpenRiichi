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


namespace openriichi {
	class MeldedKongType;
	class MeldType;
	class SetArrangement;


	/**
	 * 省メモリの面子である。
	 */
	class MemorySavedSet {
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

			/// 順子の場合は左の牌，刻子，槓子の場合は上家の牌を鳴いたことを表す。
			LEFT = 0x10,

			/// 順子の場合は中央の牌，刻子，槓子の場合は対面の牌を鳴いたことを表す。 
			CENTER = 0x20,

			/// 順子の場合は右の牌，刻子，槓子の場合は下家の牌を鳴いたことを表す。 
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
			SET_ARRANGEMENT = 0x0f,

			/// 鳴き種別のマスク。
			MELD_TYPE = 0x30,

			/// 鳴き槓子種別のマスク。
			MELDED_KONG_TYPE = 0xc0,
		};


	private:
		/**
		 * 面子を表す値。
		 * 値の構成は次の通りである (ビットの番号は最上位を 1 番目，最下位を 8 番目とする)。
		 *     - 1 ～ 2 ビット目 ... 鳴き槓子種別。
		 *     - 3 ～ 4 ビット目 ... 鳴き種別。
		 *     - 5 ～ 8 ビット目 ... 面子種別。
		 */
		uint8_t m_value;

		/**
		 * キー牌である。
		 * 順子の場合は，面子の中で一番数字の小さい牌である。
		 * 対子，刻子，槓子の場合は，面子を構成する牌である。
		 */
		Tile m_keyTile;


	public:
		/**
		 * 筒子の 1 から始まる暗順を作成する。
		 */
		MemorySavedSet();

		/**
		 * 暗順，対子，暗刻，または暗槓を生成する。
		 * 
		 * @param[in] setArrangement 面子種別。
		 * @param[in] keyTile キー牌。
		 *                    順子の場合は，面子の中で一番数字の小さい牌を指定する。
		 *                    対子，刻子，槓子の場合は，面子を構成する牌を指定する。
		 * @note 暗順生成時に数牌以外の牌を指定した場合の動作は，未定義である。
		 * @note 暗順生成時に数字が 7 以上のキー牌を指定した場合の動作は，未定義である。
		 */
		MemorySavedSet(const SetArrangement &setArrangement, const Tile &keyTile);

		/**
		 * 明順，明刻を生成する。
		 *
		 * @param[in] setArrangement 面子種別。
		 * @param[in] meldType 鳴き種別。
		 * @param[in] keyTile キー牌。
		 *                    順子の場合は，一番数字の小さい牌を指定する。
		 *                    刻子の場合は，単に牌を指定する。
		 * @note 明順生成時に数牌以外の牌を指定した場合の動作は，未定義である。
		 * @note 明順生成時に数字が 7 以上のキー牌を指定した場合の動作は，未定義である。
		 */
		MemorySavedSet(const SetArrangement &setArrangement, const MeldType &meldType, const Tile &keyTile);


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

	public:
		/**
		 * 明槓を生成する。
		 *
		 * @param[in] setArrangement 面子種別。
		 * @param[in] meldType 鳴き種別。
		 * @param[in] meldedKongType 鳴き槓子種別。
		 * @param[in] keyTile キー牌。
		 *                    槓子の牌を単に指定する。
		 * @note 明槓生成時に『面前』を鳴き種別として指定した場合の動作は，未定義である。
		 * @note 明槓生成時に『鳴き槓子ではない』を鳴き槓子種別として指定した場合の動作は，未定義である。
		 */
		MemorySavedSet(const SetArrangement &setArrangement, const MeldType &meldType, const MeldedKongType &meldedKongType, const Tile &keyTile);

		/**
		 * 面子種別を返す。
		 *
		 * @return 面子種別。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数の戻り値が使用するリソースを本関数の呼び出し側で管理する必要はない。
		 */
		const SetArrangement *getSetArrangement() const;

		/**
		 * 鳴き種別を返す。
		 *
		 * @return 鳴き種別。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数の戻り値が使用するリソースを本関数の呼び出し側で管理する必要はない。
		 */
		const MeldType *getMeldType() const;

		/**
		 * 鳴き槓子種別を返す。
		 *
		 * @return 鳴き槓子種別。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数の戻り値が使用するリソースを本関数の呼び出し側で管理する必要はない。
		 */
		const MeldedKongType *getMeldedKongType() const;

		/**
		 * キー牌を返す。
		 *
		 * @return キー牌。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数の戻り値が使用するリソースを本関数の呼び出し側で管理する必要はない。
		 */
		const Tile *getKeyTile() const;

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
