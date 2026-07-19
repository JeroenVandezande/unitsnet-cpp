#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class LuminousFluxUnit : std::uint8_t
    {
        Lumens,
    };

    /// <summary>In photometry, luminous flux or luminous power is the measure of the perceived power of light.</summary>
    class LuminousFlux
    {
    public:
        constexpr explicit LuminousFlux(
            const un_scalar_t value,
            const LuminousFluxUnit unit = LuminousFluxUnit::Lumens)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit LuminousFlux(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const LuminousFluxUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr LuminousFlux operator+(const LuminousFlux other) const noexcept
        {
            return LuminousFlux(value_ + other.value_);
        }

        [[nodiscard]] constexpr LuminousFlux operator-(const LuminousFlux other) const noexcept
        {
            return LuminousFlux(value_ - other.value_);
        }

        [[nodiscard]] constexpr LuminousFlux operator*(const un_scalar_t scalar) const noexcept
        {
            return LuminousFlux(value_ * scalar);
        }

        [[nodiscard]] constexpr LuminousFlux operator/(const un_scalar_t scalar) const noexcept
        {
            return LuminousFlux(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const LuminousFlux other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const LuminousFlux other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const LuminousFlux other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t lumens() const
        {
            return convert_from_base(LuminousFluxUnit::Lumens);
        }

        [[nodiscard]] static constexpr LuminousFlux from_lumens(const un_scalar_t value)
        {
            return LuminousFlux(value, LuminousFluxUnit::Lumens);
        }


        [[nodiscard]] static constexpr LuminousFlux from_invalid()
        {
            return LuminousFlux(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LuminousFluxUnit unit)
        {
            switch (unit)
            {

            case LuminousFluxUnit::Lumens:
                return value;

            }

            throw std::invalid_argument("Unknown LuminousFlux unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LuminousFluxUnit unit) const
        {
            switch (unit)
            {

            case LuminousFluxUnit::Lumens:
                return value_;

            }

            throw std::invalid_argument("Unknown LuminousFlux unit.");
        }

        un_scalar_t value_;
    };
}
