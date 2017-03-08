var clerk = (function() {
    var name = 'Teo';
    var sex = '남자';
    var position = '수석 엔지니어';
    // salary private
    var salary = 2000;
    var taxSalary = 200;
    var totalBonus = 100;
    var taxBonus = 10;

    var payBonus = function() {
        totalBonus = totalBonus - taxBonus;
        return totalBonus;
    };
    var paySalary = function() {
        return salary - taxSalary;
    };

    // Public 속성, 메소드
    return {
        name : name,
        sex : sex,
        position : position,
        paySalary : paySalary,
        payBonus : payBonus
    };
}());

// name 속성은 public
console.log(clerk.name); // 'Teo' 출력
// salary 변수는 즉시실행함수 내부 변수이므로 private
console.log(clerk.salary); // undefined 출력

// paySalary 메소드는 public
console.log(clerk.paySalary()); // 1800 출력

// payBonus 메소드는 public
console.log(clerk.payBonus()); // 90 출력
console.log(clerk.payBonus()); // 80 출력

/*
//위에 작성된 즉시실행함수는 name, sex, position속성과 payBonus메소드를
//가진 객체를 clerk변수에 반환합니다. 다시 말해, 즉시실행함수가 clerk변수에
//저장되는 것이 아니라 즉시실행함수의 반환값이 clerk변수에 저장됩니다.
//name, sex, position변수를 글로벌 스코프에 추가하지 않고 단지 clerk변수만 추가되었습니다.
//애플리케이션의 규모가 커지면 글로벌 변수에 대한 충돌을 고려해야 하므로 글로벌 변수 사용을 자제해야 합니다.
//또한, name, sex, position속성은 clerk변수에 저장된 객체의 속성이므로 외부에서
//접근이 가능(public)하지만 salary, totalBonus변수는 즉시실행함수 내의 변수이므로 외부에서
//접근할 수 없습니다(private). paySalary()메소드를 호출하여 지급된 급여인
1800을 반환값을 가져올 수 있고 payBonus()메소드를 호출하여 지급된 상여금인 90을
반환할 수 있으며 payBosnus()메소드를 한번 더 호출하여 80을 반환할 수 있습니다.
여기서 주목해야 할 부분은 payBonus()메소드를 호출할 때마다 totalBonus 변수에
저장된 값이 업데이트 되지만 paySalary()메소드는 여러번 호출해도 salary 변수에
저장된 값은 업데이트 되지 않는 점입니다.

즉시실행함수를 위와 같이 사용하여 언어레벨에서 제공하지 못하는 모듈화 지원도구를
극복할 수 있으며 이렇게 작성된 코드를 분리된 파일로 구성하면 재사용성을 높일 수 있습니다.
*/

/*
자바스크립트 모듈 작성시 코드 순서
Javascript로 SPA를 구현할 때, 다음과 같은 순서의 코드로 모듈을 작성하게 되면 협업하는 개발자들에게 집약되고 일관된 코드를 제공하여 많은 도움이 될 것입니다. 이렇게 코드의 순서를 정하는 이유는 집약되고 일관된 코드를 제공하는데 있으므로 코드의 순서는 개발상황과 모듈용도에 맞춰가며 조정하고 추가 및 삭제될 수도 있습니다. 아래 순서는 단지 코드작성 순서의 예일뿐입니다.

모듈 스코프 내에서 사용할 변수 작성
유틸리티 메소드 작성
DOM 조작 메소드 작성
이벤트 핸들러 작성
Public 메소드 작성
*/

