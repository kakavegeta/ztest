#include <src/test.h>
#include <string.h>
#include <stdio.h>

int func_cnt = 0;
Function func_arr[100];

struct TestInfo test_info;

void add_function(TestFunc func, const char* str) {
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].str = strdup(str);
    func_cnt++;
    return; 
}



int RUN_ALL_TESTS() {
    for (int i=0; i<func_cnt; ++i) {
        printf(GREEN("[====RUN====]") RED(": %s\n"), func_arr[i].str);
        test_info.total = 0, test_info.success = 0;
        func_arr[i].func();
        double rate = 100.0 * test_info.success/test_info.total;
        printf(GREEN("[  "));
        if (test_info.total == test_info.success) {
            printf(BLUE_HL("%6.2lf%%"), rate);
        } else {
            printf(RED_HL("%6.2lf%%"), rate);
        }
        printf(GREEN("  ]" " total : %d    sucess : %d\n"),
                    test_info.total, test_info.success);
    }
    return 0;
}


