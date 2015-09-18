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
#include <cstdint>
#include <initializer_list>
#include "OpenRiichiAssertion.h"


namespace openriichi
{
	/**
	 * 有限可変長配列である。
	 */
	template<class T, size_t SIZE, typename SizeType = uint8_t>
	class LimitedVector
	{
	private:
		/// 固定長配列型。
		using Elements = typename std::array<T, SIZE>;


	public:
		/// イテレータ型。
		using iterator = typename Elements::iterator;

		/// Const イテレータ型。
		using const_iterator = typename Elements::const_iterator;


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

		/**
		 * 有限可変長配列を生成する。
		 *
		 * @param[in] list 初期値。
		 */
		LimitedVector(const std::initializer_list<T> &list);


	public:
		/**
		 * 他の有限可変長配列と等しいか調べる。
		 *
		 * @param[in] other 他の有限可変長配列。
		 */
		bool operator==(const LimitedVector<T, SIZE, SizeType> &other) const;

		/**
		 * 他の有限可変長配列と等しくないか調べる。
		 *
		 * @param[in] other 他の有限可変長配列。
		 */
		bool operator!=(const LimitedVector<T, SIZE, SizeType> &other) const;

		/**
		 * 代入する。
		 *
		 * @param[in] list 代入値。
		 */
		LimitedVector<T, SIZE, SizeType> &operator=(const std::initializer_list<T> &list);

		/**
		 * 指定された位置にある要素を返す。
		 *
		 * @param[in] index 位置。
		 * @return 要素。
		 * @note 配列の範囲外を位置に指定した場合の動作は，未定義である。
		 */
		T &operator[](SizeType index);

		/**
		 * 指定された位置にある要素を返す。
		 *
		 * @param[in] index 位置。
		 * @return 要素。
		 * @note 配列の範囲外を位置に指定した場合の動作は，未定義である。
		 */
		const T &operator[](SizeType index) const;


	public:
		/**
		 * 配列の先頭を指すイテレータを返す。
		 *
		 * @return 配列の先頭を指すイテレータ。
		 */
		iterator begin();

		/**
		 * 配列の先頭を指すイテレータを返す。
		 *
		 * @return 配列の先頭を指すイテレータ。
		 */
		const_iterator begin() const;

		/**
		 * 配列の末尾を指すイテレータを返す。
		 *
		 * @return 配列の末尾を指すイテレータ。
		 */
		iterator end();

		/**
		 * 配列の末尾を指すイテレータを返す。
		 *
		 * @return 配列の末尾を指すイテレータ。
		 */
		const_iterator end() const;

		/**
		 * 指定された位置にある要素を返す。
		 *
		 * @param[in] index 位置。
		 * @return 要素。
		 * @note 配列の範囲外を位置に指定した場合の動作は，未定義である。
		 */
		T &at(SizeType index);

		/**
		 * 指定された位置にある要素を返す。
		 *
		 * @param[in] index 位置。
		 * @return 要素。
		 * @note 配列の範囲外を位置に指定した場合の動作は，未定義である。
		 */
		const T &at(SizeType index) const;

		/**
		 * 先頭にある要素を返す。
		 *
		 * @return 要素。
		 * @note 配列が空であった場合の動作は，未定義である。
		 */
		const T &front() const;

		/**
		 * 末尾にある要素を返す。
		 *
		 * @return 要素。
		 * @note 配列が空であった場合の動作は，未定義である。
		 */
		const T &back() const;

		/**
		 * 配列が空であるかを返す。
		 *
		 * @return 配列が空である場合は true を，それ以外は false を返す。
		 */
		bool empty() const;

		/**
		 * 要素の個数を返す。
		 *
		 * @return 要素の個数。
		 */
		SizeType size() const;

		/**
		 * 末尾に要素を追加する。
		 *
		 * @param[in] element 要素。
		 * @note 配列の要素個数が既に最大個数であった場合の動作は，未定義である。
		 */
		void push_back(const T &element);

