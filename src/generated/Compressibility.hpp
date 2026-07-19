#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class CompressibilityUnit : std::uint8_t
    {
        InversePascals,
        InverseKilopascals,
        InverseMegapascals,
        InverseAtmospheres,
        InverseMillibars,
        InverseBars,
        InversePoundsForcePerSquareInch,
    };

    /// <summary></summary>
    class Compressibility : public UnitsNetBase
    {
    public:
        constexpr explicit Compressibility(
            const un_scalar_t value,
            const CompressibilityUnit unit = CompressibilityUnit::InversePascals)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == CompressibilityUnit::InversePascals)
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
            if(base_value_exists_)
            {
                return;
            }
            else
            {
                base_value_ = convert_to_base(value_, value_unit_type_);
                base_value_exists_ = true;
                return;
            }
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            create_base_value_if_needed();    
            return base_value_;    
        }

        [[nodiscard]] constexpr un_scalar_t value(const CompressibilityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Compressibility operator+(const Compressibility& other) const noexcept
        {
            return Compressibility(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Compressibility operator-(const Compressibility& other)const noexcept
        {
            return Compressibility(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Compressibility operator*(const un_scalar_t scalar) const noexcept
        {
            return Compressibility(base_value() * scalar);
        }

        [[nodiscard]] constexpr Compressibility operator/(const un_scalar_t scalar) const noexcept
        {
            return Compressibility(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Compressibility& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Compressibility& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Compressibility& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t inverse_pascals() const
        {
            return convert_from_base(CompressibilityUnit::InversePascals);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_pascals(const un_scalar_t value)
        {
            return Compressibility(value, CompressibilityUnit::InversePascals);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_kilopascals() const
        {
            return convert_from_base(CompressibilityUnit::InverseKilopascals);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_kilopascals(const un_scalar_t value)
        {
            return Compressibility(value, CompressibilityUnit::InverseKilopascals);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_megapascals() const
        {
            return convert_from_base(CompressibilityUnit::InverseMegapascals);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_megapascals(const un_scalar_t value)
        {
            return Compressibility(value, CompressibilityUnit::InverseMegapascals);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_atmospheres() const
        {
            return convert_from_base(CompressibilityUnit::InverseAtmospheres);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_atmospheres(const un_scalar_t value)
        {
            return Compressibility(value, CompressibilityUnit::InverseAtmospheres);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_millibars() const
        {
            return convert_from_base(CompressibilityUnit::InverseMillibars);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_millibars(const un_scalar_t value)
        {
            return Compressibility(value, CompressibilityUnit::InverseMillibars);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_bars() const
        {
            return convert_from_base(CompressibilityUnit::InverseBars);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_bars(const un_scalar_t value)
        {
            return Compressibility(value, CompressibilityUnit::InverseBars);
        }


        [[nodiscard]] constexpr un_scalar_t inverse_pounds_force_per_square_inch() const
        {
            return convert_from_base(CompressibilityUnit::InversePoundsForcePerSquareInch);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_pounds_force_per_square_inch(const un_scalar_t value)
        {
            return Compressibility(value, CompressibilityUnit::InversePoundsForcePerSquareInch);
        }


        [[nodiscard]] static constexpr Compressibility from_invalid()
        {
            return Compressibility(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, CompressibilityUnit unit)
        {
            switch (unit)
            {

            case CompressibilityUnit::InversePascals:
                return value;

            case CompressibilityUnit::InverseKilopascals:
                return value * static_cast<un_scalar_t>(1e3);

            case CompressibilityUnit::InverseMegapascals:
                return value * static_cast<un_scalar_t>(1e6);

            case CompressibilityUnit::InverseAtmospheres:
                return value * static_cast<un_scalar_t>(101325);

            case CompressibilityUnit::InverseMillibars:
                return value * static_cast<un_scalar_t>(100);

            case CompressibilityUnit::InverseBars:
                return value * static_cast<un_scalar_t>(1e5);

            case CompressibilityUnit::InversePoundsForcePerSquareInch:
                return value * static_cast<un_scalar_t>(6.894757293168361e3);

            }

            throw std::invalid_argument("Unknown Compressibility unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const CompressibilityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case CompressibilityUnit::InversePascals:
                return base_value_;

            case CompressibilityUnit::InverseKilopascals:
                return base_value_ / static_cast<un_scalar_t>(1e3);

            case CompressibilityUnit::InverseMegapascals:
                return base_value_ / static_cast<un_scalar_t>(1e6);

            case CompressibilityUnit::InverseAtmospheres:
                return base_value_ / static_cast<un_scalar_t>(101325);

            case CompressibilityUnit::InverseMillibars:
                return base_value_ / static_cast<un_scalar_t>(100);

            case CompressibilityUnit::InverseBars:
                return base_value_ / static_cast<un_scalar_t>(1e5);

            case CompressibilityUnit::InversePoundsForcePerSquareInch:
                return base_value_ / static_cast<un_scalar_t>(6.894757293168361e3);

            }

            throw std::invalid_argument("Unknown Compressibility unit.");
        }

        un_scalar_t value_;
        CompressibilityUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
