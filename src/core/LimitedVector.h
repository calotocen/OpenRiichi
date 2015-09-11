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


#include <algorithm>
#include <array>
#include <cassert>
#include <cstdint>


namespace openriichi
{
	/**
	 * 有限可変長配列である。
	 */
	template<class T, size_t size, typename SizeType = uint8_t>
	class LimitedVector
	{
	private:
		/// 固定長配列型。
		using Elements = typename std::array<T, size>;


	public:
		/// イテレータ型。
		using Iterator = typename Elements::iterator;

		/// Const イテレータ型。
		using ConstIterator = typename Elements::const_iterator;


	private:
		/// 固定長配列。
		Elements m_elements;

		/// 要素の個数。
		SizeType m_elementsSize;


	public:
		/**
		 * 有限可変長配列を生成する。
		 */
		LimitedVector();


	public:
		/**
		 * 他の有限可変長配列と等しいか調べる。
		 *
		 * @param[in] other 他の有限可変長配列。
		 */
		bool operator==(const LimitedVector<T, size, SizeType> &other) const;

		/**
		 * 他の有限可変長配列と等しくないか調べる。
		 *
		 * @param[in] other 他の有限可変長配列。
		 */
		bool operator!=(const LimitedVector<T, size, SizeType> &other) const;


	public:
		/**
		 * 配列の先頭を指すイテレータを返す。
		 *
		 * @return 配列の先頭を指すイテレータ。
		 */
		Iterator getHeadIterator();

		/**
		 * 配列の先頭を指すイテレータを返す。
		 *
		 * @return 配列の先頭を指すイテレータ。
		 */
		ConstIterator getHeadConstIterator() const;

		/**
		 * 配列の末尾を指すイテレータを返す。
		 *
		 * @return 配列の末尾を指すイテレータ。
		 */
		Iterator getTailIterator();

		/**
		 * 配列の末尾を指すイテレータを返す。
		 *
		 * @return 配列の末尾を指すイテレータ。
		 */
		ConstIterator getTailConstIterator() const;

		/**
		 * 指定された位置にある要素を返す。
		 *
		 * @param[in] index 位置。
		 * @return 要素。
		 * @note 配列の範囲外を位置に指定した場合の動作は，未定義である。
		 */
		const T &get(size_t index) const;

		/**
		 * 先頭にある要素を返す。
		 *
		 * @return 要素。
		 * @note 配列が空であった場合の動作は，未定義である。
		 */
		const T &getFirst() const;

		/**
		 * 末尾にある要素を返す。
		 *
		 * @return 要素。
		 * @note 配列が空であった場合の動作は，未定義である。
		 */
		const T &getLast() const;

		/**
		 * 配列が空であるかを返す。
		 *
		 * @return 配列が空である場合は true を，それ以外は false を返す。
		 */
		bool isEmpty() const;

		/**
		 * 要素の個数を返す。
		 *
		 * @return 要素の個数。
		 */
		size_t count() const;

		/**
		 * 要素を指定された位置に設定する。
		 *
		 * @param[in] index 位置。
		 * @param[in] element 要素。
		 * @note 配列の範囲外を位置に指定した場合の動作は，未定義である。
		 */
		void set(size_t index, const T &element);

		/**
		 * 末尾に要素を追加する。
		 *
		 * @param[in] element 要素。
		 * @note 配列の要素個数が既に最大個数であった場合の動作は，未定義である。
		 */
		void add(const T &element);

		/**
		 * 要素を指定された位置に挿入する。
		 *
		 * @param[in] iterator 位置。
		 * @param[in] element 要素。
		 * @return 挿入した要素を指すイテレータ。
		 * @note 配列の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 配列の要素個数が既に最大個数であった場合の動作は，未定義である。
		 */
		Iterator insert(Iterator iterator, const T &element);

