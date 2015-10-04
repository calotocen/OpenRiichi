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
	 * プレイヤー情報である。
	 */
	class SimplePlayerInfo
	{
	public:
		/// 捨て牌の最大個数。
		static const size_t MAX_DISCARDS_SIZE = 24;


	public:
		/// 捨て牌配列型。
		using Discards = LimitedVector<MemorySavedDiscard, MAX_DISCARDS_SIZE>;


	private:
		/// 手牌。
		Hand m_hand;

		/// 捨て牌。
		LimitedVector<MemorySavedDiscard, MAX_DISCARDS_SIZE> m_discards;

		/// 点数。
		uint32_t m_points;

		/// ツモった回数
		uint8_t m_drawCount;

		/// 立直状態。
		RiichiStatus m_riichiStatus;


	public:
		/**
		 * プレイヤー情報を生成する。
		 */
		SimplePlayerInfo();


	public:
		/**
		 * 他のプレイヤー情報と等しいか調べる。
		 *
		 * @param[in] other 他のプレイヤー情報。
		 */
		bool operator==(const SimplePlayerInfo &other) const;

		/**
		 * 他のプレイヤー情報と等しくないか調べる。
		 *
		 * @param[in] other 他のプレイヤー情報。
		 */
		bool operator!=(const SimplePlayerInfo &other) const;


	public:
		/**
		 * 手牌を返す。
		 *
		 * @return 手牌。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 */
		const Hand &hand() const;

		/**
		 * 手牌を返す。
		 *
		 * @return 手牌。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数が返す参照の内容は，変更してもよい。
		 *       その場合，変更内容は取得元のインスタンスに反映される。
		 */
		Hand &hand();

		/**
		 * 手牌を返す。
		 *
		 * @return 手牌。
		 */
		const Hand &getHand() const;

		/**
		 * 手牌を設定する。
		 *
		 * @param[in] hand 手牌。
		 */
		void setHand(const Hand &hand);

		/**
		 * 捨て牌配列を返す。
		 *
		 * @return 捨て牌配列。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 */
		const Discards &discards() const;

		/**
		 * 捨て牌配列を返す。
		 *
		 * @return 捨て牌配列。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数が返す参照の内容は，変更してもよい。
		 *       その場合，変更内容は取得元のインスタンスに反映される。
		 */
		Discards &discards();

		/**
		 * 捨て牌配列を返す。
		 *
		 * @return 捨て牌配列。
		 */
		const Discards &getDiscards() const;

		/**
		 * 捨て牌配列を設定する。
		 *
		 * @param[in] discards 捨て牌配列。
		 */
		void setDiscards(const Discards &discards);

		/**
		 * 点数を返す。
		 *
		 * @return 点数。
		 */
		size_t getPoints() const;

		/**
		 * 点数を設定する。
		 *
		 * @param[in] points 点数。
		 */
		void setPoints(size_t points);

		/**
		 * 点数を加算する。
		 *
		 * @param[in] points 点数。
		 */
		void addPoints(size_t points);

		/**
		 * ツモ数を返す。
		 *
		 * @return ツモ数。
		 */
		size_t getDrawCount() const;

		/**
		 * ツモ数を設定する。
		 *
		 * @param[in] drawCount ツモ数。
		 */
		void setDrawCount(size_t drawCount);

		/**
		 * ツモ数に 1 を加算する。
		 */
		void increaseDrawCount();

		/**
		 * 立直状態を返す。
		 *
		 * @return 立直状態。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 */
		const RiichiStatus &riichiStatus() const;

		/**
		 * 立直状態を返す。
		 *
		 * @return 立直状態。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数が返す参照の内容は，変更してもよい。
		 *       その場合，変更内容は取得元のインスタンスに反映される。
		 */
		RiichiStatus &riichiStatus();

		/**
		 * 立直状態を返す。
		 *
		 * @return 立直状態。
		 */
		const RiichiStatus &getRiichiStatus() const;

		/**
		 * 立直状態を設定する。
		 *
		 * @param[in] riichiStatus 立直状態。
		 */
		void setRiichiStatus(const RiichiStatus &riichiStatus);
	};
}
