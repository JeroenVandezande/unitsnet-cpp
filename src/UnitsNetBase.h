#pragma once
#include <string_view>
#include <string>

namespace unitsnet_cpp
{
    class UnitsNetBase
    {
    public:
        virtual ~UnitsNetBase() = default;

        [[nodiscard]] virtual un_scalar_t stored_value() const noexcept = 0;
        [[nodiscard]] virtual std::string_view quantity_name() const noexcept = 0;
        [[nodiscard]] virtual std::string_view unit_name() const noexcept = 0;

#ifdef UNITSNET_ENABLE_JSON
        [[nodiscard]] std::string to_json() const
        {
            std::string result;

            result.reserve(
                quantity_name().size() +
                unit_name().size() +
                40);

            result += R"({"Unit":")";
            result += quantity_name();
            result += "Unit.";
            result += unit_name();
            result += R"(","Value":)";
            result += std::to_string(stored_value());
            result += '}';

            return result;
        }
#endif

        [[nodiscard]] std::string to_short_string() const
        {
            std::string result;

            result += unit_name();
            result += ',';
            result += std::to_string(stored_value());

            return result;
        }

        void SetValueAsInvalid()
        {
            _isInvalid = true;
        }

        void SetValueAsValid()
        {
            _isInvalid = false;
        }

        [[nodiscard]] bool GetValueIsValid() const
        {
            return !_isInvalid;
        }

    protected:

        bool _isInvalid = false;
    };

}
