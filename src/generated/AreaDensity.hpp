#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class AreaDensityUnit : std::uint8_t
    {
        KilogramsPerSquareMeter,
        GramsPerSquareMeter,
        MilligramsPerSquareMeter,
        PoundsPerSquareFoot,
        PoundsPerThousandSquareFeet,
    };

    /// <summary>The area density of a two-dimensional object is calculated as the mass per unit area. For paper this is also called grammage.</summary>
    class AreaDensity : public UnitsNetBase
    {
    public:
        constexpr explicit AreaDensity(
            const un_scalar_t value,
            const AreaDensityUnit unit = AreaDensityUnit::KilogramsPerSquareMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == AreaDensityUnit::KilogramsPerSquareMeter)
            {
                base_value_ = value;
                base_value_exists_ = true;
            }
            else
            {
                base_value_ = 0;
                base_value_exists_ = false;
            }
        }
        
        constexpr void create_base_value_if_needed() const noexcept
        {
            if(!base_value_exists_)
            {
                base_value_ = convert_to_base(value_, value_unit_type_);
                base_value_exists_ = true;
            }
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            create_base_value_if_needed();    
            return base_value_;    
        }

        [[nodiscard]] constexpr un_scalar_t value(const AreaDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr AreaDensity operator+(const AreaDensity& other) const noexcept
        {
            return AreaDensity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr AreaDensity operator-(const AreaDensity& other)const noexcept
        {
            return AreaDensity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr AreaDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return AreaDensity(base_value() * scalar);
        }

        [[nodiscard]] constexpr AreaDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return AreaDensity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const AreaDensity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const AreaDensity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const AreaDensity& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_square_meter() const
        {
            return convert_from_base(AreaDensityUnit::KilogramsPerSquareMeter);
        }

        [[nodiscard]] static constexpr AreaDensity from_kilograms_per_square_meter(const un_scalar_t value)
        {
            return AreaDensity(value, AreaDensityUnit::KilogramsPerSquareMeter);
        }


        /// <summary>Also known as grammage for paper industry. In fiber industry used with abbreviation 'gsm'.</summary>
        [[nodiscard]] constexpr un_scalar_t grams_per_square_meter() const
        {
            return convert_from_base(AreaDensityUnit::GramsPerSquareMeter);
        }

        /// <summary>Also known as grammage for paper industry. In fiber industry used with abbreviation 'gsm'.</summary>
        [[nodiscard]] static constexpr AreaDensity from_grams_per_square_meter(const un_scalar_t value)
        {
            return AreaDensity(value, AreaDensityUnit::GramsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams_per_square_meter() const
        {
            return convert_from_base(AreaDensityUnit::MilligramsPerSquareMeter);
        }

        [[nodiscard]] static constexpr AreaDensity from_milligrams_per_square_meter(const un_scalar_t value)
        {
            return AreaDensity(value, AreaDensityUnit::MilligramsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_square_foot() const
        {
            return convert_from_base(AreaDensityUnit::PoundsPerSquareFoot);
        }

        [[nodiscard]] static constexpr AreaDensity from_pounds_per_square_foot(const un_scalar_t value)
        {
            return AreaDensity(value, AreaDensityUnit::PoundsPerSquareFoot);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_thousand_square_feet() const
        {
            return convert_from_base(AreaDensityUnit::PoundsPerThousandSquareFeet);
        }

        [[nodiscard]] static constexpr AreaDensity from_pounds_per_thousand_square_feet(const un_scalar_t value)
        {
            return AreaDensity(value, AreaDensityUnit::PoundsPerThousandSquareFeet);
        }


        [[nodiscard]] static constexpr AreaDensity from_invalid()
        {
            return AreaDensity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, AreaDensityUnit unit)
        {
            switch (unit)
            {

            case AreaDensityUnit::KilogramsPerSquareMeter:
                return value;

            case AreaDensityUnit::GramsPerSquareMeter:
                return value / static_cast<un_scalar_t>(1000);

            case AreaDensityUnit::MilligramsPerSquareMeter:
                return value / static_cast<un_scalar_t>(1000000);

            case AreaDensityUnit::PoundsPerSquareFoot:
                return value * (static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.09290304));

            case AreaDensityUnit::PoundsPerThousandSquareFeet:
                return value * (static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.09290304)) / static_cast<un_scalar_t>(1000);

            }

            throw std::invalid_argument("Unknown AreaDensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const AreaDensityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case AreaDensityUnit::KilogramsPerSquareMeter:
                return base_value_;

            case AreaDensityUnit::GramsPerSquareMeter:
                return base_value_ * static_cast<un_scalar_t>(1000);

            case AreaDensityUnit::MilligramsPerSquareMeter:
                return base_value_ * static_cast<un_scalar_t>(1000000);

            case AreaDensityUnit::PoundsPerSquareFoot:
                return base_value_ / (static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.09290304));

            case AreaDensityUnit::PoundsPerThousandSquareFeet:
                return base_value_ / (static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.09290304)) * static_cast<un_scalar_t>(1000);

            }

            throw std::invalid_argument("Unknown AreaDensity unit.");
        }

        un_scalar_t value_;
        AreaDensityUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
