# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.

FROM ubuntu:16.04

RUN apt-get update && apt-get install -y --no-install-recommends \
    gfortran libsqlite3-dev libmysqlclient-dev libcurl4-openssl-dev python3 libopenblas-dev liblapack3 && \
    apt-get remove --purge -y && \
    rm -rf /var/lib/apt/lists/*

RUN ln -s /usr/lib/x86_64-linux-gnu/libmysqlclient.so /usr/lib/x86_64-linux-gnu/libmysqlclient_r.so

COPY ./milvus /var/lib/milvus
COPY ./docker-entrypoint.sh /var/lib/milvus
ENV LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/var/lib/milvus/lib"

WORKDIR /var/lib/milvus

ENTRYPOINT [ "/var/lib/milvus/docker-entrypoint.sh" ]

CMD [ "start" ]

EXPOSE 19530
