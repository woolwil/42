#!/usr/bin/env python3

import importlib.metadata

REQUIRED_PACKAGES = {
    "pandas": "Data manipulation ready",
    "numpy": "Numerical computation ready",
    "requests": "Network access ready",
    "matplotlib": "Visualization ready",
}

missing_dependencies = r"""To install dependencies using pip:
            pip install -r requirements.txt
            
            To install dependencies using Poetry:
            poetry install
            poetry run python loading.py"""


def get_package_ver(package_name: str) -> tuple[bool, str]:
    try:
        ver = importlib.metadata.version(package_name)
        return True, ver
    except importlib.metadata.PackageNotFoundError:
        return False, "N/A"


def check_dependencies() -> bool:
    all_ok = True
    for pkg, txt in REQUIRED_PACKAGES.items():
        is_installed, ver = get_package_ver(pkg)
        if not is_installed:
            print(f"[MISSING] {pkg} - Installation required")
            all_ok = False
        else:
            # for val in REQUIRED_PACKAGES.values():
            print(f"[OK] {pkg} ({ver}) - {txt}")
    if not all_ok:
        print("\n" + missing_dependencies)
        return False
    return True

def run_matrix_analysis() -> None:
    import numpy as np
    import pandas as pd
    import matplotlib
    matplotlib.use('Agg')
    import matplotlib.pyplot as plt

    print("Analyzing Matrix data...")
    print("Processing 1000 data points...")

    # generate 1000 random data points with numpy
    data = np.random.normal(loc=0.0, scale=1.0, size=1000)

    # put into pandas DataFrame
    df = pd.DataFrame({"signal": data})

    print("Generating visualization...")
    plt.figure(figsize=(8, 5))
    plt.hist(df["signal"], bins=30, color="green", alpha=0.7)
    plt.title("Matrix Signal Distribution")
    plt.xlabel("Signal Intensity")
    plt.ylabel("Frequency")

    plt.savefig("matrix_analysis.png")
    plt.close()

    print("Analysis complete!")
    print("Results saved to: matrix_analysis.png")

def main() -> None:
    print("LOADING STATUS: Loading programs...")
    print("Checking dependencies:")
    if check_dependencies():
        run_matrix_analysis()
    

if __name__ == "__main__":
    main()
