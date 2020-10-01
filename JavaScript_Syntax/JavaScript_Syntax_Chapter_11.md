# Chapter 11

1. immutable value vs. mutable value

   원시타입은 변경 불가능한 값이고 객체 타입은 병경 가능한 값이다. 즉 객체는 새로운 값을 다시 만들 필요없이 직접 변경이 가능하다는 것이다. 변경 불가능한 값을 primitive value라 한다.

2. 불변 데이터 패턴

   의도하지 않은 객체의 변경이 발생하는 원인의 대다수는 “레퍼런스를 참조한 다른 객체에서 객체를 변경”하기 때문이다. 해결 방법은 비용은 조금 들지만 객체를 불변객체로 만들어 프로퍼티의 변경을 방지하며 객체의 변경이 필요한 경우에는 참조가 아닌 객체의 방어적 복사(defensive copy)를 통해 새로운 객체를 생성한 후 변경하는 것이다.

   - 객체의 방어적 복사(defensive copy)

     Object.assign

     

   - 불변객체화를 통한 객체 변경 방지

     Object.freeze

     

   - Object.assign은 타킷 객체로 소스 객체의 프로퍼티를 복사한다. 이때 소스 객체의 프로퍼티와 동일한 프로퍼티를 가진 타켓 객체의 프로퍼티들은 소스 객체의 프로퍼티로 덮어쓰기된다. 리턴값으로 타킷 객체를 반환한다.

     

   - [Object.freeze()](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Object/freeze)를 사용하여 불변(immutable) 객체로 만들수 있다. 객체 내부의 객체는 변경가능하다.

      

   - 위 방법들은 번거롭고 성능상 이슈가 있어 큰 객체에는 사용하지 않는 것이 좋다. 대안으로 Immutable.js를 사용하는 방법이 있다.