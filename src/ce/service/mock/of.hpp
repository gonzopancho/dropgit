
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

#ifndef DROP_SERVICE_MOCK_OPENFLOW_MANAGEMENT_HPP_
#define DROP_SERVICE_MOCK_OPENFLOW_MANAGEMENT_HPP_

#include <iosfwd>
#include <vector>

#include "protocol/openflow/flow.hpp"

#include "service/service.hpp"
#include "service/openflow.hpp"

namespace drop {
namespace service {

constexpr const char mon[] = "MockOpenflowManagement";

class MockOpenflowManagement: public RegisterService<MockOpenflowManagement, mon>, public virtual Openflow
{
public:
    explicit MockOpenflowManagement(ce::ServiceElement* parent);

    virtual std::ostream& print(std::ostream& os) const override;

    virtual void add(const protocol::Flow& flow) override;
    virtual void remove(const protocol::Flow& flow) override;

    virtual const std::vector<protocol::Flow>& flows() const override;
private:
    std::vector<protocol::Flow> flows_;
};

} // namespace service
} // namespace drop

#endif