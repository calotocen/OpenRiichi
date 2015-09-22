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


#include <algorithm>
#include <array>
#include <cstdint>
#include <initializer_list>
#include <vector>


#include "OpenRiichiConfiguration.h"
#include "OpenRiichiException.h"
#include "OpenRiichiAssertion.h"

#include "LimitedVector.h"

#include "Enumeration.h"
#include "DiscardSources.h"
#include "MeldTypes.h"
#include "MeldedKongTypes.h"
#include "SetArrangements.h"
#include "TileAttributes.h"
#include "TileDesigns.h"
#include "Winds.h"

#include "Dice.h"
#include "HandCounter.h"


#if defined(OPENRIICHI_SERVER)
namespace openriichi
{
	/// 牌型。
	using Tile = class MemorySavedTile;

	/// 面子型。
	using Set = class MemorySavedSet;

	/// 手牌型。
	using Hand = class SimpleHand;

	/// 捨て牌型。
	using Discard = class MemorySavedDiscard;

	/// 立直状態型。
	using RiichiStatus = class MemorySavedRiichiStatus;

	/// プレイヤー情報型。
	using PlayerInfo = class SimplePlayerInfo;

	/// 山型。
	using Wall = class SimpleWall;

	/// 卓型。
	using Table = class SimpleTable;
}


#	include "MemorySavedTile.h"
#	include "MemorySavedSet.h"
#	include "SimpleHand.h"
#	include "MemorySavedDiscard.h"
#	include "MemorySavedRiichiStatus.h"
#	include "SimplePlayerInfo.h"
#	include "SimpleWall.h"
#	include "SimpleTable.h"
#endif


#include "Tiles.h"
