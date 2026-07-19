#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class RadiationEquivalentDoseRateUnit : std::uint8_t
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
            const un_scalar_t value,
            const RadiationEquivalentDoseRateUnit unit = RadiationEquivalentDoseRateUnit::SievertsPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const RadiationEquivalentDoseRateUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RadiationEquivalentDoseRate operator+(const RadiationEquivalentDoseRate other) const noexcept
        {
            return RadiationEquivalentDoseRate(value_ + other.value_);
        }

        [[nodiscard]] constexpr RadiationEquivalentDoseRate operator-(const RadiationEquivalentDoseRate other) const noexcept
        {
            return RadiationEquivalentDoseRate(value_ - other.value_);
        }

        [[nodiscard]] constexpr RadiationEquivalentDoseRate operator*(const un_scalar_t scalar) const noexcept
        {
            return RadiationEquivalentDoseRate(value_ * scalar);
        }

        [[nodiscard]] constexpr RadiationEquivalentDoseRate operator/(const un_scalar_t scalar) const noexcept
        {
            return RadiationEquivalentDoseRate(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RadiationEquivalentDoseRate other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const RadiationEquivalentDoseRate other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t sieverts_per_hour() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::SievertsPerHour);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_sieverts_per_hour(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::SievertsPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t nanosieverts_per_hour() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::NanosievertsPerHour);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_nanosieverts_per_hour(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::NanosievertsPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t microsieverts_per_hour() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::MicrosievertsPerHour);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_microsieverts_per_hour(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::MicrosievertsPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t millisieverts_per_hour() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::MillisievertsPerHour);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_millisieverts_per_hour(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::MillisievertsPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t sieverts_per_second() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::SievertsPerSecond);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_sieverts_per_second(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::SievertsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t nanosieverts_per_second() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::NanosievertsPerSecond);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_nanosieverts_per_second(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::NanosievertsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t microsieverts_per_second() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::MicrosievertsPerSecond);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_microsieverts_per_second(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::MicrosievertsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t millisieverts_per_second() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::MillisievertsPerSecond);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_millisieverts_per_second(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::MillisievertsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t roentgens_equivalent_man_per_hour() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::RoentgensEquivalentManPerHour);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_roentgens_equivalent_man_per_hour(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::RoentgensEquivalentManPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t milliroentgens_equivalent_man_per_hour() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::MilliroentgensEquivalentManPerHour);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_milliroentgens_equivalent_man_per_hour(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::MilliroentgensEquivalentManPerHour);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RadiationEquivalentDoseRateUnit unit)
        {
            switch (unit)
            {

            case RadiationEquivalentDoseRateUnit::SievertsPerHour:
                return value/static_cast<un_scalar_t>(3600);

            case RadiationEquivalentDoseRateUnit::NanosievertsPerHour:
                return (value * static_cast<un_scalar_t>(1e-9))/static_cast<un_scalar_t>(3600);

            case RadiationEquivalentDoseRateUnit::MicrosievertsPerHour:
                return (value * static_cast<un_scalar_t>(1e-6))/static_cast<un_scalar_t>(3600);

            case RadiationEquivalentDoseRateUnit::MillisievertsPerHour:
                return (value * static_cast<un_scalar_t>(1e-3))/static_cast<un_scalar_t>(3600);

            case RadiationEquivalentDoseRateUnit::SievertsPerSecond:
                return value;

            case RadiationEquivalentDoseRateUnit::NanosievertsPerSecond:
                return (value * static_cast<un_scalar_t>(1e-9));

            case RadiationEquivalentDoseRateUnit::MicrosievertsPerSecond:
                return (value * static_cast<un_scalar_t>(1e-6));

            case RadiationEquivalentDoseRateUnit::MillisievertsPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3));

            case RadiationEquivalentDoseRateUnit::RoentgensEquivalentManPerHour:
                return value / static_cast<un_scalar_t>(100) / static_cast<un_scalar_t>(3600);

            case RadiationEquivalentDoseRateUnit::MilliroentgensEquivalentManPerHour:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(100) / static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown RadiationEquivalentDoseRate unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RadiationEquivalentDoseRateUnit unit) const
        {
            switch (unit)
            {

            case RadiationEquivalentDoseRateUnit::SievertsPerHour:
                return value_*static_cast<un_scalar_t>(3600);

            case RadiationEquivalentDoseRateUnit::NanosievertsPerHour:
                return (value_*static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-9);

            case RadiationEquivalentDoseRateUnit::MicrosievertsPerHour:
                return (value_*static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-6);

            case RadiationEquivalentDoseRateUnit::MillisievertsPerHour:
                return (value_*static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-3);

            case RadiationEquivalentDoseRateUnit::SievertsPerSecond:
                return value_;

            case RadiationEquivalentDoseRateUnit::NanosievertsPerSecond:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case RadiationEquivalentDoseRateUnit::MicrosievertsPerSecond:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case RadiationEquivalentDoseRateUnit::MillisievertsPerSecond:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case RadiationEquivalentDoseRateUnit::RoentgensEquivalentManPerHour:
                return value_ * static_cast<un_scalar_t>(100) * static_cast<un_scalar_t>(3600);

            case RadiationEquivalentDoseRateUnit::MilliroentgensEquivalentManPerHour:
                return (value_ * static_cast<un_scalar_t>(100) * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown RadiationEquivalentDoseRate unit.");
        }

        un_scalar_t value_;
    };
}
