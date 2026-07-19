#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class TurbidityUnit : std::uint8_t
    {
        NTU,
    };

    /// <summary>Turbidity is the cloudiness or haziness of a fluid caused by large numbers of individual particles that are generally invisible to the naked eye, similar to smoke in air. The measurement of turbidity is a key test of water quality.</summary>
    class Turbidity
    {
    public:
        constexpr explicit Turbidity(
            const un_scalar_t value,
            const TurbidityUnit unit = TurbidityUnit::NTU)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const TurbidityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Turbidity operator+(const Turbidity other) const noexcept
        {
            return Turbidity(value_ + other.value_);
        }

        [[nodiscard]] constexpr Turbidity operator-(const Turbidity other) const noexcept
        {
            return Turbidity(value_ - other.value_);
        }

        [[nodiscard]] constexpr Turbidity operator*(const un_scalar_t scalar) const noexcept
        {
            return Turbidity(value_ * scalar);
        }

        [[nodiscard]] constexpr Turbidity operator/(const un_scalar_t scalar) const noexcept
        {
            return Turbidity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Turbidity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Turbidity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t n_t_u() const
        {
            return convert_from_base(TurbidityUnit::NTU);
        }

        [[nodiscard]] static constexpr Turbidity from_n_t_u(const un_scalar_t value)
        {
            return Turbidity(value, TurbidityUnit::NTU);
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
            switch (unit)
            {

            case TurbidityUnit::NTU:
                return value_;

            }

            throw std::invalid_argument("Unknown Turbidity unit.");
        }

        un_scalar_t value_;
    };
}
