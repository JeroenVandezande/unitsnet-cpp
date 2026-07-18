#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class RadiationEquivalentDoseRateUnit : std::uint16_t
    {
        SievertsPerHour,
        NanosievertsPerHour,
        MicrosievertsPerHour,
        MillisievertsPerHour,
        SievertsPerSecond,
        NanosievertsPerSecond,
        MicrosievertsPerSecond,
        MillisievertsPerSecond,
        RoentgensEquivalentManPerHour,
        MilliroentgensEquivalentManPerHour,
    };

    /// <summary>A dose rate is quantity of radiation absorbed or delivered per unit time.</summary>
    class RadiationEquivalentDoseRate
    {
    public:
        constexpr explicit RadiationEquivalentDoseRate(
            double value,
            RadiationEquivalentDoseRateUnit unit = RadiationEquivalentDoseRateUnit::SievertsPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(RadiationEquivalentDoseRateUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RadiationEquivalentDoseRate operator+(RadiationEquivalentDoseRate other) const noexcept
        {
            return RadiationEquivalentDoseRate(value_ + other.value_);
        }

        [[nodiscard]] constexpr RadiationEquivalentDoseRate operator-(RadiationEquivalentDoseRate other) const noexcept
        {
            return RadiationEquivalentDoseRate(value_ - other.value_);
        }

        [[nodiscard]] constexpr RadiationEquivalentDoseRate operator*(double scalar) const noexcept
        {
            return RadiationEquivalentDoseRate(value_ * scalar);
        }

        [[nodiscard]] constexpr RadiationEquivalentDoseRate operator/(double scalar) const noexcept
        {
            return RadiationEquivalentDoseRate(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(RadiationEquivalentDoseRate other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(RadiationEquivalentDoseRate other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double sieverts_per_hour() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::SievertsPerHour);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_sieverts_per_hour(double value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::SievertsPerHour);
        }


        [[nodiscard]] constexpr double nanosieverts_per_hour() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::NanosievertsPerHour);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_nanosieverts_per_hour(double value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::NanosievertsPerHour);
        }


        [[nodiscard]] constexpr double microsieverts_per_hour() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::MicrosievertsPerHour);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_microsieverts_per_hour(double value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::MicrosievertsPerHour);
        }


        [[nodiscard]] constexpr double millisieverts_per_hour() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::MillisievertsPerHour);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_millisieverts_per_hour(double value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::MillisievertsPerHour);
        }


        [[nodiscard]] constexpr double sieverts_per_second() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::SievertsPerSecond);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_sieverts_per_second(double value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::SievertsPerSecond);
        }


        [[nodiscard]] constexpr double nanosieverts_per_second() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::NanosievertsPerSecond);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_nanosieverts_per_second(double value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::NanosievertsPerSecond);
        }


        [[nodiscard]] constexpr double microsieverts_per_second() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::MicrosievertsPerSecond);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_microsieverts_per_second(double value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::MicrosievertsPerSecond);
        }


        [[nodiscard]] constexpr double millisieverts_per_second() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::MillisievertsPerSecond);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_millisieverts_per_second(double value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::MillisievertsPerSecond);
        }


        [[nodiscard]] constexpr double roentgens_equivalent_man_per_hour() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::RoentgensEquivalentManPerHour);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_roentgens_equivalent_man_per_hour(double value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::RoentgensEquivalentManPerHour);
        }


        [[nodiscard]] constexpr double milliroentgens_equivalent_man_per_hour() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::MilliroentgensEquivalentManPerHour);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_milliroentgens_equivalent_man_per_hour(double value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::MilliroentgensEquivalentManPerHour);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, RadiationEquivalentDoseRateUnit unit)
        {
            switch (unit)
            {

            case RadiationEquivalentDoseRateUnit::SievertsPerHour:
                return value/3600;

            case RadiationEquivalentDoseRateUnit::NanosievertsPerHour:
                return (value * 1e-9)/3600;

            case RadiationEquivalentDoseRateUnit::MicrosievertsPerHour:
                return (value * 1e-6)/3600;

            case RadiationEquivalentDoseRateUnit::MillisievertsPerHour:
                return (value * 1e-3)/3600;

            case RadiationEquivalentDoseRateUnit::SievertsPerSecond:
                return value;

            case RadiationEquivalentDoseRateUnit::NanosievertsPerSecond:
                return (value * 1e-9);

            case RadiationEquivalentDoseRateUnit::MicrosievertsPerSecond:
                return (value * 1e-6);

            case RadiationEquivalentDoseRateUnit::MillisievertsPerSecond:
                return (value * 1e-3);

            case RadiationEquivalentDoseRateUnit::RoentgensEquivalentManPerHour:
                return value / 100 / 3600;

            case RadiationEquivalentDoseRateUnit::MilliroentgensEquivalentManPerHour:
                return (value * 1e-3) / 100 / 3600;

            }

            throw std::invalid_argument("Unknown RadiationEquivalentDoseRate unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(RadiationEquivalentDoseRateUnit unit) const
        {
            switch (unit)
            {

            case RadiationEquivalentDoseRateUnit::SievertsPerHour:
                return value_*3600;

            case RadiationEquivalentDoseRateUnit::NanosievertsPerHour:
                return (value_*3600) / 1e-9;

            case RadiationEquivalentDoseRateUnit::MicrosievertsPerHour:
                return (value_*3600) / 1e-6;

            case RadiationEquivalentDoseRateUnit::MillisievertsPerHour:
                return (value_*3600) / 1e-3;

            case RadiationEquivalentDoseRateUnit::SievertsPerSecond:
                return value_;

            case RadiationEquivalentDoseRateUnit::NanosievertsPerSecond:
                return (value_) / 1e-9;

            case RadiationEquivalentDoseRateUnit::MicrosievertsPerSecond:
                return (value_) / 1e-6;

            case RadiationEquivalentDoseRateUnit::MillisievertsPerSecond:
                return (value_) / 1e-3;

            case RadiationEquivalentDoseRateUnit::RoentgensEquivalentManPerHour:
                return value_ * 100 * 3600;

            case RadiationEquivalentDoseRateUnit::MilliroentgensEquivalentManPerHour:
                return (value_ * 100 * 3600) / 1e-3;

            }

            throw std::invalid_argument("Unknown RadiationEquivalentDoseRate unit.");
        }

        double value_;
    };
}
