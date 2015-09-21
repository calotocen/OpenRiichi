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


namespace openriichi
{
	/**
	 * サイコロである。
	 */
	class Dice
	{
	private:
		uint8_t m_number;


	public:
		/**
		 * 出目が 1 の状態のサイコロを生成する。
		 */
		Dice();

		/**
		 * サイコロを生成する。
		 *
		 * @param[in] number 出目。
		 */
		Dice(size_t number);


	public:
		/**
		 * 他のさいころと等しいか調べる。
		 *
		 * @param[in] other 他のさいころ。
		 */
		bool operator==(const Dice &other) const;

		/**
		 * 他のさいころと等しくないか調べる。
		 *
		 * @param[in] other 他のさいころ。
		 */
		bool operator!=(const Dice &other) const;


	public:
		/**
		 * サイコロを振る。
		 */
		void roll();

		/**
		 * サイコロの出目を返す。
		 *
		 * @return 出目。
		 */
		size_t getNumber() const;

		/**
		 * サイコロの出目を設定する。
		 *
		 * @param[in] number 出目。
		 */
		void setNumber(size_t number);
	};
}
