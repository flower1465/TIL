# Chapter 10

1. 객체

   객체 - 원시 타입을 제외한 나머지 값들(함수, 배열, 정규표현식 등) 모두이다.

   ​			JS의 객체는 키와 값으로 구성된 프로퍼티들의 집합이다. 

   ​			프로퍼티의 값으로 JS에서 사용할 수 있는 모든 값을 사용할 수 있다.

   ​			JS의 함수는 일급 객체이므로 값으로 취급할 수 있다. 따라서 프로퍼티 값으로 함수를 사용할 수도 있으며 프로퍼티 값이 함수일 경우, 일반 함수와 구분하기 위해 메소드라 부른다.

   객체는 데이터를 의미하는 프로퍼티와 데이터를 참조하고 조작할 수 있는 동작을 의미하는 메소드로 구성된 집합이다. 데이터(프로퍼티)와 그 데이터에 관련되는 동작(메소드)을 모두 포함할 수 있기 때문에 데이터와 동작을 하나의 단위로 구조화할 수 있어 유용하다. 

   JS의 객체는 객체지향의 상속을 구현하기 위해 프로토타입이라고 불리는 객체의 프로퍼티와 메소드를 상속받을 수 있다. 타 언어와 구별되는 중요한 개념이다.

   프로퍼티 - 프로퍼티 키(이름)와 프로퍼티 값으로 구성된다. 프로퍼티는 프로퍼티 키로 유일하게 식별할 수 있다.

   - 프로퍼티 키: 빈 문자열을 포함하는 모든 문자열 또는 symbol 값
   - 프로퍼티 값: 모든 값
   - 프로퍼티 키에 문자열이나 symbol 값 이외의 값을 지정하면 암묵적으로 타입이 변환되어 문자열이 된다. 이미 존재하는 프로퍼티 키를 중복 선언하면 나중에 선언한 프로퍼티가 먼저 선언한 프로퍼티를 덮어쓴다. 배열과는 달리 객체는 프로퍼티를 열거할 때 순서를 보장하지 않는다.
   - 메소드 - 프로퍼티 값이 함수일 경우, 일반 함수와 구분하기 위해 메소드라 부흔다. 즉, 메소드는 개체에 제한되어 있는 함수를 의미한다.

   2. 객체 생성 방법

      - 일반적인 JS 객체 생성 방식 중괄호를 사용하여 객체를 생성하는데 {} 내에 1개 이상의 프로퍼티를 기술하면 해당 프로퍼티가 추가된 객체를 생성할 수 있다. {} 내에 아무것도 기술하지 않으면 빈 객체가 생성된다. ex)   var emptyObject = {};
      - new 연산자와 Object 생성자 함수를 호출하여 빈 객체를 생성할 수 있다. 빈 객체 생성 이후 프로퍼티 또는 메소드를 추가하여 객체를 완성하는 방법이다.생성자 함수란 new 키워드와 함께 객체를 생성하고 초기화하는 함수를 말한다. 
      - 생성자 함수를 통해 생성된 객체를 인스턴스라 한다. JS는 Object 생성자 함수 이외에도 String, Number, Boolean, Array, Date, RegExp 등의 빌트인 생성자 함수를 제공한다. 파스칼 키워드를 사용한다. 객체가 소유하고 있지 않은 프로퍼티 키에 값을 할당하면 해당 객체에 프로퍼티를 추가하고 값을 할당한다. 이미 존재하는 프로퍼티 키에 새로운 값을 할당하면 프로퍼티 값은 할당한 값으로 변경된다. 반드시 Ozbject 생성자 함수를 사용해 빈 객체를 생성해야 하는 것은 아니다. 객체를 생성하는 방법은 객체 리터럴을 사용하는 것이 더 간편하다. Object 생성자 함수 방식은 특별한 이유가 없다면 그다지 유용해 보이지 않는다. 
      - 객체 리터럴 방식으로 생성된 객체는 결국 빌트인 함수인 Object 생성자 함수로 객체를 생성하는 것을 단순화시킨 축약 표현이다. JS엔진은 객체 리터럴로 객체를 생성하는 코드를 만나면 내부적으로 Object 생성자 함수를 사용하여 객체를 생성한다. 따라서 개발자가 일부러 Object 생성자 함수를 사용해 객체를 생성해야 할 일은 거의 없다.
      - 위 생성 방식들은 프로퍼티 값만 다른 여러 개의 객체를 생성할 때 불편하다. 그렇기에 생성자 함수를 사용하면 마치 객체를 생성하기 위한 템플릿(클래스)처럼 사용하여 프로퍼티가 동일한 객체 여러 개를 간편하게 생성할 수 있다.
      - 생성자 함수 이름은 일반적으로 대문자이다. this는 생성자 함수가 생성할 인스턴스를 가리킨다. this에 연결되어 있는 프로퍼티와 메소드는 외부에서 참조 가능하다. 생성자 함수 내에서 선언된 일반 변수는 외부에서 참조 불가능하다. 즉, 생성자 함수 내부에서는 자유롭게 접근이 가능하나 외부에서 접근할 수 없다.

   3. 프로퍼티 키

      프로퍼티 키는 일반적으로 문자열을 지정한다. 문자열, symbol 값 이외의 값을 지정하면 암묵적으로 타입이 변환되어 문자열이 된다.

      프로퍼티 값에 접근하는 방법은 .표기법과 []표기법이 있다. 프로퍼티 키가 유효한 자바스크립트 이름이고 예약어가 아닌 경우 프로퍼티 값은 위있는 표기법을 다 사용할 수 있다. 하지만 유효한 JS 이름이 아니거나 예약어인 경우 []표기법으로 읽어야 한다. 대괄호내에 들어가는 프로퍼티 이름은 반드시 문자열이어야 한다.

      객체가 소유하고 있는 프로퍼티에 새로운 값을 할당하면 프로퍼티 값은 갱신된다.

      객체가 소유하고 있지 않은 프로퍼티 키에 값을 할당하면 주어진 키와 값으로 프로퍼티를 생성하여 객체에 추가한다.

      delete연산자를 사용하면 객체의 프로퍼티를 삭제할 수 있다. 피연산자는 프로퍼티 키어야 한다.

      for-in 문을 사용하면 객체에 포함된 모든 프로퍼티에 대해 루프를 수행할 수 있다.

      배열에는 프로퍼티의 순서가 보장되지 않고 배열 요소들만을 순회하지 않기 때문에 사용하지 않는 것이 좋다.

      그러한 단점을 보완해 주는 것이 for-of문 이다.

      object type를 객체 타입 또는 참조 타입이라 한다. 우너시 타입은 값을 변경 할 수 없지만 객체는 프로퍼티를 변경,추가,삭제가 가능하다. 객체 타입은 동적으로 변화할 수 있으므로 어느 정도의 메모리 공간을 확보해야 하는지 예측할 수 없기 때문에 런타임에 메모리 공간을 확보하고 메모리의 힙 영역에 저장된다.

      이에 반해서 원시 타입은 값으로 전달된다 즉, 복사되어 전달된다. 이를 pass-by-value라 한다

      원시 타입은 스택 영역에 고정된 메모리 영역을 점유하고 저장된다.

