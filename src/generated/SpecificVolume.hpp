#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class SpecificVolumeUnit : std::uint8_t
    {
        CubicMetersPerKilogram,
        MillicubicMetersPerKilogram,
        CubicFeetPerPound,
    };

    /// <summary>In thermodynamics, the specific volume of a substance is the ratio of the substance's volume to its mass. It is the reciprocal of density and an intrinsic property of matter as well.</summary>
    class SpecificVolume : public UnitsNetBase
    {
    public:
        constexpr explicit SpecificVolume(
            const un_scalar_t value,
            const SpecificVolumeUnit unit = SpecificVolumeUnit::CubicMetersPerKilogram)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const SpecificVolumeUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr SpecificVolume operator+(const SpecificVolume& other) const noexcept
        {
            return SpecificVolume(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr SpecificVolume operator-(const SpecificVolume& other)const noexcept
        {
            return SpecificVolume(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr SpecificVolume operator*(const un_scalar_t scalar) const noexcept
        {
            return SpecificVolume(base_value() * scalar);
        }

        [[nodiscard]] constexpr SpecificVolume operator/(const un_scalar_t scalar) const noexcept
        {
            return SpecificVolume(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const SpecificVolume& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const SpecificVolume& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const SpecificVolume& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t cubic_meters_per_kilogram() const
        {
            return convert_from_base(SpecificVolumeUnit::CubicMetersPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificVolume from_cubic_meters_per_kilogram(const un_scalar_t value)
        {
            return SpecificVolume(value, SpecificVolumeUnit::CubicMetersPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t millicubic_meters_per_kilogram() const
        {
            return convert_from_base(SpecificVolumeUnit::MillicubicMetersPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificVolume from_millicubic_meters_per_kilogram(const un_scalar_t value)
        {
            return SpecificVolume(value, SpecificVolumeUnit::MillicubicMetersPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_feet_per_pound() const
        {
            return convert_from_base(SpecificVolumeUnit::CubicFeetPerPound);
        }

        [[nodiscard]] static constexpr SpecificVolume from_cubic_feet_per_pound(const un_scalar_t value)
        {
            return SpecificVolume(value, SpecificVolumeUnit::CubicFeetPerPound);
        }

        [[nodiscard]] static constexpr SpecificVolume from_invalid()
        {
            return SpecificVolume(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, SpecificVolumeUnit unit)
        {
            switch (unit)
            {

            case SpecificVolumeUnit::CubicMetersPerKilogram:
                return value;

            case SpecificVolumeUnit::MillicubicMetersPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-3));

            case SpecificVolumeUnit::CubicFeetPerPound:
                return value * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(0.45359237);

            }

            throw std::invalid_argument("Unknown SpecificVolume unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const SpecificVolumeUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case SpecificVolumeUnit::CubicMetersPerKilogram:
                return base_value;

            case SpecificVolumeUnit::MillicubicMetersPerKilogram:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case SpecificVolumeUnit::CubicFeetPerPound:
                return base_value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.028316846592);

            }

            throw std::invalid_argument("Unknown SpecificVolume unit.");
        }

        un_scalar_t value_;
        SpecificVolumeUnit value_unit_type_;       
    };
}
