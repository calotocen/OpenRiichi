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
	 * 風である。
	 */
	class Wind : public Enumeration<Wind>
	{
	private:
		int m_id;


	public:
		/**
		 * 風を生成する。
		 */
		Wind() = default;

		/**
		 * 風を生成する。
		 *
		 * @param[in] id ID。
		 */
		explicit Wind(int id);

		/**
		 * 風を破棄する。
		 */
		virtual ~Wind() = default;


	public:
		/**
		 * 前位風を取得する。
		 *
		 * @return 前位風。
		 */
		Wind getPreviousWind() const;

		/**
		 * 次位風を取得する。
		 *
		 * @return 次位風。
		 */
		Wind getNextWind() const;
	};


	/**
	 * 風の集合である。
	 */
	class Winds
	{
	public:
		enum ID : int
		{
			/// 東の風の ID。
			EAST_ID = 1,

			/// 南の風の ID。
			SOUTH_ID = 2,

			/// 西の風の ID。
			WEST_ID = 3,

			/// 北の風の ID。
			NORTH_ID = 4,
		};


	public:
		/// 東の風。
		static const Wind EAST;

		/// 南の風。
		static const Wind SOUTH;
		
		/// 西の風。
		static const Wind WEST;
		
		/// 北の風。
		static const Wind NORTH;
	};
}
