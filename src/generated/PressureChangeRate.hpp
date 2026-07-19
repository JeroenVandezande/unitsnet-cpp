#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class PressureChangeRateUnit : std::uint8_t
    {
        PascalsPerSecond,
        KilopascalsPerSecond,
        MegapascalsPerSecond,
        PascalsPerMinute,
        KilopascalsPerMinute,
        MegapascalsPerMinute,
        MillimetersOfMercuryPerSecond,
        AtmospheresPerSecond,
        PoundsForcePerSquareInchPerSecond,
        KilopoundsForcePerSquareInchPerSecond,
        MegapoundsForcePerSquareInchPerSecond,
        PoundsForcePerSquareInchPerMinute,
        KilopoundsForcePerSquareInchPerMinute,
        MegapoundsForcePerSquareInchPerMinute,
        BarsPerSecond,
        MillibarsPerSecond,
        BarsPerMinute,
        MillibarsPerMinute,
    };

    /// <summary>Pressure change rate is the ratio of the pressure change to the time during which the change occurred (value of pressure changes per unit time).</summary>
    class PressureChangeRate : public UnitsNetBase
    {
    public:
        constexpr explicit PressureChangeRate(
            const un_scalar_t value,
            const PressureChangeRateUnit unit = PressureChangeRateUnit::PascalsPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const PressureChangeRateUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr PressureChangeRate operator+(const PressureChangeRate& other) const noexcept
        {
            return PressureChangeRate(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr PressureChangeRate operator-(const PressureChangeRate& other)const noexcept
        {
            return PressureChangeRate(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr PressureChangeRate operator*(const un_scalar_t scalar) const noexcept
        {
            return PressureChangeRate(base_value() * scalar);
        }

        [[nodiscard]] constexpr PressureChangeRate operator/(const un_scalar_t scalar) const noexcept
        {
            return PressureChangeRate(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const PressureChangeRate& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const PressureChangeRate& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const PressureChangeRate& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t pascals_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::PascalsPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_pascals_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::PascalsPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilopascals_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::KilopascalsPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_kilopascals_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::KilopascalsPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t megapascals_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::MegapascalsPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_megapascals_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MegapascalsPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t pascals_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::PascalsPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_pascals_per_minute(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::PascalsPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t kilopascals_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::KilopascalsPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_kilopascals_per_minute(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::KilopascalsPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t megapascals_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::MegapascalsPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_megapascals_per_minute(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MegapascalsPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t millimeters_of_mercury_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::MillimetersOfMercuryPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_millimeters_of_mercury_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MillimetersOfMercuryPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t atmospheres_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::AtmospheresPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_atmospheres_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::AtmospheresPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_square_inch_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::PoundsForcePerSquareInchPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_pounds_force_per_square_inch_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::PoundsForcePerSquareInchPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_square_inch_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::KilopoundsForcePerSquareInchPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_kilopounds_force_per_square_inch_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::KilopoundsForcePerSquareInchPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t megapounds_force_per_square_inch_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::MegapoundsForcePerSquareInchPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_megapounds_force_per_square_inch_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MegapoundsForcePerSquareInchPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_square_inch_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::PoundsForcePerSquareInchPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_pounds_force_per_square_inch_per_minute(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::PoundsForcePerSquareInchPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_square_inch_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::KilopoundsForcePerSquareInchPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_kilopounds_force_per_square_inch_per_minute(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::KilopoundsForcePerSquareInchPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t megapounds_force_per_square_inch_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::MegapoundsForcePerSquareInchPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_megapounds_force_per_square_inch_per_minute(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MegapoundsForcePerSquareInchPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t bars_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::BarsPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_bars_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::BarsPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t millibars_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::MillibarsPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_millibars_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MillibarsPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t bars_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::BarsPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_bars_per_minute(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::BarsPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t millibars_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::MillibarsPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_millibars_per_minute(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MillibarsPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_invalid()
        {
            return PressureChangeRate(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, PressureChangeRateUnit unit)
        {
            switch (unit)
            {

            case PressureChangeRateUnit::PascalsPerSecond:
                return value;

            case PressureChangeRateUnit::KilopascalsPerSecond:
                return (value * static_cast<un_scalar_t>(1e3));

            case PressureChangeRateUnit::MegapascalsPerSecond:
                return (value * static_cast<un_scalar_t>(1e6));

            case PressureChangeRateUnit::PascalsPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case PressureChangeRateUnit::KilopascalsPerMinute:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(60);

            case PressureChangeRateUnit::MegapascalsPerMinute:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(60);

            case PressureChangeRateUnit::MillimetersOfMercuryPerSecond:
                return value * static_cast<un_scalar_t>(133.322387415);

            case PressureChangeRateUnit::AtmospheresPerSecond:
                return value * static_cast<un_scalar_t>(1.01325) * static_cast<un_scalar_t>(1e5);

            case PressureChangeRateUnit::PoundsForcePerSquareInchPerSecond:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516);

            case PressureChangeRateUnit::KilopoundsForcePerSquareInchPerSecond:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516);

            case PressureChangeRateUnit::MegapoundsForcePerSquareInchPerSecond:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516);

            case PressureChangeRateUnit::PoundsForcePerSquareInchPerMinute:
                return value * (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516)) / static_cast<un_scalar_t>(60);

            case PressureChangeRateUnit::KilopoundsForcePerSquareInchPerMinute:
                return (value * static_cast<un_scalar_t>(1e3)) * (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516)) / static_cast<un_scalar_t>(60);

            case PressureChangeRateUnit::MegapoundsForcePerSquareInchPerMinute:
                return (value * static_cast<un_scalar_t>(1e6)) * (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516)) / static_cast<un_scalar_t>(60);

            case PressureChangeRateUnit::BarsPerSecond:
                return value * static_cast<un_scalar_t>(1e5);

            case PressureChangeRateUnit::MillibarsPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e5);

            case PressureChangeRateUnit::BarsPerMinute:
                return value * static_cast<un_scalar_t>(1e5) / static_cast<un_scalar_t>(60);

            case PressureChangeRateUnit::MillibarsPerMinute:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e5) / static_cast<un_scalar_t>(60);

            }

            throw std::invalid_argument("Unknown PressureChangeRate unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PressureChangeRateUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case PressureChangeRateUnit::PascalsPerSecond:
                return base_value;

            case PressureChangeRateUnit::KilopascalsPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case PressureChangeRateUnit::MegapascalsPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case PressureChangeRateUnit::PascalsPerMinute:
                return base_value * static_cast<un_scalar_t>(60);

            case PressureChangeRateUnit::KilopascalsPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e3);

            case PressureChangeRateUnit::MegapascalsPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e6);

            case PressureChangeRateUnit::MillimetersOfMercuryPerSecond:
                return base_value / static_cast<un_scalar_t>(133.322387415);

            case PressureChangeRateUnit::AtmospheresPerSecond:
                return base_value / (static_cast<un_scalar_t>(1.01325) * static_cast<un_scalar_t>(1e5));

            case PressureChangeRateUnit::PoundsForcePerSquareInchPerSecond:
                return base_value * static_cast<un_scalar_t>(0.00064516) / static_cast<un_scalar_t>(4.4482216152605);

            case PressureChangeRateUnit::KilopoundsForcePerSquareInchPerSecond:
                return (base_value * static_cast<un_scalar_t>(0.00064516) / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            case PressureChangeRateUnit::MegapoundsForcePerSquareInchPerSecond:
                return (base_value * static_cast<un_scalar_t>(0.00064516) / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e6);

            case PressureChangeRateUnit::PoundsForcePerSquareInchPerMinute:
                return base_value * static_cast<un_scalar_t>(60) / (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516));

            case PressureChangeRateUnit::KilopoundsForcePerSquareInchPerMinute:
                return (base_value * static_cast<un_scalar_t>(60) / (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516))) / static_cast<un_scalar_t>(1e3);

            case PressureChangeRateUnit::MegapoundsForcePerSquareInchPerMinute:
                return (base_value * static_cast<un_scalar_t>(60) / (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516))) / static_cast<un_scalar_t>(1e6);

            case PressureChangeRateUnit::BarsPerSecond:
                return base_value / static_cast<un_scalar_t>(1e5);

            case PressureChangeRateUnit::MillibarsPerSecond:
                return (base_value / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e-3);

            case PressureChangeRateUnit::BarsPerMinute:
                return base_value / static_cast<un_scalar_t>(1e5) * static_cast<un_scalar_t>(60);

            case PressureChangeRateUnit::MillibarsPerMinute:
                return (base_value / static_cast<un_scalar_t>(1e5) * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown PressureChangeRate unit.");
        }

        un_scalar_t value_;
        PressureChangeRateUnit value_unit_type_;       
    };
}
