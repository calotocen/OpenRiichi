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
	 * 牌属性である。
	 */
	class TileAttribute : public Enumeration<TileAttribute>
	{
	public:
		/**
		 * 牌属性を生成する。
		 */
		TileAttribute() = default;

		/**
		 * 牌属性を破棄する。
		 */
		virtual ~TileAttribute();
	};


	/**
	 * 牌属性のテンプレートである。
	 */
	template<int id>
	class TileAttributeTemplate : public TileAttribute
	{
	public:
		/// 関連のある列挙型間で一意の値。
		static const int ID = id;


	public:
		/**
		 * 牌属性を生成する。
		 */
		TileAttributeTemplate() = default;

		/**
		 * 牌属性を破棄する。
		 */
		virtual ~TileAttributeTemplate();


	public:
		/**
		 * 関連のある列挙型間で一意の値を返す。
		 *
		 * @return 関連のある列挙型間で一意の値。
		 */
		virtual int getId() const override;
	};


	template<int id>
	TileAttributeTemplate<id>::~TileAttributeTemplate()
	{
		// 何もしない。
	}


	template<int id>
	int TileAttributeTemplate<id>::getId() const
	{
		return id;
	}


	/**
	 * 属性なしを表す牌属性である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに TileAttributes::RED を使用すること。
	 */
	using NoneTileAttribute = TileAttributeTemplate<0>;


	/**
	 * 赤の牌属性である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに TileAttributes::RED を使用すること。
	 */
	using RedTileAttribute = TileAttributeTemplate<1>;


	/**
	 * 牌属性の集合である。
	 */
	class TileAttributes
	{
	public:
		/// 属性なしを表す牌属性。
		static const NoneTileAttribute NONE;

		/// 赤の牌属性。
		static const RedTileAttribute RED;
	};
}
