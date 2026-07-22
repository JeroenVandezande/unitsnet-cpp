import json
import sys
from pathlib import Path

from unitsnet_py import Length, LengthUnits


def main() -> None:
    if len(sys.argv) != 3:
        raise SystemExit("Usage: unitsnet_interop.py <input.json> <output.json>")

    input_path = Path(sys.argv[1])
    output_path = Path(sys.argv[2])

    with input_path.open("r", encoding="utf-8") as input_file:
        input_json = json.load(input_file)

    length = Length.from_dto_json(input_json)
    tripled = Length.from_meters(length.meters * 3)
    output_json = tripled.to_dto_json(LengthUnits.Kilometer)

    with output_path.open("w", encoding="utf-8") as output_file:
        json.dump(output_json, output_file, indent=2)
        output_file.write("\n")


if __name__ == "__main__":
    main()
