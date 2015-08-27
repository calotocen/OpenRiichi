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


#include "TileAttribute.h"


namespace openriichi
{
	/**
	 * 牌図柄の集合である。
	 */
	class TileAttributes
	{
	public:
		/// 属性がないことを表す牌属性。
		static const NoneTileAttribute NONE;

		/// 赤牌の牌属性。
		static const RedTileAttribute RED;
	};
}
