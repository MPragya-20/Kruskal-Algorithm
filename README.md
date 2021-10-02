# Kruskal-Algorithm
This is a greedy algorithm which chooses some local optimum(picking an edge with min cost first and add to mst).
Note : MST has (v-1) edges.

Since input is a graph, there might be cycles, so use Union find algo if there exists a cycle. MST is a tree ofc and should avoid loops or cycles.

Used Union find Algorithm with 'path compression' to detect cycle.

Path Compression basically fixes the root of the visited node to the root node //Optimization technique
