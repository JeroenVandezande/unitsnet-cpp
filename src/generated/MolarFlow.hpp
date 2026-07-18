#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class MolarFlowUnit : std::uint16_t
    {
        MolesPerSecond,
        KilomolesPerSecond,
        MolesPerMinute,
        KilomolesPerMinute,
        MolesPerHour,
        KilomolesPerHour,
        PoundMolesPerSecond,
        PoundMolesPerMinute,
        PoundMolesPerHour,
    };

    /// <summary>Molar flow is the ratio of the amount of substance change to the time during which the change occurred (value of amount of substance changes per unit time).</summary>
    class MolarFlow
    {
    public:
        constexpr explicit MolarFlow(
            double value,
            MolarFlowUnit unit = MolarFlowUnit::MolesPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(MolarFlowUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MolarFlow operator+(MolarFlow other) const noexcept
        {
            return MolarFlow(value_ + other.value_);
        }

        [[nodiscard]] constexpr MolarFlow operator-(MolarFlow other) const noexcept
        {
            return MolarFlow(value_ - other.value_);
        }

        [[nodiscard]] constexpr MolarFlow operator*(double scalar) const noexcept
        {
            return MolarFlow(value_ * scalar);
        }

        [[nodiscard]] constexpr MolarFlow operator/(double scalar) const noexcept
        {
            return MolarFlow(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(MolarFlow other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(MolarFlow other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double moles_per_second() const
        {
            return convert_from_base(MolarFlowUnit::MolesPerSecond);
        }

        [[nodiscard]] static constexpr MolarFlow from_moles_per_second(double value)
        {
            return MolarFlow(value, MolarFlowUnit::MolesPerSecond);
        }


        [[nodiscard]] constexpr double kilomoles_per_second() const
        {
            return convert_from_base(MolarFlowUnit::KilomolesPerSecond);
        }

        [[nodiscard]] static constexpr MolarFlow from_kilomoles_per_second(double value)
        {
            return MolarFlow(value, MolarFlowUnit::KilomolesPerSecond);
        }


        [[nodiscard]] constexpr double moles_per_minute() const
        {
            return convert_from_base(MolarFlowUnit::MolesPerMinute);
        }

        [[nodiscard]] static constexpr MolarFlow from_moles_per_minute(double value)
        {
            return MolarFlow(value, MolarFlowUnit::MolesPerMinute);
        }


        [[nodiscard]] constexpr double kilomoles_per_minute() const
        {
            return convert_from_base(MolarFlowUnit::KilomolesPerMinute);
        }

        [[nodiscard]] static constexpr MolarFlow from_kilomoles_per_minute(double value)
        {
            return MolarFlow(value, MolarFlowUnit::KilomolesPerMinute);
        }


        [[nodiscard]] constexpr double moles_per_hour() const
        {
            return convert_from_base(MolarFlowUnit::MolesPerHour);
        }

        [[nodiscard]] static constexpr MolarFlow from_moles_per_hour(double value)
        {
            return MolarFlow(value, MolarFlowUnit::MolesPerHour);
        }


        [[nodiscard]] constexpr double kilomoles_per_hour() const
        {
            return convert_from_base(MolarFlowUnit::KilomolesPerHour);
        }

        [[nodiscard]] static constexpr MolarFlow from_kilomoles_per_hour(double value)
        {
            return MolarFlow(value, MolarFlowUnit::KilomolesPerHour);
        }


        [[nodiscard]] constexpr double pound_moles_per_second() const
        {
            return convert_from_base(MolarFlowUnit::PoundMolesPerSecond);
        }

        [[nodiscard]] static constexpr MolarFlow from_pound_moles_per_second(double value)
        {
            return MolarFlow(value, MolarFlowUnit::PoundMolesPerSecond);
        }


        [[nodiscard]] constexpr double pound_moles_per_minute() const
        {
            return convert_from_base(MolarFlowUnit::PoundMolesPerMinute);
        }

        [[nodiscard]] static constexpr MolarFlow from_pound_moles_per_minute(double value)
        {
            return MolarFlow(value, MolarFlowUnit::PoundMolesPerMinute);
        }


        [[nodiscard]] constexpr double pound_moles_per_hour() const
        {
            return convert_from_base(MolarFlowUnit::PoundMolesPerHour);
        }

        [[nodiscard]] static constexpr MolarFlow from_pound_moles_per_hour(double value)
        {
            return MolarFlow(value, MolarFlowUnit::PoundMolesPerHour);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, MolarFlowUnit unit)
        {
            switch (unit)
            {

            case MolarFlowUnit::MolesPerSecond:
                return value;

            case MolarFlowUnit::KilomolesPerSecond:
                return (value * 1e3);

            case MolarFlowUnit::MolesPerMinute:
                return value / 60;

            case MolarFlowUnit::KilomolesPerMinute:
                return (value * 1e3) / 60;

            case MolarFlowUnit::MolesPerHour:
                return value / 3600;

            case MolarFlowUnit::KilomolesPerHour:
                return (value * 1e3) / 3600;

            case MolarFlowUnit::PoundMolesPerSecond:
                return value * 453.59237;

            case MolarFlowUnit::PoundMolesPerMinute:
                return (value * 453.59237) / 60;

            case MolarFlowUnit::PoundMolesPerHour:
                return (value * 453.59237) / 3600;

            }

            throw std::invalid_argument("Unknown MolarFlow unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(MolarFlowUnit unit) const
        {
            switch (unit)
            {

            case MolarFlowUnit::MolesPerSecond:
                return value_;

            case MolarFlowUnit::KilomolesPerSecond:
                return (value_) / 1e3;

            case MolarFlowUnit::MolesPerMinute:
                return value_ * 60;

            case MolarFlowUnit::KilomolesPerMinute:
                return (value_ * 60) / 1e3;

            case MolarFlowUnit::MolesPerHour:
                return value_ * 3600;

            case MolarFlowUnit::KilomolesPerHour:
                return (value_ * 3600) / 1e3;

            case MolarFlowUnit::PoundMolesPerSecond:
                return value_ / 453.59237;

            case MolarFlowUnit::PoundMolesPerMinute:
                return (value_ / 453.59237) * 60;

            case MolarFlowUnit::PoundMolesPerHour:
                return (value_ / 453.59237) * 3600;

            }

            throw std::invalid_argument("Unknown MolarFlow unit.");
        }

        double value_;
    };
}
