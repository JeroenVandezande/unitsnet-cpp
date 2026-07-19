#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class LevelUnit : std::uint8_t
    {
        Decibels,
        Nepers,
    };

    /// <summary>Level is the logarithm of the ratio of a quantity Q to a reference value of that quantity, Q₀, expressed in dimensionless units.</summary>
    class Level : public UnitsNetBase
    {
    public:
        constexpr explicit Level(
            const un_scalar_t value,
            const LevelUnit unit = LevelUnit::Decibels)
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
           return "Level"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case LevelUnit::Decibels:
                return "Decibels";

            case LevelUnit::Nepers:
                return "Nepers";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const LevelUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Level operator+(const Level& other) const noexcept
        {
            return Level(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Level operator-(const Level& other)const noexcept
        {
            return Level(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Level operator*(const un_scalar_t scalar) const noexcept
        {
            return Level(base_value() * scalar);
        }

        [[nodiscard]] constexpr Level operator/(const un_scalar_t scalar) const noexcept
        {
            return Level(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Level& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Level& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Level& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t decibels() const
        {
            return convert_from_base(LevelUnit::Decibels);
        }

        [[nodiscard]] static constexpr Level from_decibels(const un_scalar_t value)
        {
            return Level(value, LevelUnit::Decibels);
        }

        [[nodiscard]] constexpr un_scalar_t nepers() const
        {
            return convert_from_base(LevelUnit::Nepers);
        }

        [[nodiscard]] static constexpr Level from_nepers(const un_scalar_t value)
        {
            return Level(value, LevelUnit::Nepers);
        }

        [[nodiscard]] static constexpr Level from_invalid()
        {
            return Level(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LevelUnit unit)
        {
            switch (unit)
            {

            case LevelUnit::Decibels:
                return value;

            case LevelUnit::Nepers:
                return (static_cast<un_scalar_t>(1) / static_cast<un_scalar_t>(0.115129254)) * value;

            }

            throw std::invalid_argument("Unknown Level unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LevelUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case LevelUnit::Decibels:
                return base_value;

            case LevelUnit::Nepers:
                return static_cast<un_scalar_t>(0.115129254) * base_value;

            }

            throw std::invalid_argument("Unknown Level unit.");
        }

        un_scalar_t value_;
        LevelUnit value_unit_type_;       
    };
}
