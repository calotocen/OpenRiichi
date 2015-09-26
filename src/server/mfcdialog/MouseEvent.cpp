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
#include "MouseEvent.h"


MouseEvent::MouseEvent()
	: MouseEvent(NO_TYPE, NO_BUTTON, CPoint())
{
	// 何もしない。
}


MouseEvent::MouseEvent(Type type, const CPoint &point)
	: MouseEvent(type, NO_BUTTON, point)
{
	// 何もしない。
}


MouseEvent::MouseEvent(Type type, Button button, const CPoint &point)
	: m_type(type)
	, m_button(button)
	, m_point(point)
{
	// アサーションが有効である場合のみ，引数をチェックする。
	openriichi_assert((m_type != NO_TYPE && m_type != MOVED) || m_button == NO_BUTTON);
}


MouseEvent::Type MouseEvent::getType() const
{
	return m_type;
}


MouseEvent::Button MouseEvent::getButton() const
{
	return m_button;
}


const CPoint &MouseEvent::getPoint() const
{
	return m_point;
}
