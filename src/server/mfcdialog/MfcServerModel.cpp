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


void MfcServerModel::initialize()
{
	m_gameStatus = INITIAL;
	m_table = Table();
	m_mouseEvent = MouseEvent();
}


void MfcServerModel::startHand()
{
	Wall &wall = m_table.wall();

	// 山を積む。
	wall = Wall();
	wall.shuffle(static_cast<unsigned int>(time(NULL)));

	// さいころを振る。
	Table::Dices &dices = m_table.dices();
	dices[0].roll();
	dices[1].roll();

	// 開門する。
	wall.breaks(dices[0], dices[1]);

	// 配牌する。
	Wind winds[] = { Winds::EAST, Winds::SOUTH, Winds::WEST, Winds::NORTH };
	for (int i = 0; i < 3; ++i) {
		for (Wind wind : winds) {
			for (int j = 0; j < 4; ++j) {
				m_table.playerInfo(wind).hand().tiles().push_back(wall.draw());
			}
		}
	}
	for (Wind wind : winds) {
		m_table.playerInfo(wind).hand().tiles().push_back(wall.draw());
	}
	m_table.playerInfo(Winds::EAST).hand().tiles().push_back(wall.draw());
}


void MfcServerModel::play()
{
	m_gameStatus = PLAYING;

	startHand();
}
