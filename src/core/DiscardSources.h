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


#include "Enumeration.h"


namespace openriichi
{
	/**
	 * 捨て牌の捨て元である。
	 */
	class DiscardSource : public Enumeration<DiscardSource>
	{
	public:
		/**
		 * 捨て牌の捨て元を破棄する。
		 */
		virtual ~DiscardSource();
	};


	/**
	 * 捨て牌の捨て元のテンプレートである。
	 */
	template<int _ID>
	class DiscardSourceTemplate : public DiscardSource
	{
	public:
		/// 関連のある列挙型間で一意の値。
		static const int ID = _ID;


	public:
		/**
		 * 捨て牌の捨て元を破棄する。
		 */
		virtual ~DiscardSourceTemplate();


	public:
		/**
		 * 関連のある列挙型間で一意の値を返す。
		 *
		 * @return 関連のある列挙型間で一意の値。
		 */
		virtual int getId() const override;
	};


	template<int _ID>
	DiscardSourceTemplate<_ID>::~DiscardSourceTemplate()
	{
		// 何もしない。
	}


	template<int _ID>
	int DiscardSourceTemplate<_ID>::getId() const
	{
		return _ID;
	}


	/**
	 * 捨て元がツモ牌であることを表す。。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに DiscardSources::DRAWED を使用すること。
	 */
	using DrawedDiscardSource = DiscardSourceTemplate<1>;


	/**
	 * 捨て元が手持ち牌であることを表す。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに DiscardSources::HELD を使用すること。
	 */
	using HeldDiscardSource = DiscardSourceTemplate<2>;


	/**
	 * 捨て牌の捨て元の集合である。
	 */
	class DiscardSources
	{
	public:
		/// 東の捨て牌の捨て元。
		static const DrawedDiscardSource DRAWED;

		/// 南の捨て牌の捨て元。
		static const HeldDiscardSource HELD;
	};
}
