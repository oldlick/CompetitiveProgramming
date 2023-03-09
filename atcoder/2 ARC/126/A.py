import pulp

# 問題の定義
problem = pulp.LpProblem(name="Diet", sense=pulp.LpMaximize)

# 変数の定義
A = pulp.LpVariable(name = "A", lowBound = 0, cat="Integer")
B = pulp.LpVariable(name = "B", lowBound = 0, cat="Integer")
C = pulp.LpVariable(name = "C", lowBound = 0, cat="Integer")
D = pulp.LpVariable(name = "B", lowBound = 0, cat="Integer")
E = pulp.LpVariable(name = "C", lowBound = 0, cat="Integer")

# 目的関数
problem += A + B + C + D + E

# 制約条件の定義
problem += 5*A + 2*B + 3*C + D >= 200
problem += C + 2*D + E >= 200
problem += B + E >= 100

# 解く
status = problem.solve()
print(pulp.LpStatus[status])

# 結果表示
print("Result")
print("A:", A.value())
print("B:", B.value())
print("C:", C.value())
print("D:", D.value())
print("E:", E.value())