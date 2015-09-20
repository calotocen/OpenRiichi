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
#include "HandCounter.h"


using namespace openriichi;


HandCounter::HandCounter()
	: m_round(Winds::EAST)
	, m_majorCount(1)
	, m_minorCount(0)
{
	// 何もしない。
}


const Wind &HandCounter::getRound() const
{
	return m_round;
}


void HandCounter::setRound(const Wind &round)
{
	m_round = round;
}


void HandCounter::nextRound()
{
	m_round = m_round.getNextWind();
}


size_t HandCounter::getMajorCount() const
{
	return m_majorCount;
}


void HandCounter::setMajorCount(size_t count)
{
	m_majorCount = static_cast<uint8_t>(count);
}


void HandCounter::resetMajorCount()
{
	m_majorCount = 1;
}


void HandCounter::increaseMajorCount()
{
	++m_majorCount;
}


size_t HandCounter::getMinorCount() const
{
	return m_minorCount;
}


void HandCounter::setMinorCount(size_t count)
{
	m_minorCount = static_cast<uint8_t>(count);
}


void HandCounter::resetMinorCount()
{
	m_minorCount = 0;
}


void HandCounter::increaseMinorCount()
{
	++m_minorCount;
}
