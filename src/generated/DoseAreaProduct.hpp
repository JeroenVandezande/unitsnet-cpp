#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class DoseAreaProductUnit : std::uint16_t
    {
        GraySquareMeters,
        MicrograySquareMeters,
        MilligraySquareMeters,
        CentigraySquareMeters,
        DecigraySquareMeters,
        GraySquareDecimeters,
        MicrograySquareDecimeters,
        MilligraySquareDecimeters,
        CentigraySquareDecimeters,
        DecigraySquareDecimeters,
        GraySquareCentimeters,
        MicrograySquareCentimeters,
        MilligraySquareCentimeters,
        CentigraySquareCentimeters,
        DecigraySquareCentimeters,
        GraySquareMillimeters,
        MicrograySquareMillimeters,
        MilligraySquareMillimeters,
        CentigraySquareMillimeters,
        DecigraySquareMillimeters,
        GraySquareMicrometers,
        MicrograySquareMicrometers,
        MilligraySquareMicrometers,
        CentigraySquareMicrometers,
        DecigraySquareMicrometers,
    };

    /// <summary>It is defined as the absorbed dose multiplied by the area irradiated.</summary>
    class DoseAreaProduct
    {
    public:
        constexpr explicit DoseAreaProduct(
            double value,
            DoseAreaProductUnit unit = DoseAreaProductUnit::GraySquareMeters)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(DoseAreaProductUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr DoseAreaProduct operator+(DoseAreaProduct other) const noexcept
        {
            return DoseAreaProduct(value_ + other.value_);
        }

        [[nodiscard]] constexpr DoseAreaProduct operator-(DoseAreaProduct other) const noexcept
        {
            return DoseAreaProduct(value_ - other.value_);
        }

        [[nodiscard]] constexpr DoseAreaProduct operator*(double scalar) const noexcept
        {
            return DoseAreaProduct(value_ * scalar);
        }

        [[nodiscard]] constexpr DoseAreaProduct operator/(double scalar) const noexcept
        {
            return DoseAreaProduct(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(DoseAreaProduct other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(DoseAreaProduct other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double gray_square_meters() const
        {
            return convert_from_base(DoseAreaProductUnit::GraySquareMeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_gray_square_meters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::GraySquareMeters);
        }


        [[nodiscard]] constexpr double microgray_square_meters() const
        {
            return convert_from_base(DoseAreaProductUnit::MicrograySquareMeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_microgray_square_meters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MicrograySquareMeters);
        }


        [[nodiscard]] constexpr double milligray_square_meters() const
        {
            return convert_from_base(DoseAreaProductUnit::MilligraySquareMeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_milligray_square_meters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MilligraySquareMeters);
        }


        [[nodiscard]] constexpr double centigray_square_meters() const
        {
            return convert_from_base(DoseAreaProductUnit::CentigraySquareMeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_centigray_square_meters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::CentigraySquareMeters);
        }


        [[nodiscard]] constexpr double decigray_square_meters() const
        {
            return convert_from_base(DoseAreaProductUnit::DecigraySquareMeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_decigray_square_meters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::DecigraySquareMeters);
        }


        [[nodiscard]] constexpr double gray_square_decimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::GraySquareDecimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_gray_square_decimeters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::GraySquareDecimeters);
        }


        [[nodiscard]] constexpr double microgray_square_decimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::MicrograySquareDecimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_microgray_square_decimeters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MicrograySquareDecimeters);
        }


        [[nodiscard]] constexpr double milligray_square_decimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::MilligraySquareDecimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_milligray_square_decimeters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MilligraySquareDecimeters);
        }


        [[nodiscard]] constexpr double centigray_square_decimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::CentigraySquareDecimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_centigray_square_decimeters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::CentigraySquareDecimeters);
        }


        [[nodiscard]] constexpr double decigray_square_decimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::DecigraySquareDecimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_decigray_square_decimeters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::DecigraySquareDecimeters);
        }


        [[nodiscard]] constexpr double gray_square_centimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::GraySquareCentimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_gray_square_centimeters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::GraySquareCentimeters);
        }


        [[nodiscard]] constexpr double microgray_square_centimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::MicrograySquareCentimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_microgray_square_centimeters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MicrograySquareCentimeters);
        }


        [[nodiscard]] constexpr double milligray_square_centimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::MilligraySquareCentimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_milligray_square_centimeters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MilligraySquareCentimeters);
        }


        [[nodiscard]] constexpr double centigray_square_centimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::CentigraySquareCentimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_centigray_square_centimeters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::CentigraySquareCentimeters);
        }


        [[nodiscard]] constexpr double decigray_square_centimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::DecigraySquareCentimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_decigray_square_centimeters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::DecigraySquareCentimeters);
        }


        [[nodiscard]] constexpr double gray_square_millimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::GraySquareMillimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_gray_square_millimeters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::GraySquareMillimeters);
        }


        [[nodiscard]] constexpr double microgray_square_millimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::MicrograySquareMillimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_microgray_square_millimeters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MicrograySquareMillimeters);
        }


        [[nodiscard]] constexpr double milligray_square_millimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::MilligraySquareMillimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_milligray_square_millimeters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MilligraySquareMillimeters);
        }


        [[nodiscard]] constexpr double centigray_square_millimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::CentigraySquareMillimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_centigray_square_millimeters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::CentigraySquareMillimeters);
        }


        [[nodiscard]] constexpr double decigray_square_millimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::DecigraySquareMillimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_decigray_square_millimeters(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::DecigraySquareMillimeters);
        }


        [[nodiscard]] constexpr double gray_square_micrometers() const
        {
            return convert_from_base(DoseAreaProductUnit::GraySquareMicrometers);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_gray_square_micrometers(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::GraySquareMicrometers);
        }


        [[nodiscard]] constexpr double microgray_square_micrometers() const
        {
            return convert_from_base(DoseAreaProductUnit::MicrograySquareMicrometers);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_microgray_square_micrometers(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MicrograySquareMicrometers);
        }


        [[nodiscard]] constexpr double milligray_square_micrometers() const
        {
            return convert_from_base(DoseAreaProductUnit::MilligraySquareMicrometers);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_milligray_square_micrometers(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MilligraySquareMicrometers);
        }


        [[nodiscard]] constexpr double centigray_square_micrometers() const
        {
            return convert_from_base(DoseAreaProductUnit::CentigraySquareMicrometers);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_centigray_square_micrometers(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::CentigraySquareMicrometers);
        }


        [[nodiscard]] constexpr double decigray_square_micrometers() const
        {
            return convert_from_base(DoseAreaProductUnit::DecigraySquareMicrometers);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_decigray_square_micrometers(double value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::DecigraySquareMicrometers);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, DoseAreaProductUnit unit)
        {
            switch (unit)
            {

            case DoseAreaProductUnit::GraySquareMeters:
                return value;

            case DoseAreaProductUnit::MicrograySquareMeters:
                return (value * 1e-6);

            case DoseAreaProductUnit::MilligraySquareMeters:
                return (value * 1e-3);

            case DoseAreaProductUnit::CentigraySquareMeters:
                return (value * 1e-2);

            case DoseAreaProductUnit::DecigraySquareMeters:
                return (value * 1e-1);

            case DoseAreaProductUnit::GraySquareDecimeters:
                return value / 100;

            case DoseAreaProductUnit::MicrograySquareDecimeters:
                return (value * 1e-6) / 100;

            case DoseAreaProductUnit::MilligraySquareDecimeters:
                return (value * 1e-3) / 100;

            case DoseAreaProductUnit::CentigraySquareDecimeters:
                return (value * 1e-2) / 100;

            case DoseAreaProductUnit::DecigraySquareDecimeters:
                return (value * 1e-1) / 100;

            case DoseAreaProductUnit::GraySquareCentimeters:
                return value / 10000;

            case DoseAreaProductUnit::MicrograySquareCentimeters:
                return (value * 1e-6) / 10000;

            case DoseAreaProductUnit::MilligraySquareCentimeters:
                return (value * 1e-3) / 10000;

            case DoseAreaProductUnit::CentigraySquareCentimeters:
                return (value * 1e-2) / 10000;

            case DoseAreaProductUnit::DecigraySquareCentimeters:
                return (value * 1e-1) / 10000;

            case DoseAreaProductUnit::GraySquareMillimeters:
                return value / 1000000;

            case DoseAreaProductUnit::MicrograySquareMillimeters:
                return (value * 1e-6) / 1000000;

            case DoseAreaProductUnit::MilligraySquareMillimeters:
                return (value * 1e-3) / 1000000;

            case DoseAreaProductUnit::CentigraySquareMillimeters:
                return (value * 1e-2) / 1000000;

            case DoseAreaProductUnit::DecigraySquareMillimeters:
                return (value * 1e-1) / 1000000;

            case DoseAreaProductUnit::GraySquareMicrometers:
                return value / 1000000000000;

            case DoseAreaProductUnit::MicrograySquareMicrometers:
                return (value * 1e-6) / 1000000000000;

            case DoseAreaProductUnit::MilligraySquareMicrometers:
                return (value * 1e-3) / 1000000000000;

            case DoseAreaProductUnit::CentigraySquareMicrometers:
                return (value * 1e-2) / 1000000000000;

            case DoseAreaProductUnit::DecigraySquareMicrometers:
                return (value * 1e-1) / 1000000000000;

            }

            throw std::invalid_argument("Unknown DoseAreaProduct unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(DoseAreaProductUnit unit) const
        {
            switch (unit)
            {

            case DoseAreaProductUnit::GraySquareMeters:
                return value_;

            case DoseAreaProductUnit::MicrograySquareMeters:
                return (value_) / 1e-6;

            case DoseAreaProductUnit::MilligraySquareMeters:
                return (value_) / 1e-3;

            case DoseAreaProductUnit::CentigraySquareMeters:
                return (value_) / 1e-2;

            case DoseAreaProductUnit::DecigraySquareMeters:
                return (value_) / 1e-1;

            case DoseAreaProductUnit::GraySquareDecimeters:
                return value_ * 100;

            case DoseAreaProductUnit::MicrograySquareDecimeters:
                return (value_ * 100) / 1e-6;

            case DoseAreaProductUnit::MilligraySquareDecimeters:
                return (value_ * 100) / 1e-3;

            case DoseAreaProductUnit::CentigraySquareDecimeters:
                return (value_ * 100) / 1e-2;

            case DoseAreaProductUnit::DecigraySquareDecimeters:
                return (value_ * 100) / 1e-1;

            case DoseAreaProductUnit::GraySquareCentimeters:
                return value_ * 10000;

            case DoseAreaProductUnit::MicrograySquareCentimeters:
                return (value_ * 10000) / 1e-6;

            case DoseAreaProductUnit::MilligraySquareCentimeters:
                return (value_ * 10000) / 1e-3;

            case DoseAreaProductUnit::CentigraySquareCentimeters:
                return (value_ * 10000) / 1e-2;

            case DoseAreaProductUnit::DecigraySquareCentimeters:
                return (value_ * 10000) / 1e-1;

            case DoseAreaProductUnit::GraySquareMillimeters:
                return value_ * 1000000;

            case DoseAreaProductUnit::MicrograySquareMillimeters:
                return (value_ * 1000000) / 1e-6;

            case DoseAreaProductUnit::MilligraySquareMillimeters:
                return (value_ * 1000000) / 1e-3;

            case DoseAreaProductUnit::CentigraySquareMillimeters:
                return (value_ * 1000000) / 1e-2;

            case DoseAreaProductUnit::DecigraySquareMillimeters:
                return (value_ * 1000000) / 1e-1;

            case DoseAreaProductUnit::GraySquareMicrometers:
                return value_ * 1000000000000;

            case DoseAreaProductUnit::MicrograySquareMicrometers:
                return (value_ * 1000000000000) / 1e-6;

            case DoseAreaProductUnit::MilligraySquareMicrometers:
                return (value_ * 1000000000000) / 1e-3;

            case DoseAreaProductUnit::CentigraySquareMicrometers:
                return (value_ * 1000000000000) / 1e-2;

            case DoseAreaProductUnit::DecigraySquareMicrometers:
                return (value_ * 1000000000000) / 1e-1;

            }

            throw std::invalid_argument("Unknown DoseAreaProduct unit.");
        }

        double value_;
    };
}
