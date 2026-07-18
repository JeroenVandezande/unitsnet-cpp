#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricInductanceUnit : std::uint16_t
    {
        Henries,
        Picohenries,
        Nanohenries,
        Microhenries,
        Millihenries,
    };

    /// <summary>Inductance is a property of an electrical conductor which opposes a change in current.</summary>
    class ElectricInductance
    {
    public:
        constexpr explicit ElectricInductance(
            double value,
            ElectricInductanceUnit unit = ElectricInductanceUnit::Henries)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricInductanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricInductance operator+(ElectricInductance other) const noexcept
        {
            return ElectricInductance(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricInductance operator-(ElectricInductance other) const noexcept
        {
            return ElectricInductance(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricInductance operator*(double scalar) const noexcept
        {
            return ElectricInductance(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricInductance operator/(double scalar) const noexcept
        {
            return ElectricInductance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricInductance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricInductance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double henries() const
        {
            return convert_from_base(ElectricInductanceUnit::Henries);
        }

        [[nodiscard]] static constexpr ElectricInductance from_henries(double value)
        {
            return ElectricInductance(value, ElectricInductanceUnit::Henries);
        }


        [[nodiscard]] constexpr double picohenries() const
        {
            return convert_from_base(ElectricInductanceUnit::Picohenries);
        }

        [[nodiscard]] static constexpr ElectricInductance from_picohenries(double value)
        {
            return ElectricInductance(value, ElectricInductanceUnit::Picohenries);
        }


        [[nodiscard]] constexpr double nanohenries() const
        {
            return convert_from_base(ElectricInductanceUnit::Nanohenries);
        }

        [[nodiscard]] static constexpr ElectricInductance from_nanohenries(double value)
        {
            return ElectricInductance(value, ElectricInductanceUnit::Nanohenries);
        }


        [[nodiscard]] constexpr double microhenries() const
        {
            return convert_from_base(ElectricInductanceUnit::Microhenries);
        }

        [[nodiscard]] static constexpr ElectricInductance from_microhenries(double value)
        {
            return ElectricInductance(value, ElectricInductanceUnit::Microhenries);
        }


        [[nodiscard]] constexpr double millihenries() const
        {
            return convert_from_base(ElectricInductanceUnit::Millihenries);
        }

        [[nodiscard]] static constexpr ElectricInductance from_millihenries(double value)
        {
            return ElectricInductance(value, ElectricInductanceUnit::Millihenries);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricInductanceUnit unit)
        {
            switch (unit)
            {

            case ElectricInductanceUnit::Henries:
                return value;

            case ElectricInductanceUnit::Picohenries:
                return (value * 1e-12);

            case ElectricInductanceUnit::Nanohenries:
                return (value * 1e-9);

            case ElectricInductanceUnit::Microhenries:
                return (value * 1e-6);

            case ElectricInductanceUnit::Millihenries:
                return (value * 1e-3);

            }

            throw std::invalid_argument("Unknown ElectricInductance unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricInductanceUnit unit) const
        {
            switch (unit)
            {

            case ElectricInductanceUnit::Henries:
                return value_;

            case ElectricInductanceUnit::Picohenries:
                return (value_) / 1e-12;

            case ElectricInductanceUnit::Nanohenries:
                return (value_) / 1e-9;

            case ElectricInductanceUnit::Microhenries:
                return (value_) / 1e-6;

            case ElectricInductanceUnit::Millihenries:
                return (value_) / 1e-3;

            }

            throw std::invalid_argument("Unknown ElectricInductance unit.");
        }

        double value_;
    };
}
