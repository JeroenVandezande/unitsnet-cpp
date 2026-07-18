#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricConductivityUnit : std::uint16_t
    {
        SiemensPerMeter,
        SiemensPerInch,
        SiemensPerFoot,
        SiemensPerCentimeter,
        MicrosiemensPerCentimeter,
        MillisiemensPerCentimeter,
    };

    /// <summary>Electrical conductivity or specific conductance is the reciprocal of electrical resistivity, and measures a material's ability to conduct an electric current.</summary>
    class ElectricConductivity
    {
    public:
        constexpr explicit ElectricConductivity(
            double value,
            ElectricConductivityUnit unit = ElectricConductivityUnit::SiemensPerMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricConductivityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricConductivity operator+(ElectricConductivity other) const noexcept
        {
            return ElectricConductivity(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricConductivity operator-(ElectricConductivity other) const noexcept
        {
            return ElectricConductivity(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricConductivity operator*(double scalar) const noexcept
        {
            return ElectricConductivity(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricConductivity operator/(double scalar) const noexcept
        {
            return ElectricConductivity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricConductivity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricConductivity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double siemens_per_meter() const
        {
            return convert_from_base(ElectricConductivityUnit::SiemensPerMeter);
        }

        [[nodiscard]] static constexpr ElectricConductivity from_siemens_per_meter(double value)
        {
            return ElectricConductivity(value, ElectricConductivityUnit::SiemensPerMeter);
        }


        [[nodiscard]] constexpr double siemens_per_inch() const
        {
            return convert_from_base(ElectricConductivityUnit::SiemensPerInch);
        }

        [[nodiscard]] static constexpr ElectricConductivity from_siemens_per_inch(double value)
        {
            return ElectricConductivity(value, ElectricConductivityUnit::SiemensPerInch);
        }


        [[nodiscard]] constexpr double siemens_per_foot() const
        {
            return convert_from_base(ElectricConductivityUnit::SiemensPerFoot);
        }

        [[nodiscard]] static constexpr ElectricConductivity from_siemens_per_foot(double value)
        {
            return ElectricConductivity(value, ElectricConductivityUnit::SiemensPerFoot);
        }


        [[nodiscard]] constexpr double siemens_per_centimeter() const
        {
            return convert_from_base(ElectricConductivityUnit::SiemensPerCentimeter);
        }

        [[nodiscard]] static constexpr ElectricConductivity from_siemens_per_centimeter(double value)
        {
            return ElectricConductivity(value, ElectricConductivityUnit::SiemensPerCentimeter);
        }


        [[nodiscard]] constexpr double microsiemens_per_centimeter() const
        {
            return convert_from_base(ElectricConductivityUnit::MicrosiemensPerCentimeter);
        }

        [[nodiscard]] static constexpr ElectricConductivity from_microsiemens_per_centimeter(double value)
        {
            return ElectricConductivity(value, ElectricConductivityUnit::MicrosiemensPerCentimeter);
        }


        [[nodiscard]] constexpr double millisiemens_per_centimeter() const
        {
            return convert_from_base(ElectricConductivityUnit::MillisiemensPerCentimeter);
        }

        [[nodiscard]] static constexpr ElectricConductivity from_millisiemens_per_centimeter(double value)
        {
            return ElectricConductivity(value, ElectricConductivityUnit::MillisiemensPerCentimeter);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricConductivityUnit unit)
        {
            switch (unit)
            {

            case ElectricConductivityUnit::SiemensPerMeter:
                return value;

            case ElectricConductivityUnit::SiemensPerInch:
                return value / 2.54e-2;

            case ElectricConductivityUnit::SiemensPerFoot:
                return value / 0.3048;

            case ElectricConductivityUnit::SiemensPerCentimeter:
                return value * 1e2;

            case ElectricConductivityUnit::MicrosiemensPerCentimeter:
                return (value * 1e-6) * 1e2;

            case ElectricConductivityUnit::MillisiemensPerCentimeter:
                return (value * 1e-3) * 1e2;

            }

            throw std::invalid_argument("Unknown ElectricConductivity unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricConductivityUnit unit) const
        {
            switch (unit)
            {

            case ElectricConductivityUnit::SiemensPerMeter:
                return value_;

            case ElectricConductivityUnit::SiemensPerInch:
                return value_ * 2.54e-2;

            case ElectricConductivityUnit::SiemensPerFoot:
                return value_ * 0.3048;

            case ElectricConductivityUnit::SiemensPerCentimeter:
                return value_ / 1e2;

            case ElectricConductivityUnit::MicrosiemensPerCentimeter:
                return (value_ / 1e2) / 1e-6;

            case ElectricConductivityUnit::MillisiemensPerCentimeter:
                return (value_ / 1e2) / 1e-3;

            }

            throw std::invalid_argument("Unknown ElectricConductivity unit.");
        }

        double value_;
    };
}
