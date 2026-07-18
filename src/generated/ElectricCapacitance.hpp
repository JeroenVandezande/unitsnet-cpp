#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricCapacitanceUnit : std::uint16_t
    {
        Farads,
        Picofarads,
        Nanofarads,
        Microfarads,
        Millifarads,
        Kilofarads,
        Megafarads,
    };

    /// <summary>Capacitance is the capacity of a material object or device to store electric charge.</summary>
    class ElectricCapacitance
    {
    public:
        constexpr explicit ElectricCapacitance(
            double value,
            ElectricCapacitanceUnit unit = ElectricCapacitanceUnit::Farads)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricCapacitanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricCapacitance operator+(ElectricCapacitance other) const noexcept
        {
            return ElectricCapacitance(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricCapacitance operator-(ElectricCapacitance other) const noexcept
        {
            return ElectricCapacitance(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricCapacitance operator*(double scalar) const noexcept
        {
            return ElectricCapacitance(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricCapacitance operator/(double scalar) const noexcept
        {
            return ElectricCapacitance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricCapacitance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricCapacitance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double farads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Farads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_farads(double value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Farads);
        }


        [[nodiscard]] constexpr double picofarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Picofarads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_picofarads(double value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Picofarads);
        }


        [[nodiscard]] constexpr double nanofarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Nanofarads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_nanofarads(double value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Nanofarads);
        }


        [[nodiscard]] constexpr double microfarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Microfarads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_microfarads(double value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Microfarads);
        }


        [[nodiscard]] constexpr double millifarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Millifarads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_millifarads(double value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Millifarads);
        }


        [[nodiscard]] constexpr double kilofarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Kilofarads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_kilofarads(double value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Kilofarads);
        }


        [[nodiscard]] constexpr double megafarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Megafarads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_megafarads(double value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Megafarads);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricCapacitanceUnit unit)
        {
            switch (unit)
            {

            case ElectricCapacitanceUnit::Farads:
                return value;

            case ElectricCapacitanceUnit::Picofarads:
                return (value * 1e-12);

            case ElectricCapacitanceUnit::Nanofarads:
                return (value * 1e-9);

            case ElectricCapacitanceUnit::Microfarads:
                return (value * 1e-6);

            case ElectricCapacitanceUnit::Millifarads:
                return (value * 1e-3);

            case ElectricCapacitanceUnit::Kilofarads:
                return (value * 1e3);

            case ElectricCapacitanceUnit::Megafarads:
                return (value * 1e6);

            }

            throw std::invalid_argument("Unknown ElectricCapacitance unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricCapacitanceUnit unit) const
        {
            switch (unit)
            {

            case ElectricCapacitanceUnit::Farads:
                return value_;

            case ElectricCapacitanceUnit::Picofarads:
                return (value_) / 1e-12;

            case ElectricCapacitanceUnit::Nanofarads:
                return (value_) / 1e-9;

            case ElectricCapacitanceUnit::Microfarads:
                return (value_) / 1e-6;

            case ElectricCapacitanceUnit::Millifarads:
                return (value_) / 1e-3;

            case ElectricCapacitanceUnit::Kilofarads:
                return (value_) / 1e3;

            case ElectricCapacitanceUnit::Megafarads:
                return (value_) / 1e6;

            }

            throw std::invalid_argument("Unknown ElectricCapacitance unit.");
        }

        double value_;
    };
}
