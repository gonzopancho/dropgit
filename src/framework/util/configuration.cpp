
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

#include "configuration.hpp"

namespace tnt {

namespace pt = boost::property_tree;

std::unique_ptr<Configuration> Configuration::instance_;

Configuration::Configuration() {}
Configuration::Configuration(pt::ptree config): config_{ config } {}

void Configuration::default_init()
{
    instance_ = std::make_unique<Configuration>();
}

void Configuration::read(pt::ptree config)
{
	instance_ = std::make_unique<Configuration>(config);
}

bool Configuration::exists(const std::string& path)
{
    return instance_->config_.get_child_optional(path).is_initialized();
}

Configuration::ConfigurationProxy::ConfigurationProxy(pt::ptree config, const std::string& key): config_{ config }, key_{ key } {}

const Configuration::ConfigurationProxy Configuration::get(const std::string& key)
{
    return ConfigurationProxy(instance_->config_, key);
}

} // namespace tnt