#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class RadiationEquivalentDoseUnit : std::uint8_t
    {
        Sieverts,
        Nanosieverts,
        Microsieverts,
        Millisieverts,
        RoentgensEquivalentMan,
        MilliroentgensEquivalentMan,
    };

    /// <summary>Equivalent dose is a dose quantity representing the stochastic health effects of low levels of ionizing radiation on the human body which represents the probability of radiation-induced cancer and genetic damage.</summary>
    class RadiationEquivalentDose
    {
    public:
        constexpr explicit RadiationEquivalentDose(
            const un_scalar_t value,
            const RadiationEquivalentDoseUnit unit = RadiationEquivalentDoseUnit::Sieverts)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const RadiationEquivalentDoseUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RadiationEquivalentDose operator+(const RadiationEquivalentDose other) const noexcept
        {
            return RadiationEquivalentDose(value_ + other.value_);
        }

        [[nodiscard]] constexpr RadiationEquivalentDose operator-(const RadiationEquivalentDose other) const noexcept
        {
            return RadiationEquivalentDose(value_ - other.value_);
        }

        [[nodiscard]] constexpr RadiationEquivalentDose operator*(const un_scalar_t scalar) const noexcept
        {
            return RadiationEquivalentDose(value_ * scalar);
        }

        [[nodiscard]] constexpr RadiationEquivalentDose operator/(const un_scalar_t scalar) const noexcept
        {
            return RadiationEquivalentDose(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RadiationEquivalentDose other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const RadiationEquivalentDose other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t sieverts() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::Sieverts);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDose from_sieverts(const un_scalar_t value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::Sieverts);
        }


        [[nodiscard]] constexpr un_scalar_t nanosieverts() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::Nanosieverts);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDose from_nanosieverts(const un_scalar_t value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::Nanosieverts);
        }


        [[nodiscard]] constexpr un_scalar_t microsieverts() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::Microsieverts);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDose from_microsieverts(const un_scalar_t value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::Microsieverts);
        }


        [[nodiscard]] constexpr un_scalar_t millisieverts() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::Millisieverts);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDose from_millisieverts(const un_scalar_t value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::Millisieverts);
        }


        [[nodiscard]] constexpr un_scalar_t roentgens_equivalent_man() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::RoentgensEquivalentMan);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDose from_roentgens_equivalent_man(const un_scalar_t value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::RoentgensEquivalentMan);
        }


        [[nodiscard]] constexpr un_scalar_t milliroentgens_equivalent_man() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::MilliroentgensEquivalentMan);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDose from_milliroentgens_equivalent_man(const un_scalar_t value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::MilliroentgensEquivalentMan);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RadiationEquivalentDoseUnit unit)
        {
            switch (unit)
            {

            case RadiationEquivalentDoseUnit::Sieverts:
                return value;

            case RadiationEquivalentDoseUnit::Nanosieverts:
                return (value * static_cast<un_scalar_t>(1e-9));

            case RadiationEquivalentDoseUnit::Microsieverts:
                return (value * static_cast<un_scalar_t>(1e-6));

            case RadiationEquivalentDoseUnit::Millisieverts:
                return (value * static_cast<un_scalar_t>(1e-3));

            case RadiationEquivalentDoseUnit::RoentgensEquivalentMan:
                return value / static_cast<un_scalar_t>(100);

            case RadiationEquivalentDoseUnit::MilliroentgensEquivalentMan:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(100);

            }

            throw std::invalid_argument("Unknown RadiationEquivalentDose unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RadiationEquivalentDoseUnit unit) const
        {
            switch (unit)
            {

            case RadiationEquivalentDoseUnit::Sieverts:
                return value_;

            case RadiationEquivalentDoseUnit::Nanosieverts:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case RadiationEquivalentDoseUnit::Microsieverts:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case RadiationEquivalentDoseUnit::Millisieverts:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case RadiationEquivalentDoseUnit::RoentgensEquivalentMan:
                return value_ * static_cast<un_scalar_t>(100);

            case RadiationEquivalentDoseUnit::MilliroentgensEquivalentMan:
                return (value_ * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown RadiationEquivalentDose unit.");
        }

        un_scalar_t value_;
    };
}
