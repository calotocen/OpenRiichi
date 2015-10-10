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
#pragma once


#include "MouseEvent.h"


/**
 * モデルである。
 */
class MfcServerModel
{
public:
	/**
	 * ゲーム状態である。
	 */
	enum GameStatus
	{
		/// 初期状態。
		INITIAL,

		/// 対局中状態。
		PLAYING,
	};

private:
	/// ゲーム状態。
	GameStatus m_gameStatus;

	/// 卓。
	openriichi::Table m_table;

	/// マウスイベント。
	MouseEvent m_mouseEvent;


public:
	/**
	 * モデルを生成する。
	 */
	MfcServerModel();


public:
	/**
	 * ゲーム状態を返す。
	 */
	GameStatus getGameStatus() const;

	/**
	 * ゲーム状態を設定する。
	 */
	void setGameStatus(GameStatus gameStatus);

	/**
	 * 卓を返す。
	 *
	 * @return 卓。
	 */
	openriichi::Table &table();

	/**
	 * 卓を返す。
	 *
	 * @return 卓。
	 */
	const openriichi::Table &table() const;

	/**
	 * マウスイベントを返す
	 *
	 * @return マウスイベント。
	 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
	 */
	const MouseEvent &getMouseEvent() const;

	/**
	 * マウスイベントを登録する。
	 *
	 * @param[in] mouseEvent マウスイベント。
	 */
	void setMouseEvent(const MouseEvent &mouseEvent);

	/**
	 * 初期化する。
	 */
	void initialize();

	/**
	 * 局を開始する。
	 */
	void startHand();

	/**
	 * 対局を開始する。
	 */
	void play();
};
