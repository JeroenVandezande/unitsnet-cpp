#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricCurrentUnit : std::uint16_t
    {
        Amperes,
        Femtoamperes,
        Picoamperes,
        Nanoamperes,
        Microamperes,
        Milliamperes,
        Centiamperes,
        Kiloamperes,
        Megaamperes,
    };

    /// <summary>An electric current is a flow of electric charge. In electric circuits this charge is often carried by moving electrons in a wire. It can also be carried by ions in an electrolyte, or by both ions and electrons such as in a plasma.</summary>
    class ElectricCurrent
    {
    public:
        constexpr explicit ElectricCurrent(
            double value,
            ElectricCurrentUnit unit = ElectricCurrentUnit::Amperes)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricCurrentUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricCurrent operator+(ElectricCurrent other) const noexcept
        {
            return ElectricCurrent(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricCurrent operator-(ElectricCurrent other) const noexcept
        {
            return ElectricCurrent(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricCurrent operator*(double scalar) const noexcept
        {
            return ElectricCurrent(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricCurrent operator/(double scalar) const noexcept
        {
            return ElectricCurrent(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricCurrent other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricCurrent other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double amperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Amperes);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_amperes(double value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Amperes);
        }


        [[nodiscard]] constexpr double femtoamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Femtoamperes);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_femtoamperes(double value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Femtoamperes);
        }


        [[nodiscard]] constexpr double picoamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Picoamperes);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_picoamperes(double value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Picoamperes);
        }


        [[nodiscard]] constexpr double nanoamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Nanoamperes);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_nanoamperes(double value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Nanoamperes);
        }


        [[nodiscard]] constexpr double microamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Microamperes);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_microamperes(double value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Microamperes);
        }


        [[nodiscard]] constexpr double milliamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Milliamperes);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_milliamperes(double value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Milliamperes);
        }


        [[nodiscard]] constexpr double centiamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Centiamperes);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_centiamperes(double value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Centiamperes);
        }


        [[nodiscard]] constexpr double kiloamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Kiloamperes);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_kiloamperes(double value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Kiloamperes);
        }


        [[nodiscard]] constexpr double megaamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Megaamperes);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_megaamperes(double value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Megaamperes);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricCurrentUnit unit)
        {
            switch (unit)
            {

            case ElectricCurrentUnit::Amperes:
                return value;

            case ElectricCurrentUnit::Femtoamperes:
                return (value * 1e-15);

            case ElectricCurrentUnit::Picoamperes:
                return (value * 1e-12);

            case ElectricCurrentUnit::Nanoamperes:
                return (value * 1e-9);

            case ElectricCurrentUnit::Microamperes:
                return (value * 1e-6);

            case ElectricCurrentUnit::Milliamperes:
                return (value * 1e-3);

            case ElectricCurrentUnit::Centiamperes:
                return (value * 1e-2);

            case ElectricCurrentUnit::Kiloamperes:
                return (value * 1e3);

            case ElectricCurrentUnit::Megaamperes:
                return (value * 1e6);

            }

            throw std::invalid_argument("Unknown ElectricCurrent unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricCurrentUnit unit) const
        {
            switch (unit)
            {

            case ElectricCurrentUnit::Amperes:
                return value_;

            case ElectricCurrentUnit::Femtoamperes:
                return (value_) / 1e-15;

            case ElectricCurrentUnit::Picoamperes:
                return (value_) / 1e-12;

            case ElectricCurrentUnit::Nanoamperes:
                return (value_) / 1e-9;

            case ElectricCurrentUnit::Microamperes:
                return (value_) / 1e-6;

            case ElectricCurrentUnit::Milliamperes:
                return (value_) / 1e-3;

            case ElectricCurrentUnit::Centiamperes:
                return (value_) / 1e-2;

            case ElectricCurrentUnit::Kiloamperes:
                return (value_) / 1e3;

            case ElectricCurrentUnit::Megaamperes:
                return (value_) / 1e6;

            }

            throw std::invalid_argument("Unknown ElectricCurrent unit.");
        }

        double value_;
    };
}
