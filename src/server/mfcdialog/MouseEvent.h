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


/**
 * マウスイベントである。
 */
class MouseEvent
{
public:
	/**
	 * イベント種別である。
	 */
	enum Type
	{
		/// なし。
		NO_TYPE,

		/// 移動。
		MOVED,

		/// クリック。
		CLICKED,
	};

	/**
	 * ボタンである。
	 */
	enum Button
	{
		/// なし。
		NO_BUTTON,

		/// 左ボタン。
		LEFT_BUTTON,

		/// 右ボタン。
		RIGHT_BUTTON,
	};


private:
	/// イベント種別。
	Type m_type;

	/// ボタン。
	Button m_button;

	/// イベント発生場所。
	CPoint m_point;


public:
	/**
	 * マウスイベントを生成する。
	 */
	MouseEvent();

	/**
	 * マウスイベントを生成する。
	 *
	 * @param[in] type イベント種別。
	 * @param[in] point イベント発生場所。
	 */
	MouseEvent(Type type, const CPoint &point);

	/**
	 * マウスイベントを生成する。
	 *
	 * @param[in] type イベント種別。
	 * @param[in] button ボタン。
	 * @param[in] point イベント発生場所。
	 */
	MouseEvent(Type type, Button button, const CPoint &point);

	/**
	 * イベント種別を返す。
	 *
	 * @return イベント種別。
	 */
	Type getType() const;

	/**
	 * ボタンを返す。
	 *
	 * @return ボタン。
	 */
	Button getButton() const;

	/**
	 * イベント発生場所を返す。
	 *
	 * @return イベント発生場所。
	 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
	 */
	const CPoint &getPoint() const;
};
