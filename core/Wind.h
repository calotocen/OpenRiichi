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
	 * 風である。
	 */
	class Wind : public Enumeration<Wind>
	{
	public:
		/**
		 * 風を生成する。
		 */
		Wind() = default;

		/**
		 * 風を破棄する。
		 */
		virtual ~Wind();
	};


	/**
	 * 風のテンプレートである。
	 */
	template<int id>
	class WindTemplate : public Wind
	{
	public:
		/// 関連のある列挙型間で一意の値。
		static const int ID = id;


	public:
		/**
		* 風を生成する。
		*/
		WindTemplate() = default;

		/**
		* 風を破棄する。
		*/
		virtual ~WindTemplate();


	public:
		/**
		* 関連のある列挙型間で一意の値を返す。
		*
		* @return 関連のある列挙型間で一意の値。
		*/
		virtual int getId() const;
	};


	template<int id>
	WindTemplate<id>::~WindTemplate()
	{
		// 何もしない。
	}


	template<int id>
	int WindTemplate<id>::getId() const
	{
		return id;
	}


	/**
	 * 東の風である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに Winds::EAST を使用すること。
	 */
	using EastWind = WindTemplate<1>;


	/**
	 * 南の風である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに Winds::SOUTH を使用すること。
	 */
	using SouthWind = WindTemplate<2>;


	/**
	 * 西の風である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに Winds::WEST を使用すること。
	 */
	using WestWind = WindTemplate<3>;


	/**
	 * 北の風である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに Winds::NORTH を使用すること。
	 */
	using NorthWind = WindTemplate<4>;
}
