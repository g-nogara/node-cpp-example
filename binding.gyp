{
  "targets": [
    {
      "target_name": "example1",
      "sources": [
        "addons/example1.cpp",
      ],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'include_dirs': [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ],
      'dependencies': [
          "<!(node -p \"require('node-addon-api').gyp\")"
      ],
    }
  ]
}