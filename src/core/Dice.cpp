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
#include <random>
#include "OpenRiichi.h"


using namespace std;
using namespace openriichi;


Dice::Dice()
	: m_number(1)
{
	 // 何もしない。
}


Dice::Dice(size_t number)
	: m_number(static_cast<uint8_t>(number))
{
	// アサーションが有効である場合のみ，引数をチェックする。
	openriichi_assert(1 <= number && number <= 6);
}


bool Dice::operator==(const Dice &other) const
{
	return m_number == other.m_number;
}


bool Dice::operator!=(const Dice &other) const
{
	return !(*this == other);
}


void Dice::roll()
{
	random_device randomDevice;
	m_number = randomDevice() % 6 + 1;
}


size_t Dice::getNumber() const
{
	return m_number;
}


void Dice::setNumber(size_t number)
{
	// アサーションが有効である場合のみ，引数をチェックする。
	openriichi_assert(1 <= number && number <= 6);

	m_number = static_cast<uint8_t>(number);
}
