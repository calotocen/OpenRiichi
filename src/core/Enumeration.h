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


namespace openriichi
{
	/**
	 * 列挙型である。
	 */
	template<class _T>
	class Enumeration
	{
	public:
		/**
		 * 列挙型を破棄する。
		 */
		virtual ~Enumeration();


	public:
		/**
		 * 他の列挙型と等しいか調べる。
		 *
		 * @param[in] other 他の列挙型。
		 */
		bool operator==(const Enumeration<_T> &other) const;

		/**
		 * 他の列挙型と等しくないか調べる。
		 *
		 * @param[in] other 他の列挙型。
		 */
		bool operator!=(const Enumeration<_T> &other) const;


	public:
		/**
		 * 関連のある列挙型間で一意の値を返す。
		 *
		 * @return 関連のある列挙型間で一意の値。
		 */
		virtual int getId() const = 0;
	};


	template<class _T>
	Enumeration<_T>::~Enumeration()
	{
		// 何もしない。
	}


	template<class _T>
	bool Enumeration<_T>::operator==(const Enumeration<_T> &other) const
	{
		return getId() == other.getId();
	}


	template<class _T>
	bool Enumeration<_T>::operator!=(const Enumeration<_T> &other) const
	{
		return getId() != other.getId();
	}
}
