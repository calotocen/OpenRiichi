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
	 * 鳴き種別である。
	 */
	class MeldType : public Enumeration<MeldType>
	{
	public:
		/**
		 * 鳴き種別を生成する。
		 */
		MeldType() = default;

		/**
		 * 鳴き種別を生成する。
		 *
		 * @param[in] id ID。
		 */
		explicit MeldType(int id);

		/**
		 * 鳴き種別を破棄する。
		 */
		virtual ~MeldType() = default;
	};


	/**
	 * 鳴き種別の集合である。
	 */
	class MeldTypes
	{
	public:
		enum ID
		{
			/// 面前であることを表す鳴き種別の ID。
			NONE_ID = 0,

			/// 上家の牌を鳴いたことを表す南の鳴き種別の ID。
			LEFT_ID = 1,

			/// 対面の牌を鳴いたことを表す鳴き種別の ID。
			ACROSS_ID = 2,

			/// 下家の牌を鳴いたことを表す鳴き種別の ID。
			RIGHT_ID = 3,
		};


	public:
		/// 面前であることを表す鳴き種別。
		static const MeldType NONE;

		/// 上家の牌を鳴いたことを表す南の鳴き種別。
		static const MeldType LEFT;
		
		/// 対面の牌を鳴いたことを表す鳴き種別。
		static const MeldType ACROSS;
		
		/// 下家の牌を鳴いたことを表す鳴き種別。
		static const MeldType RIGHT;
	};
}
