import eventgrid as evg

assert evg.__version__ == '0.0.1'
assert evg.add(1, 2) == 3
assert evg.subtract(1, 2) == -1

print("Installation OK")
