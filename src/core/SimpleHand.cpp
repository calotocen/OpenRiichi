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
#include <initializer_list>
#include "SimpleHand.h"


using namespace std;
using namespace openriichi;


SimpleHand::SimpleHand()
	: m_tiles()
	, m_sets()
{
	// 何もしない。
}


SimpleHand::SimpleHand(const Tiles &tiles, const Sets &sets)
	: m_tiles(tiles)
	, m_sets(sets)
{
	// 何もしない。
}


SimpleHand::SimpleHand(const initializer_list<Tile> &tiles)
	: m_tiles(tiles)
	, m_sets()
{
	// 何もしない。
}


SimpleHand::SimpleHand(const initializer_list<Set> &sets)
	: m_tiles()
	, m_sets(sets)
{
	// 何もしない。
}


bool SimpleHand::operator==(const SimpleHand &other) const
{
	// 自分自身との比較であれば，true を返す。
	if (this == &other)
	{
		return true;
	}

	// 牌配列と面子配列を比較して，その結果を返す。
	return m_tiles == other.m_tiles && m_sets == other.m_sets;
}


bool SimpleHand::operator!=(const SimpleHand &other) const
{
	return !(*this == other);
}


SimpleHand &SimpleHand::operator=(const std::initializer_list<Tile> &tiles)
{
	m_tiles = tiles;
	m_sets.clear();

	return *this;
}


SimpleHand &SimpleHand::operator=(const std::initializer_list<Set> &sets)
{
	m_tiles.clear();
	m_sets = sets;

	return *this;
}


bool SimpleHand::isEmpty() const
{
	return m_tiles.isEmpty() && m_sets.isEmpty();
}


void SimpleHand::clear()
{
	m_tiles.clear();
	m_sets.clear();
}


const SimpleHand::Tiles &SimpleHand::getTiles() const
{
	return m_tiles;
}


void SimpleHand::setTiles(const Tiles &tiles)
{
	m_tiles = tiles;
}


SimpleHand::Tiles &SimpleHand::tiles()
{
	return m_tiles;
}


const SimpleHand::Sets &SimpleHand::getSets() const
{
	return m_sets;
}


void SimpleHand::setSets(const Sets &sets)
{
	m_sets = sets;
}


SimpleHand::Sets &SimpleHand::sets()
{
	return m_sets;
}
