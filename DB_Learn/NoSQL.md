# NoSQL

1. NoSQL(Not Only SQL)

   NoSQL은 단순히 기존 관계형 DAMS가 가지고 있는 특성뿐만 아니라, 다른 특성들을 부가적으로 지원하는 것을 뜻한다.

2. NoSQL (특징)

   기존의 관계형 데이터베이스 보다 더 융통성 있는 데이터 모델을 사용하고, 데이터의 저장 및 검색을 위한 특화된 메커니즘을 제공한다.

   NoSQL 데이터베이스는 단순 검색 및 추가 작업에 있어서 매우 최적화된 키 값 저장 기법으 사용하여, 응답속도나, 처리 효율 등에 있어서 매우 뛰어난 성능을 나타낸다.

   특징

   - 관계형 모델을 사용하지 않으며 테이블간의 조인 기능 없음
   - 직접 프로그래밍을 하는 등의 비SQL 인터페이스를 통한 데이터 액세스
   - 대부분 여러 대의 데이터베이스 서버를 묶어서(클러스터링) 하나의 데이터베이스를 구성
   - 관게형 데이터베이스에서는 지원하는 Data처리 완결성 (Transaction ACID 지원) 미보장
   - 데이터의 스키마와 속성들을 다양하게 수용 및 동적 정의 (Schema-less)
   - 데이터베이스의 중단 없는 서비스와 자동 복구 기능지원
   - 다수가 Open Source로 제공
   - 확장성, 가용성, 높은 성능

   정리하자면 NoSQL은 초고용향 데이터 처리 등 성능에 특화된 목적을 위해 비관계형 데이터 저장소에 비구조적인 데이터를 저장하기 위한 분산 저장 시스템이라고 볼 수 있다.

3. NoSQL 종류

   **Key Value DB**
   Key와 Value의 쌍으로 데이터가 저장되는 가장 단순한 형태의 솔루션으로 Amazon의 Dynamo Paper에서 유래되었습니다. Riak, Vodemort, Tokyo 등의 제품이 많이 알려져 있다.

   **Wide Columnar Store**
   Big Table DB라고도 하며, Google의 BigTable Paper에서 유래되었습니다. Key Value 에서 발전된 형태의 Column Family 데이터 모델을 사용하고 있고, HBase, Cassandra, ScyllaDB 등이 이에 해당한다.

    **Document DB**
   Lotus Notes에서 유래되었으며, JSON, XML과 같은 Collection 데이터 모델 구조를 채택하고 있습니다. MongoDB, CoughDB가 이 종류에 해당한다.

   **Graph DB**
   Euler & Graph Theory에서 유래한 DB입니다. Nodes, Relationship, Key-Value 데이터 모델을 채용하고 있습니다. Neo4J, OreientDB 등의 제품이 있다.

   |               용어               |                      연관 데이터 베이스                      |
   | :------------------------------: | :----------------------------------------------------------: |
   |             KV Store             | Keyspace, Flare, SchemaFree, RAMCloud, Oracle NoSQL Database (OnDB) |
   | KV Store - Eventually consistent | Dynamo, Voldemort, Dynomite, SubRecord, Mo8onDb, DovetailDB  |
   |     KV Store - Hierarchical      |                         GT.m, Cache                          |
   |        KV Store - Ordered        |   TokyoTyrant, Lightcloud, NMDB, Luxio, MemcacheDB, Actord   |
   |             KV Cache             | Memcached, Repcached, Coherence, Hazelcast, Infinispan, EXtremeScale, JBossCache, Velocity, Terracotta |
   |           Tuple Store            |               Gigaspaces, Coord, Apache River                |
   |         Object Database          |                     ZopeDB, DB40, Shoal                      |
   |          Document Store          | CouchDB, Cloudant, Couchbase, MongoDB, Jackrabbit, XML-Databases, ThruDB, CloudKit, Prsevere, Riak-Basho, Scalaris |
   |       Wide Columnar Store        | BigTable, HBase, Apache Cassandra, Hypertable, KAI, OpenNeptune, Qbase, KDI |

   데이터 모델의 종류에 따라 다양한 시스템 특성의 차이가 있다. 아래의 표에서 이러한 비기능적 품질을 나타내고 있다.

   | 데이터 모델          | 성능   | 확장성       | 유연성 | 복잡성 | 기능          |
   | -------------------- | ------ | ------------ | ------ | ------ | ------------- |
   | 키-값 스토어         | 높음   | 높음         | 높음   | 없음   | 가변적 (없음) |
   | 컬럼 지향 스토어     | 높음   | 높음         | 준수   | 낮음   | 최소          |
   | 도큐먼트 지향 스토어 | 높음   | 가변적(높음) | 높음   | 낮음   | 가변적 (낮음) |
   | 그래프 데이터베이스  | 가변적 | 가변적       | 높음   | 높음   | 그래프 이론   |
   | 관계형 데이터베이스  | 가변적 | 가변적       | 낮음   | 준수   | 관계대수      |

   요즘 인기 있는 NoSQL Database MongoDB(Document), HBase(Wide Columnar Store), Cassandra(Wide Columnar Store)

   HBase는 하둡 분산 파일 시스템(HDFS)에서 동작하는 Key-Value 구조 분산 데이터 베이스로, Google의 Bigtable을 참고해서 JAVA로 개발 되었다. 

   Cassandra는 Amazon의 Dynamo의 특징인 Hash 알고리즘을 이용한 “masterless” 아키텍처로 모든 노드가 coordinator 노드와 replica 노드가 될 수 있다.

   현재 가장 인기가 많은 NoSQL인 MongoDB는 10gen(현,MongoDB inc)이 개발한 document-oriented database로 JSON의 2진 버전인 BSON을 사용하여, C++로 개발되었다.

