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


#include <cstdint>
#include <array>
#include "Set.h"
#include "Tile.h"


namespace openriichi
{
	/**
	 * 手牌である。
	 */
	class SimpleHand
	{
	public:
		/// 牌の最大個数。
		static const size_t MAX_TILES_SIZE = 14;

		/// 面子の最大個数。
		static const size_t MAX_SETS_SIZE = 5;


	private:
		/// 牌集合。
		using Tiles = std::array<Tile, MAX_TILES_SIZE>;

		/// 面子集合。
		using Sets = std::array<Set, MAX_SETS_SIZE>;


	public:
		/// 牌集合のイテレータ。
		using TilesIterator = Tiles::iterator;

		/// 牌集合の Const イテレータ。
		using TilesConstIterator = Tiles::const_iterator;

		/// 面子集合のイテレータ。
		using SetsIterator = Sets::iterator;

		/// 面子集合の Const イテレータ。
		using SetsConstIterator = Sets::const_iterator;


	private:
		/// 牌集合。
		Tiles m_tiles;

		/// 牌の個数。
		uint8_t m_tilesSize;

		/// 面子集合。
		Sets m_sets;

		/// 面子の個数。
		uint8_t m_setsSize;


	public:
		/**
		 * 空の手牌を生成する。
		 */
		SimpleHand();


	private:
		/**
		 * 要素集合の先頭を指すイテレータを返す。
		 *
		 * @return 要素集合の先頭を指すイテレータ。
		 */
		template<class _Elements, class _ElementsIterator = _Elements::iterator>
		inline _ElementsIterator getHeadElementsIterator(_Elements &elements, uint8_t &elementsSize);

		/**
		 * 要素集合の先頭を指すイテレータを返す。
		 *
		 * @return 要素集合の先頭を指すイテレータ。
		 */
		template<class _Elements, class _ElementsConstIterator = _Elements::const_iterator>
		inline _ElementsConstIterator getHeadElementsConstIterator(const _Elements &elements, const uint8_t &elementsSize) const;

		/**
		 * 要素集合の末尾を指すイテレータを返す。
		 *
		 * @return 要素集合の末尾を指すイテレータ。
		 */
		template<class _Elements, class _ElementsIterator = _Elements::iterator>
		inline _ElementsIterator getTailElementsIterator(_Elements &elements, uint8_t &elementsSize);

		/**
		 * 要素集合の末尾を指すイテレータを返す。
		 *
		 * @return 要素集合の末尾を指すイテレータ。
		 */
		template<class _Elements, class _ElementsConstIterator = _Elements::const_iterator>
		inline _ElementsConstIterator getTailElementsConstIterator(const _Elements &elements, const uint8_t &elementsSize) const;

		/**
		 * 指定された位置にある要素を返す。
		 *
		 * @param[in] index 位置。
		 * @return 要素。
		 * @note 要素集合の範囲外を位置に指定した場合の動作は，未定義である。
		 */
		template<class _Element, class _Elements>
		inline const _Element *getElement(const _Elements &elements, const uint8_t &elementsSize, size_t index) const;

		/**
		 * 先頭にある要素を返す。
		 *
		 * @return 要素。
		 * @note 要素集合が空であった場合の動作は，未定義である。
		 */
		template<class _Element, class _Elements>
		inline const _Element *getFirstElement(const _Elements &elements, const uint8_t &elementsSize) const;

		/**
		 * 末尾にある要素を返す。
		 *
		 * @return 要素。
		 * @note 要素集合が空であった場合の動作は，未定義である。
		 */
		template<class _Element, class _Elements>
		inline const _Element *getLastElement(const _Elements &elements, const uint8_t &elementsSize) const;

		/**
		 * 要素の個数を返す。
		 *
		 * @return 要素の個数。
		 */
		template<class _Elements>
		inline size_t countElements(const _Elements &elements, const uint8_t &elementsSize) const;

