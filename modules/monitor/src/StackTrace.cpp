// copyright (c) 2016 Richard Guadagno
// contact: rrguadagno@gmail.com
//
// This file is part of French-Roast
//
//    French-Roast is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    French-Roast is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with French-Roast.  If not, see <http://www.gnu.org/licenses/>.
//


#include <vector>
#include "StackTrace.h"

namespace frenchroast { namespace monitor {

      StackTrace::StackTrace(const std::string tname) : _thread_name(tname), _key("")
      {
      }

      std::string StackTrace::key()  const
      {
	return _key;
      }

      const std::vector<StackFrame>& StackTrace::frames() const
      {
	return _frames;
      }

      void StackTrace::addFrame(const StackFrame& frame) 
      {
	_key += frame.get_decorated_name();
	_frames.push_back(frame);
      }

      std::string StackTrace::thread_name()  const 
      {
	return _thread_name;
      }

  }
}