4. NoSQ 데이터베이스 유형

   **키 값:** 키 값 데이터베이스는 분할성이 커서 다른 유형의 데이터베이스로는 불가능한 범위까지 수평 확장을 가능하게 합니다. 게이밍, 광고 기술 및 IoT와 같은 사용 사례에서 키 값 데이터 모델이 특별히 적합하다는 것을 보여준다.

   **문서:** 애플리케이션 코드에서 데이터는 종종 객체 또는 JSON 유사 형식의 문서로 표시됩니다. 이 형식이 개발자에게 효율적이고 직관적인 데이터 모델이기 때문입니다. 문서 데이터베이스를 사용하면 개발자들이 자신의 애플리케이션 코드에서 사용하는 것과 동일한 문서 모델 형식을 사용하여 데이터베이스에서 보다 손쉽게 데이터를 저장하고 쿼리할 수 있습니다. 문서 및 문서 데이터베이스의 유연하고 반구조화된 계층적 특성을 통해 개발자는 계속해서 애플리케이션의 요구를 발전시킬 수 있습니다. 문서 모델은 각 문서가 고유하고 시간에 따라 진화하는 콘텐츠 관리 시스템, 사용자 프로파일 및 카탈로그에서 사용할 수 있다.

   **그래프:** 그래프 데이터베이스의 목적은 고도로 연결된 데이터세트를 사용하는 애플리케이션을 쉽게 구축하고 실행하는 것입니다. 그래프 데이터베이스의 일반적인 사용 사례로는 소셜 네트워킹, 추천 엔진, 사기 감지 및 지식 그래프가 있다.

   **인 메모리:** 게이밍과 광고 기술 애플리케이션에는 밀리초의 응답 시간을 필요로 하며, 언제라도 수신 트래픽이 급등할 수 있는 리더보드, 세션 스토어, 실시간 분석 같은 사용 사례가 있다.

   **검색:** 많은 애플리케이션이 로그를 생성해 개발자들이 문제를 해결하는 데 도움을 준다.

5. NoSQL을 사용해야 하는 이유

   - 유연성: NoSQL 데이터베이스는 일반적으로 유연한 스키마를 제공하여 보다 빠르고 반복적인 개발을 가능하게 해준다. 이같은 유연한 데이터 모델은 NoSQL 데이터베이스를 반정형 및 비정형 데이터에 이상적으로 만들어 준다.
   - 확장성: NoSQL 데이터베이스는 일반적으로 고가의 강력한 서버를 추가하는 대신 분산형 하드웨어 클러스터를 이용해 확장하도록 설계되어있다. 일부 클라우드 제공자들은 완전관리형 서비스로서 이런 운연 작업을 보이지 않게 처리한다.
   - 고성능: NoSQL 데이터베이스는 특정 데이터 모델 및 액세스 패턴에 대해 최적화 되어 관계형 데이터베이스를 통해 유사한 기능을 충족하려 할 때보다 뛰어난 성능을 얻게 해준다.
   - 고기능성: NoSQL 데이터베이스는 각 데이터 모델에 맞춰 특별히 구축된 뀌어난 기능의 APL와 데이터 유형을 제공해준다.