		/**
		 * 要素を指定された位置に設定する。
		 *
		 * @param[in] index 位置。
		 * @param[in] element 要素。
		 * @note 要素集合の範囲外を位置に指定した場合の動作は，未定義である。
		 */
		template<class _Element, class _Elements>
		inline void setElement(_Elements &elements, uint8_t &elementsSize, size_t index, const _Element &element);

		/**
		 * 末尾に要素を追加する。
		 *
		 * @param[in] element 要素。
		 * @note 手要素の要素個数が既に最大個数であった場合の動作は，未定義である。
		 */
		template<class _Element, class _Elements>
		inline void addElement(_Elements &elements, uint8_t &elementsSize, const _Element &element);

		/**
		 * 要素を指定された位置に挿入する。
		 *
		 * @param[in] iterator 位置。
		 * @param[in] element 要素。
		 * @note 要素集合の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 手要素の要素個数が既に最大個数であった場合の動作は，未定義である。
		 */
		template<class _Element, class _Elements, class _ElementsIterator = _Elements::iterator>
		inline _ElementsIterator insertElement(_Elements &elements, uint8_t &elementsSize, _ElementsIterator iterator, const _Element &element);

		/**
		 * 要素を指定された位置に挿入する。
		 *
		 * @param[in] index 位置。
		 * @param[in] element 要素。
		 * @note 要素集合の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 手要素の要素個数が既に最大個数であった場合の動作は，未定義である。
		 */
		template<class _Element, class _Elements>
		inline void insertElement(_Elements &elements, uint8_t &elementsSize, size_t index, const _Element &element);

		/**
		 * 指定された位置にある要素を削除する。
		 *
		 * @param[in] iterator 位置。
		 * @note 要素集合の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 手要素の要素個数が既に最大個数であった場合の動作は，未定義である。
		 */
		template<class _Elements, class _ElementsIterator = _Elements::iterator>
		inline _ElementsIterator removeElement(_Elements &elements, uint8_t &elementsSize, _ElementsIterator iterator);

		/**
		 * 指定された位置にある要素を削除する。
		 *
		 * @param[in] index 位置。
		 * @note 要素集合の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 手要素の要素個数が既に最大個数であった場合の動作は，未定義である。
		 */
		template<class _Elements>
		inline void removeElement(_Elements &elements, uint8_t &elementsSize, size_t index);

		/**
		 * 要素を全削除する。
		 */
		template<class _Elements>
		inline void clearElements(_Elements &elements, uint8_t &elementsSize);

	
	public:
		/**
		 * 手牌が空であるか調べる。
		 *
		 * @retval true 手牌は空であった。
		 * @retval false 手牌は空ではなかった。
		 */
		bool isEmpty() const;

		/**
		 * 手牌を空にする。
		 */
		void clear();

		/**
		 * 牌集合の先頭を指すイテレータを返す。
		 *
		 * @return 牌集合の先頭を指すイテレータ。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 */
		TilesIterator getHeadTilesIterator();

		/**
		 * 牌集合の先頭を指すイテレータを返す。
		 *
		 * @return 牌集合の先頭を指すイテレータ。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 */
		TilesConstIterator getHeadTilesConstIterator() const;

		/**
		 * 牌集合の末尾を指すイテレータを返す。
		 *
		 * @return 牌集合の末尾を指すイテレータ。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 */
		TilesIterator getTailTilesIterator();

		/**
		 * 牌集合の末尾を指すイテレータを返す。
		 *
		 * @return 牌集合の末尾を指すイテレータ。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 */
		TilesConstIterator getTailTilesConstIterator() const;

		/**
		 * 指定された位置にある牌を返す。
		 *
		 * @param[in] index 位置。
		 * @return 牌。
		 * @note 牌集合の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数の戻り値が使用するリソースを本関数の呼び出し側で管理する必要はない。
		 */
		const Tile *getTile(size_t index) const;

		/**
		 * 先頭にある牌を返す。
		 *
		 * @return 牌。
		 * @note 牌集合が空であった場合の動作は，未定義である。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数の戻り値が使用するリソースを本関数の呼び出し側で管理する必要はない。
		 */
		const Tile *getFirstTile() const;