// SPA 모듈 작성 순서 예시
var app = (function() {

    // 1. 모듈 스코프 내에서 사용할 변수 작성
    var scopeVar = {};
    var utilMethod;
    var manipulateDom;
    var eventHandle;
    var initModule;

    // 2. 유틸리티 메소드 작성
    utilMethod = function() {
        // 실행코드
    };

    // 3. DOM 조작 메소드 작성
    manipulateDom = function() {
        // 실행코드
    };

    // 4. 이벤트 핸들러 작성
    eventHandle = function() {
        // 실행코드
    };

    // Public 메소드 작성
    initModule = function() {
        // 실행코드
    };

    return {
        init : initModule
    };
}());
/*
Javascript : 함수(function) 다시 보기
 Nextree  Jan 12, 2014  2 Comments
자바스크립트는 한동안 개발자들의 많은 오해와 편견으로 toy language 취급을 받아 왔습니다. 누구든지 쉽게 배워 간단히 적용할 수 있다는 생각에 깊이 있는 학습이 이뤄지지 않았습니다. 하지만, 현대의 웹 애플리케이션이 시대적 요구와 사용자의 기대로 인해 점점 더 복잡한 대규모 시스템으로 발전해 나가면서 자바스크립트에 대한 관심이 크게 늘고 있습니다. 이에 자바스크립트에 대한 올바른 이해를 위해 자바스크립트에서 가장 중요한 주제인 함수에 대해 간략히 설명하겠습니다.

대부분 자바스크립트에서 함수를 설명할 때 "자바스크립트에서 함수는 first-class object(또는 citizen, value)다"라는 정의는 항상 빠지지 않고 등장하는 단골문장입니다. 하지만, first-class object에 대한 정확한 언급이 없어 그냥 흘려 듣기 쉽습니다.

그렇다면 first-class object란 무엇일까요?

first-class object는 변수에 저장할 수 있어야 합니다.
first-class object는 함수의 파라미터로 전달할 수 있어야 합니다.
first-class object는 함수의 반환값으로 사용할 수 있어야 합니다.
first-class object는 자료 구조에 저장할 수 있어야 합니다.
위와 같은 조건들을 충족시키는 객체를 first-class object라 부릅니다. Java에서 메소드는 위 조건들을 충족시키지 못하기 때문에 first-class citizen으로 취급되지 않습니다.

자바스크립트에서 함수는 first-class object다.

또한, 함수는 변수의 스코프를 결정하고 private 변수 또는 메소드 뿐만 아니라 함수의 특징을 이용하여 public 속성과 메소드를 제공하며 자바스크립트 모듈을 작성하는 좋은 도구이기도 합니다.

함수에 대한 올바르고 정확한 이해는 자바스크립트를 이해하는 데 있어 핵심 중의 하나이며 대규모 웹 애플리케이션이나 Single Page Applications(SPAs)을 개발하는데 있어 가장 중요한 개념이 됩니다.

함수와 익명함수

자바스크립트에서 함수를 정의하는 방법은 Function 객체를 사용하는 방법과 연산자인 function을 사용하는 방법이 있습니다. 일반적으로 Function 객체를 사용한 정의 방법은 많이 사용되지는 않습니다. 연산자인 function을 이용한 함수 정의 방식은 함수선언문(function declaration)과 함수표현식(function expression)으로 나뉩니다.

우리는 그간 아래와 같이 함수를 정의하고 사용해 왔습니다.

// 함수선언식(function declaration)
function company() {
    /* 실행코드 */
}
이와 같은 방식을 함수선언식(function declaration)이라고 합니다. 함수선언식으로 정의된 함수는 자바스크립트 인터프리터가 스크립트가 로딩되는 시점에 바로 초기화하고 이를 VO(variable object)에 저장합니다. 그렇기 때문에 함수 선언의 위치와는 상관없이 소스 내 어느 곳에서든지 호출이 가능합니다.

함수 정의할 때 "함수는 first-class object이므로 변수에 할당될 수 있다." 라는 전제 하에 아래와 같이 작성할 수 있습니다.

// 기명 함수표현식(named function expression)
var company = function company() {
    /* 실행코드 */
};

// 익명 함수표현식(anonymous function expression)
var company = function() {
    /* 실행코드 */
};

// 기명 즉시실행함수(named immediately-invoked function expression)
(function company() {
    /* 실행코드 */
}());

// 익명 즉시실행함수(immediately-invoked function expression)
// Javascript 대가이신 더글라스 클락포트의 권장 표기법
(function() {
    /* 실행코드 */
}());

// 익명 즉시실행함수(immediately-invoked function expression)
(function() {
    /* 실행코드 */
})();
이렇게 정의한 방식을 함수표현식(function expression)이라고 합니다. 함수가 변수에 할당되었으므로 "함수는 객체이다."라는 정의가 가능합니다. 함수표현식은 함수선언식과는 달리 스크립트 로딩 시점에 VO에 함수를 저장하지 않고 runtime시에 해석되고 실행되므로 이 두가지를 구분하는 것은 중요합니다.

