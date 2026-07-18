#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricImpedanceUnit : std::uint16_t
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

    /// <summary>Electric impedance is the opposition to alternating current presented by the combined effect of resistance and reactance in a circuit. It is defined as the inverse of admittance. The SI unit of impedance is the ohm (symbol Ω).</summary>
    class ElectricImpedance
    {
    public:
        constexpr explicit ElectricImpedance(
            double value,
            ElectricImpedanceUnit unit = ElectricImpedanceUnit::Ohms)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricImpedanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricImpedance operator+(ElectricImpedance other) const noexcept
        {
            return ElectricImpedance(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricImpedance operator-(ElectricImpedance other) const noexcept
        {
            return ElectricImpedance(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricImpedance operator*(double scalar) const noexcept
        {
            return ElectricImpedance(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricImpedance operator/(double scalar) const noexcept
        {
            return ElectricImpedance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricImpedance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricImpedance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double ohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Ohms);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_ohms(double value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Ohms);
        }


        [[nodiscard]] constexpr double nanoohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Nanoohms);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_nanoohms(double value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Nanoohms);
        }


        [[nodiscard]] constexpr double microohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Microohms);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_microohms(double value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Microohms);
        }


        [[nodiscard]] constexpr double milliohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Milliohms);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_milliohms(double value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Milliohms);
        }


        [[nodiscard]] constexpr double kiloohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Kiloohms);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_kiloohms(double value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Kiloohms);
        }


        [[nodiscard]] constexpr double megaohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Megaohms);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_megaohms(double value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Megaohms);
        }


        [[nodiscard]] constexpr double gigaohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Gigaohms);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_gigaohms(double value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Gigaohms);
        }


        [[nodiscard]] constexpr double teraohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Teraohms);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_teraohms(double value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Teraohms);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricImpedanceUnit unit)
        {
            switch (unit)
            {

            case ElectricImpedanceUnit::Ohms:
                return value;

            case ElectricImpedanceUnit::Nanoohms:
                return (value * 1e-9);

            case ElectricImpedanceUnit::Microohms:
                return (value * 1e-6);

            case ElectricImpedanceUnit::Milliohms:
                return (value * 1e-3);

            case ElectricImpedanceUnit::Kiloohms:
                return (value * 1e3);

            case ElectricImpedanceUnit::Megaohms:
                return (value * 1e6);

            case ElectricImpedanceUnit::Gigaohms:
                return (value * 1e9);

            case ElectricImpedanceUnit::Teraohms:
                return (value * 1e12);

            }

            throw std::invalid_argument("Unknown ElectricImpedance unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricImpedanceUnit unit) const
        {
            switch (unit)
            {

            case ElectricImpedanceUnit::Ohms:
                return value_;

            case ElectricImpedanceUnit::Nanoohms:
                return (value_) / 1e-9;

            case ElectricImpedanceUnit::Microohms:
                return (value_) / 1e-6;

            case ElectricImpedanceUnit::Milliohms:
                return (value_) / 1e-3;

            case ElectricImpedanceUnit::Kiloohms:
                return (value_) / 1e3;

            case ElectricImpedanceUnit::Megaohms:
                return (value_) / 1e6;

            case ElectricImpedanceUnit::Gigaohms:
                return (value_) / 1e9;

            case ElectricImpedanceUnit::Teraohms:
                return (value_) / 1e12;

            }

            throw std::invalid_argument("Unknown ElectricImpedance unit.");
        }

        double value_;
    };
}
