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
//    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef OP_H
#define OP_H
#include <unordered_map>
#include "ClassFileComponent.h"

namespace frenchroast {
  class OpCode {
    BYTE        _code;
    int         _size;
    std::string _name;
    bool        _isBranch;
    bool        _isDynamic;
    static std::unordered_map<BYTE, OpCode> _op_codes;    
  public:
    OpCode(BYTE code, int size,const std::string& name);
    OpCode(BYTE code, int size,const std::string& name,bool isbranch);
    OpCode(BYTE code, int size,const std::string& name,bool isbranch,bool isdynamic);
    OpCode();
    OpCode& operator[](BYTE op);
    operator BYTE() const;
    bool is_branch() const;
    int get_size() const;
    bool is_dynamic() const;
    std::string get_name() const;
    BYTE get_code() const;
    static void load(const std::string& fileName);
  };
}


#endif