		/**
		 * 要素を指定された位置に挿入する。
		 *
		 * @param[in] iterator 位置。
		 * @param[in] element 要素。
		 * @return 挿入した要素を指すイテレータ。
		 * @note 配列の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 配列の要素個数が既に最大個数であった場合の動作は，未定義である。
		 */
		iterator insert(const_iterator iterator, const T &element);

		/**
		 * 指定された位置にある要素を削除する。
		 *
		 * @param[in] iterator 位置。
		 * @return 削除した要素の次の要素を指すイテレータ。
		 * @note 配列の範囲外を位置に指定した場合の動作は，未定義である。
		 * @note 配列の要素個数が既に最大個数であった場合の動作は，未定義である。
		 */
		iterator erase(const_iterator iterator);

		/**
		 * 要素を全削除する。
		 */
		void clear();
	};


	template<class T, size_t SIZE, typename SizeType>
	LimitedVector<T, SIZE, SizeType>::LimitedVector()
		: m_elements()
		, m_elementsSize(0)
	{
		// 何もしない。
	}


	template<class T, size_t SIZE, typename SizeType>
	LimitedVector<T, SIZE, SizeType>::LimitedVector(const std::initializer_list<T> &list)
		: m_elements()
		, m_elementsSize(static_cast<SizeType>(list.size()))
	{
		// アサーションが有効である場合のみ，引数をチェックする。
		openriichi_assert(list.size() <= SIZE);

		// 要素を設定する。
		std::copy(list.begin(), list.end(), m_elements.begin());
	}


	template<class T, size_t SIZE, typename SizeType>
	bool LimitedVector<T, SIZE, SizeType>::operator==(const LimitedVector<T, SIZE, SizeType> &other) const
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


	template<class T, size_t SIZE, typename SizeType>
	bool LimitedVector<T, SIZE, SizeType>::operator!=(const LimitedVector<T, SIZE, SizeType> &other) const
	{
		return !(*this == other);
	}


	template<class T, size_t SIZE, typename SizeType>
	LimitedVector<T, SIZE, SizeType> &LimitedVector<T, SIZE, SizeType>::operator=(const std::initializer_list<T> &list)
	{
		// アサーションが有効である場合のみ，引数をチェックする。
		openriichi_assert(list.size() <= SIZE);

		// 要素を設定する。
		std::copy(list.begin(), list.end(), m_elements.begin());
		m_elementsSize = static_cast<SizeType>(list.size());

		return *this;
	}


	template<class T, size_t SIZE, typename SizeType>
	T &LimitedVector<T, SIZE, SizeType>::operator[](SizeType index)
	{
		// アサーションが有効である場合のみ，引数をチェックする。
		openriichi_assert(0 <= index && index < m_elementsSize);

		// 要素を返す。
		return m_elements[index];
	}


	template<class T, size_t SIZE, typename SizeType>
	const T &LimitedVector<T, SIZE, SizeType>::operator[](SizeType index) const
	{
		// アサーションが有効である場合のみ，引数をチェックする。
		openriichi_assert(0 <= index && index < m_elementsSize);

		// 要素を返す。
		return m_elements[index];
	}


	template<class T, size_t SIZE, typename SizeType>
	typename LimitedVector<T, SIZE, SizeType>::iterator LimitedVector<T, SIZE, SizeType>::begin()
	{
		return m_elements.begin();
	}


	template<class T, size_t SIZE, typename SizeType>
	typename LimitedVector<T, SIZE, SizeType>::const_iterator LimitedVector<T, SIZE, SizeType>::begin() const
	{
		return m_elements.cbegin();
	}


	template<class T, size_t SIZE, typename SizeType>
	typename LimitedVector<T, SIZE, SizeType>::iterator LimitedVector<T, SIZE, SizeType>::end()
	{
		return m_elements.begin() + m_elementsSize;
	}


	template<class T, size_t SIZE, typename SizeType>
	typename LimitedVector<T, SIZE, SizeType>::const_iterator LimitedVector<T, SIZE, SizeType>::end() const
	{
		return m_elements.cbegin() + m_elementsSize;
	}


