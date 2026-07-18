#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class RadiationEquivalentDoseUnit : std::uint16_t
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
            double value,
            RadiationEquivalentDoseUnit unit = RadiationEquivalentDoseUnit::Sieverts)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(RadiationEquivalentDoseUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RadiationEquivalentDose operator+(RadiationEquivalentDose other) const noexcept
        {
            return RadiationEquivalentDose(value_ + other.value_);
        }

        [[nodiscard]] constexpr RadiationEquivalentDose operator-(RadiationEquivalentDose other) const noexcept
        {
            return RadiationEquivalentDose(value_ - other.value_);
        }

        [[nodiscard]] constexpr RadiationEquivalentDose operator*(double scalar) const noexcept
        {
            return RadiationEquivalentDose(value_ * scalar);
        }

        [[nodiscard]] constexpr RadiationEquivalentDose operator/(double scalar) const noexcept
        {
            return RadiationEquivalentDose(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(RadiationEquivalentDose other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(RadiationEquivalentDose other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double sieverts() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::Sieverts);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDose from_sieverts(double value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::Sieverts);
        }


        [[nodiscard]] constexpr double nanosieverts() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::Nanosieverts);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDose from_nanosieverts(double value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::Nanosieverts);
        }


        [[nodiscard]] constexpr double microsieverts() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::Microsieverts);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDose from_microsieverts(double value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::Microsieverts);
        }


        [[nodiscard]] constexpr double millisieverts() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::Millisieverts);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDose from_millisieverts(double value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::Millisieverts);
        }


        [[nodiscard]] constexpr double roentgens_equivalent_man() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::RoentgensEquivalentMan);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDose from_roentgens_equivalent_man(double value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::RoentgensEquivalentMan);
        }


        [[nodiscard]] constexpr double milliroentgens_equivalent_man() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::MilliroentgensEquivalentMan);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDose from_milliroentgens_equivalent_man(double value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::MilliroentgensEquivalentMan);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, RadiationEquivalentDoseUnit unit)
        {
            switch (unit)
            {

            case RadiationEquivalentDoseUnit::Sieverts:
                return value;

            case RadiationEquivalentDoseUnit::Nanosieverts:
                return (value * 1e-9);

            case RadiationEquivalentDoseUnit::Microsieverts:
                return (value * 1e-6);

            case RadiationEquivalentDoseUnit::Millisieverts:
                return (value * 1e-3);

            case RadiationEquivalentDoseUnit::RoentgensEquivalentMan:
                return value / 100;

            case RadiationEquivalentDoseUnit::MilliroentgensEquivalentMan:
                return (value * 1e-3) / 100;

            }

            throw std::invalid_argument("Unknown RadiationEquivalentDose unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(RadiationEquivalentDoseUnit unit) const
        {
            switch (unit)
            {

            case RadiationEquivalentDoseUnit::Sieverts:
                return value_;

            case RadiationEquivalentDoseUnit::Nanosieverts:
                return (value_) / 1e-9;

            case RadiationEquivalentDoseUnit::Microsieverts:
                return (value_) / 1e-6;

            case RadiationEquivalentDoseUnit::Millisieverts:
                return (value_) / 1e-3;

            case RadiationEquivalentDoseUnit::RoentgensEquivalentMan:
                return value_ * 100;

            case RadiationEquivalentDoseUnit::MilliroentgensEquivalentMan:
                return (value_ * 100) / 1e-3;

            }

            throw std::invalid_argument("Unknown RadiationEquivalentDose unit.");
        }

        double value_;
    };
}
