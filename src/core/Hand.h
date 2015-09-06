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


#include "Set.h"
#include "SimpleHand.h"
#include "Tile.h"


namespace openriichi
{
	/// 手牌である。
	using Hand = class SimpleHand;

	/// 手牌の牌配列である。
	using Tiles = LimitedVector<Tile, Hand::MAX_TILES_SIZE>;

	/// 手牌の面子配列である。
	using Sets = LimitedVector<Set, Hand::MAX_SETS_SIZE>;
}
