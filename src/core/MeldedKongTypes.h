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
	 * 鳴き槓子種別である。
	 */
	class MeldedKongType : public Enumeration<MeldedKongType>
	{
	public:
		/**
		 * 鳴き槓子種別を生成する。
		 */
		MeldedKongType() = default;

		/**
		 * 鳴き槓子種別を破棄する。
		 */
		virtual ~MeldedKongType();
	};


	/**
	 * 鳴き槓子種別のテンプレートである。
	 */
	template<int id>
	class MeldedKongTypeTemplate : public MeldedKongType
	{
	public:
		/// 関連のある列挙型間で一意の値。
		static const int ID = id;


	public:
		/**
		 * 鳴き槓子種別を生成する。
		 */
		MeldedKongTypeTemplate() = default;

		/**
		 * 鳴き槓子種別を破棄する。
		 */
		virtual ~MeldedKongTypeTemplate();


	public:
		/**
		 * 関連のある列挙型間で一意の値を返す。
		 *
		 * @return 関連のある列挙型間で一意の値。
		 */
		virtual int getId() const;
	};


	template<int id>
	MeldedKongTypeTemplate<id>::~MeldedKongTypeTemplate()
	{
		// 何もしない。
	}


	template<int id>
	int MeldedKongTypeTemplate<id>::getId() const
	{
		return id;
	}


	/**
	 * 槓子でないことを表す鳴き槓子種別である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに MeldedKongTypes::NO を使用すること。
	 */
	using NoMeldedKongType = MeldedKongTypeTemplate<0>;


	/**
	 * 小明槓 (加槓) を表す鳴き槓子種別である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに MeldedKongTypes::LITTLE を使用すること。
	 */
	using LittleMeldedKongType = MeldedKongTypeTemplate<1>;


	/**
	 * 大明槓を表す鳴き槓子種別である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに MeldedKongTypes::BIG を使用すること。
	 */
	using BigMeldedKongType = MeldedKongTypeTemplate<2>;


	/**
	 * 鳴き槓子種別の集合である。
	 */
	class MeldedKongTypes
	{
	public:
		/// 鳴き槓子でないことを表す鳴き槓子種別。
		static const NoMeldedKongType NO;

		/// 小明槓 (加槓) を表す鳴き槓子種別。
		static const LittleMeldedKongType LITTLE;
		
		/// 大明槓を表す鳴き槓子種別。
		static const BigMeldedKongType BIG;
	};
}
