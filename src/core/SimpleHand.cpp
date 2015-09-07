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
#include <cassert>
#include "SimpleHand.h"


using namespace openriichi;


SimpleHand::SimpleHand()
	: m_tiles()
	, m_sets()
{
	// 何もしない。
}


bool SimpleHand::isEmpty() const
{
	bool returnValue = m_tiles.isEmpty() && m_sets.isEmpty();		// 戻り値。

	return returnValue;
}


void SimpleHand::clear()
{
	m_tiles.clear();
	m_sets.clear();
}


LimitedVector<Tile, SimpleHand::MAX_TILES_SIZE> &SimpleHand::tiles()
{
	return m_tiles;
}


LimitedVector<Set, SimpleHand::MAX_SETS_SIZE> &SimpleHand::sets()
{
	return m_sets;
}
