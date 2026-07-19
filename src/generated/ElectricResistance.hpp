#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class ElectricResistanceUnit : std::uint8_t
    {
        Ohms,
        Nanoohms,
        Microohms,
        Milliohms,
        Kiloohms,
        Megaohms,
        Gigaohms,
        Teraohms,
    };

    /// <summary>The electrical resistance of an object is a measure of its opposition to the flow of electric current. Along with reactance, it is one of two elements of impedance. Its reciprocal quantity is electrical conductance.</summary>
    class ElectricResistance
    {
    public:
        constexpr explicit ElectricResistance(
            const un_scalar_t value,
            const ElectricResistanceUnit unit = ElectricResistanceUnit::Ohms)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricResistanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricResistance operator+(const ElectricResistance other) const noexcept
        {
            return ElectricResistance(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricResistance operator-(const ElectricResistance other) const noexcept
        {
            return ElectricResistance(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricResistance operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricResistance(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricResistance operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricResistance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricResistance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const ElectricResistance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t ohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Ohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_ohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Ohms);
        }


        [[nodiscard]] constexpr un_scalar_t nanoohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Nanoohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_nanoohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Nanoohms);
        }


        [[nodiscard]] constexpr un_scalar_t microohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Microohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_microohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Microohms);
        }


        [[nodiscard]] constexpr un_scalar_t milliohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Milliohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_milliohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Milliohms);
        }


        [[nodiscard]] constexpr un_scalar_t kiloohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Kiloohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_kiloohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Kiloohms);
        }


        [[nodiscard]] constexpr un_scalar_t megaohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Megaohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_megaohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Megaohms);
        }


        [[nodiscard]] constexpr un_scalar_t gigaohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Gigaohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_gigaohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Gigaohms);
        }


        [[nodiscard]] constexpr un_scalar_t teraohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Teraohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_teraohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Teraohms);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricResistanceUnit unit)
        {
            switch (unit)
            {

            case ElectricResistanceUnit::Ohms:
                return value;

            case ElectricResistanceUnit::Nanoohms:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricResistanceUnit::Microohms:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricResistanceUnit::Milliohms:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricResistanceUnit::Kiloohms:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricResistanceUnit::Megaohms:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricResistanceUnit::Gigaohms:
                return (value * static_cast<un_scalar_t>(1e9));

            case ElectricResistanceUnit::Teraohms:
                return (value * static_cast<un_scalar_t>(1e12));

            }

            throw std::invalid_argument("Unknown ElectricResistance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricResistanceUnit unit) const
        {
            switch (unit)
            {

            case ElectricResistanceUnit::Ohms:
                return value_;

            case ElectricResistanceUnit::Nanoohms:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case ElectricResistanceUnit::Microohms:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case ElectricResistanceUnit::Milliohms:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case ElectricResistanceUnit::Kiloohms:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case ElectricResistanceUnit::Megaohms:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case ElectricResistanceUnit::Gigaohms:
                return (value_) / static_cast<un_scalar_t>(1e9);

            case ElectricResistanceUnit::Teraohms:
                return (value_) / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown ElectricResistance unit.");
        }

        un_scalar_t value_;
    };
}
