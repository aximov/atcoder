# スプリンクラー
# 隣接リストで表現したグラフの頂点の色を塗り替える

n, m, q = map(int, input().split())

# 辺の頂点
edges: list[list[int]] = []
for _ in range(n):
    edges.append([])
for _ in range(m):
    u, v = map(int, input().split())
    # この時点で0-indexedにしたほうがミスしにくい
    u -= 1
    v -= 1
    edges[u].append(v)
    # 無向グラフなので逆も追加する
    edges[v].append(u)

# 頂点の色
c = list(map(int, input().split()))

for _ in range(q):
    s = input().split()

    # '1 x' なら頂点 x の色を出力し、スプリンクラーを起動する
    if s[0] == "1":
        x = int(s[1])
        # 0-indexedにする
        x -= 1
        color = c[x]
        print(color)
        # 頂点 x に隣接する頂点の色を全て x の色に塗り替える
        for i in edges[x]:
            c[i] = color

    # '2 x y' なら頂点 x の色を出力し、頂点 x の色を y に塗り替える
    elif s[0] == "2":
        x, y = int(s[1]), int(s[2])
        # 頂点番号のみ0-indexedにする
        x -= 1
        print(c[x])
        c[x] = y
