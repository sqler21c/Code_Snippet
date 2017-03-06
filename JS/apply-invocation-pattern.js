/*
함수 호출 시 각 상황에 따라 this에 바인딩될 객체가 결정된다. 이는 자바스크립트 엔진 내부에서 자동으로 실시되는 것이다.
이러한 내부적인 바인딩 이외에 this를 특정 객체에 명시적으로 바인딩하는 방법도 제공된다.
이것을 가능하게 하는 것이 Function.prototype.apply(), Function.prototype.call() 메서드이다.
이 메서드들은 모든 함수 객체의 프로토타입 객체인 Function.prototype 객체의 메서드이다.
*/

//func.apply(thisArg, [argsArray])
// thisArg: 함수 내부의 this에 바인딩할 객체
// argsArray: 함수에 전달할 인자 배열

//기억해야 할 것은 apply() 메서드를 호출하는 주체가 함수이며 apply() 메서드도 this를 특정 객체에 바인딩할 뿐 본질적인 기능은 함수 호출이라는 것이다.
var Person = function(name) {
  this.name= name;
}
var foo = {};

// 생성자함수 Person을 호출한다. 이때 this에 객체 foo를 바인딩한다.
Person.apply(foo, ['name']);
console.log(foo);
