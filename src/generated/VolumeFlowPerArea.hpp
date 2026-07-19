#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class VolumeFlowPerAreaUnit : std::uint8_t
    {
        CubicMetersPerSecondPerSquareMeter,
        CubicFeetPerMinutePerSquareFoot,
    };

    /// <summary></summary>
    class VolumeFlowPerArea : public UnitsNetBase
    {
    public:
        constexpr explicit VolumeFlowPerArea(
            const un_scalar_t value,
            const VolumeFlowPerAreaUnit unit = VolumeFlowPerAreaUnit::CubicMetersPerSecondPerSquareMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const VolumeFlowPerAreaUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr VolumeFlowPerArea operator+(const VolumeFlowPerArea& other) const noexcept
        {
            return VolumeFlowPerArea(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr VolumeFlowPerArea operator-(const VolumeFlowPerArea& other)const noexcept
        {
            return VolumeFlowPerArea(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr VolumeFlowPerArea operator*(const un_scalar_t scalar) const noexcept
        {
            return VolumeFlowPerArea(base_value() * scalar);
        }

        [[nodiscard]] constexpr VolumeFlowPerArea operator/(const un_scalar_t scalar) const noexcept
        {
            return VolumeFlowPerArea(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const VolumeFlowPerArea& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const VolumeFlowPerArea& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const VolumeFlowPerArea& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t cubic_meters_per_second_per_square_meter() const
        {
            return convert_from_base(VolumeFlowPerAreaUnit::CubicMetersPerSecondPerSquareMeter);
        }

        [[nodiscard]] static constexpr VolumeFlowPerArea from_cubic_meters_per_second_per_square_meter(const un_scalar_t value)
        {
            return VolumeFlowPerArea(value, VolumeFlowPerAreaUnit::CubicMetersPerSecondPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_feet_per_minute_per_square_foot() const
        {
            return convert_from_base(VolumeFlowPerAreaUnit::CubicFeetPerMinutePerSquareFoot);
        }

        [[nodiscard]] static constexpr VolumeFlowPerArea from_cubic_feet_per_minute_per_square_foot(const un_scalar_t value)
        {
            return VolumeFlowPerArea(value, VolumeFlowPerAreaUnit::CubicFeetPerMinutePerSquareFoot);
        }

        [[nodiscard]] static constexpr VolumeFlowPerArea from_invalid()
        {
            return VolumeFlowPerArea(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, VolumeFlowPerAreaUnit unit)
        {
            switch (unit)
            {

            case VolumeFlowPerAreaUnit::CubicMetersPerSecondPerSquareMeter:
                return value;

            case VolumeFlowPerAreaUnit::CubicFeetPerMinutePerSquareFoot:
                return value * (static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(9.290304e-2);

            }

            throw std::invalid_argument("Unknown VolumeFlowPerArea unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const VolumeFlowPerAreaUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case VolumeFlowPerAreaUnit::CubicMetersPerSecondPerSquareMeter:
                return base_value;

            case VolumeFlowPerAreaUnit::CubicFeetPerMinutePerSquareFoot:
                return base_value * static_cast<un_scalar_t>(9.290304e-2) / (static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(60));

            }

            throw std::invalid_argument("Unknown VolumeFlowPerArea unit.");
        }

        un_scalar_t value_;
        VolumeFlowPerAreaUnit value_unit_type_;       
    };
}
