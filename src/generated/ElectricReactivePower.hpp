#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricReactivePowerUnit : std::uint16_t
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
            double value,
            ElectricReactivePowerUnit unit = ElectricReactivePowerUnit::VoltamperesReactive)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricReactivePowerUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricReactivePower operator+(ElectricReactivePower other) const noexcept
        {
            return ElectricReactivePower(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricReactivePower operator-(ElectricReactivePower other) const noexcept
        {
            return ElectricReactivePower(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricReactivePower operator*(double scalar) const noexcept
        {
            return ElectricReactivePower(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricReactivePower operator/(double scalar) const noexcept
        {
            return ElectricReactivePower(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricReactivePower other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricReactivePower other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double voltamperes_reactive() const
        {
            return convert_from_base(ElectricReactivePowerUnit::VoltamperesReactive);
        }

        [[nodiscard]] static constexpr ElectricReactivePower from_voltamperes_reactive(double value)
        {
            return ElectricReactivePower(value, ElectricReactivePowerUnit::VoltamperesReactive);
        }


        [[nodiscard]] constexpr double kilovoltamperes_reactive() const
        {
            return convert_from_base(ElectricReactivePowerUnit::KilovoltamperesReactive);
        }

        [[nodiscard]] static constexpr ElectricReactivePower from_kilovoltamperes_reactive(double value)
        {
            return ElectricReactivePower(value, ElectricReactivePowerUnit::KilovoltamperesReactive);
        }


        [[nodiscard]] constexpr double megavoltamperes_reactive() const
        {
            return convert_from_base(ElectricReactivePowerUnit::MegavoltamperesReactive);
        }

        [[nodiscard]] static constexpr ElectricReactivePower from_megavoltamperes_reactive(double value)
        {
            return ElectricReactivePower(value, ElectricReactivePowerUnit::MegavoltamperesReactive);
        }


        [[nodiscard]] constexpr double gigavoltamperes_reactive() const
        {
            return convert_from_base(ElectricReactivePowerUnit::GigavoltamperesReactive);
        }

        [[nodiscard]] static constexpr ElectricReactivePower from_gigavoltamperes_reactive(double value)
        {
            return ElectricReactivePower(value, ElectricReactivePowerUnit::GigavoltamperesReactive);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricReactivePowerUnit unit)
        {
            switch (unit)
            {

            case ElectricReactivePowerUnit::VoltamperesReactive:
                return value;

            case ElectricReactivePowerUnit::KilovoltamperesReactive:
                return (value * 1e3);

            case ElectricReactivePowerUnit::MegavoltamperesReactive:
                return (value * 1e6);

            case ElectricReactivePowerUnit::GigavoltamperesReactive:
                return (value * 1e9);

            }

            throw std::invalid_argument("Unknown ElectricReactivePower unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricReactivePowerUnit unit) const
        {
            switch (unit)
            {

            case ElectricReactivePowerUnit::VoltamperesReactive:
                return value_;

            case ElectricReactivePowerUnit::KilovoltamperesReactive:
                return (value_) / 1e3;

            case ElectricReactivePowerUnit::MegavoltamperesReactive:
                return (value_) / 1e6;

            case ElectricReactivePowerUnit::GigavoltamperesReactive:
                return (value_) / 1e9;

            }

            throw std::invalid_argument("Unknown ElectricReactivePower unit.");
        }

        double value_;
    };
}
