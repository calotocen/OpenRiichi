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
	template<class T>
	class Enumeration
	{
	private:
		int m_id;


	public:
		/**
		 * 列挙型を生成する。
		 */
		Enumeration();

		/**
		 * 列挙型を生成する。
		 *
		 * @param[in] id ID。
		 */
		explicit Enumeration(int id);

		/**
		 * 列挙型を破棄する。
		 */
		virtual ~Enumeration() = default;


	public:
		/**
		 * 他の列挙型と等しいか調べる。
		 *
		 * @param[in] other 他の列挙型。
		 */
		bool operator==(const Enumeration<T> &other) const;

		/**
		 * 他の列挙型と等しくないか調べる。
		 *
		 * @param[in] other 他の列挙型。
		 */
		bool operator!=(const Enumeration<T> &other) const;


	public:
		/**
		 * 関連のある列挙型間で一意の値を返す。
		 *
		 * @return 関連のある列挙型間で一意の値。
		 */
		int getId() const;
	};


	template<class T>
	Enumeration<T>::Enumeration()
		: Enumeration(0)
	{
		// 何もしない。
	}

	template<class T>
	Enumeration<T>::Enumeration(int id)
		: m_id(id)
	{
		// 何もしない。
	}

	template<class T>
	bool Enumeration<T>::operator==(const Enumeration<T> &other) const
	{
		return m_id == other.m_id;
	}


	template<class T>
	bool Enumeration<T>::operator!=(const Enumeration<T> &other) const
	{
		return m_id != other.m_id;
	}


	template<class T>
	int Enumeration<T>::getId() const
	{
		return m_id;
	}
}
