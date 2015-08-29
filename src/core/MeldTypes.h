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
	 * 鳴き種別である。
	 */
	class MeldType : public Enumeration<MeldType>
	{
	public:
		/**
		 * 鳴き種別を破棄する。
		 */
		virtual ~MeldType();
	};


	/**
	 * 鳴き種別のテンプレートである。
	 */
	template<int _ID>
	class MeldTypeTemplate : public MeldType
	{
	public:
		/// 関連のある列挙型間で一意の値。
		static const int ID = _ID;


	public:
		/**
		 * 鳴き種別を破棄する。
		 */
		virtual ~MeldTypeTemplate();


	public:
		/**
		 * 関連のある列挙型間で一意の値を返す。
		 *
		 * @return 関連のある列挙型間で一意の値。
		 */
		virtual int getId() const override;
	};


	template<int _ID>
	MeldTypeTemplate<_ID>::~MeldTypeTemplate()
	{
		// 何もしない。
	}


	template<int _ID>
	int MeldTypeTemplate<_ID>::getId() const
	{
		return _ID;
	}


	/**
	 * 面前であることを表す鳴き種別である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに MeldTypes::NONE を使用すること。
	 */
	using NoneMeldType = MeldTypeTemplate<0>;


	/**
	 * 順子の場合は左の牌，刻子，槓子の場合は上家の牌を鳴いたことを表す鳴き種別である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに MeldTypes::LEFT を使用すること。
	 */
	using LeftMeldType = MeldTypeTemplate<1>;


	/**
	 * 順子の場合は中央の牌，刻子，槓子の場合は対面の牌を鳴いたことを表す鳴き種別である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに MeldTypes::CENTER を使用すること。
	 */
	using CenterMeldType = MeldTypeTemplate<2>;


	/**
	 * 順子の場合は右の牌，刻子，槓子の場合は下家の牌を鳴いたことを表す鳴き種別である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに MeldTypes::RIGHT を使用すること。
	 */
	using RightMeldType = MeldTypeTemplate<3>;


	/**
	 * 鳴き種別の集合である。
	 */
	class MeldTypes
	{
	public:
		/// 面前であることを表す鳴き種別。
		static const NoneMeldType NONE;

		/// 順子の場合は左の牌，刻子，槓子の場合は上家の牌を鳴いたことを表す南の鳴き種別。
		static const LeftMeldType LEFT;
		
		/// 順子の場合は中央の牌，刻子，槓子の場合は対面の牌を鳴いたことを表す鳴き種別。
		static const CenterMeldType CENTER;
		
		/// 順子の場合は右の牌，刻子，槓子の場合は下家の牌を鳴いたことを表す鳴き種別。
		static const RightMeldType RIGHT;
	};
}
