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


#include "OpenRiichiConfiguration.h"
#include "OpenRiichiException.h"


namespace openriichi
{
	/**
	 * 例外である。
	 */
	class OpenRiichiAssertion : public OpenRiichiException
	{
	public:
		/**
		 * 例外を生成する。
		 */
		OpenRiichiAssertion(const char *expression, const char *filePath, unsigned int lineNo);

		/**
		 * 例外を破棄する。
		 */
		virtual ~OpenRiichiAssertion() = default;
	};
}


#if OPENRIICHI_ENABLE_ASSERTION == 0
#	define openriichi_assert(expression) ((void)0)
#else // OPENRIICHI_ENABLE_ASSERTION == 0
#	define openriichi_assert(expression) if (expression) {} else throw openriichi::OpenRiichiAssertion(#expression, __FILE__, __LINE__)
#endif // OPENRIICHI_ENABLE_ASSERTION == 0
