#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class ElectricApparentEnergyUnit : std::uint8_t
    {
        VoltampereHours,
        KilovoltampereHours,
        MegavoltampereHours,
    };

    /// <summary>A unit for expressing the integral of apparent power over time, equal to the product of 1 volt-ampere and 1 hour, or to 3600 joules.</summary>
    class ElectricApparentEnergy
    {
    public:
        constexpr explicit ElectricApparentEnergy(
            const un_scalar_t value,
            const ElectricApparentEnergyUnit unit = ElectricApparentEnergyUnit::VoltampereHours)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit ElectricApparentEnergy(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const ElectricApparentEnergyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricApparentEnergy operator+(const ElectricApparentEnergy other) const noexcept
        {
            return ElectricApparentEnergy(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricApparentEnergy operator-(const ElectricApparentEnergy other) const noexcept
        {
            return ElectricApparentEnergy(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricApparentEnergy operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricApparentEnergy(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricApparentEnergy operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricApparentEnergy(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricApparentEnergy other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const ElectricApparentEnergy other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricApparentEnergy other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t voltampere_hours() const
        {
            return convert_from_base(ElectricApparentEnergyUnit::VoltampereHours);
        }

        [[nodiscard]] static constexpr ElectricApparentEnergy from_voltampere_hours(const un_scalar_t value)
        {
            return ElectricApparentEnergy(value, ElectricApparentEnergyUnit::VoltampereHours);
        }


        [[nodiscard]] constexpr un_scalar_t kilovoltampere_hours() const
        {
            return convert_from_base(ElectricApparentEnergyUnit::KilovoltampereHours);
        }

        [[nodiscard]] static constexpr ElectricApparentEnergy from_kilovoltampere_hours(const un_scalar_t value)
        {
            return ElectricApparentEnergy(value, ElectricApparentEnergyUnit::KilovoltampereHours);
        }


        [[nodiscard]] constexpr un_scalar_t megavoltampere_hours() const
        {
            return convert_from_base(ElectricApparentEnergyUnit::MegavoltampereHours);
        }

        [[nodiscard]] static constexpr ElectricApparentEnergy from_megavoltampere_hours(const un_scalar_t value)
        {
            return ElectricApparentEnergy(value, ElectricApparentEnergyUnit::MegavoltampereHours);
        }


        [[nodiscard]] static constexpr ElectricApparentEnergy from_invalid()
        {
            return ElectricApparentEnergy(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricApparentEnergyUnit unit)
        {
            switch (unit)
            {

            case ElectricApparentEnergyUnit::VoltampereHours:
                return value;

            case ElectricApparentEnergyUnit::KilovoltampereHours:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricApparentEnergyUnit::MegavoltampereHours:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown ElectricApparentEnergy unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricApparentEnergyUnit unit) const
        {
            switch (unit)
            {

            case ElectricApparentEnergyUnit::VoltampereHours:
                return value_;

            case ElectricApparentEnergyUnit::KilovoltampereHours:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case ElectricApparentEnergyUnit::MegavoltampereHours:
                return (value_) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricApparentEnergy unit.");
        }

        un_scalar_t value_;
    };
}