함수선언식으로 함수를 정의하면 사용하기에 쉽지만 대규모 애플리케이션을 개발하는 경우 인터프리터가 너무 많은 코드를 VO에 저장하므로 애플리케이션의 응답속도는 현저히 떨어질 수 있으므로 주의해야 할 필요가 있습니다. 참고로, 스크립트 파일을 모듈화하고 이를 필요한 시점에 비동기 방식으로 로딩하여 http 요청을 줄이고 응답속도와 사용자 체감속도를 향상시킬 수 있습니다.

즉시실행함수(Immediately-invoked function expression)

자바스크립트에서 가장 큰 문제점 중의 하나는 글로벌 스코프에 정의된 것은 코드 내의 어디서든지 접근이 가능하다는 것입니다. 하지만, 외부에 공유되면 안되거나 공유될 필요가 없는 속성이나 메소드가 있습니다. 또한, 다른 스크립트 파일 내에서 동일한 이름으로 명명된 변수나 함수가 있을 경우 원치 않는 결과를 가져올 수 있습니다.

익명 함수표현식으로 함수를 하나 정의하고 실행해 보겠습니다. 그리고 외부에서 함수 내의 변수에 접근해 보겠습니다.

// 함수표현식에 의한 명시적인 함수호출
var app = function() {
    console.log('함수 호출'); // "함수 호출" 출력
};
app();
이번에는 익명 즉시실행함수로 함수를 정의해 보겠습니다.

// 즉시실행함수
(function() {
    console.log('함수 호출'); // "함수 호출" 출력
}());
위 두개의 코드는 동일한 동작을 수행합니다.

함수표현식은 함수를 정의하고, 변수에 함수를 저장하고 실행하는 일련의 과정을 거칩니다. 하지만, 즉시실행함수를 사용하면 이와 같은 과정을 거치지 않고 즉시 실행된다는 특징이 있습니다. 차이점이라면 단순히 함수를 괄호"()"로 랩핑한 게 전부입니다. 이런 함수를 즉시실행함수(IIFE)라 부릅니다.

이번에는 변수를 선언하고 이 변수에 즉시실행함수를 할당해 보겠습니다.

var app = (function() {
    var privateVar = 'private';
    return {
        prop : privateVar
    };
}());
console.log(app.prop); // "private" 출력
콘솔에는 "private" 라고 출력됩니다.

즉시실행함수 내에서 선언한 변수를 외부에서도 접근할 수 있음을 확인할 수 있습니다. 변수의 접근 범위가 함수 내부가 아닌 외부에서도 가능해진 것입니다. 이와 같이, 즉시실행함수는 변수의 스코프를 포함하는데 사용되며 외부에서 함수 내의 변수에 접근할 경우 이를 통제할 수 있습니다. 즉시실행함수는 글로벌 네임스페이스에 변수를 추가하지 않아도 되기 때문에 코드 충돌이 없이 구현할 수 있어 플러그인이나 라이브러리 등을 만들 때 많이 사용됩니다.

아래 두개의 코드는 기명 함수표현식과 즉시실행함수에서 파라미터를 전달하는 방법을 보여줍니다.

var buyCar = function(carName) {
    // "내가 구매한 차는 sonata입니다." 출력
    console.log('내가 구매한 차는 ' + carName + '입니다.');
};
buyCar('sonata');

(function(carName) {
    // "내가 구매한 차는 sonata입니다." 출력
    console.log('내가 구매한 차는 ' + carName + '입니다.');
}('sonata'));
위 두개의 코드 블럭은 동일한 동작을 수행합니다. 또한, 앞서의 예제처럼 괄호"()"로 랩핑한 차이 밖에 없습니다.

jQuery나 Prototype 라이브러리는 동일한 $라는 글로벌 변수를 사용합니다. 만약, 이 두개의 라이브러리를 같이 사용한다면 $ 변수에 대한 충돌이 생길 것입니다. 하지만, 즉시실행함수의 코드 블럭에서 jQuery를 위한 $ 변수를 사용하고자 한다면 아래와 같이 파라미터를 전달하는 방법으로 Prototype의 $ 변수에 대한 overwritting을 예방할 수 있습니다.

