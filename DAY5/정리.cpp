// 1. 변하는 것을 분리하는 기술

// => 변하는 것을 가상함수로 : template method, 
//						   factory method

// => 변하는 것을 다른 클래스로
// 객체가 사용하는 알고리즘의 교체 : strategy 
// 객체의 모든 동작을 교체        : state 
// 동일공정의 다른 표현을 가질수 있는 복잡한 객체 만들기 : builder

// 2. 재귀적 포함을 사용하는 기술
// => 재귀적 포함으로 무엇을 하는가 ?
// 복합객체 만들기    : composite      File/Folder 
// 객체에 기능을 추가 : decorator      FileStream/ZipStream
// 파이썬 decorator(@로시작) : 함수에 기능을 추가하는 함수
//							중첩도 가능.

// 3. 중간층을 넣어서 문제를 해결하는 것
// 사용자 ===== stack ======> list : adapter
// 
// 사용자 ===== MP3   ======> IMP3 : bridge
// 
// 사용자 ===== TCPSERVER ==> Socket, IPAddress : facade
// 
// 사용자 ===== Calc =======> CalcServer : proxy



// 객체를 만들때 사용하는 패턴 5가지(생성 패턴)
// => singleton, prototype, abstract factory, 
//    factory method, builder


// 구조에 대한 패턴 7가지
// => 재귀적 포함 2가지 : composite, decorator
// => 간접층 4가지 : adapter, bridge, facade, proxy
// => 공유 : flyweight

// 동작(행위)에 대한 패턴 11가지
// => 변하는 것 분리  : state, strategy, template
// => 명령 의 객체화  : command
// => 열거, 통보, 방문, 전가 : iterator, visitor, observer, 
//							chain of responsibility

// => 객체 저장 : memento
// => 기타 : mediator, interpret




