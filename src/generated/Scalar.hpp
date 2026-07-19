#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ScalarUnit : std::uint8_t
    {
        Amount,
    };

    /// <summary>A way of representing a number of items.</summary>
    class Scalar : public UnitsNetBase
    {
    public:
        constexpr explicit Scalar(
            const un_scalar_t value,
            const ScalarUnit unit = ScalarUnit::Amount)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
        
        [[nodiscard]] constexpr un_scalar_t stored_value() const noexcept override
        {
           return value_; 
        }
        
        [[nodiscard]] constexpr std::string_view quantity_name() const noexcept override
        {
           return "Scalar"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case ScalarUnit::Amount:
                return "Amount";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ScalarUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Scalar operator+(const Scalar& other) const noexcept
        {
            return Scalar(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Scalar operator-(const Scalar& other)const noexcept
        {
            return Scalar(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Scalar operator*(const un_scalar_t scalar) const noexcept
        {
            return Scalar(base_value() * scalar);
        }

        [[nodiscard]] constexpr Scalar operator/(const un_scalar_t scalar) const noexcept
        {
            return Scalar(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Scalar& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Scalar& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Scalar& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t amount() const
        {
            return convert_from_base(ScalarUnit::Amount);
        }

        [[nodiscard]] static constexpr Scalar from_amount(const un_scalar_t value)
        {
            return Scalar(value, ScalarUnit::Amount);
        }

        [[nodiscard]] static constexpr Scalar from_invalid()
        {
            return Scalar(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ScalarUnit unit)
        {
            switch (unit)
            {

            case ScalarUnit::Amount:
                return value;

            }

            throw std::invalid_argument("Unknown Scalar unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ScalarUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ScalarUnit::Amount:
                return base_value;

            }

            throw std::invalid_argument("Unknown Scalar unit.");
        }

        un_scalar_t value_;
        ScalarUnit value_unit_type_;       
    };
}
