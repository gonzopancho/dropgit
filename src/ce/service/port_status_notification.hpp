
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

#ifndef DROP_SERVICE_PORT_STATUS_NOTIFICATION_HPP_
#define DROP_SERVICE_PORT_STATUS_NOTIFICATION_HPP_

#include <string>
#include <functional>
#include <vector>

#include "service/service.hpp"

#include "router/port_status.hpp"

namespace drop {
namespace service {

constexpr const char psnn[] = "PortStatusNotification";

class PortStatusNotification: public RegisterService<PortStatusNotification, psnn>
{
    using SubscribersBag = std::vector<std::function<void(const std::string&, PortStatus)>>;
public:
    explicit PortStatusNotification(ce::ServiceElement* parent);

    virtual std::ostream& print(std::ostream& os) const override;

    void subscribe(std::function<void(const std::string&, PortStatus)> func);
private:
    ce::ServiceElement* parent_;

    SubscribersBag subscribers_;
};

} // namespace service
} // namespace drop

#endif