		/**
		 * 末尾にある牌を返す。
		 *
		 * @return 牌。
		 * @note 牌集合が空であった場合の動作は，未定義である。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数の戻り値が使用するリソースを本関数の呼び出し側で管理する必要はない。
		 */
		const Tile *getLastTile() const;

		/**
		 * 牌の個数を返す。
		 *
		 * @return 牌の個数。
		 */
		size_t countTiles() const;

		/**
		 * 牌を指定された位置に設定する。
		 *
		 * @param[in] index 位置。
		 * @param[in] tile 牌。
		 * @note 牌集合の範囲外を位置に指定した場合の動作は，未定義である。
		 */
		void setTile(size_t index, const Tile &tile);

		/**
		 * 末尾に牌を追加する。
		 *
		 * @param[in] tile 牌。
		 * @note 手牌の牌個数が既に最大個数であった場合の動作は，未定義である。
		 */
		void addTile(const Tile &tile);

		/**
		 * 牌を指定された位置に挿入する。
		 *
		 * @param[in] iterator 位置。
		 * @param[in] tile 牌。
		 * @note 牌集合の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 手牌の牌個数が既に最大個数であった場合の動作は，未定義である。
		 */
		TilesIterator insertTile(TilesIterator iterator, const Tile &tile);

		/**
		 * 牌を指定された位置に挿入する。
		 *
		 * @param[in] index 位置。
		 * @param[in] tile 牌。
		 * @note 牌集合の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 手牌の牌個数が既に最大個数であった場合の動作は，未定義である。
		 */
		void insertTile(size_t index, const Tile &tile);

		/**
		 * 指定された位置にある牌を削除する。
		 *
		 * @param[in] iterator 位置。
		 * @note 牌集合の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 手牌の牌個数が既に最大個数であった場合の動作は，未定義である。
		 */
		TilesIterator removeTile(TilesIterator iterator);

		/**
		 * 指定された位置にある牌を削除する。
		 *
		 * @param[in] index 位置。
		 * @note 牌集合の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 手牌の牌個数が既に最大個数であった場合の動作は，未定義である。
		 */
		void removeTile(size_t index);

		/**
		 * 牌を全削除する。
		 */
		void clearTiles();

		/**
		 * 面子集合の先頭を指すイテレータを返す。
		 *
		 * @return 面子集合の先頭を指すイテレータ。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 */
		SetsIterator getHeadSetsIterator();

		/**
		 * 面子集合の先頭を指すイテレータを返す。
		 *
		 * @return 面子集合の先頭を指すイテレータ。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 */
		SetsConstIterator getHeadSetsConstIterator() const;

		/**
		 * 面子集合の末尾を指すイテレータを返す。
		 *
		 * @return 面子集合の末尾を指すイテレータ。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 */
		SetsIterator getTailSetsIterator();

		/**
		 * 面子集合の末尾を指すイテレータを返す。
		 *
		 * @return 面子集合の末尾を指すイテレータ。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 */
		SetsConstIterator getTailSetsConstIterator() const;

		/**
		 * 指定された位置にある面子を返す。
		 *
		 * @param[in] index 位置。
		 * @return 面子。
		 * @note 面子集合の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数の戻り値が使用するリソースを本関数の呼び出し側で管理する必要はない。
		 */
		const Set *getSet(size_t index) const;

		/**
		 * 先頭にある面子を返す。
		 *
		 * @return 面子。
		 * @note 面子集合が空であった場合の動作は，未定義である。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数の戻り値が使用するリソースを本関数の呼び出し側で管理する必要はない。
		 */
		const Set *getFirstSet() const;

		/**
		 * 末尾にある面子を返す。
		 *
		 * @return 面子。
		 * @note 面子集合が空であった場合の動作は，未定義である。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数の戻り値が使用するリソースを本関数の呼び出し側で管理する必要はない。
		 */
		const Set *getLastSet() const;

