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
	 * 面子種別である。
	 */
	class SetArrangement : public Enumeration<SetArrangement>
	{
	public:
		/**
		 * 面子種別を生成する。
		 */
		SetArrangement() = default;

		/**
		 * 面子種別を破棄する。
		 */
		virtual ~SetArrangement();
	};


	/**
	 * 面子種別のテンプレートである。
	 */
	template<int id>
	class SetArrangementTemplate : public SetArrangement
	{
	public:
		/// 関連のある列挙型間で一意の値。
		static const int ID = id;


	public:
		/**
		 * 面子種別を生成する。
		 */
		SetArrangementTemplate() = default;

		/**
		 * 面子種別を破棄する。
		 */
		virtual ~SetArrangementTemplate();


	public:
		/**
		 * 関連のある列挙型間で一意の値を返す。
		 *
		 * @return 関連のある列挙型間で一意の値。
		 */
		virtual int getId() const;
	};


	template<int id>
	SetArrangementTemplate<id>::~SetArrangementTemplate()
	{
		// 何もしない。
	}


	template<int id>
	int SetArrangementTemplate<id>::getId() const
	{
		return id;
	}


	/**
	 * 順子の面子種別である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに SetArrangements::CHOW を使用すること。
	 */
	using ChowSetArrangement = SetArrangementTemplate<1>;


	/**
	 * 対子の面子種別である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに SetArrangements::PAIR を使用すること。
	 */
	using PairSetArrangement = SetArrangementTemplate<2>;


	/**
	 * 刻子の面子種別である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに SetArrangements::PUNG を使用すること。
	 */
	using PungSetArrangement = SetArrangementTemplate<3>;


	/**
	 * 槓子の面子種別である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに SetArrangements::KONG を使用すること。
	 */
	using KongSetArrangement = SetArrangementTemplate<4>;


	/**
	 * 面子種別の集合である。
	 */
	class SetArrangements
	{
	public:
		/// 順子の面子種別。
		static const ChowSetArrangement CHOW;

		/// 対子の面子種別。
		static const PairSetArrangement PAIR;
		
		/// 刻子の面子種別。
		static const PungSetArrangement PUNG;
		
		/// 槓子の面子種別。
		static const KongSetArrangement KONG;
	};
}
