#include "build_test/test/mocks/mock_hal.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/cmock/src/cmock.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"








int GlobalExpectCount;

int GlobalVerifyOrder;

char* GlobalOrderError;





extern void setUp(void);

extern void tearDown(void);

extern void test__delay_init__null_instance(void);

extern void test__delay_init__randon_duration(void);

extern void test__delay_get_status__null_instance(void);

extern void test__delay_get_status__delay_running(void);

extern void test__delay_get_status__delay_expired(void);

extern void test__delay_reset__null_instance(void);

extern void test__delay_reset__reset(void);







static void CMock_Init(void)

{

  GlobalExpectCount = 0;

  GlobalVerifyOrder = 0;

  GlobalOrderError = 

                    ((void *)0)

                        ;

  mock_hal_Init();

}

static void CMock_Verify(void)

{

  mock_hal_Verify();

}

static void CMock_Destroy(void)

{

  mock_hal_Destroy();

}





void resetTest(void);

void resetTest(void)

{

  tearDown();

  CMock_Verify();

  CMock_Destroy();

  CMock_Init();

  setUp();

}

void verifyTest(void);

void verifyTest(void)

{

  CMock_Verify();

}





static void run_test(UnityTestFunction func, const char* name, UNITY_UINT line_num)

{

    Unity.CurrentTestName = name;

    Unity.CurrentTestLineNumber = line_num;









    Unity.NumberOfTests++;

    { Unity.CurrentDetail1 = 0; Unity.CurrentDetail2 = 0; };

    do{}while(0);

    CMock_Init();

    if ((

       _setjmp (

       Unity.AbortFrame

       ) 

       == 0))

    {

        setUp();

        func();

    }

    if ((

       _setjmp (

       Unity.AbortFrame

       ) 

       == 0))

    {

        tearDown();

        CMock_Verify();

    }

    CMock_Destroy();

    do{}while(0);

    UnityConcludeTest();

}





int main(void)

{

  UnityBegin("test_de.c");

  run_test(test__delay_init__null_instance, "test__delay_init__null_instance", 26);

  run_test(test__delay_init__randon_duration, "test__delay_init__randon_duration", 44);

  run_test(test__delay_get_status__null_instance, "test__delay_get_status__null_instance", 68);

  run_test(test__delay_get_status__delay_running, "test__delay_get_status__delay_running", 85);

  run_test(test__delay_get_status__delay_expired, "test__delay_get_status__delay_expired", 112);

  run_test(test__delay_reset__null_instance, "test__delay_reset__null_instance", 139);

  run_test(test__delay_reset__reset, "test__delay_reset__reset", 156);



  CMock_Guts_MemFreeFinal();

  return UnityEnd();

}
