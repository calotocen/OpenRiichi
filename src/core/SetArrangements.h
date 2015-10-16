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
	 * 面子種別である。
	 */
	class SetArrangement : public Enumeration<SetArrangement>
	{
	public:
		/**
		 * 面子種別を生成する。
		 */
		SetArrangement() = default;

		/**
		 * 面子種別を生成する。
		 *
		 * @param[in] id ID。
		 */
		explicit SetArrangement(int id);

		/**
		 * 面子種別を破棄する。
		 */
		virtual ~SetArrangement() = default;
	};


	/**
	 * 面子種別の集合である。
	 */
	class SetArrangements
	{
	public:
		enum ID
		{
			/// 順子の面子種別の ID。
			CHOW_ID = 1,

			/// 対子の面子種別の ID。
			PAIR_ID = 2,

			/// 刻子の面子種別の ID。
			PUNG_ID = 3,

			/// 槓子の面子種別の ID。
			KONG_ID = 4,
		};


	public:
		/// 順子の面子種別。
		static const SetArrangement CHOW;

		/// 対子の面子種別。
		static const SetArrangement PAIR;
		
		/// 刻子の面子種別。
		static const SetArrangement PUNG;
		
		/// 槓子の面子種別。
		static const SetArrangement KONG;
	};
}
