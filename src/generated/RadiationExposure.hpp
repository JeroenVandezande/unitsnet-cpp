#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class RadiationExposureUnit : std::uint8_t
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
            const un_scalar_t value,
            const RadiationExposureUnit unit = RadiationExposureUnit::CoulombsPerKilogram)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const RadiationExposureUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RadiationExposure operator+(const RadiationExposure other) const noexcept
        {
            return RadiationExposure(value_ + other.value_);
        }

        [[nodiscard]] constexpr RadiationExposure operator-(const RadiationExposure other) const noexcept
        {
            return RadiationExposure(value_ - other.value_);
        }

        [[nodiscard]] constexpr RadiationExposure operator*(const un_scalar_t scalar) const noexcept
        {
            return RadiationExposure(value_ * scalar);
        }

        [[nodiscard]] constexpr RadiationExposure operator/(const un_scalar_t scalar) const noexcept
        {
            return RadiationExposure(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RadiationExposure other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const RadiationExposure other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t coulombs_per_kilogram() const
        {
            return convert_from_base(RadiationExposureUnit::CoulombsPerKilogram);
        }

        [[nodiscard]] static constexpr RadiationExposure from_coulombs_per_kilogram(const un_scalar_t value)
        {
            return RadiationExposure(value, RadiationExposureUnit::CoulombsPerKilogram);
        }


        [[nodiscard]] constexpr un_scalar_t picocoulombs_per_kilogram() const
        {
            return convert_from_base(RadiationExposureUnit::PicocoulombsPerKilogram);
        }

        [[nodiscard]] static constexpr RadiationExposure from_picocoulombs_per_kilogram(const un_scalar_t value)
        {
            return RadiationExposure(value, RadiationExposureUnit::PicocoulombsPerKilogram);
        }


        [[nodiscard]] constexpr un_scalar_t nanocoulombs_per_kilogram() const
        {
            return convert_from_base(RadiationExposureUnit::NanocoulombsPerKilogram);
        }

        [[nodiscard]] static constexpr RadiationExposure from_nanocoulombs_per_kilogram(const un_scalar_t value)
        {
            return RadiationExposure(value, RadiationExposureUnit::NanocoulombsPerKilogram);
        }


        [[nodiscard]] constexpr un_scalar_t microcoulombs_per_kilogram() const
        {
            return convert_from_base(RadiationExposureUnit::MicrocoulombsPerKilogram);
        }

        [[nodiscard]] static constexpr RadiationExposure from_microcoulombs_per_kilogram(const un_scalar_t value)
        {
            return RadiationExposure(value, RadiationExposureUnit::MicrocoulombsPerKilogram);
        }


        [[nodiscard]] constexpr un_scalar_t millicoulombs_per_kilogram() const
        {
            return convert_from_base(RadiationExposureUnit::MillicoulombsPerKilogram);
        }

        [[nodiscard]] static constexpr RadiationExposure from_millicoulombs_per_kilogram(const un_scalar_t value)
        {
            return RadiationExposure(value, RadiationExposureUnit::MillicoulombsPerKilogram);
        }


        [[nodiscard]] constexpr un_scalar_t roentgens() const
        {
            return convert_from_base(RadiationExposureUnit::Roentgens);
        }

        [[nodiscard]] static constexpr RadiationExposure from_roentgens(const un_scalar_t value)
        {
            return RadiationExposure(value, RadiationExposureUnit::Roentgens);
        }


        [[nodiscard]] constexpr un_scalar_t microroentgens() const
        {
            return convert_from_base(RadiationExposureUnit::Microroentgens);
        }

        [[nodiscard]] static constexpr RadiationExposure from_microroentgens(const un_scalar_t value)
        {
            return RadiationExposure(value, RadiationExposureUnit::Microroentgens);
        }


        [[nodiscard]] constexpr un_scalar_t milliroentgens() const
        {
            return convert_from_base(RadiationExposureUnit::Milliroentgens);
        }

        [[nodiscard]] static constexpr RadiationExposure from_milliroentgens(const un_scalar_t value)
        {
            return RadiationExposure(value, RadiationExposureUnit::Milliroentgens);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RadiationExposureUnit unit)
        {
            switch (unit)
            {

            case RadiationExposureUnit::CoulombsPerKilogram:
                return value;

            case RadiationExposureUnit::PicocoulombsPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-12));

            case RadiationExposureUnit::NanocoulombsPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-9));

            case RadiationExposureUnit::MicrocoulombsPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-6));

            case RadiationExposureUnit::MillicoulombsPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-3));

            case RadiationExposureUnit::Roentgens:
                return value * 2.58e-4;

            case RadiationExposureUnit::Microroentgens:
                return (value * static_cast<un_scalar_t>(1e-6)) * 2.58e-4;

            case RadiationExposureUnit::Milliroentgens:
                return (value * static_cast<un_scalar_t>(1e-3)) * 2.58e-4;

            }

            throw std::invalid_argument("Unknown RadiationExposure unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RadiationExposureUnit unit) const
        {
            switch (unit)
            {

            case RadiationExposureUnit::CoulombsPerKilogram:
                return value_;

            case RadiationExposureUnit::PicocoulombsPerKilogram:
                return (value_) / static_cast<un_scalar_t>(1e-12);

            case RadiationExposureUnit::NanocoulombsPerKilogram:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case RadiationExposureUnit::MicrocoulombsPerKilogram:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case RadiationExposureUnit::MillicoulombsPerKilogram:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case RadiationExposureUnit::Roentgens:
                return value_ / 2.58e-4;

            case RadiationExposureUnit::Microroentgens:
                return (value_ / 2.58e-4) / static_cast<un_scalar_t>(1e-6);

            case RadiationExposureUnit::Milliroentgens:
                return (value_ / 2.58e-4) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown RadiationExposure unit.");
        }

        un_scalar_t value_;
    };
}
