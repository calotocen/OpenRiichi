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
	 * 局カウンタである。
	 */
	class HandCounter
	{
	private:
		/// 場 (東場，南場など)。
		Wind m_round;

		/// 局数 (一局目，二局目など)。
		uint8_t m_majorCount;

		/// 本数 (一本場，二本場など)。
		uint8_t m_minorCount;


	public:
		/**
		 * 局カウンタを生成する。
		 */
		HandCounter();


	public:
		/**
		 * 他の局カウンタと等しいか調べる。
		 *
		 * @param[in] other 他の局カウンタ。
		 */
		bool operator==(const HandCounter &other) const;

		/**
		 * 他の局カウンタと等しくないか調べる。
		 *
		 * @param[in] other 他の局カウンタ。
		 */
		bool operator!=(const HandCounter &other) const;


	public:
		/**
		 * 場を返す。
		 *
		 * @return 場。
		 */
		const Wind &getRound() const;

		/**
		 * 場を設定する。
		 *
		 * @param[in] round 場。
		 */
		void setRound(const Wind &round);

		/**
		 * 場を進める。
		 */
		void nextRound();

		/**
		 * 局数を返す。
		 *
		 * @return 局数。
		 */
		size_t getMajorCount() const;

		/**
		 * 局数を設定する。
		 *
		 * @param[in] count 局数。
		 */
		void setMajorCount(size_t count);

		/**
		 * 局数を初期化する。
		 */
		void resetMajorCount();

		/**
		 * 局数に 1 を加算する。
		 */
		void increaseMajorCount();

		/**
		 * 本数を返す。
		 *
		 * @return 本数。
		 */
		size_t getMinorCount() const;

		/**
		 * 本数を設定する。
		 *
		 * @param[in] count 本数。
		 */
		void setMinorCount(size_t count);

		/**
		 * 本数を初期化する。
		 */
		void resetMinorCount();

		/**
		 * 本数に 1 を加算する。
		 */
		void increaseMinorCount();
	};
}
