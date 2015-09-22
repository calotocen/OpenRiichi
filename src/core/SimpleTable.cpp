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
#include "OpenRiichiConfiguration.h"
#include "SimpleTable.h"


using namespace openriichi;


 SimpleTable::SimpleTable()
	 : m_playerInfos{}
	 , m_wall()
	 , m_handCounter()
 {
	 // 何もしない。
 }


 bool SimpleTable::operator==(const SimpleTable &other) const
 {
	 if (this == &other) {
		 return true;
	 }

	 return m_playerInfos == other.m_playerInfos && m_wall == other.m_wall && m_handCounter == other.m_handCounter;
 }


 bool SimpleTable::operator!=(const SimpleTable &other) const
 {
	 return !(*this == other);
 }


 const PlayerInfo &SimpleTable::getPlayerInfo(const Wind &wind) const
 {
	 // アサーションが有効である場合のみ，引数をチェックする。
	 openriichi_assert(1 <= wind.getId() && wind.getId() <= 4);

	 return m_playerInfos[wind.getId() - 1];
 }


 void SimpleTable::setPlayerInfo(const Wind &wind, const PlayerInfo &playerInfo)
 {
	 // アサーションが有効である場合のみ，引数をチェックする。
	 openriichi_assert(1 <= wind.getId() && wind.getId() <= 4);

	 m_playerInfos[wind.getId() - 1] = playerInfo;
 }


 PlayerInfo &SimpleTable::playerInfo(const Wind &wind)
 {
	 // アサーションが有効である場合のみ，引数をチェックする。
	 openriichi_assert(1 <= wind.getId() && wind.getId() <= 4);

	 return m_playerInfos[wind.getId() - 1];
 }


 const Wall &SimpleTable::getWall() const
 {
	 return m_wall;
 }

 
 void SimpleTable::setWall(const Wall &wall)
 {
	 m_wall = wall;
 }

 
 Wall &SimpleTable::wall()
 {
	 return m_wall;
 }

 
 const HandCounter &SimpleTable::getHandCounter() const
 {
	 return m_handCounter;
 }

 
 void SimpleTable::setHandCounter(const HandCounter &handCounter)
 {
	 m_handCounter = handCounter;
 }


 HandCounter &SimpleTable::handCounter()
 {
	 return m_handCounter;
 }
