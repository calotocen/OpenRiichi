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
#include <cstdio>
#include "OpenRiichi.h"


using namespace openriichi;


OpenRiichiException::OpenRiichiException(const char *message)
	: m_message()
{
	if (message == nullptr) {
		message = "";
	}

	snprintf(m_message, sizeof(m_message), "%s", message);
}


const char *OpenRiichiException::getMessage() const
{
	return m_message;
}