		/**
		 * 要素を指定された位置に挿入する。
		 *
		 * @param[in] index 位置。
		 * @param[in] element 要素。
		 * @note 配列の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 配列の要素個数が既に最大個数であった場合の動作は，未定義である。
		 */
		void insert(size_t index, const T &element);

		/**
		 * 指定された位置にある要素を削除する。
		 *
		 * @param[in] iterator 位置。
		 * @return 削除した要素の次の要素を指すイテレータ。
		 * @note 配列の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 配列の要素個数が既に最大個数であった場合の動作は，未定義である。
		 */
		Iterator remove(Iterator iterator);

		/**
		 * 指定された位置にある要素を削除する。
		 *
		 * @param[in] index 位置。
		 * @note 配列の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 配列の要素個数が既に最大個数であった場合の動作は，未定義である。
		 */
		void remove(size_t index);

		/**
		 * 要素を全削除する。
		 */
		void clear();
	};


	template<class T, size_t size, typename SizeType>
	LimitedVector<T, size, SizeType>::LimitedVector()
		: m_elements()
		, m_elementsSize(0)
	{
		// 何もしない。
	}


	template<class T, size_t size, typename SizeType>
	bool LimitedVector<T, size, SizeType>::operator==(const LimitedVector<T, size, SizeType> &other) const
	{
		// 自分自身との比較であれば，true を返す。
		if (this == &other)
		{
			return true;
		}

		// 要素数が異なる場合は，false を返す。
		if (m_elementsSize != other.m_elementsSize)
		{
			return false;
		}

		// 要素を比較して，その結果を返す。
		return std::equal(m_elements.begin(), m_elements.begin() + m_elementsSize, other.m_elements.begin());
	}


	template<class T, size_t size, typename SizeType>
	bool LimitedVector<T, size, SizeType>::operator!=(const LimitedVector<T, size, SizeType>& other) const
	{
		return !(*this == other);
	}


	template<class T, size_t size, typename SizeType>
	typename LimitedVector<T, size, SizeType>::Iterator LimitedVector<T, size, SizeType>::getHeadIterator()
	{
		Iterator returnValue = m_elements.begin();		// 戻り値。

		return returnValue;
	}


	template<class T, size_t size, typename SizeType>
	typename LimitedVector<T, size, SizeType>::ConstIterator LimitedVector<T, size, SizeType>::getHeadConstIterator() const
	{
		ConstIterator returnValue = m_elements.cbegin();		// 戻り値。

		return returnValue;
	}


	template<class T, size_t size, typename SizeType>
	typename LimitedVector<T, size, SizeType>::Iterator LimitedVector<T, size, SizeType>::getTailIterator()
	{
		Iterator returnValue = m_elements.begin() + m_elementsSize;		// 戻り値。

		return returnValue;
	}


	template<class T, size_t size, typename SizeType>
	typename LimitedVector<T, size, SizeType>::ConstIterator LimitedVector<T, size, SizeType>::getTailConstIterator() const
	{
		ConstIterator returnValue = m_elements.cbegin() + m_elementsSize;		// 戻り値。

		return returnValue;
	}


	template<class T, size_t size, typename SizeType>
	const T &LimitedVector<T, size, SizeType>::get(size_t index) const
	{
		// デバッグ版の場合のみ，引数をチェックする。
		assert(0 <= index && index < m_elementsSize);

		// 要素を返す。
		return m_elements[index];
	}


	template<class T, size_t size, typename SizeType>
	const T &LimitedVector<T, size, SizeType>::getFirst() const
	{
		// デバッグ版の場合のみ，状態をチェックする。
		assert(m_elementsSize > 0);

		// 要素を返す。
		return m_elements[0];
	}


	template<class T, size_t size, typename SizeType>
	const T &LimitedVector<T, size, SizeType>::getLast() const
	{
		// デバッグ版の場合のみ，状態をチェックする。
		assert(m_elementsSize > 0);

		// 要素を返す。
		return m_elements[m_elementsSize - 1];
	}


