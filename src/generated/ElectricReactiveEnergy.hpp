#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class ElectricReactiveEnergyUnit : std::uint8_t
    {
        VoltampereReactiveHours,
        KilovoltampereReactiveHours,
        MegavoltampereReactiveHours,
    };

    /// <summary>The volt-ampere reactive hour (expressed as varh) is the reactive power of one Volt-ampere reactive produced in one hour.</summary>
    class ElectricReactiveEnergy
    {
    public:
        constexpr explicit ElectricReactiveEnergy(
            const un_scalar_t value,
            const ElectricReactiveEnergyUnit unit = ElectricReactiveEnergyUnit::VoltampereReactiveHours)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit ElectricReactiveEnergy(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const ElectricReactiveEnergyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricReactiveEnergy operator+(const ElectricReactiveEnergy other) const noexcept
        {
            return ElectricReactiveEnergy(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricReactiveEnergy operator-(const ElectricReactiveEnergy other) const noexcept
        {
            return ElectricReactiveEnergy(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricReactiveEnergy operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricReactiveEnergy(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricReactiveEnergy operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricReactiveEnergy(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricReactiveEnergy other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const ElectricReactiveEnergy other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricReactiveEnergy other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t voltampere_reactive_hours() const
        {
            return convert_from_base(ElectricReactiveEnergyUnit::VoltampereReactiveHours);
        }

        [[nodiscard]] static constexpr ElectricReactiveEnergy from_voltampere_reactive_hours(const un_scalar_t value)
        {
            return ElectricReactiveEnergy(value, ElectricReactiveEnergyUnit::VoltampereReactiveHours);
        }


        [[nodiscard]] constexpr un_scalar_t kilovoltampere_reactive_hours() const
        {
            return convert_from_base(ElectricReactiveEnergyUnit::KilovoltampereReactiveHours);
        }

        [[nodiscard]] static constexpr ElectricReactiveEnergy from_kilovoltampere_reactive_hours(const un_scalar_t value)
        {
            return ElectricReactiveEnergy(value, ElectricReactiveEnergyUnit::KilovoltampereReactiveHours);
        }


        [[nodiscard]] constexpr un_scalar_t megavoltampere_reactive_hours() const
        {
            return convert_from_base(ElectricReactiveEnergyUnit::MegavoltampereReactiveHours);
        }

        [[nodiscard]] static constexpr ElectricReactiveEnergy from_megavoltampere_reactive_hours(const un_scalar_t value)
        {
            return ElectricReactiveEnergy(value, ElectricReactiveEnergyUnit::MegavoltampereReactiveHours);
        }


        [[nodiscard]] static constexpr ElectricReactiveEnergy from_invalid()
        {
            return ElectricReactiveEnergy(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricReactiveEnergyUnit unit)
        {
            switch (unit)
            {

            case ElectricReactiveEnergyUnit::VoltampereReactiveHours:
                return value;

            case ElectricReactiveEnergyUnit::KilovoltampereReactiveHours:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricReactiveEnergyUnit::MegavoltampereReactiveHours:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown ElectricReactiveEnergy unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricReactiveEnergyUnit unit) const
        {
            switch (unit)
            {

            case ElectricReactiveEnergyUnit::VoltampereReactiveHours:
                return value_;

            case ElectricReactiveEnergyUnit::KilovoltampereReactiveHours:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case ElectricReactiveEnergyUnit::MegavoltampereReactiveHours:
                return (value_) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricReactiveEnergy unit.");
        }

        un_scalar_t value_;
    };
}
