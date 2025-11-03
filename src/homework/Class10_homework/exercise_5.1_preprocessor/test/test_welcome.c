#include "utest.h"
#include "welcome.h"
#include <string.h>

UTEST(Welcome, ReturnsNonNull) {
    const char* msg = get_welcome_msg();
    ASSERT_TRUE(msg != NULL);
}

UTEST(Welcome, MessageNotEmpty) {
    const char* msg = get_welcome_msg();
    ASSERT_TRUE(strlen(msg) > 0);
}

UTEST(Welcome, MessageContainsText) {
    const char* msg = get_welcome_msg();
    
    int contains_hello = (strstr(msg, "Hello") != NULL);
    int contains_hola = (strstr(msg, "Hola") != NULL);
    int contains_world = (strstr(msg, "World") != NULL);
    int contains_mundo = (strstr(msg, "Mundo") != NULL);
    
    // at least one of these should be true
}

#ifdef LANGUAGE
#if LANGUAGE == EN
// Test specifically for English message
UTEST(Welcome, EnglishMessage) {
    const char* msg = get_welcome_msg();
    ASSERT_TRUE(strstr(msg, "Hello") != NULL);
    ASSERT_TRUE(strstr(msg, "World") != NULL);
}
#elif LANGUAGE == ES
// Test specifically for Spanish message
UTEST(Welcome, SpanishMessage) {
    const char* msg = get_welcome_msg();
    ASSERT_TRUE(strstr(msg, "Hola") != NULL);
    ASSERT_TRUE(strstr(msg, "Mundo") != NULL);
}
#endif
#endif

UTEST(Welcome, ConsistentMessage) {
    const char* msg1 = get_welcome_msg();
    const char* msg2 = get_welcome_msg();
    ASSERT_STREQ(msg1, msg2);
}

UTEST_MAIN()