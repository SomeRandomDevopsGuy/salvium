// Copyright (c) 2019, Haven Protocol
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

#pragma once

#include <vector>

#include "serialization.h"
#include "debug_archive.h"
#include "oracle/pricing_record.h"
#include "cryptonote_config.h"

// read
template <template <bool> class Archive>
bool do_serialize(Archive<false> &ar, oracle::supply_data &ad, uint8_t version)
{
  assert(false);
  return false;
}

// write
template <template <bool> class Archive>
bool do_serialize(Archive<true> &ar, oracle::supply_data &sd, uint8_t version)
{
  ar.begin_string();
  ar.serialize_blob(&sd, sizeof(oracle::supply_data), "");
  if (!ar.good())
    return false;
  ar.end_string();
  return true;
}

// read
template <template <bool> class Archive>
bool do_serialize(Archive<false> &ar, oracle::asset_data &ad, uint8_t version)
{
  assert(false);
  return false;
}

// write
template <template <bool> class Archive>
bool do_serialize(Archive<true> &ar, oracle::asset_data &ad, uint8_t version)
{
  ar.begin_string();
  ar.serialize_blob(&ad, sizeof(oracle::asset_data), "");
  if (!ar.good())
    return false;
  ar.end_string();
  return true;
}

// read
template <template <bool> class Archive>
bool do_serialize(Archive<false> &ar, oracle::pricing_record &pr, uint8_t version)
{
  // very basic sanity check
  if (ar.remaining_bytes() < sizeof(oracle::pricing_record)) {
    return false;
  }
  
  ar.serialize_blob(&pr, sizeof(oracle::pricing_record), "");
  if (!ar.good())
    return false;

  return true;
}

// write
template <template <bool> class Archive>
bool do_serialize(Archive<true> &ar, oracle::pricing_record &pr, uint8_t version)
{
  ar.begin_string();
  ar.serialize_blob(&pr, sizeof(oracle::pricing_record), "");
  if (!ar.good())
    return false;
  ar.end_string();
  return true;
}

BLOB_SERIALIZER(oracle::supply_data);
BLOB_SERIALIZER(oracle::asset_data);
BLOB_SERIALIZER(oracle::pricing_record);
