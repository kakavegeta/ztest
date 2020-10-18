/*************************************************************************
	> File Name: test.h
	> Author: 
	> Mail: 
	> Created Time: Fri 16 Oct 2020 06:19:35 AM EDT
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H


#define TEST(a, b)\
void a##_##b();\
__attribute__((constructor))\
void unittest##_##a##_##b() {\
    add_function(a##_##b, #a "." #b);\
}\
void a##_##b()

#define CORLOR(a, b) "\033[" #b "m" a "\033[0m"

#define CORLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"

#define GREEN(a) CORLOR(a, 32)
#define RED(a) CORLOR(a, 31)
#define BLUE(a) CORLOR(a, 34)
#define YELLOW(a) CORLOR(a, 33)

#define GREEN_HL(a) CORLOR_HL(a, 32)
#define RED_HL(a) CORLOR_HL(a, 31) 
#define BLUE_HL(a) CORLOR_HL(a, 34)
#define YELLOW_HL(a) CORLOR_HL(a, 33)

#define TYPE(a) _Generic((a),\
    int : "%d",\
    double : "%lf",\
    float : "%f",\
    long long : "%lld",\
    default: "%s"\
)

#define P(a, color) {\
    char frm[1000];\
    sprintf(frm, color("%s"), TYPE(a));\
    printf(frm, a);\
}

#define EXPECT(a, b, comp) {\
    test_info.total++;\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    if (_a comp _b) test_info.success++;\
    else {\
        printf("\n");\
        printf(YELLOW_HL("\t%s: %d: Failure\n"), __FILE__, __LINE__);\
        printf(YELLOW_HL("\t\texpect : " #a " " #comp " " #b "\n\t\t" "actual : "));\
        P(_a, YELLOW_HL);\
        P(" vs ", YELLOW_HL);\
        P(_b, YELLOW_HL);\
        printf("\n");\
    }\
    printf(GREEN("[-----------] ") #a " " #comp " " #b);\
    printf(" %s\n", _a comp _b ? GREEN_HL("TRUE") : RED_HL("FALSE"));\
}

#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)



typedef void (*TestFunc)();

typedef struct Function {
    TestFunc func;
    const char *str;
} Function;

void add_function(TestFunc, const char*);

struct TestInfo {
    int total;
    int success;
};
extern struct TestInfo test_info;

int RUN_ALL_TESTS(); 


#endif