	template<class T, size_t size, typename SizeType>
	bool LimitedVector<T, size, SizeType>::isEmpty() const
	{
		bool returnValue = m_elementsSize == 0;		// 戻り値。

		return returnValue;
	}


	template<class T, size_t size, typename SizeType>
	size_t LimitedVector<T, size, SizeType>::count() const
	{
		size_t returnValue = m_elementsSize;		// 戻り値。

		return returnValue;
	}


	template<class T, size_t size, typename SizeType>
	void LimitedVector<T, size, SizeType>::set(size_t index, const T &element)
	{
		// デバッグ版の場合のみ，引数をチェックする。
		assert(0 <= index && index < m_elementsSize);

		// 要素を設定する。
		m_elements[index] = element;
	}


	template<class T, size_t size, typename SizeType>
	void LimitedVector<T, size, SizeType>::add(const T &element)
	{
		// デバッグ版の場合のみ，状態をチェックする。
		assert(m_elementsSize < m_elements.max_size());

		// 要素を追加する。
		m_elements[m_elementsSize] = element;
		++m_elementsSize;
	}


	template<class T, size_t size, typename SizeType>
	typename LimitedVector<T, size, SizeType>::Iterator LimitedVector<T, size, SizeType>::insert(Iterator iterator, const T &element)
	{
		// デバッグ版の場合のみ，引数をチェックする。
		assert(m_elements.begin() <= iterator && iterator <= m_elements.begin() + m_elementsSize && m_elementsSize < m_elements.max_size());

		// 挿入位置以降にある要素を一つ後ろにずらす。
		if (iterator < m_elements.begin() + m_elementsSize) {
			auto headIt = m_elements.begin();		// 配列の先頭を指すイテレータ。

			for (auto it = headIt + m_elementsSize; it >= iterator && it > headIt; --it) {
				*it = *(it - 1);
			}
		}

		// 挿入位置に要素を設定する。
		*iterator = element;
		++m_elementsSize;

		return iterator;
	}


	template<class T, size_t size, typename SizeType>
	void LimitedVector<T, size, SizeType>::insert(size_t index, const T &element)
	{
		// デバッグ版の場合のみ，引数をチェックする。
		assert(0 <= index && index <= m_elementsSize && m_elementsSize < m_elements.max_size());

		// 挿入位置以降にある要素を一つ後ろにずらす。
		if (index < m_elementsSize) {
			for (auto i = m_elementsSize; i >= index && i > 0; --i) {
				m_elements[i] = m_elements[i - 1];
			}
		}

		// 挿入位置に要素を設定する。
		m_elements[index] = element;
		++m_elementsSize;
	}


	template<class T, size_t size, typename SizeType>
	typename LimitedVector<T, size, SizeType>::Iterator LimitedVector<T, size, SizeType>::remove(Iterator iterator)
	{
		// デバッグ版の場合のみ，引数をチェックする。
		assert(m_elements.begin() <= iterator && iterator < m_elements.begin() + m_elementsSize);

		// 削除位置以降にある要素を一つ前にずらす。
		for (auto it = iterator; it < m_elements.begin() + m_elementsSize - 1; ++it)
		{
			*it = *(it + 1);
		}

		// 要素の個数を一つ減らす。
		--m_elementsSize;

		return iterator;
	}


	template<class T, size_t size, typename SizeType>
	void LimitedVector<T, size, SizeType>::remove(size_t index)
	{
		// デバッグ版の場合のみ，引数をチェックする。
		assert(0 <= index && index < m_elementsSize);

		// 削除位置以降にある要素を一つ前にずらす。
		for (auto i = index; i + 1 < m_elementsSize; ++i)
		{
			m_elements[i] = m_elements[i + 1];
		}

		// 要素の個数を一つ減らす。
		--m_elementsSize;
	}


	template<class T, size_t size, typename SizeType>
	void LimitedVector<T, size, SizeType>::clear()
	{
		m_elementsSize = 0;
	}
}
