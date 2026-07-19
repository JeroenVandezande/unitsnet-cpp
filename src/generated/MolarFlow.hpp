#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class MolarFlowUnit : std::uint8_t
    {
        MolesPerSecond,
        KilomolesPerSecond,
        MolesPerMinute,
        KilomolesPerMinute,
        MolesPerHour,
        KilomolesPerHour,
        PoundMolesPerSecond,
        PoundMolesPerMinute,
        PoundMolesPerHour,
    };

    /// <summary>Molar flow is the ratio of the amount of substance change to the time during which the change occurred (value of amount of substance changes per unit time).</summary>
    class MolarFlow
    {
    public:
        constexpr explicit MolarFlow(
            const un_scalar_t value,
            const MolarFlowUnit unit = MolarFlowUnit::MolesPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit MolarFlow(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const MolarFlowUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MolarFlow operator+(const MolarFlow other) const noexcept
        {
            return MolarFlow(value_ + other.value_);
        }

        [[nodiscard]] constexpr MolarFlow operator-(const MolarFlow other) const noexcept
        {
            return MolarFlow(value_ - other.value_);
        }

        [[nodiscard]] constexpr MolarFlow operator*(const un_scalar_t scalar) const noexcept
        {
            return MolarFlow(value_ * scalar);
        }

        [[nodiscard]] constexpr MolarFlow operator/(const un_scalar_t scalar) const noexcept
        {
            return MolarFlow(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MolarFlow other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const MolarFlow other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const MolarFlow other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t moles_per_second() const
        {
            return convert_from_base(MolarFlowUnit::MolesPerSecond);
        }

        [[nodiscard]] static constexpr MolarFlow from_moles_per_second(const un_scalar_t value)
        {
            return MolarFlow(value, MolarFlowUnit::MolesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t kilomoles_per_second() const
        {
            return convert_from_base(MolarFlowUnit::KilomolesPerSecond);
        }

        [[nodiscard]] static constexpr MolarFlow from_kilomoles_per_second(const un_scalar_t value)
        {
            return MolarFlow(value, MolarFlowUnit::KilomolesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t moles_per_minute() const
        {
            return convert_from_base(MolarFlowUnit::MolesPerMinute);
        }

        [[nodiscard]] static constexpr MolarFlow from_moles_per_minute(const un_scalar_t value)
        {
            return MolarFlow(value, MolarFlowUnit::MolesPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t kilomoles_per_minute() const
        {
            return convert_from_base(MolarFlowUnit::KilomolesPerMinute);
        }

        [[nodiscard]] static constexpr MolarFlow from_kilomoles_per_minute(const un_scalar_t value)
        {
            return MolarFlow(value, MolarFlowUnit::KilomolesPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t moles_per_hour() const
        {
            return convert_from_base(MolarFlowUnit::MolesPerHour);
        }

        [[nodiscard]] static constexpr MolarFlow from_moles_per_hour(const un_scalar_t value)
        {
            return MolarFlow(value, MolarFlowUnit::MolesPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t kilomoles_per_hour() const
        {
            return convert_from_base(MolarFlowUnit::KilomolesPerHour);
        }

        [[nodiscard]] static constexpr MolarFlow from_kilomoles_per_hour(const un_scalar_t value)
        {
            return MolarFlow(value, MolarFlowUnit::KilomolesPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t pound_moles_per_second() const
        {
            return convert_from_base(MolarFlowUnit::PoundMolesPerSecond);
        }

        [[nodiscard]] static constexpr MolarFlow from_pound_moles_per_second(const un_scalar_t value)
        {
            return MolarFlow(value, MolarFlowUnit::PoundMolesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t pound_moles_per_minute() const
        {
            return convert_from_base(MolarFlowUnit::PoundMolesPerMinute);
        }

        [[nodiscard]] static constexpr MolarFlow from_pound_moles_per_minute(const un_scalar_t value)
        {
            return MolarFlow(value, MolarFlowUnit::PoundMolesPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t pound_moles_per_hour() const
        {
            return convert_from_base(MolarFlowUnit::PoundMolesPerHour);
        }

        [[nodiscard]] static constexpr MolarFlow from_pound_moles_per_hour(const un_scalar_t value)
        {
            return MolarFlow(value, MolarFlowUnit::PoundMolesPerHour);
        }


        [[nodiscard]] static constexpr MolarFlow from_invalid()
        {
            return MolarFlow(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MolarFlowUnit unit)
        {
            switch (unit)
            {

            case MolarFlowUnit::MolesPerSecond:
                return value;

            case MolarFlowUnit::KilomolesPerSecond:
                return (value * static_cast<un_scalar_t>(1e3));

            case MolarFlowUnit::MolesPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case MolarFlowUnit::KilomolesPerMinute:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(60);

            case MolarFlowUnit::MolesPerHour:
                return value / static_cast<un_scalar_t>(3600);

            case MolarFlowUnit::KilomolesPerHour:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(3600);

            case MolarFlowUnit::PoundMolesPerSecond:
                return value * static_cast<un_scalar_t>(453.59237);

            case MolarFlowUnit::PoundMolesPerMinute:
                return (value * static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(60);

            case MolarFlowUnit::PoundMolesPerHour:
                return (value * static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown MolarFlow unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MolarFlowUnit unit) const
        {
            switch (unit)
            {

            case MolarFlowUnit::MolesPerSecond:
                return value_;

            case MolarFlowUnit::KilomolesPerSecond:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case MolarFlowUnit::MolesPerMinute:
                return value_ * static_cast<un_scalar_t>(60);

            case MolarFlowUnit::KilomolesPerMinute:
                return (value_ * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e3);

            case MolarFlowUnit::MolesPerHour:
                return value_ * static_cast<un_scalar_t>(3600);

            case MolarFlowUnit::KilomolesPerHour:
                return (value_ * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e3);

            case MolarFlowUnit::PoundMolesPerSecond:
                return value_ / static_cast<un_scalar_t>(453.59237);

            case MolarFlowUnit::PoundMolesPerMinute:
                return (value_ / static_cast<un_scalar_t>(453.59237)) * static_cast<un_scalar_t>(60);

            case MolarFlowUnit::PoundMolesPerHour:
                return (value_ / static_cast<un_scalar_t>(453.59237)) * static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown MolarFlow unit.");
        }

        un_scalar_t value_;
    };
}
