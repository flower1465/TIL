# Chapter 5

1. 변수

   변수는 값을 저장하고 참조하기 위해 사용한다.

   변수는 주소를 기억함 변수란 주소에 접근하기 위한 식별자이다.

   변수 선언할 때에는 var 사용 =을 사용하여 변수에 값을 대입한다.

   var x;

   x = 6;

2. 값

   Data Type = 프로그래밍 언어에서 사용할 수 있는 값의 종류

   Variable = 값이 저장된 메모리 공간의 주소를 가리키는 식별자

   Literal = 소스코드 안에서 직접 만들어 낸 상수 값 자체를 말하며 값을 구성하는 최소 단위

   원시 타입 (primitive data type) 	number, string, boolean, null, undefined, symbol

   객체 타입	object

   자바스크립트는 동적 타입 언어이기 때문에 변수 선언때 데이터 타입을 미리 지정하지 않아도 자동이로 지정이됨

3. 연산자

   명시적 타입 변환 또는 타입 캐스팅을 하지 않아도 암묵적 타입 변환이 된다. 이 또한 동적 타입 언어의 특징이다.

4. 키워드

   키워드는 수행할 동작을 규정한 것이다. 

   ex) var, function, while, console.log()

5. 주석

   // 또는 /**/로 코드에 주석을 작성하여 코드의 이해를 돕는다.

6. 문

   프로그램(스크립트)은 컴퓨터에 의해 단계별로 수행될 명령들의 집합이다. 

   각각의 명령을 문(Statement)이라 한다.

   문은 리터럴, 연산자, 표현식, 키워드 등으로 구성되며 세미콜론으로 끝내야 한다.

   문들은 절차지향이다. 실행순서는 조건문이나 반복문의 사용으로 제어가 가능하다. 이를 흐름제어라 하며 함수 호출로 변경될 수 있다.

   다른 언어와는 다르게 블록 유효범위를 생성하지 않는다. 함수 단위의 유효범위만이 생성된다.

7. 표현식

   표현식은 하나의 값으로 평가 된다. 

   값(리터럴), 변수, 객체의 프로퍼티, 배열의 요소, 함수 호출, 메소드 호출, 피연산자와 연산자의 조합은 모두 표현식이며 하나의 값으로 평가된다.

   ex) 5 * 10 <- 50 으로 평가됨

8. 문과 표현식의 비교

   자연어에서 문이 하나의 완전한 문장이라고 한다면 표현식은 문을 구성하는 요소이다.

   표현식은 그자체로 하나의 문이 될 수도 있다.

   표현식은 평가되어 값을 만들지만 그 이상은 할 수 없다. 표현식을 통해 평가한 겂을 통해 실제호 컴퓨터에게 명령을 하여 무언가를 하는 것은 문이다. ex) var, function, if, for, while

9. 함수

   어떤 작업을 수행하기 위해 필요한 문들의 집합을 정의한 코드 블록이다.

   여러번 호출 할 수 있다. 

10. 객체

    자바스스크립트를 이루는 거의 "모든 것"이 객체이다. 원시 타입을 제외한 나머지 값들(함수, 배열, 정규표현식 등)은 모두 객체이다. 

    자바스크립트 객체는 키(이름)와 값으로 구성된 프로퍼티(property)의 집합이다. 프로퍼티 값으로 자바스크립트에서 사용할 수 있는 모든 값을 사용할 수 있다. 함수는 일급 객체이므로 값으로 취급할 수 있다. 따라서 프로퍼티 값으로 함수를 사용할 수도 있으며 프로퍼티 값이 함수일 경우, 일반 함수와 구분하기 위해 메소드라 부흔다.

    객체는 데이터를 의미하는 프로퍼티와 데이터를 참조하고 조작할 수 있는 동작을 의미하는 메소드로 구성된 집합이다.

    객체는 데이터와 그 데이터에 관련되는 동작(메소드)을 모두 포함할 수 있기 때문에 데이터와 동작을 하나의 단위로 구조화 할 수 있다. 

    JS의 객체는 객체지향의 상속을 구현하기 위해 "프로토타입"이라고 불리는 객체의 프로퍼티와 메소드를 상속받을 수 있다. 이 프로토타입은 타 언어와 구별되는 중요한 개념이다.

11. 배열

    배열은 1개의 변수에 여러 개의 값을 순차적으로 저장할 때 사용한다. JS의 배열은 객체이며 유용한 내장 메소드를 포함하고 있다.