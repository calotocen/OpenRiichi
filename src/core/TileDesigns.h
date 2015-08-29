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
	 * 牌図柄である。
	 */
	class TileDesign : public Enumeration<TileDesign>
	{
	public:
		/**
		 * 牌図柄を破棄する。
		 */
		virtual ~TileDesign();


	public:
		/**
		 * 数牌であるかを調べる。
		 *
		 * @retval true 数牌であった。
		 * @retval false 数牌ではなかった。
		 */
		virtual bool isSuit() const = 0;

		/**
		 * 字牌であるかを調べる。
		 *
		 * @retval true 字牌であった。
		 * @retval false 字牌ではなかった。
		 */
		virtual bool isHonour() const = 0;

		/**
		 * 風牌であるかを調べる。
		 *
		 * @retval true 風牌であった。
		 * @retval false 風牌ではなかった。
		 */
		virtual bool isWind() const = 0;

		/**
		 * 三元牌であるかを調べる。
		 *
		 * @retval true 三元牌であった。
		 * @retval false 三元牌ではなかった。
		 */
		virtual bool isDragon() const = 0;
	};


	/**
	 * 牌図柄のテンプレートである。
	 */
	template<int _ID, bool _SUIT, bool _HONOUR, bool _WIND, bool _DRAGON>
	class TileDesignTemplate : public TileDesign
	{
	public:
		/// 関連のある列挙型間で一意の値。
		static const int ID = _ID;


	public:
		/**
		 * 牌図柄を破棄する。
		 */
		virtual ~TileDesignTemplate();


	public:
		/**
		 * 関連のある列挙型間で一意の値を返す。
		 *
		 * @return 関連のある列挙型間で一意の値。
		 */
		virtual int getId() const override;

		/**
		 * 数牌であるかを調べる。
		 *
		 * @retval true 数牌であった。
		 * @retval false 数牌ではなかった。
		 */
		virtual bool isSuit() const override;

		/**
		 * 字牌であるかを調べる。
		 *
		 * @retval true 字牌であった。
		 * @retval false 字牌ではなかった。
		 */
		virtual bool isHonour() const override;

		/**
		 * 風牌であるかを調べる。
		 *
		 * @retval true 風牌であった。
		 * @retval false 風牌ではなかった。
		 */
		virtual bool isWind() const override;

		/**
		 * 三元牌であるかを調べる。
		 *
		 * @retval true 三元牌であった。
		 * @retval false 三元牌ではなかった。
		 */
		virtual bool isDragon() const override;
	};


	template<int _ID, bool _SUIT, bool _HONOUR, bool _WIND, bool _DRAGON>
	TileDesignTemplate<_ID, _SUIT, _HONOUR, _WIND, _DRAGON>::~TileDesignTemplate()
	{
		// 何もしない。
	}


	template<int _ID, bool _SUIT, bool _HONOUR, bool _WIND, bool _DRAGON>
	int TileDesignTemplate<_ID, _SUIT, _HONOUR, _WIND, _DRAGON>::getId() const
	{
		return _ID;
	}


	template<int _ID, bool _SUIT, bool _HONOUR, bool _WIND, bool _DRAGON>
	bool TileDesignTemplate<_ID, _SUIT, _HONOUR, _WIND, _DRAGON>::isSuit() const
	{
		return _SUIT;
	}


	template<int _ID, bool _SUIT, bool _HONOUR, bool _WIND, bool _DRAGON>
	bool TileDesignTemplate<_ID, _SUIT, _HONOUR, _WIND, _DRAGON>::isHonour() const
	{
		return _HONOUR;
	}


	template<int _ID, bool _SUIT, bool _HONOUR, bool _WIND, bool _DRAGON>
	bool TileDesignTemplate<_ID, _SUIT, _HONOUR, _WIND, _DRAGON>::isWind() const
	{
		return _WIND;
	}


	template<int _ID, bool _SUIT, bool _HONOUR, bool _WIND, bool _DRAGON>
	bool TileDesignTemplate<_ID, _SUIT, _HONOUR, _WIND, _DRAGON>::isDragon() const
	{
		return _DRAGON;
	}


	/**
	 * 筒子の牌図柄である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに TileDesigns::CIRCLES を使用すること。
	 */
	using CirclesTileDesign = TileDesignTemplate<1, true, false, false, false>;


	/**
	 * 索子の牌図柄である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに TileDesigns::BAMBOO を使用すること。
	 */
	using BambooTileDesign = TileDesignTemplate<2, true, false, false, false>;


	/**
	 * 萬子の牌図柄である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに TileDesigns::CHARACTERS を使用すること。
	 */
	using CharactersTileDesign = TileDesignTemplate<3, true, false, false, false>;


	/**
	 * 東の牌図柄である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに TileDesigns::EAST を使用すること。
	 */
	using EastTileDesign = TileDesignTemplate<4, false, true, true, false>;


	/**
	 * 南の牌図柄である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに TileDesigns::SOUTH を使用すること。
	 */
	using SouthTileDesign = TileDesignTemplate<5, false, true, true, false>;


	/**
	 * 西の牌図柄である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに TileDesigns::WEST を使用すること。
	 */
	using WestTileDesign = TileDesignTemplate<6, false, true, true, false>;


	/**
	 * 北の牌図柄である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに TileDesigns::NORTH を使用すること。
	 */
	using NorthTileDesign = TileDesignTemplate<7, false, true, true, false>;


	/**
	 * 中の牌図柄である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに TileDesigns::RED を使用すること。
	 */
	using RedTileDesign = TileDesignTemplate<8, false, true, false, true>;


	/**
	 * 白の牌図柄である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに TileDesigns::WHITE を使用すること。
	 */
	using WhiteTileDesign = TileDesignTemplate<9, false, true, false, true>;


	/**
	 * 發の牌図柄である。
	 *
	 * @note 本クラスを個別にインスタンス化してはならない。
	 *       代わりに TileDesigns::GREEN を使用すること。
	 */
	using GreenTileDesign = TileDesignTemplate<10, false, true, false, true>;


	/**
	 * 牌図柄の集合である。
	 */
	class TileDesigns
	{
	public:
		/// 筒子の牌図柄。
		static const CirclesTileDesign CIRCLES;


		/// 索子の牌図柄。
		static const BambooTileDesign BAMBOO;


		/// 萬子の牌図柄。
		static const CharactersTileDesign CHARACTERS;


		/// 東の牌図柄。
		static const EastTileDesign EAST;


		/// 南の牌図柄。
		static const SouthTileDesign SOUTH;


		/// 西の牌図柄。
		static const WestTileDesign WEST;


		/// 北の牌図柄。
		static const NorthTileDesign NORTH;


		/// 中の牌図柄。
		static const RedTileDesign RED;


		/// 白の牌図柄。
		static const WhiteTileDesign WHITE;


		/// 發の牌図柄。
		static const GreenTileDesign GREEN;
	};
}
