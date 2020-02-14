// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#pragma once

#include <faiss/Index.h>

#include <cstdint>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "db/engine/ExecutionEngine.h"
#include "segment/Types.h"

namespace milvus {
namespace engine {

typedef segment::doc_id_t IDNumber;
typedef IDNumber* IDNumberPtr;
typedef std::vector<IDNumber> IDNumbers;

typedef std::vector<faiss::Index::idx_t> ResultIds;
typedef std::vector<faiss::Index::distance_t> ResultDistances;

struct TableIndex {
    int32_t engine_type_ = (int)EngineType::FAISS_IDMAP;
    int32_t nlist_ = 16384;
    int32_t metric_type_ = (int)MetricType::L2;
};

struct VectorsData {
    uint64_t vector_count_ = 0;
    std::vector<float> float_data_;
    std::vector<uint8_t> binary_data_;
    IDNumbers id_array_;
};

using File2RefCount = std::map<std::string, int64_t>;
using Table2Files = std::map<std::string, File2RefCount>;

struct SegmentStat {
    std::string name_;
    int64_t row_count_ = 0;
};

struct TableStat {
    std::string name_;
    std::vector<SegmentStat> segments_stat_;
};

struct TableInfo {
    TableStat native_stat_;
    std::vector<TableStat> partitions_stat_;
};

}  // namespace engine
}  // namespace milvus