		/**
		 * 面子の個数を返す。
		 *
		 * @return 面子の個数。
		 */
		size_t countSets() const;

		/**
		 * 面子を指定された位置に設定する。
		 *
		 * @param[in] index 位置。
		 * @param[in] set 面子。
		 * @note 面子集合の範囲外を位置に指定した場合の動作は，未定義である。
		 */
		void setSet(size_t index, const Set &set);

		/**
		 * 末尾に面子を追加する。
		 *
		 * @param[in] set 面子。
		 * @note 手牌の面子個数が既に最大個数であった場合の動作は，未定義である。
		 */
		void addSet(const Set &set);

		/**
		 * 面子を指定された位置に挿入する。
		 *
		 * @param[in] iterator 位置。
		 * @param[in] set 面子。
		 * @note 面子集合の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 手牌の面子個数が既に最大個数であった場合の動作は，未定義である。
		 */
		SetsIterator insertSet(SetsIterator iterator, const Set &set);

		/**
		 * 面子を指定された位置に挿入する。
		 *
		 * @param[in] index 位置。
		 * @param[in] set 面子。
		 * @note 面子集合の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 手牌の面子個数が既に最大個数であった場合の動作は，未定義である。
		 */
		void insertSet(size_t index, const Set &set);

		/**
		 * 指定された位置にある面子を削除する。
		 *
		 * @param[in] iterator 位置。
		 * @note 面子集合の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 手牌の面子個数が既に最大個数であった場合の動作は，未定義である。
		 */
		SetsIterator removeSet(SetsIterator iterator);

		/**
		 * 指定された位置にある面子を削除する。
		 *
		 * @param[in] index 位置。
		 * @note 面子集合の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 手牌の面子個数が既に最大個数であった場合の動作は，未定義である。
		 */
		void removeSet(size_t index);

		/**
		 * 面子を全削除する。
		 */
		void clearSets();
	};


	template<class _Elements, class _ElementsIterator>
	inline _ElementsIterator SimpleHand::getHeadElementsIterator(_Elements &elements, uint8_t &)
	{
		_ElementsIterator returnValue = elements.begin();		// 戻り値。

		return returnValue;
	}


	template<class _Elements, class _ElementsConstIterator>
	inline _ElementsConstIterator SimpleHand::getHeadElementsConstIterator(const _Elements &elements, const uint8_t &) const
	{
		_ElementsConstIterator returnValue = elements.cbegin();		// 戻り値。

		return returnValue;
	}


	template<class _Elements, class _ElementsIterator>
	inline _ElementsIterator SimpleHand::getTailElementsIterator(_Elements &elements, uint8_t &elementsSize)
	{
		_ElementsIterator returnValue = elements.begin() + elementsSize;		// 戻り値。

		return returnValue;
	}


	template<class _Elements, class _ElementsConstIterator>
	inline _ElementsConstIterator SimpleHand::getTailElementsConstIterator(const _Elements &elements, const uint8_t &elementsSize) const
	{
		_ElementsConstIterator returnValue = elements.cbegin() + elementsSize;		// 戻り値。

		return returnValue;
	}


	template<class _Element, class _Elements>
	inline const _Element *SimpleHand::getElement(const _Elements &elements, const uint8_t &elementsSize, size_t index) const
	{
		const _Element *returnValue;		// 戻り値。

		// デバッグ版の場合のみ，引数をチェックする。
		assert(0 <= index && index < elementsSize);

		// 要素を取得する。
		returnValue = &elements[index];

		return returnValue;
	}


	template<class _Element, class _Elements>
	inline const _Element *SimpleHand::getFirstElement(const _Elements &elements, const uint8_t &elementsSize) const
	{
		const _Element *returnValue;		// 戻り値。

		// デバッグ版の場合のみ，状態をチェックする。
		assert(elementsSize > 0);

		// 牌を取得する。
		returnValue = &elements[0];

		return returnValue;
	}


