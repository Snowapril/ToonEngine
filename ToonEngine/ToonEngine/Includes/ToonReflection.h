/**
 * @file ToonReflection.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief several macros for implementing C++ Reflection system.
 * @version 0.1
 * @date 2019-05-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TOON_REFLECTION_H
#define TOON_REFLECTION_H

// referenced on https://www.unrealengine.com/ko/blog/unreal-property-system-reflection?lang=ko

/****************************************************************************
				ToonEngine property system Macros here

	Unreal Build Tool (UBT) �� Unreal Header Tool (UHT) �� �Բ��Ͽ� ����ð� 
	���÷����� ��ȭ��Ű�� �� �ʿ��� �����͸� �����մϴ�. UBT �� �� ������ ���� 
	����� ��ĵ�� ���� ���÷��ǵ� ������ �ּ� �ϳ� �ִ� ����� ����ִ� ����� 
	����մϴ�. �� ��� �� � ���̵� ���� �� ������ ���� ����Ǿ��ٸ�, 
	UHT �� �����Ͽ� ���÷��� �����͸� �����ϰ� ������Ʈ�մϴ�. 
	UHT �� ����� �Ľ��ϰ�, ���÷��� ������ ��Ʈ�� ����� ����, 
	(��⺰.generated.inl �� �⿩�ϴ�) ���÷��� �����Ͱ� ����ִ� 
	C++ �ڵ带 ������ �Ӹ� �ƴ϶�, (����� .generated.h ��) 
	�پ��� ���� �� thunk �Լ��� �����մϴ�.
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