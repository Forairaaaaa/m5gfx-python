# m5gfx-python

python ./fetch_repos.py

pip install scikit-build setuptools wheel cmake ninja

pip install pybind11 scikit-build cmake

python ./fetch_repos.py

python setup.py build_ext --inplace

pip install .

pip uninstall m5gfx

issue:

- no handle to colors_t, so no Gradient functions yet

- no Palette handle yet

- no pushImage yet

- set font crash