	template<class _Element, class _Elements>
	inline const _Element *SimpleHand::getLastElement(const _Elements &elements, const uint8_t &elementsSize) const
	{
		const _Element *returnValue;		// 戻り値。

		// デバッグ版の場合のみ，状態をチェックする。
		assert(elementsSize > 0);

		// 牌を取得する。
		returnValue = &elements[elementsSize - 1];

		return returnValue;
	}


	template<class _Elements>
	inline size_t SimpleHand::countElements(const _Elements &, const uint8_t &elementsSize) const
	{
		size_t returnValue = elementsSize;		// 戻り値。

		return returnValue;
	}


	template<class _Element, class _Elements>
	inline void SimpleHand::setElement(_Elements &elements, uint8_t &elementsSize, size_t index, const _Element &element)
	{
		// デバッグ版の場合のみ，引数をチェックする。
		assert(0 <= index && index < elementsSize);

		// 牌を設定する。
		elements[index] = element;
	}


	template<class _Element, class _Elements>
	inline void SimpleHand::addElement(_Elements &elements, uint8_t &elementsSize, const _Element &element)
	{
		// デバッグ版の場合のみ，状態をチェックする。
		assert(elementsSize < elements.max_size());

		// 牌を追加する。
		elements[elementsSize] = element;
		++elementsSize;
	}


	template<class _Element, class _Elements, class _ElementsIterator>
	inline _ElementsIterator SimpleHand::insertElement(_Elements &elements, uint8_t &elementsSize, _ElementsIterator iterator, const _Element &element)
	{
		// デバッグ版の場合のみ，引数をチェックする。
		assert(elements.begin() <= iterator && iterator <= elements.begin() + elementsSize && elementsSize < elements.max_size());

		// 挿入位置以降にある牌を一つ後ろにずらす。
		if (iterator < elements.begin() + elementsSize) {
			auto headIt = elements.begin();		// 牌集合の先頭を指すイテレータ。
			for (auto it = headIt + elementsSize; it >= iterator && it > headIt; --it) {
				*it = *(it - 1);
			}
		}

		// 挿入位置に牌を設定する。
		*iterator = element;
		++elementsSize;

		return iterator;
	}


	template<class _Element, class _Elements>
	inline void SimpleHand::insertElement(_Elements &elements, uint8_t &elementsSize, size_t index, const _Element &element)
	{
		// デバッグ版の場合のみ，引数をチェックする。
		assert(0 <= index && index <= elementsSize && elementsSize < elements.max_size());

		// 挿入位置以降にある牌を一つ後ろにずらす。
		if (index < elementsSize) {
			for (auto i = elementsSize; i >= index && i > 0; --i) {
				elements[i] = elements[i - 1];
			}
		}

		// 挿入位置に牌を設定する。
		elements[index] = element;
		++elementsSize;
	}


	template<class _Elements, class _ElementsIterator>
	inline _ElementsIterator SimpleHand::removeElement(_Elements &elements, uint8_t &elementsSize, _ElementsIterator iterator)
	{
		// デバッグ版の場合のみ，引数をチェックする。
		assert(elements.begin() <= iterator && iterator < elements.begin() + elementsSize);

		// 削除位置以降にある牌を一つ前にずらす。
		for (auto it = iterator; it < elements.begin() + elementsSize - 1; ++it)
		{
			*it = *(it + 1);
		}

		// 牌の個数を一つ減らす。
		--elementsSize;

		return iterator;
	}


	template<class _Elements>
	inline void SimpleHand::removeElement(_Elements &elements, uint8_t &elementsSize, size_t index)
	{
		// デバッグ版の場合のみ，引数をチェックする。
		assert(0 <= index && index < elementsSize);

		// 削除位置以降にある牌を一つ前にずらす。
		for (auto i = index; i + 1 < elementsSize; ++i)
		{
			elements[i] = elements[i + 1];
		}

		// 牌の個数を一つ減らす。
		--elementsSize;
	}


	template<class _Elements>
	inline void SimpleHand::clearElements(_Elements &, uint8_t &elementsSize)
	{
		elementsSize = 0;
	}
}
