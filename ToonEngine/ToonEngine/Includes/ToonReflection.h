#ifndef TOON_REFLECTION_H
#define TOON_REFLECTION_H

// referenced on https://www.unrealengine.com/ko/blog/unreal-property-system-reflection?lang=ko

/****************************************************************************
				ToonEngine property system Macros here

	Unreal Build Tool (UBT) 와 Unreal Header Tool (UHT) 가 함께하여 실행시간 
	리플렉션을 강화시키는 데 필요한 데이터를 생성합니다. UBT 는 그 역할을 위해 
	헤더를 스캔한 다음 리플렉션된 유형이 최소 하나 있는 헤더가 들어있는 모듈을 
	기억합니다. 그 헤더 중 어떤 것이든 지난 번 컴파일 이후 변경되었다면, 
	UHT 를 실행하여 리플렉션 데이터를 수집하고 업데이트합니다. 
	UHT 는 헤더를 파싱하고, 리플렉션 데이터 세트를 빌드한 다음, 
	(모듈별.generated.inl 에 기여하는) 리플렉션 데이터가 들어있는 
	C++ 코드를 생성할 뿐만 아니라, (헤더별 .generated.h 인) 
	다양한 헬퍼 및 thunk 함수도 생성합니다.
****************************************************************************/

namespace Toon
{
#define TOON_PROPERTY(...)
#define TOON_FUNCTION(...)
#define TOON_STRUCT(...)
#define TOON_ENUM(...)

#define BODY_MACRO_COMBINE_INNER(a, b, c, d) a##b##c##d
#define BODY_MACRO_COMBINE(a, b, c, d) BODY_MACRO_COMBINE_INNER(a, b, c, d)

#define TOON_GENERATED_CLASS_BODY(...) BODY_MACRO_COMBINE(TOON_FILE_ID,_,__LINE__,_GENERATED_BODY)
#define TOON_GENERATED_STRUCT_BOD(...) BODY_MACRO_COMBINE(TOON_FILE_ID,_,__LINE__,_GENERATED_BODY)

#define TOON_CLASS(...) BODY_MACRO_COMBINE(TOON_FILE_ID,_,__LINE__,_CLASS)
};

#endif