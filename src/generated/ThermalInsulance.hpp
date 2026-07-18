#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ThermalInsulanceUnit : std::uint16_t
    {
        SquareMeterKelvinsPerKilowatt,
        SquareMeterKelvinsPerWatt,
        SquareMeterDegreesCelsiusPerWatt,
        SquareCentimeterKelvinsPerWatt,
        SquareMillimeterKelvinsPerWatt,
        SquareCentimeterHourDegreesCelsiusPerKilocalorie,
        HourSquareFeetDegreesFahrenheitPerBtu,
    };

    /// <summary>Thermal insulance (R-value) is a measure of a material's resistance to the heat current. It quantifies how effectively a material can resist the transfer of heat through conduction, convection, and radiation. It has the units square metre kelvins per watt (m2⋅K/W) in SI units or square foot degree Fahrenheit–hours per British thermal unit (ft2⋅°F⋅h/Btu) in imperial units. The higher the thermal insulance, the better a material insulates against heat transfer. It is commonly used in construction to assess the insulation properties of materials such as walls, roofs, and insulation products.</summary>
    class ThermalInsulance
    {
    public:
        constexpr explicit ThermalInsulance(
            double value,
            ThermalInsulanceUnit unit = ThermalInsulanceUnit::SquareMeterKelvinsPerKilowatt)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ThermalInsulanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ThermalInsulance operator+(ThermalInsulance other) const noexcept
        {
            return ThermalInsulance(value_ + other.value_);
        }

        [[nodiscard]] constexpr ThermalInsulance operator-(ThermalInsulance other) const noexcept
        {
            return ThermalInsulance(value_ - other.value_);
        }

        [[nodiscard]] constexpr ThermalInsulance operator*(double scalar) const noexcept
        {
            return ThermalInsulance(value_ * scalar);
        }

        [[nodiscard]] constexpr ThermalInsulance operator/(double scalar) const noexcept
        {
            return ThermalInsulance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ThermalInsulance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ThermalInsulance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double square_meter_kelvins_per_kilowatt() const
        {
            return convert_from_base(ThermalInsulanceUnit::SquareMeterKelvinsPerKilowatt);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_square_meter_kelvins_per_kilowatt(double value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::SquareMeterKelvinsPerKilowatt);
        }


        [[nodiscard]] constexpr double square_meter_kelvins_per_watt() const
        {
            return convert_from_base(ThermalInsulanceUnit::SquareMeterKelvinsPerWatt);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_square_meter_kelvins_per_watt(double value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::SquareMeterKelvinsPerWatt);
        }


        [[nodiscard]] constexpr double square_meter_degrees_celsius_per_watt() const
        {
            return convert_from_base(ThermalInsulanceUnit::SquareMeterDegreesCelsiusPerWatt);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_square_meter_degrees_celsius_per_watt(double value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::SquareMeterDegreesCelsiusPerWatt);
        }


        [[nodiscard]] constexpr double square_centimeter_kelvins_per_watt() const
        {
            return convert_from_base(ThermalInsulanceUnit::SquareCentimeterKelvinsPerWatt);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_square_centimeter_kelvins_per_watt(double value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::SquareCentimeterKelvinsPerWatt);
        }


        [[nodiscard]] constexpr double square_millimeter_kelvins_per_watt() const
        {
            return convert_from_base(ThermalInsulanceUnit::SquareMillimeterKelvinsPerWatt);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_square_millimeter_kelvins_per_watt(double value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::SquareMillimeterKelvinsPerWatt);
        }


        [[nodiscard]] constexpr double square_centimeter_hour_degrees_celsius_per_kilocalorie() const
        {
            return convert_from_base(ThermalInsulanceUnit::SquareCentimeterHourDegreesCelsiusPerKilocalorie);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_square_centimeter_hour_degrees_celsius_per_kilocalorie(double value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::SquareCentimeterHourDegreesCelsiusPerKilocalorie);
        }


        [[nodiscard]] constexpr double hour_square_feet_degrees_fahrenheit_per_btu() const
        {
            return convert_from_base(ThermalInsulanceUnit::HourSquareFeetDegreesFahrenheitPerBtu);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_hour_square_feet_degrees_fahrenheit_per_btu(double value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::HourSquareFeetDegreesFahrenheitPerBtu);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ThermalInsulanceUnit unit)
        {
            switch (unit)
            {

            case ThermalInsulanceUnit::SquareMeterKelvinsPerKilowatt:
                return value;

            case ThermalInsulanceUnit::SquareMeterKelvinsPerWatt:
                return value * 1000;

            case ThermalInsulanceUnit::SquareMeterDegreesCelsiusPerWatt:
                return value * 1000.0;

            case ThermalInsulanceUnit::SquareCentimeterKelvinsPerWatt:
                return value * 0.1;

            case ThermalInsulanceUnit::SquareMillimeterKelvinsPerWatt:
                return value * 0.001;

            case ThermalInsulanceUnit::SquareCentimeterHourDegreesCelsiusPerKilocalorie:
                return value * (0.0001 * 3600) / 4.184;

            case ThermalInsulanceUnit::HourSquareFeetDegreesFahrenheitPerBtu:
                return value * (1000 * 0.3048 * 0.3048 * 3600) / (1055.05585262 * 1.8);

            }

            throw std::invalid_argument("Unknown ThermalInsulance unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ThermalInsulanceUnit unit) const
        {
            switch (unit)
            {

            case ThermalInsulanceUnit::SquareMeterKelvinsPerKilowatt:
                return value_;

            case ThermalInsulanceUnit::SquareMeterKelvinsPerWatt:
                return value_ / 1000;

            case ThermalInsulanceUnit::SquareMeterDegreesCelsiusPerWatt:
                return value_ / 1000.0;

            case ThermalInsulanceUnit::SquareCentimeterKelvinsPerWatt:
                return value_ / 0.1;

            case ThermalInsulanceUnit::SquareMillimeterKelvinsPerWatt:
                return value_ / 0.001;

            case ThermalInsulanceUnit::SquareCentimeterHourDegreesCelsiusPerKilocalorie:
                return value_ * 4.184 / (0.0001 * 3600);

            case ThermalInsulanceUnit::HourSquareFeetDegreesFahrenheitPerBtu:
                return value_ * (1055.05585262 * 1.8) / (1000 * 0.3048 * 0.3048 * 3600);

            }

            throw std::invalid_argument("Unknown ThermalInsulance unit.");
        }

        double value_;
    };
}
