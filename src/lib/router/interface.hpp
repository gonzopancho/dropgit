
/*

Copyright (c) 2013, Sergio Mangialardi (sergio@reti.dist.unige.it)
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list 
of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice, this 
list of conditions and the following disclaimer in the documentation and/or 
other materials provided with the distribution.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE 
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef DROP_ROUTER_INTERFACE_HPP_
#define DROP_ROUTER_INTERFACE_HPP_

#include <vector>
#include <memory>
#include <iosfwd>
#include <iterator>

#include "mac_address.hpp"

namespace drop {
namespace router {

class Interface
{
public:
    Interface(uint32_t index, const std::string& name, const tnt::MacAddress& hw);

    uint32_t index() const;
    uint32_t flags() const;
    std::string name() const;
    const tnt::MacAddress& hw_address() const;

    bool running() const;
private:
    uint32_t index_;
    uint32_t flags_;
    std::string name_;
    tnt::MacAddress hw_address_;
};

std::ostream& operator<<(std::ostream& os, const Interface& interface);

} // namespace router
} // namespace drop

#endif