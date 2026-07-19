#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class PermeabilityUnit : std::uint8_t
    {
        HenriesPerMeter,
    };

    /// <summary>In electromagnetism, permeability is the measure of the ability of a material to support the formation of a magnetic field within itself.</summary>
    class Permeability
    {
    public:
        constexpr explicit Permeability(
            const un_scalar_t value,
            const PermeabilityUnit unit = PermeabilityUnit::HenriesPerMeter)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit Permeability(const bool isValid)
        {
            _isInvalid = !isValid;
        }
        
        void SetValueAsInvalid()
        {
            _isInvalid = true;
        }
        
        void SetValueAsValid()
        {
            _isInvalid = false;
        }
        
        [[nodiscard]] bool GetValueIsValid() const
        {
            return _isInvalid;
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const PermeabilityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Permeability operator+(const Permeability other) const noexcept
        {
            return Permeability(value_ + other.value_);
        }

        [[nodiscard]] constexpr Permeability operator-(const Permeability other) const noexcept
        {
            return Permeability(value_ - other.value_);
        }

        [[nodiscard]] constexpr Permeability operator*(const un_scalar_t scalar) const noexcept
        {
            return Permeability(value_ * scalar);
        }

        [[nodiscard]] constexpr Permeability operator/(const un_scalar_t scalar) const noexcept
        {
            return Permeability(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Permeability other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Permeability other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const Permeability other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t henries_per_meter() const
        {
            return convert_from_base(PermeabilityUnit::HenriesPerMeter);
        }

        [[nodiscard]] static constexpr Permeability from_henries_per_meter(const un_scalar_t value)
        {
            return Permeability(value, PermeabilityUnit::HenriesPerMeter);
        }


        [[nodiscard]] static constexpr Permeability from_invalid()
        {
            return Permeability(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, PermeabilityUnit unit)
        {
            switch (unit)
            {

            case PermeabilityUnit::HenriesPerMeter:
                return value;

            }

            throw std::invalid_argument("Unknown Permeability unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PermeabilityUnit unit) const
        {
            switch (unit)
            {

            case PermeabilityUnit::HenriesPerMeter:
                return value_;

            }

            throw std::invalid_argument("Unknown Permeability unit.");
        }

        un_scalar_t value_;
    };
}
