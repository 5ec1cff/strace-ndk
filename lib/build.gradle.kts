plugins {
    alias(libs.plugins.android.library)
}

android {
    namespace = "io.github.a13e300.strace_ndk"
    compileSdk = 35

    buildFeatures {
        prefabPublishing = true
    }

    defaultConfig {
        minSdk = 28
    }

    externalNativeBuild.cmake {
        path("src/main/CMakeLists.txt")
    }

    prefab {
        register("strace")
    }
}
