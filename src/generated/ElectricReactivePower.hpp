#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class ElectricReactivePowerUnit : std::uint8_t
    {
        VoltamperesReactive,
        KilovoltamperesReactive,
        MegavoltamperesReactive,
        GigavoltamperesReactive,
    };

    /// <summary>In electric power transmission and distribution, volt-ampere reactive (var) is a unit of measurement of reactive power. Reactive power exists in an AC circuit when the current and voltage are not in phase.</summary>
    class ElectricReactivePower
    {
    public:
        constexpr explicit ElectricReactivePower(
            const un_scalar_t value,
            const ElectricReactivePowerUnit unit = ElectricReactivePowerUnit::VoltamperesReactive)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit ElectricReactivePower(const bool isValid)
        {
            _isInvalid = !isValid;
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
            return _isInvalid;
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricReactivePowerUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricReactivePower operator+(const ElectricReactivePower other) const noexcept
        {
            return ElectricReactivePower(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricReactivePower operator-(const ElectricReactivePower other) const noexcept
        {
            return ElectricReactivePower(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricReactivePower operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricReactivePower(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricReactivePower operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricReactivePower(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricReactivePower other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const ElectricReactivePower other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricReactivePower other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t voltamperes_reactive() const
        {
            return convert_from_base(ElectricReactivePowerUnit::VoltamperesReactive);
        }

        [[nodiscard]] static constexpr ElectricReactivePower from_voltamperes_reactive(const un_scalar_t value)
        {
            return ElectricReactivePower(value, ElectricReactivePowerUnit::VoltamperesReactive);
        }


        [[nodiscard]] constexpr un_scalar_t kilovoltamperes_reactive() const
        {
            return convert_from_base(ElectricReactivePowerUnit::KilovoltamperesReactive);
        }

        [[nodiscard]] static constexpr ElectricReactivePower from_kilovoltamperes_reactive(const un_scalar_t value)
        {
            return ElectricReactivePower(value, ElectricReactivePowerUnit::KilovoltamperesReactive);
        }


        [[nodiscard]] constexpr un_scalar_t megavoltamperes_reactive() const
        {
            return convert_from_base(ElectricReactivePowerUnit::MegavoltamperesReactive);
        }

        [[nodiscard]] static constexpr ElectricReactivePower from_megavoltamperes_reactive(const un_scalar_t value)
        {
            return ElectricReactivePower(value, ElectricReactivePowerUnit::MegavoltamperesReactive);
        }


        [[nodiscard]] constexpr un_scalar_t gigavoltamperes_reactive() const
        {
            return convert_from_base(ElectricReactivePowerUnit::GigavoltamperesReactive);
        }

        [[nodiscard]] static constexpr ElectricReactivePower from_gigavoltamperes_reactive(const un_scalar_t value)
        {
            return ElectricReactivePower(value, ElectricReactivePowerUnit::GigavoltamperesReactive);
        }


        [[nodiscard]] static constexpr ElectricReactivePower from_invalid()
        {
            return ElectricReactivePower(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricReactivePowerUnit unit)
        {
            switch (unit)
            {

            case ElectricReactivePowerUnit::VoltamperesReactive:
                return value;

            case ElectricReactivePowerUnit::KilovoltamperesReactive:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricReactivePowerUnit::MegavoltamperesReactive:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricReactivePowerUnit::GigavoltamperesReactive:
                return (value * static_cast<un_scalar_t>(1e9));

            }

            throw std::invalid_argument("Unknown ElectricReactivePower unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricReactivePowerUnit unit) const
        {
            switch (unit)
            {

            case ElectricReactivePowerUnit::VoltamperesReactive:
                return value_;

            case ElectricReactivePowerUnit::KilovoltamperesReactive:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case ElectricReactivePowerUnit::MegavoltamperesReactive:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case ElectricReactivePowerUnit::GigavoltamperesReactive:
                return (value_) / static_cast<un_scalar_t>(1e9);

            }

            throw std::invalid_argument("Unknown ElectricReactivePower unit.");
        }

        un_scalar_t value_;
    };
}