	template<class T, size_t SIZE, typename SizeType>
	T &LimitedVector<T, SIZE, SizeType>::at(SizeType index)
	{
		// アサーションが有効である場合のみ，引数をチェックする。
		openriichi_assert(0 <= index && index < m_elementsSize);

		// 要素を返す。
		return m_elements[index];
	}


	template<class T, size_t SIZE, typename SizeType>
	const T &LimitedVector<T, SIZE, SizeType>::at(SizeType index) const
	{
		// アサーションが有効である場合のみ，引数をチェックする。
		openriichi_assert(0 <= index && index < m_elementsSize);

		// 要素を返す。
		return m_elements[index];
	}


	template<class T, size_t SIZE, typename SizeType>
	const T &LimitedVector<T, SIZE, SizeType>::front() const
	{
		// アサーションが有効である場合のみ，状態をチェックする。
		openriichi_assert(m_elementsSize > 0);

		// 要素を返す。
		return m_elements[0];
	}


	template<class T, size_t SIZE, typename SizeType>
	const T &LimitedVector<T, SIZE, SizeType>::back() const
	{
		// アサーションが有効である場合のみ，状態をチェックする。
		openriichi_assert(m_elementsSize > 0);

		// 要素を返す。
		return m_elements[m_elementsSize - 1];
	}


	template<class T, size_t SIZE, typename SizeType>
	bool LimitedVector<T, SIZE, SizeType>::empty() const
	{
		return m_elementsSize == 0;
	}


	template<class T, size_t SIZE, typename SizeType>
	SizeType LimitedVector<T, SIZE, SizeType>::size() const
	{
		return m_elementsSize;
	}


	template<class T, size_t SIZE, typename SizeType>
	void LimitedVector<T, SIZE, SizeType>::push_back(const T &element)
	{
		// アサーションが有効である場合のみ，状態をチェックする。
		openriichi_assert(m_elementsSize < m_elements.max_size());

		// 要素を追加する。
		m_elements[m_elementsSize] = element;
		++m_elementsSize;
	}


	template<class T, size_t SIZE, typename SizeType>
	typename LimitedVector<T, SIZE, SizeType>::iterator LimitedVector<T, SIZE, SizeType>::insert(const_iterator iterator, const T &element)
	{
		// アサーションが有効である場合のみ，引数をチェックする。
		openriichi_assert(m_elements.begin() <= iterator && iterator <= m_elements.begin() + m_elementsSize && m_elementsSize < m_elements.max_size());

		// 挿入位置以降にある要素を一つ後ろにずらす。
		Elements::difference_type index = iterator - m_elements.begin();
		if (index < m_elementsSize) {
			for (auto i = m_elementsSize; i >= index && i > 0; --i) {
				m_elements[i] = m_elements[i - 1];
			}
		}

		// 挿入位置に要素を設定する。
		m_elements[index] = element;
		++m_elementsSize;

		return m_elements.begin() + index;
	}


	template<class T, size_t SIZE, typename SizeType>
	typename LimitedVector<T, SIZE, SizeType>::iterator LimitedVector<T, SIZE, SizeType>::erase(const_iterator iterator)
	{
		// アサーションが有効である場合のみ，引数をチェックする。
		openriichi_assert(m_elements.begin() <= iterator && iterator < m_elements.begin() + m_elementsSize);

		// 削除位置以降にある要素を一つ前にずらす。
		Elements::difference_type index = iterator - m_elements.begin();
		for (auto i = index; i + 1 < m_elementsSize; ++i)
		{
			m_elements[i] = m_elements[i + 1];
		}

		// 要素の個数を一つ減らす。
		--m_elementsSize;

		return m_elements.begin() + index;
	}


	template<class T, size_t SIZE, typename SizeType>
	void LimitedVector<T, SIZE, SizeType>::clear()
	{
		m_elementsSize = 0;
	}
}
