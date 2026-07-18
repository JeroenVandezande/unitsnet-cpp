#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricApparentPowerUnit : std::uint16_t
    {
        Voltamperes,
        Microvoltamperes,
        Millivoltamperes,
        Kilovoltamperes,
        Megavoltamperes,
        Gigavoltamperes,
    };

    /// <summary>Power engineers measure apparent power as the magnitude of the vector sum of active and reactive power. It is the product of the root mean square voltage (in volts) and the root mean square current (in amperes).</summary>
    class ElectricApparentPower
    {
    public:
        constexpr explicit ElectricApparentPower(
            double value,
            ElectricApparentPowerUnit unit = ElectricApparentPowerUnit::Voltamperes)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricApparentPowerUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricApparentPower operator+(ElectricApparentPower other) const noexcept
        {
            return ElectricApparentPower(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricApparentPower operator-(ElectricApparentPower other) const noexcept
        {
            return ElectricApparentPower(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricApparentPower operator*(double scalar) const noexcept
        {
            return ElectricApparentPower(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricApparentPower operator/(double scalar) const noexcept
        {
            return ElectricApparentPower(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricApparentPower other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricApparentPower other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double voltamperes() const
        {
            return convert_from_base(ElectricApparentPowerUnit::Voltamperes);
        }

        [[nodiscard]] static constexpr ElectricApparentPower from_voltamperes(double value)
        {
            return ElectricApparentPower(value, ElectricApparentPowerUnit::Voltamperes);
        }


        [[nodiscard]] constexpr double microvoltamperes() const
        {
            return convert_from_base(ElectricApparentPowerUnit::Microvoltamperes);
        }

        [[nodiscard]] static constexpr ElectricApparentPower from_microvoltamperes(double value)
        {
            return ElectricApparentPower(value, ElectricApparentPowerUnit::Microvoltamperes);
        }


        [[nodiscard]] constexpr double millivoltamperes() const
        {
            return convert_from_base(ElectricApparentPowerUnit::Millivoltamperes);
        }

        [[nodiscard]] static constexpr ElectricApparentPower from_millivoltamperes(double value)
        {
            return ElectricApparentPower(value, ElectricApparentPowerUnit::Millivoltamperes);
        }


        [[nodiscard]] constexpr double kilovoltamperes() const
        {
            return convert_from_base(ElectricApparentPowerUnit::Kilovoltamperes);
        }

        [[nodiscard]] static constexpr ElectricApparentPower from_kilovoltamperes(double value)
        {
            return ElectricApparentPower(value, ElectricApparentPowerUnit::Kilovoltamperes);
        }


        [[nodiscard]] constexpr double megavoltamperes() const
        {
            return convert_from_base(ElectricApparentPowerUnit::Megavoltamperes);
        }

        [[nodiscard]] static constexpr ElectricApparentPower from_megavoltamperes(double value)
        {
            return ElectricApparentPower(value, ElectricApparentPowerUnit::Megavoltamperes);
        }


        [[nodiscard]] constexpr double gigavoltamperes() const
        {
            return convert_from_base(ElectricApparentPowerUnit::Gigavoltamperes);
        }

        [[nodiscard]] static constexpr ElectricApparentPower from_gigavoltamperes(double value)
        {
            return ElectricApparentPower(value, ElectricApparentPowerUnit::Gigavoltamperes);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricApparentPowerUnit unit)
        {
            switch (unit)
            {

            case ElectricApparentPowerUnit::Voltamperes:
                return value;

            case ElectricApparentPowerUnit::Microvoltamperes:
                return (value * 1e-6);

            case ElectricApparentPowerUnit::Millivoltamperes:
                return (value * 1e-3);

            case ElectricApparentPowerUnit::Kilovoltamperes:
                return (value * 1e3);

            case ElectricApparentPowerUnit::Megavoltamperes:
                return (value * 1e6);

            case ElectricApparentPowerUnit::Gigavoltamperes:
                return (value * 1e9);

            }

            throw std::invalid_argument("Unknown ElectricApparentPower unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricApparentPowerUnit unit) const
        {
            switch (unit)
            {

            case ElectricApparentPowerUnit::Voltamperes:
                return value_;

            case ElectricApparentPowerUnit::Microvoltamperes:
                return (value_) / 1e-6;

            case ElectricApparentPowerUnit::Millivoltamperes:
                return (value_) / 1e-3;

            case ElectricApparentPowerUnit::Kilovoltamperes:
                return (value_) / 1e3;

            case ElectricApparentPowerUnit::Megavoltamperes:
                return (value_) / 1e6;

            case ElectricApparentPowerUnit::Gigavoltamperes:
                return (value_) / 1e9;

            }

            throw std::invalid_argument("Unknown ElectricApparentPower unit.");
        }

        double value_;
    };
}
