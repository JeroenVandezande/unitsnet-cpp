#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class AngleUnit : std::uint8_t
    {
        Radians,
        Nanoradians,
        Microradians,
        Milliradians,
        Centiradians,
        Deciradians,
        Degrees,
        Nanodegrees,
        Microdegrees,
        Millidegrees,
        Arcminutes,
        Arcseconds,
        Gradians,
        NatoMils,
        Revolutions,
    };

    /// <summary>In geometry, an angle is the figure formed by two rays, called the sides of the angle, sharing a common endpoint, called the vertex of the angle.</summary>
    class Angle : public UnitsNetBase
    {
    public:
        constexpr explicit Angle(
            const un_scalar_t value,
            const AngleUnit unit = AngleUnit::Radians)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const AngleUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Angle operator+(const Angle& other) const noexcept
        {
            return Angle(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Angle operator-(const Angle& other)const noexcept
        {
            return Angle(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Angle operator*(const un_scalar_t scalar) const noexcept
        {
            return Angle(base_value() * scalar);
        }

        [[nodiscard]] constexpr Angle operator/(const un_scalar_t scalar) const noexcept
        {
            return Angle(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Angle& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Angle& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Angle& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t radians() const
        {
            return convert_from_base(AngleUnit::Radians);
        }

        [[nodiscard]] static constexpr Angle from_radians(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Radians);
        }

        [[nodiscard]] constexpr un_scalar_t nanoradians() const
        {
            return convert_from_base(AngleUnit::Nanoradians);
        }

        [[nodiscard]] static constexpr Angle from_nanoradians(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Nanoradians);
        }

        [[nodiscard]] constexpr un_scalar_t microradians() const
        {
            return convert_from_base(AngleUnit::Microradians);
        }

        [[nodiscard]] static constexpr Angle from_microradians(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Microradians);
        }

        [[nodiscard]] constexpr un_scalar_t milliradians() const
        {
            return convert_from_base(AngleUnit::Milliradians);
        }

        [[nodiscard]] static constexpr Angle from_milliradians(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Milliradians);
        }

        [[nodiscard]] constexpr un_scalar_t centiradians() const
        {
            return convert_from_base(AngleUnit::Centiradians);
        }

        [[nodiscard]] static constexpr Angle from_centiradians(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Centiradians);
        }

        [[nodiscard]] constexpr un_scalar_t deciradians() const
        {
            return convert_from_base(AngleUnit::Deciradians);
        }

        [[nodiscard]] static constexpr Angle from_deciradians(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Deciradians);
        }

        [[nodiscard]] constexpr un_scalar_t degrees() const
        {
            return convert_from_base(AngleUnit::Degrees);
        }

        [[nodiscard]] static constexpr Angle from_degrees(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Degrees);
        }

        [[nodiscard]] constexpr un_scalar_t nanodegrees() const
        {
            return convert_from_base(AngleUnit::Nanodegrees);
        }

        [[nodiscard]] static constexpr Angle from_nanodegrees(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Nanodegrees);
        }

        [[nodiscard]] constexpr un_scalar_t microdegrees() const
        {
            return convert_from_base(AngleUnit::Microdegrees);
        }

        [[nodiscard]] static constexpr Angle from_microdegrees(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Microdegrees);
        }

        [[nodiscard]] constexpr un_scalar_t millidegrees() const
        {
            return convert_from_base(AngleUnit::Millidegrees);
        }

        [[nodiscard]] static constexpr Angle from_millidegrees(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Millidegrees);
        }

        [[nodiscard]] constexpr un_scalar_t arcminutes() const
        {
            return convert_from_base(AngleUnit::Arcminutes);
        }

        [[nodiscard]] static constexpr Angle from_arcminutes(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Arcminutes);
        }

        [[nodiscard]] constexpr un_scalar_t arcseconds() const
        {
            return convert_from_base(AngleUnit::Arcseconds);
        }

        [[nodiscard]] static constexpr Angle from_arcseconds(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Arcseconds);
        }

        [[nodiscard]] constexpr un_scalar_t gradians() const
        {
            return convert_from_base(AngleUnit::Gradians);
        }

        [[nodiscard]] static constexpr Angle from_gradians(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Gradians);
        }

        [[nodiscard]] constexpr un_scalar_t nato_mils() const
        {
            return convert_from_base(AngleUnit::NatoMils);
        }

        [[nodiscard]] static constexpr Angle from_nato_mils(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::NatoMils);
        }

        [[nodiscard]] constexpr un_scalar_t revolutions() const
        {
            return convert_from_base(AngleUnit::Revolutions);
        }

        [[nodiscard]] static constexpr Angle from_revolutions(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Revolutions);
        }

        [[nodiscard]] static constexpr Angle from_invalid()
        {
            return Angle(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, AngleUnit unit)
        {
            switch (unit)
            {

            case AngleUnit::Radians:
                return value;

            case AngleUnit::Nanoradians:
                return (value * static_cast<un_scalar_t>(1e-9));

            case AngleUnit::Microradians:
                return (value * static_cast<un_scalar_t>(1e-6));

            case AngleUnit::Milliradians:
                return (value * static_cast<un_scalar_t>(1e-3));

            case AngleUnit::Centiradians:
                return (value * static_cast<un_scalar_t>(1e-2));

            case AngleUnit::Deciradians:
                return (value * static_cast<un_scalar_t>(1e-1));

            case AngleUnit::Degrees:
                return value * std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(180);

            case AngleUnit::Nanodegrees:
                return (value * static_cast<un_scalar_t>(1e-9)) * std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(180);

            case AngleUnit::Microdegrees:
                return (value * static_cast<un_scalar_t>(1e-6)) * std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(180);

            case AngleUnit::Millidegrees:
                return (value * static_cast<un_scalar_t>(1e-3)) * std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(180);

            case AngleUnit::Arcminutes:
                return value * std::numbers::pi_v<un_scalar_t> / (static_cast<un_scalar_t>(60) * static_cast<un_scalar_t>(180));

            case AngleUnit::Arcseconds:
                return value * std::numbers::pi_v<un_scalar_t> / (static_cast<un_scalar_t>(3600) * static_cast<un_scalar_t>(180));

            case AngleUnit::Gradians:
                return value * std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(200);

            case AngleUnit::NatoMils:
                return value * std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(3200);

            case AngleUnit::Revolutions:
                return value * static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>;

            }

            throw std::invalid_argument("Unknown Angle unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const AngleUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case AngleUnit::Radians:
                return base_value;

            case AngleUnit::Nanoradians:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case AngleUnit::Microradians:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case AngleUnit::Milliradians:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case AngleUnit::Centiradians:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case AngleUnit::Deciradians:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case AngleUnit::Degrees:
                return base_value * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>;

            case AngleUnit::Nanodegrees:
                return (base_value * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>) / static_cast<un_scalar_t>(1e-9);

            case AngleUnit::Microdegrees:
                return (base_value * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>) / static_cast<un_scalar_t>(1e-6);

            case AngleUnit::Millidegrees:
                return (base_value * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>) / static_cast<un_scalar_t>(1e-3);

            case AngleUnit::Arcminutes:
                return base_value * static_cast<un_scalar_t>(60) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>;

            case AngleUnit::Arcseconds:
                return base_value * static_cast<un_scalar_t>(3600) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>;

            case AngleUnit::Gradians:
                return base_value * static_cast<un_scalar_t>(200) / std::numbers::pi_v<un_scalar_t>;

            case AngleUnit::NatoMils:
                return base_value * static_cast<un_scalar_t>(3200) / std::numbers::pi_v<un_scalar_t>;

            case AngleUnit::Revolutions:
                return base_value / (static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>);

            }

            throw std::invalid_argument("Unknown Angle unit.");
        }

        un_scalar_t value_;
        AngleUnit value_unit_type_;       
    };
}
