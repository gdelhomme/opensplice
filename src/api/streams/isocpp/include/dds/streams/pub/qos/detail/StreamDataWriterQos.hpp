#ifndef DDS_STREAMS_PUB_QOS_DETAIL_STREAM_DATA_WRITER_QOS_HPP_
#define DDS_STREAMS_PUB_QOS_DETAIL_STREAM_DATA_WRITER_QOS_HPP_
/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to TO_YEAR PrismTech
 *   Limited, its affiliated companies and licensors. All rights reserved.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */

/**
 * @file
 */

#include <dds/core/TEntityQos.hpp>
#include <org/opensplice/streams/pub/qos/StreamDataWriterQosImpl.hpp>

namespace dds
{
namespace streams
{
namespace pub
{
namespace qos
{
namespace detail
{

typedef dds::core::TEntityQos<org::opensplice::streams::pub::qos::StreamDataWriterQosImpl> StreamDataWriterQos;

}
}
}
}
}

#endif /* DDS_STREAMS_PUB_QOS_DETAIL_STREAM_DATA_WRITER_QOS_HPP_ */
