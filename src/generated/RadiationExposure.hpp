#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class RadiationExposureUnit : std::uint16_t
    {
        CoulombsPerKilogram,
        PicocoulombsPerKilogram,
        NanocoulombsPerKilogram,
        MicrocoulombsPerKilogram,
        MillicoulombsPerKilogram,
        Roentgens,
        Microroentgens,
        Milliroentgens,
    };

    /// <summary>Radiation exposure is a measure of the ionization of air due to ionizing radiation from photons.</summary>
    class RadiationExposure
    {
    public:
        constexpr explicit RadiationExposure(
            double value,
            RadiationExposureUnit unit = RadiationExposureUnit::CoulombsPerKilogram)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(RadiationExposureUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RadiationExposure operator+(RadiationExposure other) const noexcept
        {
            return RadiationExposure(value_ + other.value_);
        }

        [[nodiscard]] constexpr RadiationExposure operator-(RadiationExposure other) const noexcept
        {
            return RadiationExposure(value_ - other.value_);
        }

        [[nodiscard]] constexpr RadiationExposure operator*(double scalar) const noexcept
        {
            return RadiationExposure(value_ * scalar);
        }

        [[nodiscard]] constexpr RadiationExposure operator/(double scalar) const noexcept
        {
            return RadiationExposure(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(RadiationExposure other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(RadiationExposure other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double coulombs_per_kilogram() const
        {
            return convert_from_base(RadiationExposureUnit::CoulombsPerKilogram);
        }

        [[nodiscard]] static constexpr RadiationExposure from_coulombs_per_kilogram(double value)
        {
            return RadiationExposure(value, RadiationExposureUnit::CoulombsPerKilogram);
        }


        [[nodiscard]] constexpr double picocoulombs_per_kilogram() const
        {
            return convert_from_base(RadiationExposureUnit::PicocoulombsPerKilogram);
        }

        [[nodiscard]] static constexpr RadiationExposure from_picocoulombs_per_kilogram(double value)
        {
            return RadiationExposure(value, RadiationExposureUnit::PicocoulombsPerKilogram);
        }


        [[nodiscard]] constexpr double nanocoulombs_per_kilogram() const
        {
            return convert_from_base(RadiationExposureUnit::NanocoulombsPerKilogram);
        }

        [[nodiscard]] static constexpr RadiationExposure from_nanocoulombs_per_kilogram(double value)
        {
            return RadiationExposure(value, RadiationExposureUnit::NanocoulombsPerKilogram);
        }


        [[nodiscard]] constexpr double microcoulombs_per_kilogram() const
        {
            return convert_from_base(RadiationExposureUnit::MicrocoulombsPerKilogram);
        }

        [[nodiscard]] static constexpr RadiationExposure from_microcoulombs_per_kilogram(double value)
        {
            return RadiationExposure(value, RadiationExposureUnit::MicrocoulombsPerKilogram);
        }


        [[nodiscard]] constexpr double millicoulombs_per_kilogram() const
        {
            return convert_from_base(RadiationExposureUnit::MillicoulombsPerKilogram);
        }

        [[nodiscard]] static constexpr RadiationExposure from_millicoulombs_per_kilogram(double value)
        {
            return RadiationExposure(value, RadiationExposureUnit::MillicoulombsPerKilogram);
        }


        [[nodiscard]] constexpr double roentgens() const
        {
            return convert_from_base(RadiationExposureUnit::Roentgens);
        }

        [[nodiscard]] static constexpr RadiationExposure from_roentgens(double value)
        {
            return RadiationExposure(value, RadiationExposureUnit::Roentgens);
        }


        [[nodiscard]] constexpr double microroentgens() const
        {
            return convert_from_base(RadiationExposureUnit::Microroentgens);
        }

        [[nodiscard]] static constexpr RadiationExposure from_microroentgens(double value)
        {
            return RadiationExposure(value, RadiationExposureUnit::Microroentgens);
        }


        [[nodiscard]] constexpr double milliroentgens() const
        {
            return convert_from_base(RadiationExposureUnit::Milliroentgens);
        }

        [[nodiscard]] static constexpr RadiationExposure from_milliroentgens(double value)
        {
            return RadiationExposure(value, RadiationExposureUnit::Milliroentgens);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, RadiationExposureUnit unit)
        {
            switch (unit)
            {

            case RadiationExposureUnit::CoulombsPerKilogram:
                return value;

            case RadiationExposureUnit::PicocoulombsPerKilogram:
                return (value * 1e-12);

            case RadiationExposureUnit::NanocoulombsPerKilogram:
                return (value * 1e-9);

            case RadiationExposureUnit::MicrocoulombsPerKilogram:
                return (value * 1e-6);

            case RadiationExposureUnit::MillicoulombsPerKilogram:
                return (value * 1e-3);

            case RadiationExposureUnit::Roentgens:
                return value * 2.58e-4;

            case RadiationExposureUnit::Microroentgens:
                return (value * 1e-6) * 2.58e-4;

            case RadiationExposureUnit::Milliroentgens:
                return (value * 1e-3) * 2.58e-4;

            }

            throw std::invalid_argument("Unknown RadiationExposure unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(RadiationExposureUnit unit) const
        {
            switch (unit)
            {

            case RadiationExposureUnit::CoulombsPerKilogram:
                return value_;

            case RadiationExposureUnit::PicocoulombsPerKilogram:
                return (value_) / 1e-12;

            case RadiationExposureUnit::NanocoulombsPerKilogram:
                return (value_) / 1e-9;

            case RadiationExposureUnit::MicrocoulombsPerKilogram:
                return (value_) / 1e-6;

            case RadiationExposureUnit::MillicoulombsPerKilogram:
                return (value_) / 1e-3;

            case RadiationExposureUnit::Roentgens:
                return value_ / 2.58e-4;

            case RadiationExposureUnit::Microroentgens:
                return (value_ / 2.58e-4) / 1e-6;

            case RadiationExposureUnit::Milliroentgens:
                return (value_ / 2.58e-4) / 1e-3;

            }

            throw std::invalid_argument("Unknown RadiationExposure unit.");
        }

        double value_;
    };
}
