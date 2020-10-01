# Chapter 13

js는 동적 타입 언어이므로 변수에 어떤 값이 할당될지 예측하기 어렵다. 그렇기 떄문에 JS는 타입 체크가 필요하다.

1. typeof

   타입 연산자 typeof는 피연산자의 데이터 타입을 문자열로 반환한다.

   typeof '';              // string

   typeof 1;               // number 

   typeof NaN;             // number

    typeof true;            // boolean 등등

   그런데 typeof 연산자는 null과 배열의 경우 object, 함수의 경우 function을 반환하고, Date, RegExp, 사용자 정의 객체 등 거의 모든 객체의 경우, object를 반환한다. 따라서 typeof는 null을 제외한 원시 타입을 체크하는 데는 문제가 없지만 객체의 종류까지 구분하여 체크하려 할때는 사용하기 곤란하다.

2. Object.prototype.toString

   Object.prototype.toString 메소드는 객체를 나타내는 문자열을 반환한다.

   var obj = new Object();

   obj.toString(); // [object Object]

   Function.protype.call 메소드를 사용하면 모든 타입의 값의 타입을 알아낼 수 있다.

   Object.prototype.toString.call('');             // [object String] 

   Object.prototype.toString.call(new String());   // [object String] 

   Object.prototype.toString.call(1);              // [object Number] 

   Object.prototype.toString.call(new Number());   // [object Number] 등등

3. instanceof

   객체의 종류까지 식별할 수 있는 타입 체크 기능을 작성하였다. 하지만 위의 방법으로는 객체의 상속 관계까지 체크할 수는 없다.

   타입 연산자에는 앞서 살펴본 typeof 이외에 instanceof를 제공한다.

    instanceof 연산자는 피연산자인 객체가 우항에 명시한 타입의 인스턴스인지 여부를 알려준다. 이때 타입이란 constructor를 말하며 프로토타입 체인에 존재하는 모든 constructor를 검색하여 일치하는 constructor가 있다면 true를 반환한다.

4. 유사 배열 객체

   배열인지 체크하기 위해서는 Array.isArray 메소드를 사용한다.

   유사 배열 객체(array-like object)은 length 프로퍼티를 갖는 객체로 문자열, arguments, HTMLCollection, NodeList 등은 유사 배열이다. 유사 배열 객체는 length 프로퍼티가 있으므로 순회할 수 있으며 call, apply 함수를 사용하여 배열의 메소드를 사용할 수도 있다.

   어떤 객체가 유사 배열인지 체크하려면 우선 length 프로퍼티를 갖는지 length 프로퍼티의 값이 정상적인 값인지 체크한다.