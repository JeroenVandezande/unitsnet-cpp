#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class LuminosityUnit : std::uint16_t
    {
        Watts,
        Femtowatts,
        Picowatts,
        Nanowatts,
        Microwatts,
        Milliwatts,
        Deciwatts,
        Decawatts,
        Kilowatts,
        Megawatts,
        Gigawatts,
        Terawatts,
        Petawatts,
        SolarLuminosities,
    };

    /// <summary>Luminosity is an absolute measure of radiated electromagnetic power (light), the radiant power emitted by a light-emitting object.</summary>
    class Luminosity
    {
    public:
        constexpr explicit Luminosity(
            double value,
            LuminosityUnit unit = LuminosityUnit::Watts)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(LuminosityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Luminosity operator+(Luminosity other) const noexcept
        {
            return Luminosity(value_ + other.value_);
        }

        [[nodiscard]] constexpr Luminosity operator-(Luminosity other) const noexcept
        {
            return Luminosity(value_ - other.value_);
        }

        [[nodiscard]] constexpr Luminosity operator*(double scalar) const noexcept
        {
            return Luminosity(value_ * scalar);
        }

        [[nodiscard]] constexpr Luminosity operator/(double scalar) const noexcept
        {
            return Luminosity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Luminosity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Luminosity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double watts() const
        {
            return convert_from_base(LuminosityUnit::Watts);
        }

        [[nodiscard]] static constexpr Luminosity from_watts(double value)
        {
            return Luminosity(value, LuminosityUnit::Watts);
        }


        [[nodiscard]] constexpr double femtowatts() const
        {
            return convert_from_base(LuminosityUnit::Femtowatts);
        }

        [[nodiscard]] static constexpr Luminosity from_femtowatts(double value)
        {
            return Luminosity(value, LuminosityUnit::Femtowatts);
        }


        [[nodiscard]] constexpr double picowatts() const
        {
            return convert_from_base(LuminosityUnit::Picowatts);
        }

        [[nodiscard]] static constexpr Luminosity from_picowatts(double value)
        {
            return Luminosity(value, LuminosityUnit::Picowatts);
        }


        [[nodiscard]] constexpr double nanowatts() const
        {
            return convert_from_base(LuminosityUnit::Nanowatts);
        }

        [[nodiscard]] static constexpr Luminosity from_nanowatts(double value)
        {
            return Luminosity(value, LuminosityUnit::Nanowatts);
        }


        [[nodiscard]] constexpr double microwatts() const
        {
            return convert_from_base(LuminosityUnit::Microwatts);
        }

        [[nodiscard]] static constexpr Luminosity from_microwatts(double value)
        {
            return Luminosity(value, LuminosityUnit::Microwatts);
        }


        [[nodiscard]] constexpr double milliwatts() const
        {
            return convert_from_base(LuminosityUnit::Milliwatts);
        }

        [[nodiscard]] static constexpr Luminosity from_milliwatts(double value)
        {
            return Luminosity(value, LuminosityUnit::Milliwatts);
        }


        [[nodiscard]] constexpr double deciwatts() const
        {
            return convert_from_base(LuminosityUnit::Deciwatts);
        }

        [[nodiscard]] static constexpr Luminosity from_deciwatts(double value)
        {
            return Luminosity(value, LuminosityUnit::Deciwatts);
        }


        [[nodiscard]] constexpr double decawatts() const
        {
            return convert_from_base(LuminosityUnit::Decawatts);
        }

        [[nodiscard]] static constexpr Luminosity from_decawatts(double value)
        {
            return Luminosity(value, LuminosityUnit::Decawatts);
        }


        [[nodiscard]] constexpr double kilowatts() const
        {
            return convert_from_base(LuminosityUnit::Kilowatts);
        }

        [[nodiscard]] static constexpr Luminosity from_kilowatts(double value)
        {
            return Luminosity(value, LuminosityUnit::Kilowatts);
        }


        [[nodiscard]] constexpr double megawatts() const
        {
            return convert_from_base(LuminosityUnit::Megawatts);
        }

        [[nodiscard]] static constexpr Luminosity from_megawatts(double value)
        {
            return Luminosity(value, LuminosityUnit::Megawatts);
        }


        [[nodiscard]] constexpr double gigawatts() const
        {
            return convert_from_base(LuminosityUnit::Gigawatts);
        }

        [[nodiscard]] static constexpr Luminosity from_gigawatts(double value)
        {
            return Luminosity(value, LuminosityUnit::Gigawatts);
        }


        [[nodiscard]] constexpr double terawatts() const
        {
            return convert_from_base(LuminosityUnit::Terawatts);
        }

        [[nodiscard]] static constexpr Luminosity from_terawatts(double value)
        {
            return Luminosity(value, LuminosityUnit::Terawatts);
        }


        [[nodiscard]] constexpr double petawatts() const
        {
            return convert_from_base(LuminosityUnit::Petawatts);
        }

        [[nodiscard]] static constexpr Luminosity from_petawatts(double value)
        {
            return Luminosity(value, LuminosityUnit::Petawatts);
        }


        [[nodiscard]] constexpr double solar_luminosities() const
        {
            return convert_from_base(LuminosityUnit::SolarLuminosities);
        }

        [[nodiscard]] static constexpr Luminosity from_solar_luminosities(double value)
        {
            return Luminosity(value, LuminosityUnit::SolarLuminosities);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, LuminosityUnit unit)
        {
            switch (unit)
            {

            case LuminosityUnit::Watts:
                return value;

            case LuminosityUnit::Femtowatts:
                return (value * 1e-15);

            case LuminosityUnit::Picowatts:
                return (value * 1e-12);

            case LuminosityUnit::Nanowatts:
                return (value * 1e-9);

            case LuminosityUnit::Microwatts:
                return (value * 1e-6);

            case LuminosityUnit::Milliwatts:
                return (value * 1e-3);

            case LuminosityUnit::Deciwatts:
                return (value * 1e-1);

            case LuminosityUnit::Decawatts:
                return (value * 1e1);

            case LuminosityUnit::Kilowatts:
                return (value * 1e3);

            case LuminosityUnit::Megawatts:
                return (value * 1e6);

            case LuminosityUnit::Gigawatts:
                return (value * 1e9);

            case LuminosityUnit::Terawatts:
                return (value * 1e12);

            case LuminosityUnit::Petawatts:
                return (value * 1e15);

            case LuminosityUnit::SolarLuminosities:
                return value * 3.828e26;

            }

            throw std::invalid_argument("Unknown Luminosity unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(LuminosityUnit unit) const
        {
            switch (unit)
            {

            case LuminosityUnit::Watts:
                return value_;

            case LuminosityUnit::Femtowatts:
                return (value_) / 1e-15;

            case LuminosityUnit::Picowatts:
                return (value_) / 1e-12;

            case LuminosityUnit::Nanowatts:
                return (value_) / 1e-9;

            case LuminosityUnit::Microwatts:
                return (value_) / 1e-6;

            case LuminosityUnit::Milliwatts:
                return (value_) / 1e-3;

            case LuminosityUnit::Deciwatts:
                return (value_) / 1e-1;

            case LuminosityUnit::Decawatts:
                return (value_) / 1e1;

            case LuminosityUnit::Kilowatts:
                return (value_) / 1e3;

            case LuminosityUnit::Megawatts:
                return (value_) / 1e6;

            case LuminosityUnit::Gigawatts:
                return (value_) / 1e9;

            case LuminosityUnit::Terawatts:
                return (value_) / 1e12;

            case LuminosityUnit::Petawatts:
                return (value_) / 1e15;

            case LuminosityUnit::SolarLuminosities:
                return value_ / 3.828e26;

            }

            throw std::invalid_argument("Unknown Luminosity unit.");
        }

        double value_;
    };
}
