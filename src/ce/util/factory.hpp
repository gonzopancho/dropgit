
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

#ifndef DROP_UTIL_FACTORY_HPP_
#define DROP_UTIL_FACTORY_HPP_

#include <memory>

namespace tnt {

struct Protocol;
struct IO;

} // namespace tnt

namespace activity {

struct ProfileScheduler;

} // namespace activity

namespace drop {

struct LocalControlPolicyTask;

} // namespace drop

namespace factory {

std::shared_ptr<drop::LocalControlPolicyTask> create_lcp_process();
std::shared_ptr<activity::ProfileScheduler> create_scheduler();
std::shared_ptr<tnt::Protocol> create_kernel_protocol();
std::shared_ptr<tnt::Protocol> create_deth_protocol();
std::shared_ptr<tnt::Protocol> create_drop_protocol(const std::shared_ptr<tnt::IO>& io);

} // namespace factory

#endif
