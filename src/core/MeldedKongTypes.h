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


#include "Enumeration.h"


namespace openriichi
{
	/**
	 * 鳴き槓子種別である。
	 */
	class MeldedKongType : public Enumeration<MeldedKongType>
	{
	public:
		/**
		 * 鳴き槓子種別を生成する。
		 */
		MeldedKongType() = default;

		/**
		 * 鳴き槓子種別を生成する。
		 *
		 * @param[in] id ID。
		 */
		explicit MeldedKongType(int id);

		/**
		 * 鳴き槓子種別を破棄する。
		 */
		virtual ~MeldedKongType() = default;
	};


	/**
	 * 鳴き槓子種別の集合である。
	 */
	class MeldedKongTypes
	{
	public:
		enum ID : int
		{
			/// 鳴き槓子でないことを表す鳴き槓子種別の ID。
			NO_ID = 0,

			/// 小明槓 (加槓) を表す鳴き槓子種別の ID。
			LITTLE_ID = 1,

			/// 大明槓を表す鳴き槓子種別の ID。
			BIG_ID = 2,
		};


	public:
		/// 鳴き槓子でないことを表す鳴き槓子種別。
		static const MeldedKongType NO;

		/// 小明槓 (加槓) を表す鳴き槓子種別。
		static const MeldedKongType LITTLE;
		
		/// 大明槓を表す鳴き槓子種別。
		static const MeldedKongType BIG;
	};
}