(function($) {
    // 함수 스코프 내에서 $는 jQuery Object임.
    console.log($);
}(jQuery));
모듈 패턴(Module Pattern)

현대의 웹 애플리케이션은 점점 더 복잡하고 고도화된 대규모 애플리케이션이나 데스크탑 애플리케이션의 모습을 닮아가는 형태(Rich Internet Application)로 진화하고 있는 추세입니다. 하나의 파일에 모든 코드를 담는 것은 불가능하고 설사 그렇게 작성되었다 하더라도 많은 문제점을 내포할 뿐만 아니라 유지보수시 골치 아픈 경험을 자주 하게될 것입니다. 그렇다면 이를 어떻게 극복할 수 있을까요? 그에 대한 답은 자바스크립트 함수의 특징을 이용한 모듈화에서 부터 찾을 수 있습니다.

Java나 C++과 같은 고급언어들은 언어 자체적으로 모듈화를 지원하는 방법을 제공하지만 자바스크립트는 언어레벨에서 캡슐화를 위한 접근제어자(private, public 등), 모듈 간의 구분을 위한 package가 명시적으로 제공되지 않습니다. 하지만, 명시적으로 제공되지 않는 이런 지원도구들을 자바스크립트 함수의 특징을 이용하여 유사하게 제공할 수 있습니다.

즉시실행함수는 우리가 작성한 코드들 뿐만 아니라 함께 사용하는 외부 라이브러리와도 충돌없이 구동하는 샌드박스(sandbox)를 제공합니다. 이 특징과 단위기능별로 작성된 코드를 분리된 개별 파일 형태로 유지한다면 앞서 언급한 모듈화를 위한 조건을 해결할 수 있습니다.

var clerk = (function() {
    var name = 'Teo';
    var sex = '남자';
    var position = '수석 엔지니어';
    // salary private
    var salary = 2000;
    var taxSalary = 200;
    var totalBonus = 100;
    var taxBonus = 10;

    var payBonus = function() {
        totalBonus = totalBonus - taxBonus;
        return totalBonus;
    };
    var paySalary = function() {
        return salary - taxSalary;
    };

    // Public 속성, 메소드
    return {
        name : name,
        sex : sex,
        position : position,
        paySalary : paySalary,
        payBonus : payBonus
    };
}());

// name 속성은 public
console.log(clerk.name); // 'Teo' 출력
// salary 변수는 즉시실행함수 내부 변수이므로 private
console.log(clerk.salary); // undefined 출력

// paySalary 메소드는 public
console.log(clerk.paySalary()); // 1800 출력

// payBonus 메소드는 public
console.log(clerk.payBonus()); // 90 출력
console.log(clerk.payBonus()); // 80 출력
위에 작성된 즉시실행함수는 name, sex, position속성과 payBonus메소드를 가진 객체를 clerk변수에 반환합니다. 다시 말해, 즉시실행함수가 clerk변수에 저장되는 것이 아니라 즉시실행함수의 반환값이 clerk변수에 저장됩니다. name, sex, position변수를 글로벌 스코프에 추가하지 않고 단지 clerk변수만 추가되었습니다. 애플리케이션의 규모가 커지면 글로벌 변수에 대한 충돌을 고려해야 하므로 글로벌 변수 사용을 자제해야 합니다. 또한, name, sex, position속성은 clerk변수에 저장된 객체의 속성이므로 외부에서 접근이 가능(public)하지만 salary, totalBonus변수는 즉시실행함수 내의 변수이므로 외부에서 접근할 수 없습니다(private). paySalary()메소드를 호출하여 지급된 급여인 1800을 반환값을 가져올 수 있고 payBonus()메소드를 호출하여 지급된 상여금인 90을 반환할 수 있으며 payBosnus()메소드를 한번 더 호출하여 80을 반환할 수 있습니다. 여기서 주목해야 할 부분은 payBonus()메소드를 호출할 때마다 totalBonus 변수에 저장된 값이 업데이트 되지만 paySalary()메소드는 여러번 호출해도 salary 변수에 저장된 값은 업데이트 되지 않는 점입니다.

