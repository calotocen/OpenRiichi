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
#include "SimplePlayerInfo.h"


using namespace openriichi;


SimplePlayerInfo::SimplePlayerInfo()
	: m_hand()
	, m_discards()
	, m_points(0)
	, m_drawCount(0)
	, m_riichiStatus()
{
	// 何もしない。
}


Hand &SimplePlayerInfo::hand()
{
	return m_hand;
}


SimplePlayerInfo::Discards &SimplePlayerInfo::discards()
{
	return m_discards;
}


size_t SimplePlayerInfo::getPoints() const
{
	return m_points;
}


void SimplePlayerInfo::setPoints(size_t points)
{
	m_points = static_cast<uint32_t>(points);
}


void SimplePlayerInfo::addPoints(size_t points)
{
	m_points += static_cast<uint32_t>(points);
}


size_t SimplePlayerInfo::getDrawCount() const
{
	return m_drawCount;
}


void SimplePlayerInfo::setDrawCount(size_t drawCount)
{
	m_drawCount = static_cast<uint8_t>(drawCount);
}


void SimplePlayerInfo::increaseDrawCount()
{
	++m_drawCount;
}


RiichiStatus &SimplePlayerInfo::riichiStatus()
{
	return m_riichiStatus;
}
