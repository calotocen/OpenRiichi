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


bool SimplePlayerInfo::operator==(const SimplePlayerInfo &other) const
{
	if (this == &other) {
		return true;
	}

	return m_hand == other.m_hand
		&& m_discards == other.m_discards
		&& m_points == other.m_points
		&& m_drawCount == other.m_drawCount
		&& m_riichiStatus == other.m_riichiStatus;
}


bool SimplePlayerInfo::operator!=(const SimplePlayerInfo &other) const
{
	return !(*this == other);
}


const Hand &SimplePlayerInfo::getHand() const
{
	return m_hand;
}


void SimplePlayerInfo::setHand(const Hand &hand)
{
	m_hand = hand;
}


Hand &SimplePlayerInfo::hand()
{
	return m_hand;
}


const SimplePlayerInfo::Discards &SimplePlayerInfo::getDiscards() const
{
	return m_discards;
}


void SimplePlayerInfo::setDiscards(const Discards &discards)
{
	m_discards = discards;
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


const RiichiStatus &SimplePlayerInfo::getRiichiStatus() const
{
	return m_riichiStatus;
}


void SimplePlayerInfo::setRiichiStatus(const RiichiStatus &riichiStatus)
{
	m_riichiStatus = riichiStatus;
}


RiichiStatus &SimplePlayerInfo::riichiStatus()
{
	return m_riichiStatus;
}
