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
#include "stdafx.h"
#include "MfcServerModel.h"


using namespace openriichi;


MfcServerModel::MfcServerModel()
	: m_gameStatus(INITIAL)
	, m_table()
	, m_mouseEvent()
{
	// 何もしない。
}


MfcServerModel::GameStatus MfcServerModel::getGameStatus() const
{
	return m_gameStatus;
}


void MfcServerModel::setGameStatus(GameStatus gameStatus)
{
	m_gameStatus = gameStatus;
}


Table &MfcServerModel::table()
{
	return m_table;
}


const Table &MfcServerModel::table() const
{
	return m_table;
}


const MouseEvent &MfcServerModel::getMouseEvent() const
{
	return m_mouseEvent;
}


void MfcServerModel::setMouseEvent(const MouseEvent &mouseEvent)
{
	m_mouseEvent = mouseEvent;
}
