#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class DoseAreaProductUnit : std::uint8_t
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
            const un_scalar_t value,
            const DoseAreaProductUnit unit = DoseAreaProductUnit::GraySquareMeters)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const DoseAreaProductUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr DoseAreaProduct operator+(const DoseAreaProduct other) const noexcept
        {
            return DoseAreaProduct(value_ + other.value_);
        }

        [[nodiscard]] constexpr DoseAreaProduct operator-(const DoseAreaProduct other) const noexcept
        {
            return DoseAreaProduct(value_ - other.value_);
        }

        [[nodiscard]] constexpr DoseAreaProduct operator*(const un_scalar_t scalar) const noexcept
        {
            return DoseAreaProduct(value_ * scalar);
        }

        [[nodiscard]] constexpr DoseAreaProduct operator/(const un_scalar_t scalar) const noexcept
        {
            return DoseAreaProduct(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const DoseAreaProduct other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const DoseAreaProduct other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t gray_square_meters() const
        {
            return convert_from_base(DoseAreaProductUnit::GraySquareMeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_gray_square_meters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::GraySquareMeters);
        }


        [[nodiscard]] constexpr un_scalar_t microgray_square_meters() const
        {
            return convert_from_base(DoseAreaProductUnit::MicrograySquareMeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_microgray_square_meters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MicrograySquareMeters);
        }


        [[nodiscard]] constexpr un_scalar_t milligray_square_meters() const
        {
            return convert_from_base(DoseAreaProductUnit::MilligraySquareMeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_milligray_square_meters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MilligraySquareMeters);
        }


        [[nodiscard]] constexpr un_scalar_t centigray_square_meters() const
        {
            return convert_from_base(DoseAreaProductUnit::CentigraySquareMeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_centigray_square_meters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::CentigraySquareMeters);
        }


        [[nodiscard]] constexpr un_scalar_t decigray_square_meters() const
        {
            return convert_from_base(DoseAreaProductUnit::DecigraySquareMeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_decigray_square_meters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::DecigraySquareMeters);
        }


        [[nodiscard]] constexpr un_scalar_t gray_square_decimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::GraySquareDecimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_gray_square_decimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::GraySquareDecimeters);
        }


        [[nodiscard]] constexpr un_scalar_t microgray_square_decimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::MicrograySquareDecimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_microgray_square_decimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MicrograySquareDecimeters);
        }


        [[nodiscard]] constexpr un_scalar_t milligray_square_decimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::MilligraySquareDecimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_milligray_square_decimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MilligraySquareDecimeters);
        }


        [[nodiscard]] constexpr un_scalar_t centigray_square_decimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::CentigraySquareDecimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_centigray_square_decimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::CentigraySquareDecimeters);
        }


        [[nodiscard]] constexpr un_scalar_t decigray_square_decimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::DecigraySquareDecimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_decigray_square_decimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::DecigraySquareDecimeters);
        }


        [[nodiscard]] constexpr un_scalar_t gray_square_centimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::GraySquareCentimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_gray_square_centimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::GraySquareCentimeters);
        }


        [[nodiscard]] constexpr un_scalar_t microgray_square_centimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::MicrograySquareCentimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_microgray_square_centimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MicrograySquareCentimeters);
        }


        [[nodiscard]] constexpr un_scalar_t milligray_square_centimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::MilligraySquareCentimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_milligray_square_centimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MilligraySquareCentimeters);
        }


        [[nodiscard]] constexpr un_scalar_t centigray_square_centimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::CentigraySquareCentimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_centigray_square_centimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::CentigraySquareCentimeters);
        }


        [[nodiscard]] constexpr un_scalar_t decigray_square_centimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::DecigraySquareCentimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_decigray_square_centimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::DecigraySquareCentimeters);
        }


        [[nodiscard]] constexpr un_scalar_t gray_square_millimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::GraySquareMillimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_gray_square_millimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::GraySquareMillimeters);
        }


        [[nodiscard]] constexpr un_scalar_t microgray_square_millimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::MicrograySquareMillimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_microgray_square_millimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MicrograySquareMillimeters);
        }


        [[nodiscard]] constexpr un_scalar_t milligray_square_millimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::MilligraySquareMillimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_milligray_square_millimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MilligraySquareMillimeters);
        }


        [[nodiscard]] constexpr un_scalar_t centigray_square_millimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::CentigraySquareMillimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_centigray_square_millimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::CentigraySquareMillimeters);
        }


        [[nodiscard]] constexpr un_scalar_t decigray_square_millimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::DecigraySquareMillimeters);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_decigray_square_millimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::DecigraySquareMillimeters);
        }


        [[nodiscard]] constexpr un_scalar_t gray_square_micrometers() const
        {
            return convert_from_base(DoseAreaProductUnit::GraySquareMicrometers);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_gray_square_micrometers(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::GraySquareMicrometers);
        }


        [[nodiscard]] constexpr un_scalar_t microgray_square_micrometers() const
        {
            return convert_from_base(DoseAreaProductUnit::MicrograySquareMicrometers);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_microgray_square_micrometers(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MicrograySquareMicrometers);
        }


        [[nodiscard]] constexpr un_scalar_t milligray_square_micrometers() const
        {
            return convert_from_base(DoseAreaProductUnit::MilligraySquareMicrometers);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_milligray_square_micrometers(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MilligraySquareMicrometers);
        }


        [[nodiscard]] constexpr un_scalar_t centigray_square_micrometers() const
        {
            return convert_from_base(DoseAreaProductUnit::CentigraySquareMicrometers);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_centigray_square_micrometers(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::CentigraySquareMicrometers);
        }


        [[nodiscard]] constexpr un_scalar_t decigray_square_micrometers() const
        {
            return convert_from_base(DoseAreaProductUnit::DecigraySquareMicrometers);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_decigray_square_micrometers(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::DecigraySquareMicrometers);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, DoseAreaProductUnit unit)
        {
            switch (unit)
            {

            case DoseAreaProductUnit::GraySquareMeters:
                return value;

            case DoseAreaProductUnit::MicrograySquareMeters:
                return (value * static_cast<un_scalar_t>(1e-6));

            case DoseAreaProductUnit::MilligraySquareMeters:
                return (value * static_cast<un_scalar_t>(1e-3));

            case DoseAreaProductUnit::CentigraySquareMeters:
                return (value * static_cast<un_scalar_t>(1e-2));

            case DoseAreaProductUnit::DecigraySquareMeters:
                return (value * static_cast<un_scalar_t>(1e-1));

            case DoseAreaProductUnit::GraySquareDecimeters:
                return value / 100;

            case DoseAreaProductUnit::MicrograySquareDecimeters:
                return (value * static_cast<un_scalar_t>(1e-6)) / 100;

            case DoseAreaProductUnit::MilligraySquareDecimeters:
                return (value * static_cast<un_scalar_t>(1e-3)) / 100;

            case DoseAreaProductUnit::CentigraySquareDecimeters:
                return (value * static_cast<un_scalar_t>(1e-2)) / 100;

            case DoseAreaProductUnit::DecigraySquareDecimeters:
                return (value * static_cast<un_scalar_t>(1e-1)) / 100;

            case DoseAreaProductUnit::GraySquareCentimeters:
                return value / 10000;

            case DoseAreaProductUnit::MicrograySquareCentimeters:
                return (value * static_cast<un_scalar_t>(1e-6)) / 10000;

            case DoseAreaProductUnit::MilligraySquareCentimeters:
                return (value * static_cast<un_scalar_t>(1e-3)) / 10000;

            case DoseAreaProductUnit::CentigraySquareCentimeters:
                return (value * static_cast<un_scalar_t>(1e-2)) / 10000;

            case DoseAreaProductUnit::DecigraySquareCentimeters:
                return (value * static_cast<un_scalar_t>(1e-1)) / 10000;

            case DoseAreaProductUnit::GraySquareMillimeters:
                return value / 1000000;

            case DoseAreaProductUnit::MicrograySquareMillimeters:
                return (value * static_cast<un_scalar_t>(1e-6)) / 1000000;

            case DoseAreaProductUnit::MilligraySquareMillimeters:
                return (value * static_cast<un_scalar_t>(1e-3)) / 1000000;

            case DoseAreaProductUnit::CentigraySquareMillimeters:
                return (value * static_cast<un_scalar_t>(1e-2)) / 1000000;

            case DoseAreaProductUnit::DecigraySquareMillimeters:
                return (value * static_cast<un_scalar_t>(1e-1)) / 1000000;

            case DoseAreaProductUnit::GraySquareMicrometers:
                return value / 1000000000000;

            case DoseAreaProductUnit::MicrograySquareMicrometers:
                return (value * static_cast<un_scalar_t>(1e-6)) / 1000000000000;

            case DoseAreaProductUnit::MilligraySquareMicrometers:
                return (value * static_cast<un_scalar_t>(1e-3)) / 1000000000000;

            case DoseAreaProductUnit::CentigraySquareMicrometers:
                return (value * static_cast<un_scalar_t>(1e-2)) / 1000000000000;

            case DoseAreaProductUnit::DecigraySquareMicrometers:
                return (value * static_cast<un_scalar_t>(1e-1)) / 1000000000000;

            }

            throw std::invalid_argument("Unknown DoseAreaProduct unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const DoseAreaProductUnit unit) const
        {
            switch (unit)
            {

            case DoseAreaProductUnit::GraySquareMeters:
                return value_;

            case DoseAreaProductUnit::MicrograySquareMeters:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case DoseAreaProductUnit::MilligraySquareMeters:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case DoseAreaProductUnit::CentigraySquareMeters:
                return (value_) / static_cast<un_scalar_t>(1e-2);

            case DoseAreaProductUnit::DecigraySquareMeters:
                return (value_) / static_cast<un_scalar_t>(1e-1);

            case DoseAreaProductUnit::GraySquareDecimeters:
                return value_ * 100;

            case DoseAreaProductUnit::MicrograySquareDecimeters:
                return (value_ * 100) / static_cast<un_scalar_t>(1e-6);

            case DoseAreaProductUnit::MilligraySquareDecimeters:
                return (value_ * 100) / static_cast<un_scalar_t>(1e-3);

            case DoseAreaProductUnit::CentigraySquareDecimeters:
                return (value_ * 100) / static_cast<un_scalar_t>(1e-2);

            case DoseAreaProductUnit::DecigraySquareDecimeters:
                return (value_ * 100) / static_cast<un_scalar_t>(1e-1);

            case DoseAreaProductUnit::GraySquareCentimeters:
                return value_ * 10000;

            case DoseAreaProductUnit::MicrograySquareCentimeters:
                return (value_ * 10000) / static_cast<un_scalar_t>(1e-6);

            case DoseAreaProductUnit::MilligraySquareCentimeters:
                return (value_ * 10000) / static_cast<un_scalar_t>(1e-3);

            case DoseAreaProductUnit::CentigraySquareCentimeters:
                return (value_ * 10000) / static_cast<un_scalar_t>(1e-2);

            case DoseAreaProductUnit::DecigraySquareCentimeters:
                return (value_ * 10000) / static_cast<un_scalar_t>(1e-1);

            case DoseAreaProductUnit::GraySquareMillimeters:
                return value_ * 1000000;

            case DoseAreaProductUnit::MicrograySquareMillimeters:
                return (value_ * 1000000) / static_cast<un_scalar_t>(1e-6);

            case DoseAreaProductUnit::MilligraySquareMillimeters:
                return (value_ * 1000000) / static_cast<un_scalar_t>(1e-3);

            case DoseAreaProductUnit::CentigraySquareMillimeters:
                return (value_ * 1000000) / static_cast<un_scalar_t>(1e-2);

            case DoseAreaProductUnit::DecigraySquareMillimeters:
                return (value_ * 1000000) / static_cast<un_scalar_t>(1e-1);

            case DoseAreaProductUnit::GraySquareMicrometers:
                return value_ * 1000000000000;

            case DoseAreaProductUnit::MicrograySquareMicrometers:
                return (value_ * 1000000000000) / static_cast<un_scalar_t>(1e-6);

            case DoseAreaProductUnit::MilligraySquareMicrometers:
                return (value_ * 1000000000000) / static_cast<un_scalar_t>(1e-3);

            case DoseAreaProductUnit::CentigraySquareMicrometers:
                return (value_ * 1000000000000) / static_cast<un_scalar_t>(1e-2);

            case DoseAreaProductUnit::DecigraySquareMicrometers:
                return (value_ * 1000000000000) / static_cast<un_scalar_t>(1e-1);

            }

            throw std::invalid_argument("Unknown DoseAreaProduct unit.");
        }

        un_scalar_t value_;
    };
}
