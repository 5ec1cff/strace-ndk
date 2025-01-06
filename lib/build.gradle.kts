plugins {
    alias(libs.plugins.android.library)
}

android {
    namespace = "io.github.a13e300.strace_ndk"
    compileSdk = 35

    ndkVersion = "27.2.12479018"

    buildFeatures {
        prefabPublishing = true
        prefab = true
    }

    externalNativeBuild.cmake {
        path("src/main/CMakeLists.txt")
    }

    defaultConfig {
        minSdk = 28

        externalNativeBuild.cmake {
            arguments += "-DANDROID_STL=c++_static"
            cppFlags += arrayOf("-std=c++20", "-fno-exceptions", "-fno-rtti")
        }
    }

    buildTypes {
        release {
            externalNativeBuild.cmake {
                cppFlags += arrayOf("-Oz", "-flto")
            }
        }
    }

    prefab {
        register("strace")
    }
}

dependencies {
    // TODO: fix prefab-cxx has no cxxabi.h
    // implementation(libs.cxx)
}
