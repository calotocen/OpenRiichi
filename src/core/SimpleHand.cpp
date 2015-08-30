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
	, m_tilesSize(0)
	, m_sets()
	, m_setsSize(0)
{
	// 何もしない。
}


bool SimpleHand::isEmpty() const
{
	bool returnValue = m_tilesSize == 0 && m_setsSize == 0;		// 戻り値。

	return returnValue;
}


void SimpleHand::clear()
{
	m_tilesSize = 0;
	m_setsSize = 0;
}


SimpleHand::TilesIterator SimpleHand::getHeadTilesIterator()
{
	return getHeadElementsIterator(m_tiles, m_tilesSize);
}


SimpleHand::TilesConstIterator SimpleHand::getHeadTilesConstIterator() const
{
	return getHeadElementsConstIterator(m_tiles, m_tilesSize);
}


SimpleHand::TilesIterator SimpleHand::getTailTilesIterator()
{
	return getTailElementsIterator(m_tiles, m_tilesSize);
}


SimpleHand::TilesConstIterator SimpleHand::getTailTilesConstIterator() const
{
	return getTailElementsConstIterator(m_tiles, m_tilesSize);
}


const Tile * SimpleHand::getTile(size_t index) const
{
	return getElement<Tile>(m_tiles, m_tilesSize, index);
}


const Tile * SimpleHand::getFirstTile() const
{
	return getFirstElement<Tile>(m_tiles, m_tilesSize);
}


const Tile * SimpleHand::getLastTile() const
{
	return getLastElement<Tile>(m_tiles, m_tilesSize);
}


size_t SimpleHand::countTiles() const
{
	return countElements(m_tiles, m_tilesSize);
}


void SimpleHand::setTile(size_t index, const Tile & tile)
{
	setElement(m_tiles, m_tilesSize, index, tile);
}


void SimpleHand::addTile(const Tile & tile)
{
	addElement(m_tiles, m_tilesSize, tile);
}


SimpleHand::TilesIterator SimpleHand::insertTile(TilesIterator iterator, const Tile & tile)
{
	return insertElement(m_tiles, m_tilesSize, iterator, tile);
}


void SimpleHand::insertTile(size_t index, const Tile & tile)
{
	insertElement(m_tiles, m_tilesSize, index, tile);
}


SimpleHand::TilesIterator SimpleHand::removeTile(TilesIterator iterator)
{
	return removeElement(m_tiles, m_tilesSize, iterator);
}


void SimpleHand::removeTile(size_t index)
{
	return removeElement(m_tiles, m_tilesSize, index);
}


void SimpleHand::clearTiles()
{
	return clearElements(m_tiles, m_tilesSize);
}


SimpleHand::SetsIterator SimpleHand::getHeadSetsIterator()
{
	return getHeadElementsIterator(m_sets, m_setsSize);
}


SimpleHand::SetsConstIterator SimpleHand::getHeadSetsConstIterator() const
{
	return getHeadElementsConstIterator(m_sets, m_setsSize);
}


SimpleHand::SetsIterator SimpleHand::getTailSetsIterator()
{
	return getTailElementsIterator(m_sets, m_setsSize);
}


SimpleHand::SetsConstIterator SimpleHand::getTailSetsConstIterator() const
{
	return getTailElementsConstIterator(m_sets, m_setsSize);
}


const Set * SimpleHand::getSet(size_t index) const
{
	return getElement<Set>(m_sets, m_setsSize, index);
}


const Set * SimpleHand::getFirstSet() const
{
	return getFirstElement<Set>(m_sets, m_setsSize);
}


const Set * SimpleHand::getLastSet() const
{
	return getLastElement<Set>(m_sets, m_setsSize);
}


size_t SimpleHand::countSets() const
{
	return countElements(m_sets, m_setsSize);
}


void SimpleHand::setSet(size_t index, const Set & set)
{
	setElement(m_sets, m_setsSize, index, set);
}


void SimpleHand::addSet(const Set & set)
{
	addElement(m_sets, m_setsSize, set);
}


SimpleHand::SetsIterator SimpleHand::insertSet(SetsIterator iterator, const Set & set)
{
	return insertElement(m_sets, m_setsSize, iterator, set);
}


void SimpleHand::insertSet(size_t index, const Set & set)
{
	insertElement(m_sets, m_setsSize, index, set);
}


SimpleHand::SetsIterator SimpleHand::removeSet(SetsIterator iterator)
{
	return removeElement(m_sets, m_setsSize, iterator);
}


void SimpleHand::removeSet(size_t index)
{
	return removeElement(m_sets, m_setsSize, index);
}


void SimpleHand::clearSets()
{
	return clearElements(m_sets, m_setsSize);
}
