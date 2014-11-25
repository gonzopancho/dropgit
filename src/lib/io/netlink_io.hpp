
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

#ifndef DROP_IO_NETLINK_IO_HPP_
#define DROP_IO_NETLINK_IO_HPP_

#include <memory>
#include <array>
#include <string>
#include <string>

#include <sys/socket.h>
#include <linux/netlink.h>

#include "io/io.hpp"

namespace drop {
namespace io {

enum class NetlinkSocketProtocol
{
    NetlinkRoute = NETLINK_ROUTE,
    NetlinkDeth = 31                // NETLINK_DETH in kernel_modules/virtual_interfaces/deth.c
};

class NetlinkIO: public tnt::IO
{
public:
    explicit NetlinkIO(NetlinkSocketProtocol proto);

    virtual void reset() override;
    virtual std::string read() override;
    virtual bool try_read(std::string& data) override;
    virtual void write(const std::string& message) override;
private:
    std::string do_read();
private:
    static const size_t buff_len = 1024 * 1024;
    int sock_fd_;
    std::array<char, buff_len> buff_;
};

} // namespace io
} // namespace drop

#endif
