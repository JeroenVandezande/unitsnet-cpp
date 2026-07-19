#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

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
    class RadiationExposure : public UnitsNetBase
    {
    public:
        constexpr explicit RadiationExposure(
            const un_scalar_t value,
            const RadiationExposureUnit unit = RadiationExposureUnit::CoulombsPerKilogram)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const RadiationExposureUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RadiationExposure operator+(const RadiationExposure& other) const noexcept
        {
            return RadiationExposure(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr RadiationExposure operator-(const RadiationExposure& other)const noexcept
        {
            return RadiationExposure(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr RadiationExposure operator*(const un_scalar_t scalar) const noexcept
        {
            return RadiationExposure(base_value() * scalar);
        }

        [[nodiscard]] constexpr RadiationExposure operator/(const un_scalar_t scalar) const noexcept
        {
            return RadiationExposure(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RadiationExposure& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const RadiationExposure& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const RadiationExposure& other) const noexcept
        {
            return base_value() > other.base_value();
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

        [[nodiscard]] static constexpr RadiationExposure from_invalid()
        {
            return RadiationExposure(false);
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
                return value * static_cast<un_scalar_t>(2.58e-4);

            case RadiationExposureUnit::Microroentgens:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(2.58e-4);

            case RadiationExposureUnit::Milliroentgens:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(2.58e-4);

            }

            throw std::invalid_argument("Unknown RadiationExposure unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RadiationExposureUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case RadiationExposureUnit::CoulombsPerKilogram:
                return base_value;

            case RadiationExposureUnit::PicocoulombsPerKilogram:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case RadiationExposureUnit::NanocoulombsPerKilogram:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case RadiationExposureUnit::MicrocoulombsPerKilogram:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case RadiationExposureUnit::MillicoulombsPerKilogram:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case RadiationExposureUnit::Roentgens:
                return base_value / static_cast<un_scalar_t>(2.58e-4);

            case RadiationExposureUnit::Microroentgens:
                return (base_value / static_cast<un_scalar_t>(2.58e-4)) / static_cast<un_scalar_t>(1e-6);

            case RadiationExposureUnit::Milliroentgens:
                return (base_value / static_cast<un_scalar_t>(2.58e-4)) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown RadiationExposure unit.");
        }

        un_scalar_t value_;
        RadiationExposureUnit value_unit_type_;       
    };
}
