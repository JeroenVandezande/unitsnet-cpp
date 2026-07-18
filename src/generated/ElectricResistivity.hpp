#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricResistivityUnit : std::uint16_t
    {
        OhmMeters,
        PicoohmMeters,
        NanoohmMeters,
        MicroohmMeters,
        MilliohmMeters,
        KiloohmMeters,
        MegaohmMeters,
        OhmsCentimeter,
        PicoohmsCentimeter,
        NanoohmsCentimeter,
        MicroohmsCentimeter,
        MilliohmsCentimeter,
        KiloohmsCentimeter,
        MegaohmsCentimeter,
    };

    /// <summary>Electrical resistivity (also known as resistivity, specific electrical resistance, or volume resistivity) is a fundamental property that quantifies how strongly a given material opposes the flow of electric current.</summary>
    class ElectricResistivity
    {
    public:
        constexpr explicit ElectricResistivity(
            double value,
            ElectricResistivityUnit unit = ElectricResistivityUnit::OhmMeters)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricResistivityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricResistivity operator+(ElectricResistivity other) const noexcept
        {
            return ElectricResistivity(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricResistivity operator-(ElectricResistivity other) const noexcept
        {
            return ElectricResistivity(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricResistivity operator*(double scalar) const noexcept
        {
            return ElectricResistivity(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricResistivity operator/(double scalar) const noexcept
        {
            return ElectricResistivity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricResistivity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricResistivity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double ohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::OhmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_ohm_meters(double value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::OhmMeters);
        }


        [[nodiscard]] constexpr double picoohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::PicoohmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_picoohm_meters(double value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::PicoohmMeters);
        }


        [[nodiscard]] constexpr double nanoohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::NanoohmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_nanoohm_meters(double value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::NanoohmMeters);
        }


        [[nodiscard]] constexpr double microohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::MicroohmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_microohm_meters(double value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MicroohmMeters);
        }


        [[nodiscard]] constexpr double milliohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::MilliohmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_milliohm_meters(double value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MilliohmMeters);
        }


        [[nodiscard]] constexpr double kiloohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::KiloohmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_kiloohm_meters(double value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::KiloohmMeters);
        }


        [[nodiscard]] constexpr double megaohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::MegaohmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_megaohm_meters(double value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MegaohmMeters);
        }


        [[nodiscard]] constexpr double ohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::OhmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_ohms_centimeter(double value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::OhmsCentimeter);
        }


        [[nodiscard]] constexpr double picoohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::PicoohmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_picoohms_centimeter(double value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::PicoohmsCentimeter);
        }


        [[nodiscard]] constexpr double nanoohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::NanoohmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_nanoohms_centimeter(double value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::NanoohmsCentimeter);
        }


        [[nodiscard]] constexpr double microohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::MicroohmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_microohms_centimeter(double value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MicroohmsCentimeter);
        }


        [[nodiscard]] constexpr double milliohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::MilliohmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_milliohms_centimeter(double value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MilliohmsCentimeter);
        }


        [[nodiscard]] constexpr double kiloohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::KiloohmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_kiloohms_centimeter(double value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::KiloohmsCentimeter);
        }


        [[nodiscard]] constexpr double megaohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::MegaohmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_megaohms_centimeter(double value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MegaohmsCentimeter);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricResistivityUnit unit)
        {
            switch (unit)
            {

            case ElectricResistivityUnit::OhmMeters:
                return value;

            case ElectricResistivityUnit::PicoohmMeters:
                return (value * 1e-12);

            case ElectricResistivityUnit::NanoohmMeters:
                return (value * 1e-9);

            case ElectricResistivityUnit::MicroohmMeters:
                return (value * 1e-6);

            case ElectricResistivityUnit::MilliohmMeters:
                return (value * 1e-3);

            case ElectricResistivityUnit::KiloohmMeters:
                return (value * 1e3);

            case ElectricResistivityUnit::MegaohmMeters:
                return (value * 1e6);

            case ElectricResistivityUnit::OhmsCentimeter:
                return value / 100;

            case ElectricResistivityUnit::PicoohmsCentimeter:
                return (value * 1e-12) / 100;

            case ElectricResistivityUnit::NanoohmsCentimeter:
                return (value * 1e-9) / 100;

            case ElectricResistivityUnit::MicroohmsCentimeter:
                return (value * 1e-6) / 100;

            case ElectricResistivityUnit::MilliohmsCentimeter:
                return (value * 1e-3) / 100;

            case ElectricResistivityUnit::KiloohmsCentimeter:
                return (value * 1e3) / 100;

            case ElectricResistivityUnit::MegaohmsCentimeter:
                return (value * 1e6) / 100;

            }

            throw std::invalid_argument("Unknown ElectricResistivity unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricResistivityUnit unit) const
        {
            switch (unit)
            {

            case ElectricResistivityUnit::OhmMeters:
                return value_;

            case ElectricResistivityUnit::PicoohmMeters:
                return (value_) / 1e-12;

            case ElectricResistivityUnit::NanoohmMeters:
                return (value_) / 1e-9;

            case ElectricResistivityUnit::MicroohmMeters:
                return (value_) / 1e-6;

            case ElectricResistivityUnit::MilliohmMeters:
                return (value_) / 1e-3;

            case ElectricResistivityUnit::KiloohmMeters:
                return (value_) / 1e3;

            case ElectricResistivityUnit::MegaohmMeters:
                return (value_) / 1e6;

            case ElectricResistivityUnit::OhmsCentimeter:
                return value_ * 100;

            case ElectricResistivityUnit::PicoohmsCentimeter:
                return (value_ * 100) / 1e-12;

            case ElectricResistivityUnit::NanoohmsCentimeter:
                return (value_ * 100) / 1e-9;

            case ElectricResistivityUnit::MicroohmsCentimeter:
                return (value_ * 100) / 1e-6;

            case ElectricResistivityUnit::MilliohmsCentimeter:
                return (value_ * 100) / 1e-3;

            case ElectricResistivityUnit::KiloohmsCentimeter:
                return (value_ * 100) / 1e3;

            case ElectricResistivityUnit::MegaohmsCentimeter:
                return (value_ * 100) / 1e6;

            }

            throw std::invalid_argument("Unknown ElectricResistivity unit.");
        }

        double value_;
    };
}