즉시실행함수를 위와 같이 사용하여 언어레벨에서 제공하지 못하는 모듈화 지원도구를 극복할 수 있으며 이렇게 작성된 코드를 분리된 파일로 구성하면 재사용성을 높일 수 있습니다.
자바스크립트 모듈 작성시 코드 순서
Javascript로 SPA를 구현할 때, 다음과 같은 순서의 코드로 모듈을 작성하게 되면 협업하는 개발자들에게 집약되고 일관된 코드를 제공하여 많은 도움이 될 것입니다. 이렇게 코드의 순서를 정하는 이유는 집약되고 일관된 코드를 제공하는데 있으므로 코드의 순서는 개발상황과 모듈용도에 맞춰가며 조정하고 추가 및 삭제될 수도 있습니다. 아래 순서는 단지 코드작성 순서의 예일뿐입니다.

모듈 스코프 내에서 사용할 변수 작성
유틸리티 메소드 작성
DOM 조작 메소드 작성
이벤트 핸들러 작성
Public 메소드 작성
// SPA 모듈 작성 순서 예시
var app = (function() {

    // 1. 모듈 스코프 내에서 사용할 변수 작성
    var scopeVar = {};
    var utilMethod;
    var manipulateDom;
    var eventHandle;
    var initModule;

    // 2. 유틸리티 메소드 작성
    utilMethod = function() {
        // 실행코드
    };

    // 3. DOM 조작 메소드 작성
    manipulateDom = function() {
        // 실행코드
    };

    // 4. 이벤트 핸들러 작성
    eventHandle = function() {
        // 실행코드
    };

    // Public 메소드 작성
    initModule = function() {
        // 실행코드
    };

    return {
        init : initModule
    };
}());
/*
아래 코드는 라이브러리를 모듈화하는 코딩기법을 정리해 봤습니다.
jQuery, Backbone, underscore, requireJs 등 많은 자바스크립트 라이브러리나
프레임워크가 아래와 같은 코딩기법을 사용하고 있습니다.
*/
/**
 * Library 모듈화를 위한 코딩기법 1
 * call 함수 이용
 */
(function() {
    'use strict';
    var root = this;
    var version = '1.0';
    var Module1;
    if(typeof exports !== 'undefined') {
        Module1 = exports;
    } else {
        Module1 = root.Module1 = {};
    }
    Module1.getVersion = function() {
        return version;
    }
}).call(this);
console.log(Module1.getVersion());

/**
 * Library 모듈화를 위한 코딩기법 2
 * 글로벌 객체를 파라미터로 전달
 */
(function(global) {
    var root = global;
    var version = '1.0';
    var Module2;
    if(typeof exports !== 'undefined') {
        Module2 = exports;
    } else {
        Module2 = root.Module2 = {};
    }
    Module2.getVersion = function() {
        return version;
    }
}(this));
console.log(Module2.getVersion());

/**
 * Library 모듈화를 위한 코딩기법 3
 * 즉시실행함수 내부에서 글로벌 객체를 내부 변수에 할당
 */
(function() {
    var root = this;
    var version = '1.0';
    var Module3;
    if(typeof exports !== 'undefined') {
        Module3 = exports;
    } else {
        Module3 = root.Module3 = {};
    }
    Module3.getVersion = function() {
        return version;
    }
}());
console.log(Module3.getVersion());

/**
 * Library 모듈화를 위한 코딩기법 4
 * apply 함수 이용
 */
(function() {
    var root = this;
    var version = '1.0';
    var Module4;
    if(typeof exports !== 'undefined') {
        Module4 = exports;
    } else {
        Module4 = root.Module4 = {};
    }
    Module4.getVersion = function() {
        return version;
    }
}).apply(this) ;
console.log(Module4.getVersion());

/**
 * Library 모듈화를 위한 코딩기법 5
 * 기명 즉시실행함수 이용
 */
var Module5 = (function() {
    var root = this;
    var version = '1.0';
    var Module;
    if(typeof exports !== 'undefined') {
        Module = exports;
    } else {
        Module = root.Module = {};
    }
    Module.getVersion = function() {
        return version;
    }
    return Module;
}());
console.log(Module5.getVersion());
