# Chapter 9

1. 타입 변환

   명시적 타입 변환 (타입 캐스팅) - 개발자에 의해 의도적으로 값의 타입을 변환하는 것

   암묵적 타입 변환 (타입 강제 변환) - JS 엔진에 의해 암묵적으로 타입이 자동 변환되는 것

   코드를 보고 암묵적 타입 변환이 발생하는지 발생한다면 어떤 타입의 어떤 값으로 변환되는지 타입 변환된 값으로 표현식은 어떻게 평가될 것인지 예측 할 수 있어야 한다. 

2. 암묵적 타입 변환

   JS 엔진은 표현식을 평가할 때 문맥, 즉 컨텍스트에 고려하여 암묵적 타입 변환을 실행한다.

   

   2.1 문자열 타입으로 변환

   // 숫자 타입 

   0 + ' '              // "0"

    -0 + ' '             // "0"

    1 + ' '              // "1"

    -1 + ' '             // "-1" 

   NaN + ' '            // "NaN"

    Infinity + ' '       // "Infinity"

    -Infinity + ' '      // "-Infinity" 

   // 불리언 타입 

   true + ' '           // "true"

    false + ' '          // "false" 

   // null 타입

    null + ' '           // "null"

    // undefined 타입 

   undefined + ' '      // "undefined" 

   // 심볼 타입

    (Symbol()) + ' '     // TypeError: Cannot convert a Symbol value to a string 

   // 객체 타입

    ({}) + ' '           // "[object Object]" 

   Math + ' '           // "[object Math]"

    [] + ' '             // " "

    [10, 20] + ' '       // "10,20"

    (function(){}) + ' ' // "function(){}"

    Array + ' '          // "function Array() { [native code] }"

   

   2.2  숫자 타입으로 변환

   // 문자열 타입 

   +''             // 0

    +'0'            // 0 

   +'1'            // 1 

   +'string'       // NaN 

   // 불리언 타입

    +true           // 1 

   +false          // 0 

   // null 타입 

   +null           // 0 

   // undefined 타입 

   +undefined      // NaN

    // 심볼 타입 

   +Symbol()       // TypeError: Cannot convert a Symbol value to a number

    // 객체 타입 +{}             // NaN 

   +[]             // 0 

   +[10, 20]       // NaN 

   +(function(){}) // NaN

   

   2.3 불리업 타입으로 변환

   if ('')    console.log('1');

   if (true)  console.log('2'); 

   if (0)     console.log('3');

   if ('str') console.log('4');

   if (null)  console.log('5'); 

   // 2 4

   

   

   