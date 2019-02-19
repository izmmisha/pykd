
#define PYKD_VERSION_MAJOR      0
#define PYKD_VERSION_MINOR      3
#define PYKD_VERSION_SUBVERSION 4
#define PYKD_VERSION_BUILDNO    5

#define __VER_STR2__(x) #x
#define __VER_STR1__(x) __VER_STR2__(x)

#define PYKD_VERSION_BUILD_COMMA    PYKD_VERSION_MAJOR, PYKD_VERSION_MINOR, PYKD_VERSION_SUBVERSION, PYKD_VERSION_BUILDNO
#define PYKD_VERSION_BUILD          PYKD_VERSION_MAJOR.PYKD_VERSION_MINOR.PYKD_VERSION_SUBVERSION.PYKD_VERSION_BUILDNO

#define PYKD_VERSION_BUILD_STR_COMMA    __VER_STR1__(PYKD_VERSION_BUILD_COMMA)
#define PYKD_VERSION_BUILD_STR          __VER_STR1__(PYKD_VERSION_BUILD)
