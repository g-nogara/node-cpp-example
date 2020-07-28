#include <string.h>
#include <napi.h>

Napi::Value add(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();

    if (info.Length() != 2) {
        Napi::TypeError::New(env, "Must have TWO numbers to add").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Must have two NUMBERS to add").ThrowAsJavaScriptException();
        return env.Null();
    }    

    int n1, n2;
    n1 = info[0].As<Napi::Number>();
    n2 = info[1].As<Napi::Number>();

    return Napi::Number::New(env, n1 + n2);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "add"), Napi::Function::New(env, add));
    return exports;
}

NODE_API_MODULE(example1, Init);