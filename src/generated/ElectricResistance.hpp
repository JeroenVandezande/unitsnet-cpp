#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricResistanceUnit : std::uint16_t
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
            double value,
            ElectricResistanceUnit unit = ElectricResistanceUnit::Ohms)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricResistanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricResistance operator+(ElectricResistance other) const noexcept
        {
            return ElectricResistance(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricResistance operator-(ElectricResistance other) const noexcept
        {
            return ElectricResistance(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricResistance operator*(double scalar) const noexcept
        {
            return ElectricResistance(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricResistance operator/(double scalar) const noexcept
        {
            return ElectricResistance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricResistance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricResistance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double ohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Ohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_ohms(double value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Ohms);
        }


        [[nodiscard]] constexpr double nanoohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Nanoohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_nanoohms(double value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Nanoohms);
        }


        [[nodiscard]] constexpr double microohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Microohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_microohms(double value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Microohms);
        }


        [[nodiscard]] constexpr double milliohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Milliohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_milliohms(double value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Milliohms);
        }


        [[nodiscard]] constexpr double kiloohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Kiloohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_kiloohms(double value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Kiloohms);
        }


        [[nodiscard]] constexpr double megaohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Megaohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_megaohms(double value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Megaohms);
        }


        [[nodiscard]] constexpr double gigaohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Gigaohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_gigaohms(double value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Gigaohms);
        }


        [[nodiscard]] constexpr double teraohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Teraohms);
        }

        [[nodiscard]] static constexpr ElectricResistance from_teraohms(double value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Teraohms);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricResistanceUnit unit)
        {
            switch (unit)
            {

            case ElectricResistanceUnit::Ohms:
                return value;

            case ElectricResistanceUnit::Nanoohms:
                return (value * 1e-9);

            case ElectricResistanceUnit::Microohms:
                return (value * 1e-6);

            case ElectricResistanceUnit::Milliohms:
                return (value * 1e-3);

            case ElectricResistanceUnit::Kiloohms:
                return (value * 1e3);

            case ElectricResistanceUnit::Megaohms:
                return (value * 1e6);

            case ElectricResistanceUnit::Gigaohms:
                return (value * 1e9);

            case ElectricResistanceUnit::Teraohms:
                return (value * 1e12);

            }

            throw std::invalid_argument("Unknown ElectricResistance unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricResistanceUnit unit) const
        {
            switch (unit)
            {

            case ElectricResistanceUnit::Ohms:
                return value_;

            case ElectricResistanceUnit::Nanoohms:
                return (value_) / 1e-9;

            case ElectricResistanceUnit::Microohms:
                return (value_) / 1e-6;

            case ElectricResistanceUnit::Milliohms:
                return (value_) / 1e-3;

            case ElectricResistanceUnit::Kiloohms:
                return (value_) / 1e3;

            case ElectricResistanceUnit::Megaohms:
                return (value_) / 1e6;

            case ElectricResistanceUnit::Gigaohms:
                return (value_) / 1e9;

            case ElectricResistanceUnit::Teraohms:
                return (value_) / 1e12;

            }

            throw std::invalid_argument("Unknown ElectricResistance unit.");
        }

        double value_;
    };
}
