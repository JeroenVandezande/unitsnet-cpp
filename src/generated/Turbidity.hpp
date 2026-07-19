#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class TurbidityUnit : std::uint8_t
    {
        NTU,
    };

    /// <summary>Turbidity is the cloudiness or haziness of a fluid caused by large numbers of individual particles that are generally invisible to the naked eye, similar to smoke in air. The measurement of turbidity is a key test of water quality.</summary>
    class Turbidity : public UnitsNetBase
    {
    public:
        constexpr explicit Turbidity(
            const un_scalar_t value,
            const TurbidityUnit unit = TurbidityUnit::NTU)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const TurbidityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Turbidity operator+(const Turbidity& other) const noexcept
        {
            return Turbidity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Turbidity operator-(const Turbidity& other)const noexcept
        {
            return Turbidity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Turbidity operator*(const un_scalar_t scalar) const noexcept
        {
            return Turbidity(base_value() * scalar);
        }

        [[nodiscard]] constexpr Turbidity operator/(const un_scalar_t scalar) const noexcept
        {
            return Turbidity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Turbidity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Turbidity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Turbidity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t n_t_u() const
        {
            return convert_from_base(TurbidityUnit::NTU);
        }

        [[nodiscard]] static constexpr Turbidity from_n_t_u(const un_scalar_t value)
        {
            return Turbidity(value, TurbidityUnit::NTU);
        }

        [[nodiscard]] static constexpr Turbidity from_invalid()
        {
            return Turbidity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, TurbidityUnit unit)
        {
            switch (unit)
            {

            case TurbidityUnit::NTU:
                return value;

            }

            throw std::invalid_argument("Unknown Turbidity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const TurbidityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case TurbidityUnit::NTU:
                return base_value;

            }

            throw std::invalid_argument("Unknown Turbidity unit.");
        }

        un_scalar_t value_;
        TurbidityUnit value_unit_type_;       
    };
}
