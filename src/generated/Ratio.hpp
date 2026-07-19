#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class RatioUnit : std::uint8_t
    {
        DecimalFractions,
        Percent,
        PartsPerThousand,
        PartsPerMillion,
        PartsPerBillion,
        PartsPerTrillion,
    };

    /// <summary>In mathematics, a ratio is a relationship between two numbers of the same kind (e.g., objects, persons, students, spoonfuls, units of whatever identical dimension), usually expressed as "a to b" or a:b, sometimes expressed arithmetically as a dimensionless quotient of the two that explicitly indicates how many times the first number contains the second (not necessarily an integer).</summary>
    class Ratio : public UnitsNetBase
    {
    public:
        constexpr explicit Ratio(
            const un_scalar_t value,
            const RatioUnit unit = RatioUnit::DecimalFractions)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const RatioUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Ratio operator+(const Ratio& other) const noexcept
        {
            return Ratio(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Ratio operator-(const Ratio& other)const noexcept
        {
            return Ratio(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Ratio operator*(const un_scalar_t scalar) const noexcept
        {
            return Ratio(base_value() * scalar);
        }

        [[nodiscard]] constexpr Ratio operator/(const un_scalar_t scalar) const noexcept
        {
            return Ratio(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Ratio& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Ratio& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Ratio& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t decimal_fractions() const
        {
            return convert_from_base(RatioUnit::DecimalFractions);
        }

        [[nodiscard]] static constexpr Ratio from_decimal_fractions(const un_scalar_t value)
        {
            return Ratio(value, RatioUnit::DecimalFractions);
        }

        [[nodiscard]] constexpr un_scalar_t percent() const
        {
            return convert_from_base(RatioUnit::Percent);
        }

        [[nodiscard]] static constexpr Ratio from_percent(const un_scalar_t value)
        {
            return Ratio(value, RatioUnit::Percent);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_thousand() const
        {
            return convert_from_base(RatioUnit::PartsPerThousand);
        }

        [[nodiscard]] static constexpr Ratio from_parts_per_thousand(const un_scalar_t value)
        {
            return Ratio(value, RatioUnit::PartsPerThousand);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_million() const
        {
            return convert_from_base(RatioUnit::PartsPerMillion);
        }

        [[nodiscard]] static constexpr Ratio from_parts_per_million(const un_scalar_t value)
        {
            return Ratio(value, RatioUnit::PartsPerMillion);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_billion() const
        {
            return convert_from_base(RatioUnit::PartsPerBillion);
        }

        [[nodiscard]] static constexpr Ratio from_parts_per_billion(const un_scalar_t value)
        {
            return Ratio(value, RatioUnit::PartsPerBillion);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_trillion() const
        {
            return convert_from_base(RatioUnit::PartsPerTrillion);
        }

        [[nodiscard]] static constexpr Ratio from_parts_per_trillion(const un_scalar_t value)
        {
            return Ratio(value, RatioUnit::PartsPerTrillion);
        }

        [[nodiscard]] static constexpr Ratio from_invalid()
        {
            return Ratio(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RatioUnit unit)
        {
            switch (unit)
            {

            case RatioUnit::DecimalFractions:
                return value;

            case RatioUnit::Percent:
                return value / static_cast<un_scalar_t>(1e2);

            case RatioUnit::PartsPerThousand:
                return value / static_cast<un_scalar_t>(1e3);

            case RatioUnit::PartsPerMillion:
                return value / static_cast<un_scalar_t>(1e6);

            case RatioUnit::PartsPerBillion:
                return value / static_cast<un_scalar_t>(1e9);

            case RatioUnit::PartsPerTrillion:
                return value / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown Ratio unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RatioUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case RatioUnit::DecimalFractions:
                return base_value;

            case RatioUnit::Percent:
                return base_value * static_cast<un_scalar_t>(1e2);

            case RatioUnit::PartsPerThousand:
                return base_value * static_cast<un_scalar_t>(1e3);

            case RatioUnit::PartsPerMillion:
                return base_value * static_cast<un_scalar_t>(1e6);

            case RatioUnit::PartsPerBillion:
                return base_value * static_cast<un_scalar_t>(1e9);

            case RatioUnit::PartsPerTrillion:
                return base_value * static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown Ratio unit.");
        }

        un_scalar_t value_;
        RatioUnit value_unit_type_;       
    };
}
