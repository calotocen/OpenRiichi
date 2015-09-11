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
#include <cstdint>
#include "MemorySavedRiichiStatus.h"


using namespace openriichi;


MemorySavedRiichiStatus::MemorySavedRiichiStatus()
	: MemorySavedRiichiStatus(false)
{
	// 何もしない。
}


MemorySavedRiichiStatus::MemorySavedRiichiStatus(bool declared, bool open, bool doubl, bool oneShot)
	: m_value(0)
{
	setDeclared(declared);
	setOpen(open);
	setDouble(doubl);
	setOneShot(oneShot);
}


bool MemorySavedRiichiStatus::operator==(const MemorySavedRiichiStatus & other) const
{
	return m_value == other.m_value;
}


bool MemorySavedRiichiStatus::operator!=(const MemorySavedRiichiStatus & other) const
{
	return !(*this == other);
}


bool MemorySavedRiichiStatus::isDeclared() const
{
	uint8_t declaredValue;		// 立直宣言有無。
	bool returnValue;				// 戻り値。

	// 値に応じた戻り値を返す。
	declaredValue = m_value & Flag::DECLARED;
	returnValue = (declaredValue) ? true : false;

	return returnValue;
}


void MemorySavedRiichiStatus::setDeclared(bool declared)
{
	if (declared) {
		m_value |= Flag::DECLARED;
	}
	else {
		m_value &= ~Flag::DECLARED;
	}
}


bool MemorySavedRiichiStatus::isOpen() const
{
	uint8_t openValue;		// 立直宣言有無。
	bool returnValue;		// 戻り値。

	// 値に応じた戻り値を返す。
	openValue = m_value & Flag::OPEN;
	returnValue = (openValue) ? true : false;

	return returnValue;
}


void MemorySavedRiichiStatus::setOpen(bool open)
{
	if (open) {
		m_value |= Flag::OPEN;
	}
	else {
		m_value &= ~Flag::OPEN;
	}
}


bool MemorySavedRiichiStatus::isDouble() const
{
	uint8_t doubleValue;		// 立直宣言有無。
	bool returnValue;			// 戻り値。

	// 値に応じた戻り値を返す。
	doubleValue = m_value & Flag::DOUBLE;
	returnValue = (doubleValue) ? true : false;

	return returnValue;
}


void MemorySavedRiichiStatus::setDouble(bool doubl)
{
	if (doubl) {
		m_value |= Flag::DOUBLE;
	}
	else {
		m_value &= ~Flag::DOUBLE;
	}
}


bool MemorySavedRiichiStatus::isOneShot() const
{
	uint8_t oneShotValue;		// 立直宣言有無。
	bool returnValue;			// 戻り値。

	// 値に応じた戻り値を返す。
	oneShotValue = m_value & Flag::ONE_SHOT;
	returnValue = (oneShotValue) ? true : false;

	return returnValue;
}


void MemorySavedRiichiStatus::setOneShot(bool oneShot)
{
	if (oneShot) {
		m_value |= Flag::ONE_SHOT;
	}
	else {
		m_value &= ~Flag::ONE_SHOT;
	}
}
