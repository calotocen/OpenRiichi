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
	 * 捨て牌の捨て元である。
	 */
	class DiscardSource : public Enumeration<DiscardSource>
	{
	public:
		/**
		 * 捨て牌を生成する。
		 */
		DiscardSource() = default;

		/**
		 * 捨て牌を生成する。
		 *
		 * @param[in] id ID。
		 */
		explicit DiscardSource(int id);

		/**
		 * 捨て牌の捨て元を破棄する。
		 */
		virtual ~DiscardSource() = default;
	};


	/**
	 * 捨て牌の捨て元の集合である。
	 */
	class DiscardSources
	{
	public:
		enum ID : int
		{
			/// ツモ牌が捨て元の ID。
			DRAWED_ID = 1,

			/// 手持ち牌が捨て元の ID。
			HELD_ID = 2,
		};


	public:
		/// ツモ牌が捨て元。
		static const DiscardSource DRAWED;

		/// 手持ち牌が捨て元。
		static const DiscardSource HELD;
	};
}
