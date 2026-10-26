#pragma once

#include <array>
#include <meta>
#include <string_view>
#include <type_traits>

namespace metaorm {

template<typename T, typename Func>
constexpr void forEachField(T&& obj, Func&& func) {
    using Type = std::remove_cvref_t<T>;

    static constexpr auto fields = std::define_static_array(
        std::meta::nonstatic_data_members_of(
            ^^Type, std::meta::access_context::current()
        )
    );

    template for (constexpr auto field : fields) {
        func(std::meta::identifier_of(field), obj.[:field:]);
    }
}

template<typename T>
consteval auto fieldNames() {
    constexpr auto fields = std::define_static_array(
        std::meta::nonstatic_data_members_of(
            ^^T, std::meta::access_context::current()
        )
    );

    std::array<std::string_view, fields.size()> names{};

    for (std::size_t i = 0; i < fields.size(); ++i) {
        names[i] = std::meta::identifier_of(fields[i]);
    }

    return names;
}

}
