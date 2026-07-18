#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricReactanceUnit : std::uint16_t
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

    /// <summary>In electrical circuits, reactance is the opposition presented to alternating current by inductance and capacitance. Along with resistance, it is one of two elements of impedance.</summary>
    class ElectricReactance
    {
    public:
        constexpr explicit ElectricReactance(
            double value,
            ElectricReactanceUnit unit = ElectricReactanceUnit::Ohms)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricReactanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricReactance operator+(ElectricReactance other) const noexcept
        {
            return ElectricReactance(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricReactance operator-(ElectricReactance other) const noexcept
        {
            return ElectricReactance(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricReactance operator*(double scalar) const noexcept
        {
            return ElectricReactance(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricReactance operator/(double scalar) const noexcept
        {
            return ElectricReactance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricReactance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricReactance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double ohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Ohms);
        }

        [[nodiscard]] static constexpr ElectricReactance from_ohms(double value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Ohms);
        }


        [[nodiscard]] constexpr double nanoohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Nanoohms);
        }

        [[nodiscard]] static constexpr ElectricReactance from_nanoohms(double value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Nanoohms);
        }


        [[nodiscard]] constexpr double microohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Microohms);
        }

        [[nodiscard]] static constexpr ElectricReactance from_microohms(double value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Microohms);
        }


        [[nodiscard]] constexpr double milliohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Milliohms);
        }

        [[nodiscard]] static constexpr ElectricReactance from_milliohms(double value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Milliohms);
        }


        [[nodiscard]] constexpr double kiloohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Kiloohms);
        }

        [[nodiscard]] static constexpr ElectricReactance from_kiloohms(double value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Kiloohms);
        }


        [[nodiscard]] constexpr double megaohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Megaohms);
        }

        [[nodiscard]] static constexpr ElectricReactance from_megaohms(double value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Megaohms);
        }


        [[nodiscard]] constexpr double gigaohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Gigaohms);
        }

        [[nodiscard]] static constexpr ElectricReactance from_gigaohms(double value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Gigaohms);
        }


        [[nodiscard]] constexpr double teraohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Teraohms);
        }

        [[nodiscard]] static constexpr ElectricReactance from_teraohms(double value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Teraohms);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricReactanceUnit unit)
        {
            switch (unit)
            {

            case ElectricReactanceUnit::Ohms:
                return value;

            case ElectricReactanceUnit::Nanoohms:
                return (value * 1e-9);

            case ElectricReactanceUnit::Microohms:
                return (value * 1e-6);

            case ElectricReactanceUnit::Milliohms:
                return (value * 1e-3);

            case ElectricReactanceUnit::Kiloohms:
                return (value * 1e3);

            case ElectricReactanceUnit::Megaohms:
                return (value * 1e6);

            case ElectricReactanceUnit::Gigaohms:
                return (value * 1e9);

            case ElectricReactanceUnit::Teraohms:
                return (value * 1e12);

            }

            throw std::invalid_argument("Unknown ElectricReactance unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricReactanceUnit unit) const
        {
            switch (unit)
            {

            case ElectricReactanceUnit::Ohms:
                return value_;

            case ElectricReactanceUnit::Nanoohms:
                return (value_) / 1e-9;

            case ElectricReactanceUnit::Microohms:
                return (value_) / 1e-6;

            case ElectricReactanceUnit::Milliohms:
                return (value_) / 1e-3;

            case ElectricReactanceUnit::Kiloohms:
                return (value_) / 1e3;

            case ElectricReactanceUnit::Megaohms:
                return (value_) / 1e6;

            case ElectricReactanceUnit::Gigaohms:
                return (value_) / 1e9;

            case ElectricReactanceUnit::Teraohms:
                return (value_) / 1e12;

            }

            throw std::invalid_argument("Unknown ElectricReactance unit.");
        }

        double value_;
    };
}
